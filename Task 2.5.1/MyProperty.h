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
	void print();

	void add(string name);

	void add(string name, int i);

	void remove(int index);

	void change(Element* e, string name);

	bool not_exist(string name);

	Element* find_element_by_name(string name);

	int find_element_index_by_name(string name);
private:
	string name;
};
