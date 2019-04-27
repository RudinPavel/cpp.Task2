#include "MyClass.h"

#include <vector>
#include <string>
#include <iostream>
#include "MyField.h"
#include "MyProperty.h"
#include "MyMethod.h"
#include "MyUtils.h"

using namespace std;

void MyClass::print()
{
	cout << "class " << name << endl;
	cout << "	";
	cout << "{" << endl;
	for each (Element * e in elements)
	{
		cout << "	 ";
		e->print();
	}
	cout << "	";
	cout << "}" << endl;
	cout << endl;
}

void MyClass::add(string name, MyClassMemberType t, string value)
{
	Element* e;
	switch (t) 
	{
	case Field:
		e = new MyField(name, value);
		break;
	case Property:
		e = new MyProperty(name, value);
		break;
	case Method:
		e = new MyMethod(name, value);
		break;
	}
	elements.push_back(e);
	cout << "Успешно добавили сущность" << endl;
}

void MyClass::add(string name)
{
}

void MyClass::remove(int index)
{
	Element* d = elements.at(index);
	elements.erase(this->elements.begin() + index);
	delete d;
	cout << "Удалили сущность" << endl;
}

void MyClass::change(Element * e, string name)
{
	e->set_name(name);
}

void MyClass::set_name(string name)
{
	this->name = name;
}

string MyClass::get_name()
{
	return name;
}

bool MyClass::not_exist(string name)
{
	for each (Element * e in elements)
	{
		if (e->get_name() == name)
			return false;
	}
	return true;
}

Element* MyClass::find_element_by_name(string name)
{
	for each (Element * e in elements)
	{
		if (e->get_name() == name)
			return e;
	}
	return NULL; //nullptr
}

int MyClass::find_element_index_by_name(string name)
{
	int size = static_cast<int>(elements.size());
	for (int i = 0; i < size; i++)
	{
		if (elements[i]->get_name() == name)
		{
			return i;
		}
	}
	return -1;
}

MyClass::MyClass(string name)
{
	this->name = name;
}

MyClass::~MyClass()
{
	for each (Element * e in elements)
	{
		delete e;
	}
}

void MyClass::set_value(string name)
{
}

string MyClass::get_value()
{
	return string();
}
