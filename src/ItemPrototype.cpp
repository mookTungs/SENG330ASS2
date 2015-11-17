#include "ItemPrototype.h"

using namespace std;

//!Print out statement confirming object has been created.
void Item::printItem()
{
	cout<< getType() << " named " << getName() << " is created." << endl;
}

//!Return the type of the object.
string Item::getType()
{
	return itemType;
}

//!Return the name of the object.
string Item::getName()
{
	return itemName;
}

//!creating a JSON object 
Json::Value Item::toJson() const
{
	Json::Value object(Json::objectValue);
	object["name"] = itemName;
	object["type"] = itemType;
	return object;
}

//!Constructs an object Potion.
Potion::Potion(string name)
{
	itemName = name;
	itemType = "Potion";
}

//!Return a new object Potion.
Item* Potion::clone(string name)
{
	return new Potion(name);
}

//!Constructs an object Antidote.
Antidote::Antidote(string name)
{
	itemName = name;
	itemType = "Antidote";
}

//!Return a new object Antidote.
Item* Antidote::clone(string name)
{
	return new Antidote(name);
}

void ItemFactory::initialize()
{
	potion = new Potion("Prototype Potion");
	antidote = new Antidote("Prototype Antidote");
}
	
//!Call the clone() of Potion and return the object.
Item* ItemFactory::makePotion(string name)
{
	return potion->clone(name);
}
//!Call the clone() of Antidote and return the object.
Item* ItemFactory::makeAntidote(string name)
{
	return antidote->clone(name);
}


Item* ItemFactory::potion = 0;
Item* ItemFactory::antidote = 0;
