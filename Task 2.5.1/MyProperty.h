#pragma once

#include "Element.h"

#include <string>
using namespace std;

class MyProperty : public Element
{
public:
	MyProperty(string name);
	~MyProperty();
	string get_name();
	void set_name(string name);
private:
	string name;
};
