#include "MyNamespace.h"

#include <string>
using namespace std;

class MyNamespace1 //: Container
{
public:
	string name = "";
	vector<MyClass*> classes;

	MyNamespace(string name)
	{
		this->name = name;  // -> ��� ���������� *.
	}

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

MyNamespace::MyNamespace()
{
}


MyNamespace::~MyNamespace()
{
}
