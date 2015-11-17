#include "JSONParsing.h"


//!Serialized and store object at runtime in a file called ItemsJSON.txt.
void JsonSave (vector<Item*> l)
{
	ofstream out("ItemsJSON.txt", ofstream::out);
	Json::Value itemList_json(Json::objectValue);
	Json::Value items_json(Json::arrayValue);
	for(vector<Item*>::iterator it = l.begin(); it != l.end(); it++)
	{
		items_json.append((*it)->toJson());
	}
	itemList_json["items"] = items_json;
	out << itemList_json;
	out.close();
}

//!Load the objects previously created from a file called ItemsJSON.txt.
void JsonLoad(vector<Item*> &l)
{
	Item* obj;
	string s;
	string t;
	ifstream in("ItemsJSON.txt");
	if(!in)
	{
		return;
	}
	cout << "Reading from ItemsJSON.txt." << endl;
	Json::Value item_json;
	in >> item_json;
	for(Json::Value::iterator it = item_json["items"].begin(); it != item_json["items"].end(); it++)
	{
		s = (*it)["type"].asString();
		t = (*it)["name"].asString();
		if(s.compare("Potion") == 0)
		{
			obj = ItemFactory::makePotion(t);
		}
		else
		{
			obj = ItemFactory::makeAntidote(t);
		}
		obj->printItem();
		l.push_back(obj);
	}
	cout << endl;
}