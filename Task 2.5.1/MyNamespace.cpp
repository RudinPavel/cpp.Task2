#include "MyNamespace.h"

#include <string>
#include <vector>
#include <iostream>
#include "MyUtils.h"

using namespace std;

void MyNamespace::print()
{
	cout << "namespace " << name << endl;
	cout << "    ";
	cout << "{" << endl;
	for each (Element * e in elements)
	{
		cout << "	";
		e->print();
	}
	cout << "    ";
	cout << "}" << endl;
	cout << endl;
}

void MyNamespace::add(string name)
{
	Element* e = new MyClass(name);
	elements.push_back(e);
	cout << "������� �������� �����" << endl;
}

void MyNamespace::add(string name, MyClassMemberType t, string value)
{
}

void MyNamespace::remove(int index)
{
	Element* d = elements.at(index);
	elements.erase(this->elements.begin() + index);
	delete d;
	cout << "������� �����" << endl;
}

void MyNamespace::change(Element * e, string name)
{
	e->set_name(name);
}

void MyNamespace::set_name(string name)
{
	this->name = name;
}

string MyNamespace::get_name()
{
	return name;
}

bool MyNamespace::not_exist(string name)
{
	for each (Element * e in elements)
	{
		if (e->get_name() == name)
			return false;
	}
	return true;
}

Element* MyNamespace::find_element_by_name(string name)
{
	for each (Element * e in elements)
	{
		if (e->get_name() == name)
			return e;
	}
	return NULL; //nullptr
}

int MyNamespace::find_element_index_by_name(string name)
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

MyNamespace::MyNamespace(string name)
{
	this->name = name;
}

MyNamespace::~MyNamespace()
{
	for each (Element * e in elements)
	{
		delete e;
	}
}

void MyNamespace::set_value(string value)
{
}

string MyNamespace::get_value()
{
	return string();
}







/*
MyNamespace::MyNamespace(string name)
{
	if (MyUtils::check_valid_name(name))
	{
		this->name = name;
		cout << "������� ������� ������������ ���� � ������ " << name << endl;
	}
}

MyNamespace::~MyNamespace()
{
	cout << "������� ������� ������������ ���" << endl;
}

void MyNamespace::print()
{
}

void MyNamespace::add(Element* e)
{
}

void MyNamespace::remove(Element* e)
{
}

void MyNamespace::change(Element* e, string name)
{
}

Element* MyNamespace::find_element_by_name(string name)
{
	return nullptr;
}

void MyNamespace::add(MyClass* myClass)
{
	if (!exist(myClass->get_name()) && MyUtils::check_valid_name(myClass->get_name()))
	{
		myClasses.push_back(myClass);
		cout << "����� " << myClass->get_name() << " ���� ������� �������� � ������������ ���� " << name << endl;
		cout << endl;
	}
}

void MyNamespace::deleteClass(string name)
{
	int position = findIndexByName(name);

	if (position != -1)
	{
		MyClass* n = findClassByName(name);
		this->myClasses.erase(this->myClasses.begin() + position);
		delete n;
		cout << "������� ����� � ������ " << name << endl;
		return;
	}
	cout << "�� ������� ������� ����� � ������ " << name << endl;
}

int MyNamespace::findIndexByName(string name)
{
	int size = static_cast<int>(myClasses.size());
	for (int i = 0; i < size; i++)
	{
		if (myClasses[i]->get_name() == name)
		{
			return i;
		}
	}
	return -1;
}

MyClass* MyNamespace::findClassByName(string name)
{
	int size = static_cast<int>(myClasses.size());
	for (int i = 0; i < size; i++)
	{
		if (myClasses[i]->get_name() == name)
		{
			return myClasses[i];
		}
	}
	return NULL;
}

bool MyNamespace::exist(MyClass* m)
{
	int size = static_cast<int>(myClasses.size()); // ������ ������ ������ size()
	for (int i = 0; i < size; i++)
	{
		if (myClasses[i]->get_name() == m->get_name())
		{
			cout << "����� " << m->get_name() << " ��� ��������� � ������������ ��� " << name << endl;
			cout << endl;
			return true;
		}
	}
	return false;
}

bool MyNamespace::exist(string name)
{
	int size = static_cast<int>(myClasses.size()); // ������ ������ ������ size()
	for (int i = 0; i < size; i++)
	{
		if (myClasses[i]->get_name() == name)
		{
			cout << "����� " << name << " ��� ��������� � ������������ ��� " << this->name << endl;
			cout << endl;
			return true;
		}
	}
	return false;
}

void MyNamespace::printer()
{
	string result;
	int size = static_cast<int>(myClasses.size()); // ������ ������ ������ size()
	if (size == 0)
	{
		cout << "� ������������ ���� ��� �� ������ ������." << endl;
		return;
	}
	cout << "��������� ������" << endl;
	for (int i = 0; i < size; i++)
	{
		result += to_string(i + 1) + ". ";
		result += myClasses[i]->get_name() + "\n\r";
	}
	cout << result << endl;
}

void MyNamespace::change(string name, MyClass* m)
{
	if (exist(name))
		return;
	m->set_name(name);
	cout << "������� ��������� ����� ���" << endl;
}

string MyNamespace::get_name()
{
	return name;
}

void MyNamespace::set_name(string name)
{
	this->name = name;
}





/*
class MyNamespace1 //: Container
{
public:
	string name = "";
	vector<MyClass*> classes;

	void add(MyClass* m) // ��������� � ���� ��������� �� ��������� ������ MyClass
	{
		if (checkExistance(m) && (check_name(m->name)))
		{
			classes.push_back(m);
			cout << "����� " << m->name << " ��� ������� �������� � ������������ ��� " << name << endl;
			cout << endl;
		}
	}

	MyClass* findClassByName(string name)
	{
		int size = static_cast<int>(classes.size());
		for (int i = 0; i < size; i++)
		{
			if (classes[i]->name == name)
			{
				return classes[i];
			}
		}
		return NULL;
	}

	bool checkExistance(string name) // ���������� �������
	{
		int size = static_cast<int>(classes.size()); // ������ ������ ������ size()
		for (int i = 0; i < size; i++)
		{
			if (classes[i]->name == name)
			{
				cout << "����� " << name << " ��� ��������� � ������������ ���� " << endl;
				cout << endl;
				return false;
			}
		}
		return true;
	}


	bool checkExistance(MyClass* m)
	{
		int size = static_cast<int>(classes.size()); // ������ ������ ������ size()
		for (int i = 0; i < size; i++)
		{
			if (classes[i]->name == m->name)
			{
				cout << "����� " << m->name << " ��� ��������� � ������������ ��� " << name << endl;
				cout << endl;
				return false;
			}
		}
		return true;
	}

	void printer()
	{
		string result;
		int size = static_cast<int>(classes.size()); // ������ ������ ������ size()
		if (size == 0)
		{
			cout << "� ������������ ���� ��� ��� �� ������ ������." << endl;
			return;
		}
		cout << "��������� ������" << endl;
		for (int i = 0; i < size; i++)
		{
			result += to_string(i + 1) + ". ";
			result += classes[i]->name + "\n\r";
		}
		cout << result << endl;;
	}

	int findIndexByName(string name)
	{
		int size = static_cast<int>(classes.size());
		for (int i = 0; i < size; i++)
		{
			if (classes[i]->name == name)
			{
				return i;
			}
		}
		return -1;
	}

	void deleteClass(string name)
	{

		int position = findIndexByName(name);

		if (position != -1)
		{
			MyClass* n = findClassByName(name);
			classes.erase(classes.begin() + position);
			delete n;
			cout << "������� ����� � ������ " << name << endl;
			return;
		}
		cout << "�� ������� ������� ����� � ������ " << name << endl;
	}

};
*/