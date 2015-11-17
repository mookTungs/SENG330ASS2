#include "ItemPrototype.h"
#include "JSONParsing.h"

int main()
{
	ItemFactory::initialize();
	Item* object;
	string objectType;
	string objectName;
	vector<Item*> objectList;
	JsonLoad(objectList);
	cout << "Types of object: potion, antidote" << endl;
	cout << "Example: if you want to create potion, type \"potion\"" << endl;
	cout << "Type \"exit\" if you want to exit the program" << endl;
	while(true)
	{
		cout << "Type of object:" << endl;
		cout << ">> ";
		cin >> objectType;
		if(objectType.compare("potion") == 0)
		{
			cout << "Name:" << endl;
			cout << ">> ";
			cin >> objectName;
			object = ItemFactory::makePotion(objectName);
			objectList.push_back(object);
			object->printItem();
		}
		else if(objectType.compare("antidote") == 0)
		{
			cout << "Name: " << endl;
			cout << ">> ";
			cin >> objectName;
			object = ItemFactory::makeAntidote(objectName);
			objectList.push_back(object);
			object->printItem();
		}
		else if(objectType.compare("exit") == 0)
		{
			break;
		}
		else
		{
			cout << "Invalid object. Please enter either \"potion\" or \"antidote\"" << endl;
			cout << "Type \"exit\" to exit the program." << endl; 
		}
	}
	if(!objectList.empty())
	{
		JsonSave(objectList);
		cout << endl;
		cout << "Objects have been saved in a file called ItemJSON.txt." << endl;
	}
	while(!objectList.empty())
	{
		object = objectList.back();
		objectList.pop_back();
		delete object;
	}
	delete ItemFactory::potion;
	delete ItemFactory::antidote;
	return 0;
}