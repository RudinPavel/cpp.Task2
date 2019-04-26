#include "MyRepository.h"

#include <string>
#include <iostream>
#include "MyNamespace.h"
#include "MyUtils.h"

using namespace std;

void MyRepository::print()
{
	cout << "Репозиторий " << name << endl;
	cout << "{" << endl;
	for each (Element * e in elements)
	{
		e->print();
	}
	cout << "};" << endl;
	cout << endl;
}

void MyRepository::add(string name)
{
	Element* e = new MyNamespace(name);
	elements.push_back(e);
	cout << "Успешно добавили пространство имён "<< name << endl;
	cout << endl;
}

void MyRepository::add(string name, int i)
{
}

void MyRepository::remove(int index)
{
	Element* d = elements.at(index);
	elements.erase(this->elements.begin() + index);
	delete d;
	cout << "Удалили пространство имён" << endl;
	cout << endl;
}

void MyRepository::change(Element* e, string name)
{
	e->set_name(name);
}

void MyRepository::set_name(string name)
{
	this->name = name;
}

string MyRepository::get_name()
{
	return name;
}

bool MyRepository::not_exist(string name)
{
	for each (Element * e in elements)
	{
		if (e->get_name() == name)
			return false;
	}
	return true;
}

Element* MyRepository::find_element_by_name(string name)
{
	for each (Element * e in elements)
	{
		if (e->get_name() == name)
			return e;
	}
	return NULL; //nullptr
}

int MyRepository::find_element_index_by_name(string name)
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

MyRepository::MyRepository(string name)
{
	this->name = name;
}

MyRepository::~MyRepository()
{
	for each (Element * e in elements)
	{
		delete e;
	}
	cout << "Репозиторий удалён" << endl;
}