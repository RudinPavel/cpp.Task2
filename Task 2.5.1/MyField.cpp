#include "MyField.h"
#include <string>
#include <iostream>
using namespace std;

MyField::MyField(string name, string value)
{
	this->name = name;
	this->value = value;
}

MyField::~MyField()
{
}

string MyField::get_name()
{
	return name;
}

void MyField::set_name(string name)
{
	this->name = name;
}

void MyField::print()
{
	cout << value << " " << name << ";"<< endl;
}

void MyField::set_value(string value)
{
	this->value = value;
}

string MyField::get_value()
{
	return value;
}

void MyField::add(string name)
{
}

void MyField::add(string name, MyClassMemberType t, string value)
{
}


void MyField::remove(int index)
{
}

void MyField::change(Element* e, string name)
{
}

bool MyField::not_exist(string name)
{
	return false;
}

Element* MyField::find_element_by_name(string name)
{
	return nullptr;
}

int MyField::find_element_index_by_name(string name)
{
	return 0;
}
