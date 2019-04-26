#include "MyMethod.h"
#include <string>
#include <iostream>
using namespace std;


MyMethod::MyMethod(string name)
{
	this->name = name;
}

MyMethod::~MyMethod()
{
}

string MyMethod::get_name()
{
	return name;
}

void MyMethod::set_name(string name)
{
	this->name = name;
}

void MyMethod::print()
{
	cout << "Метод " << name << endl;
}

void MyMethod::add(string name)
{
}

void MyMethod::add(string name, int i)
{
}

void MyMethod::remove(int index)
{
}

void MyMethod::change(Element* e, string name)
{
}

bool MyMethod::not_exist(string name)
{
	return false;
}

Element* MyMethod::find_element_by_name(string name)
{
	return nullptr;
}

int MyMethod::find_element_index_by_name(string name)
{
	return 0;
}
