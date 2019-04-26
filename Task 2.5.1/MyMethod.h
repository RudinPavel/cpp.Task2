#pragma once
#include "Element.h"
#include <string>
using namespace std;

class MyMethod : public Element
{
public:
	MyMethod(string name);
	~MyMethod();
	string get_name();
	void set_name(string name);
private:
	string name;
};
