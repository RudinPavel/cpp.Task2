#pragma once
#include "Element.h"
#include <string>
using namespace std;

class MyField : public Element
{
public:
	MyField(string name);
	~MyField();
	string get_name();
	void set_name(string name);
	void print_all();
private:
	string name;
};

