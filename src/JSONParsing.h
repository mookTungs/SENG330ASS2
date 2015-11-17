#ifndef JSONParsing_H
#define JSONParsing_H

#include <vector>
#include "json.h"
#include <fstream>
#include <iostream>
#include <string>
#include "ItemPrototype.h"

using namespace std;

//!Serialized and store object at runtime in a file called ItemsJSON.txt.
void JsonSave (vector<Item*> l);
//!Load the objects previously created from a file called ItemsJSON.txt.
void JsonLoad(vector<Item*> &l);

#endif