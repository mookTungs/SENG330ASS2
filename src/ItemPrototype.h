#ifndef _ItemPrototype_H_
#define _ItemPrototype_H_

#include <string>
#include "json.h"
#include <iostream>

using namespace std;

//!Abstract Item Class
class Item
{
public:
	//!Pure virtual clone method
	virtual Item* clone(string name) = 0;
	//!Print out statement confirming object has been created.
	void printItem();
	//!Return the type of the object.
	string getType();
	//!Return the name of the object.
	string getName();
	//!creating a JSON object 
	Json::Value toJson() const;
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
	Potion(string name);
	//!Return a new object Potion.
	Item* clone(string name);
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
	Antidote(string name);
	//!Return a new object Antidote.
	Item* clone(string name);
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
	static void initialize();
	//!Call the clone() of Potion and return the object.
	static Item* makePotion(string name);
	//!Call the clone() of Antidote and return the object.
	static Item* makeAntidote(string name);
};

#endif