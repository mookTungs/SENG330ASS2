#include <iostream>
#include <string>
using namespace std;

//Abstract Class
class Item
{
public:
	virtual Item* clone() = 0;
	virtual void printItem() = 0;
	string getType()
	{
		return type;
	}
protected:
	string type;
};

class Potion : public Item
{
public:
	Potion()
	{
		type = "Potion";
	}
	Item* clone()
	{
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
		type = "Antidote";
	}
	Item* clone()
	{
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
	Item* makePotion()
	{
		return potion->clone();
	}
	Item* makeAntidote()
	{
		return antidote->clone();
	}
};