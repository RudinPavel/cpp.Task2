#include "MyField.h"
#include <string>
#include <iostream>
using namespace std;

MyField::MyField(string name)
{
	this->name = name;
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
	cout << "Поле " << name << endl;
}

void MyField::add(string name)
{
}

void MyField::add(string name, int i)
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
