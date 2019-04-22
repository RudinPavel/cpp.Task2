#include "MyClass.h"

#include <vector>
#include <string>
#include <iostream>
#include "MyField.h"
#include "MyProperty.h"
#include "MyMethod.h"
#include "MyUtils.h"

using namespace std;

MyClass::MyClass(string name)
{
	this->name = name;
}

MyClass::~MyClass()
{
	cout << "������� ������� �����" << endl;
}

void MyClass::add(MyField* myField)
{
	if (!existField(myField->get_name()) && MyUtils::check_valid_name(myField->get_name()))
	{
		myFields.push_back(myField);
		cout << "���� " << myField->get_name() << " ���� ������� ��������� � ����� " << name << endl;
		cout << endl;
	}
}

void MyClass::add(MyProperty* myProperty)
{
	if (!existField(myProperty->get_name()) && MyUtils::check_valid_name(myProperty->get_name()))
	{
		myProperties.push_back(myProperty);
		cout << "�������� " << myProperty->get_name() << " ���� ������� ��������� � ����� " << name << endl;
		cout << endl;
	}
}

void MyClass::add(MyMethod* myMethod)
{
	if (!existField(myMethod->get_name()) && MyUtils::check_valid_name(myMethod->get_name()))
	{
		myMethods.push_back(myMethod);
		cout << "����� " << myMethod->get_name() << " ��� ������� �������� � ����� " << name << endl;
		cout << endl;
	}
}

void MyClass::deleteField(string name)
{
	int position = findPropertyIndexByName(name);

	if (position != -1)
	{
		MyField* n = findFieldByName(name);
		this->myFields.erase(this->myFields.begin() + position);
		delete n;
		cout << "������� ���� � ������ " << name << endl;
		return;
	}
	cout << "�� ������� ������� ���� � ������ " << name << endl;
}

void MyClass::deleteProperty(string name)
{
	int position = findPropertyIndexByName(name);

	if (position != -1)
	{
		MyProperty* n = findPropertyByName(name);
		this->myProperties.erase(this->myProperties.begin() + position);
		delete n;
		cout << "������� �������� � ������ " << name << endl;
		return;
	}
	cout << "�� ������� ������� �������� � ������ " << name << endl;
}

void MyClass::deleteMethod(string name)
{
	int position = findMethodIndexByName(name);

	if (position != -1)
	{
		MyMethod* n = findMethodByName(name);
		this->myMethods.erase(this->myMethods.begin() + position);
		delete n;
		cout << "������� ����� � ������ " << name << endl;
		return;
	}
	cout << "�� ������� ������� ����� � ������ " << name << endl;
}

int MyClass::findFieldIndexByName(string name)
{
	int size = static_cast<int>(myFields.size());
	for (int i = 0; i < size; i++)
	{
		if (myFields[i]->get_name() == name)
		{
			return i;
		}
	}
	return -1;
}

MyField* MyClass::findFieldByName(string name)
{
	int size = static_cast<int>(myFields.size());
	for (int i = 0; i < size; i++)
	{
		if (myFields[i]->get_name() == name)
		{
			return myFields[i];
		}
	}
	return NULL;
}

int MyClass::findPropertyIndexByName(string name)
{
	int size = static_cast<int>(myProperties.size());
	for (int i = 0; i < size; i++)
	{
		if (myProperties[i]->get_name() == name)
		{
			return i;
		}
	}
	return -1;
}

MyProperty* MyClass::findPropertyByName(string name)
{
	int size = static_cast<int>(myProperties.size());
	for (int i = 0; i < size; i++)
	{
		if (myProperties[i]->get_name() == name)
		{
			return myProperties[i];
		}
	}
	return NULL;
}

int MyClass::findMethodIndexByName(string name)
{
	int size = static_cast<int>(myMethods.size());
	for (int i = 0; i < size; i++)
	{
		if (myMethods[i]->get_name() == name)
		{
			return i;
		}
	}
	return -1;
}

MyMethod* MyClass::findMethodByName(string name)
{
	int size = static_cast<int>(myMethods.size());
	for (int i = 0; i < size; i++)
	{
		if (myMethods[i]->get_name() == name)
		{
			return myMethods[i];
		}
	}
	return NULL;
}

bool MyClass::existField(MyField* m)
{
	int size = static_cast<int>(myFields.size()); // ������ ������ ������ size()
	for (int i = 0; i < size; i++)
	{
		if (myFields[i]->get_name() == m->get_name())
		{
			cout << "���� " << name << " ��� ���������� � ������ " << this->name << endl;
			cout << endl;
			return true;
		}
	}
	return false;
}

bool MyClass::existField(string name)
{
	int size = static_cast<int>(myFields.size()); // ������ ������ ������ size()
	for (int i = 0; i < size; i++)
	{
		if (myFields[i]->get_name() == name)
		{
			cout << "���� " << name << " ��� ���������� � ������ " << this->name << endl;
			cout << endl;
			return true;
		}
	}
	return false;
}

bool MyClass::existProperty(MyProperty* m)
{
	int size = static_cast<int>(myProperties.size()); // ������ ������ ������ size()
	for (int i = 0; i < size; i++)
	{
		if (myProperties[i]->get_name() == m->get_name())
		{
			cout << "�������� " << name << " ��� ���������� � ������ " << this->name << endl;
			cout << endl;
			return true;
		}
	}
	return false;
}

bool MyClass::existProperty(string name)
{
	int size = static_cast<int>(myProperties.size()); // ������ ������ ������ size()
	for (int i = 0; i < size; i++)
	{
		if (myProperties[i]->get_name() == name)
		{
			cout << "�������� " << name << " ��� ���������� � ������ " << this->name << endl;
			cout << endl;
			return true;
		}
	}
	return false;
}

bool MyClass::existMethod(MyMethod* m)
{
	int size = static_cast<int>(myMethods.size()); // ������ ������ ������ size()
	for (int i = 0; i < size; i++)
	{
		if (myMethods[i]->get_name() == m->get_name())
		{
			cout << "����� " << name << " ��� ��������� � ������ " << this->name << endl;
			cout << endl;
			return true;
		}
	}
	return false;
}

bool MyClass::existMethod(string name)
{
	int size = static_cast<int>(myMethods.size()); // ������ ������ ������ size()
	for (int i = 0; i < size; i++)
	{
		if (myMethods[i]->get_name() == name)
		{
			cout << "����� " << name << " ��� ��������� � ������ " << this->name << endl;
			cout << endl;
			return true;
		}
	}
	return false;
}

void MyClass::printFields()
{
	string result;
	int size = static_cast<int>(myFields.size()); // ������ ������ ������ size()
	if (size == 0)
	{
		cout << "� ������ ��� ��� �� ������ ����." << endl;
		return;
	}
	cout << "��������� ����" << endl;
	for (int i = 0; i < size; i++)
	{
		result += to_string(i + 1) + ". ";
		result += myFields[i]->get_name() + "\n\r";
	}
	cout << result << endl;
}

void MyClass::printProperties()
{
	string result;
	int size = static_cast<int>(myProperties.size()); // ������ ������ ������ size()
	if (size == 0)
	{
		cout << "� ������ ��� ��� �� ������ ��������." << endl;
		return;
	}
	cout << "��������� ��������" << endl;
	for (int i = 0; i < size; i++)
	{
		result += to_string(i + 1) + ". ";
		result += myProperties[i]->get_name() + "\n\r";
	}
	cout << result << endl;
}

void MyClass::printMethods()
{
	string result;
	int size = static_cast<int>(myMethods.size()); // ������ ������ ������ size()
	if (size == 0)
	{
		cout << "� ������ ��� ��� �� ������ ������." << endl;
		return;
	}
	cout << "��������� ������" << endl;
	for (int i = 0; i < size; i++)
	{
		result += to_string(i + 1) + ". ";
		result += myMethods[i]->get_name() + "\n\r";
	}
	cout << result << endl;
}

void MyClass::changeField(string name, MyField* m)
{
	if (existField(name))
		return;
	m->set_name(name);
	cout << "������� ��������� ����� ��� ����" << endl;
}

void MyClass::changeProperty(string name, MyProperty* m)
{
	if (existProperty(name))
		return;
	m->set_name(name);
	cout << "������� ��������� ����� ��� ��������" << endl;
}

void MyClass::changeMethod(string name, MyMethod* m)
{
	if (existMethod(name))
		return;
	m->set_name(name);
	cout << "������� ��������� ����� ��� ������" << endl;
}

string MyClass::get_name()
{
	return name;
}

void MyClass::set_name(string name)
{
	this->name = name;
}
