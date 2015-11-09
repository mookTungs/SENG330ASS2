#include <iostream>

//Abstract Class
class Item
{
public:
	virtual Item* clone() = 0;
	virtual void printItem() = 0;
};

class Potion : public Item
{
public:
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

};