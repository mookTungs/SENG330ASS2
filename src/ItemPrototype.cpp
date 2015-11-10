#include <iostream>
#include <string>
using namespace std;

//Abstract Class
class Item
{
public:
	virtual Item* clone(string name) = 0;
	virtual void printItem() = 0;
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
	Potion()
	{
		itemType = "Potion";
	}
	Item* clone(string name)
	{
		itemName = name;
		return new Potion;
	}
	void printItem()
	{
		cout << "Potion is created\n";
	}
};

class Antidote : public Item
{
public:
	Antidote()
	{
		itemType = "Antidote";
	}
	Item* clone(string name)
	{
		itemName = name;
		return new Antidote;
	}
	void printItem()
	{
		cout << "Antidote is created\n";
	}
};

class ItemFactory
{
	Item* potion;
	Item* antidote;
public:
	void initialize()
	{
		potion = new Potion();
		antidote = new Antidote();
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