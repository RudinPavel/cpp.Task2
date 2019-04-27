#pragma once

#include "Element.h"

#include <string>
using namespace std;

class MyProperty : public Element
{
public:
	MyProperty(string name, string value);
	~MyProperty();
	string get_name();
	void set_name(string name);
	void print();

	void set_value(string value);

	string get_value();

	void add(string name);

	void add(string name, MyClassMemberType t, string value);

	void remove(int index);

	void change(Element* e, string name);

	bool not_exist(string name);

	Element* find_element_by_name(string name);

	int find_element_index_by_name(string name);
private:
	string name;
	string value;
};
