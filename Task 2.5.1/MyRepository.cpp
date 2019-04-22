#include "MyRepository.h"
#include "MyNamespace.h"
#include <string>
#include <iostream>
#include "MyUtils.h"
using namespace std;

MyRepository::MyRepository(string name)
{
	if (MyUtils::check_valid_name(name))
	{
		this->name = name;
		cout << "������� ������ ����������� � ������ " << name << endl;
	}
}


MyRepository::~MyRepository()
{
	cout << "������� ����� ����������� � ������ " << name << endl; 
}


void MyRepository::add(MyNamespace* myNamespace)
{
	if (!exist(myNamespace->get_name()) && MyUtils::check_valid_name(myNamespace->get_name()))
	{
		myNamespaces.push_back(myNamespace);
		cout << "������������ ��� " << myNamespace->get_name() << " ���� ������� ��������� � ����������� " << name << endl;
		cout << endl;
	}
}

void MyRepository::deleteNamespace(string name)
{
	int position = findIndexByName(name);

	if (position != -1)
	{
		MyNamespace* n = findNamespaceByName(name);
		this->myNamespaces.erase(this->myNamespaces.begin() + position);
		delete n;
		cout << "������� ������������ ��� � ������ " << name << endl;
		return;
	}
	cout << "�� ������� ������� ������������ ��� � ������ " << name << endl;
}

int MyRepository::findIndexByName(string name)
{
	int size = static_cast<int>(myNamespaces.size());
	for (int i = 0; i < size; i++)
	{
		if (myNamespaces[i]->get_name() == name)
		{
			return i;
		}
	}
	return -1;
}

MyNamespace* MyRepository::findNamespaceByName(string name)
{
	int size = static_cast<int>(myNamespaces.size());
	for (int i = 0; i < size; i++)
	{
		if (myNamespaces[i]->get_name() == name)
		{
			return myNamespaces[i];
		}
	}
	return NULL;
}


bool MyRepository::exist(MyNamespace* m)  // ���������� �������
{
	int size = static_cast<int>(myNamespaces.size()); // ������ ������ ������ size()
	for (int i = 0; i < size; i++)
	{
		if (myNamespaces[i]->get_name() == m->get_name())
		{
			cout << "������������ ��� " << m->get_name() << " ��� ���������� � ����������� " << name << endl;
			cout << endl;
			return true;
		}
	}
	return false;
}

void MyRepository::change(string name)
{
	if (exist(name))
		return;
	this->name = name;
	cout << "������� ��������� ����� ���" << endl;
}

string MyRepository::get_name()
{
	return name;
}

void MyRepository::set_name(string name)
{
	this->name = name;
}

int addd() { return 1; }

void MyRepository::printer()
{
	string result;
	int size = static_cast<int>(myNamespaces.size()); // ������ ������ ������ size()
	if (size == 0)
	{
		cout << "� ����������� ��� ��� �� ������ ������������ ���." << endl;
		return;
	}
	cout << "��������� ������������ ���" << endl;
	for (int i = 0; i < size; i++)
	{
		result += to_string(i + 1) + ". ";
		result += myNamespaces[i]->get_name() + "\n\r";
	}
	cout << result << endl;
}



bool MyRepository::exist(string name)
{
	int size = static_cast<int>(myNamespaces.size()); // ������ ������ ������ size()
	for (int i = 0; i < size; i++)
	{
		if (myNamespaces[i]->get_name() == name)
		{
			cout << "������������ ��� " << name << " ��� ���������� � ����������� " << endl;
			cout << endl;
			return true;
		}
	}
	return false;
}

