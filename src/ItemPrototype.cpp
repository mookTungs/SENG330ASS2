#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Abstract Class
class Item
{
public:
	virtual Item* clone(string name) = 0;
	void printItem()
	{
		cout<< getType() << " named " << getName() << " is created.\n";
	}
	string getType()
	{
		return itemType;
	}
	string getName()
	{
		return itemName;
	}
protected:
	string itemType;
	string itemName;
};

class Potion : public Item
{
public:
	Potion(string name)
	{
		itemName = name;
		itemType = "Potion";
	}
	Item* clone(string name)
	{
		return new Potion(name);
	}
};

class Antidote : public Item
{
public:
	Antidote(string name)
	{
		itemName = name;
		itemType = "Antidote";
	}
	Item* clone(string name)
	{
		return new Antidote(name);
	}
};

class ItemFactory
{
public:
	static Item* potion = 0;
	static Item* antidote = 0;
	static void initialize()
	{
		potion = new Potion("Prototype Potion");
		antidote = new Antidote("Prototype Antidote");
	}
	static Item* makePotion(string name)
	{
		return potion->clone(name);
	}
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
		}
		else if(objectType.compare("antidote") == 0)
		{
			cout<< "Name:\n>> ";
			cin>> objectName;
		}
		else if(objectType.compare("exit") == 0)
		{
			break;
		}
		else
		{
			cout<< "Invalid of object. Please enter either \"potion\" or \"antidote\"\n";
			cout<< "Type \"exit\" to exit the program.\n"; 
		}
	}
	
	return 0;
}