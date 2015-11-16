#include <iostream>
#include <string>
#include <vector>
using namespace std;

//!Abstract Item Class
class Item
{
public:
	//!Pure virtual clone method
	virtual Item* clone(string name) = 0;
	//!Print out statement confirming object has been created.
	void printItem()
	{
		cout<< getType() << " named " << getName() << " is created.\n";
	}
	//!Return the type of the object.
	string getType()
	{
		return itemType;
	}
	//!Return the name of the object.
	string getName()
	{
		return itemName;
	}
protected:
	//!Store the type of the object.
	string itemType;
	//!Store the name of the object.
	string itemName;
};

//!A Potion class inherited from Item class.
/*!
   Potion class inherited from Item class. It contains a constructor and a clone function.
   It is used to increase the player's health.
*/
class Potion : public Item
{
public:
	//!Constructs an object Potion.
	Potion(string name)
	{
		itemName = name;
		itemType = "Potion";
	}
	//!Return a new object Potion.
	Item* clone(string name)
	{
		return new Potion(name);
	}
};

//!An Antidote class.
/*!
   Antidote class inherited from Item class. It contains a constructor and a clone function.
   It is used to cure the player from poison.
*/
class Antidote : public Item
{
public:
	//!Constructs an object Antidote.
	Antidote(string name)
	{
		itemName = name;
		itemType = "Antidote";
	}
	//!Return a new object Antidote.
	Item* clone(string name)
	{
		return new Antidote(name);
	}
};

//!An ItemFactory class
/*!
   ItemFactory store the prototypes and calls the clone() on that object,
   and return the object.
*/
class ItemFactory
{
public:
	//!A pointer to the Potion prototype.
	static Item* potion;
	//!A pointer to the Antidote prototype.
	static Item* antidote;
	//!Initialized the prototypes.
	static void initialize()
	{
		potion = new Potion("Prototype Potion");
		antidote = new Antidote("Prototype Antidote");
	}
	//!Call the clone() of Potion and return the object.
	static Item* makePotion(string name)
	{
		return potion->clone(name);
	}
	//!Call the clone() of Antidote and return the object.
	static Item* makeAntidote(string name)
	{
		return antidote->clone(name);
	}
};

Item* ItemFactory::potion = 0;
Item* ItemFactory::antidote = 0;

int main()
{
	ItemFactory::initialize();
	Item* object;
	string objectType;
	string objectName;
	vector<Item*> objectList;
	cout<< "Types of object: potion, antidote\n";
	cout<< "Example: if you want to create potion, type \"potion\"\n";
	cout<< "Type \"exit\" if you want to exit the program\n";
	while(true)
	{
		cout<< "Type of object:\n";
		cout<< ">> ";
		cin>> objectType;
		if(objectType.compare("potion") == 0)
		{
			cout<< "Name:\n>> ";
			cin>> objectName;
			object = ItemFactory::makePotion(objectName);
			objectList.push_back(object);
			object->printItem();
		}
		else if(objectType.compare("antidote") == 0)
		{
			cout<< "Name:\n>> ";
			cin>> objectName;
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
			cout<< "Invalid object. Please enter either \"potion\" or \"antidote\"\n";
			cout<< "Type \"exit\" to exit the program.\n"; 
		}
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