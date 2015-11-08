#include <iostream>

class Item
{
public:
	virtual Item* clone() = 0;
	virtual void printItem() = 0;
};
