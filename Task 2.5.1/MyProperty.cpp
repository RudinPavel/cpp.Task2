#include "MyProperty.h"
#include <string>
#include <iostream>
using namespace std;

MyProperty::MyProperty(string name)
{
	this->name = name;
}

MyProperty::~MyProperty()
{
}

string MyProperty::get_name()
{
	return name;
}

void MyProperty::set_name(string name)
{
	this->name = name;
}

void MyProperty::print()
{
	cout << "Свойство " << name << endl;
}

void MyProperty::add(string name)
{
}

void MyProperty::add(string name, int i)
{
}

void MyProperty::remove(int index)
{
}

void MyProperty::change(Element* e, string name)
{
}

bool MyProperty::not_exist(string name)
{
	return false;
}

Element* MyProperty::find_element_by_name(string name)
{
	return nullptr;
}

int MyProperty::find_element_index_by_name(string name)
{
	return 0;
}
