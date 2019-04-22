#include "MyNamespace.h"

#include <string>
#include <vector>
#include <iostream>
#include "MyUtils.h"

using namespace std;

MyNamespace::MyNamespace(string name)
{
	if (MyUtils::check_valid_name(name))
	{
		this->name = name;
		cout << "������� ������ ����������� � ������ " << name << endl;
	}
}

MyNamespace::~MyNamespace()
{
	cout << "������� ������� ������������ ���" << endl;
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

void MyNamespace::change(string name)
{
	if (exist(name))
		return;
	this->name = name;
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