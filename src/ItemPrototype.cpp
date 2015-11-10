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
	Item* makePotion(string name)
	{
		return potion->clone(name);
	}
	Item* makeAntidote(string name)
	{
		return antidote->clone(name);
	}
};

int main()
{
	return 0;
}