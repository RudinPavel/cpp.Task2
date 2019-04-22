#include "MyClass.h"

class MyClass1 : Container
{
public:
	string name = "";

	vector<MyField*> fields;
	vector<MyProperty*> properties;
	vector<MyMethod*> methods;

	void add() override {}
	bool check() override { return true; }
	void remove() override {}
	void update() override {}

	MyClass(string name)
	{
		this->name = name;
	}

	void add(MyField* m)
	{
		if (checkExistance(m) && (check_name(m->name)))
		{
			fields.push_back(m);
			cout << "���� " << m->name << " ���� ������� ��������� � ����� " << name << endl;
			cout << endl;
		}
	}

	void add(MyProperty* m)
	{
		if (checkExistance(m) && (check_name(m->name)))
		{
			properties.push_back(m);
			cout << "�������� " << m->name << " ��� ������� ��������� � ����� " << name << endl;
			cout << endl;
		}
	}

	void add(MyMethod* m) // ��������� � ���� ��������� �� ��������� ������ MyClass
	{
		if (checkExistance(m) && (check_name(m->name)))
		{
			methods.push_back(m);
			cout << "����� " << m->name << " ��� ������� �������� � ����� " << name << endl;
			cout << endl;
		}
	}

	bool checkExistance(MyField* m)
	{
		int size = static_cast<int>(fields.size()); // ������ ������ ������ size()
		for (int i = 0; i < size; i++)
		{
			if (fields[i]->name == m->name)
			{
				cout << "���� " << m->name << " ��� ���������� � ������ " << name << endl;
				cout << endl;
				return false;
			}
		}
		return true;
	}

	bool checkExistance(MyProperty* m)
	{
		int size = static_cast<int>(properties.size()); // ������ ������ ������ size()
		for (int i = 0; i < size; i++)
		{
			if (properties[i]->name == m->name)
			{
				cout << "�������� " << m->name << " ��� ���������� � ������ " << name << endl;
				cout << endl;
				return false;
			}
		}
		return true;
	}

	bool checkExistance(MyMethod* m)
	{
		int size = static_cast<int>(methods.size()); // ������ ������ ������ size()
		for (int i = 0; i < size; i++)
		{
			if (methods[i]->name == m->name)
			{
				cout << "����� " << m->name << " ��� ��������� � ������ " << name << endl;
				cout << endl;
				return false;
			}
		}
		return true;
	}

	void printer()
	{
		cout << "����, �������� � ������ " << endl;
	}
};

MyClass::MyClass()
{
}


MyClass::~MyClass()
{
}
