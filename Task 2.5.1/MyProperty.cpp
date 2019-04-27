#include "MyProperty.h"
#include <string>
#include <iostream>
using namespace std;

MyProperty::MyProperty(string name, string value)
{
	this->name = name;
	this->value = value;
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
	cout << "get {" << value <<" "<<name << "}; set {"<< value << " " << name << "};" << endl;
}

void MyProperty::set_value(string value)
{
	this->value = value;
}

string MyProperty::get_value()
{
	return value;
}

void MyProperty::add(string name)
{
}

void MyProperty::add(string name, MyClassMemberType t, string value)
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
