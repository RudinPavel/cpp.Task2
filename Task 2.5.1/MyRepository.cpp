#include "MyRepository.h"
#include <string>
using namespace std;

class MyRepository1 //: Container
{
public:
	string name = "";
	vector<MyNamespace*> namespaces;

	MyRepository(string name)
	{
		if (check_name(name))
		{
			this->name = name;
			cout << "������� ������ ����������� � ������ " << name << endl;
		}
	}

	void add(MyNamespace* m) // ��������� � ���� ��������� �� ��������� ������ MyClass
	{
		if (exist(m) && check_name(m->name))
		{
			namespaces.push_back(m);
			cout << "������������ ��� " << m->name << " ���� ������� ��������� � ����������� " << name << endl;
			cout << endl;
		}
	}

	void change(string name)
	{
		if (exist(name))
			return;
		this->name = name;
		cout << "������� ��������� ����� ���" << endl;
	}

	MyNamespace* findNamespaceByName(string name)
	{
		int size = static_cast<int>(namespaces.size());
		for (int i = 0; i < size; i++)
		{
			if (namespaces[i]->name == name)
			{
				return namespaces[i];
			}
		}
		return NULL;
	}

	int findIndexByName(string name)
	{
		int size = static_cast<int>(namespaces.size());
		for (int i = 0; i < size; i++)
		{
			if (namespaces[i]->name == name)
			{
				return i;
			}
		}
		return -1;
	}

	void deleteNamespace(string name)
	{
		int position = findIndexByName(name);

		if (position != -1)
		{
			MyNamespace* n = findNamespaceByName(name);
			namespaces.erase(namespaces.begin() + position);
			delete n;
			cout << "������� ������������ ��� � ������ " << name << endl;
			return;
		}
		cout << "�� ������� ������� ������������ ��� � ������ " << name << endl;
	}

	bool exist(MyNamespace * m)  // ���������� �������
	{
		int size = static_cast<int>(namespaces.size()); // ������ ������ ������ size()
		for (int i = 0; i < size; i++)
		{
			if (namespaces[i]->name == m->name)
			{
				cout << "������������ ��� " << m->name << " ��� ���������� � ����������� " << name << endl;
				cout << endl;
				return true;
			}
		}
		return false;
	}

	bool exist(string name) // ���������� �������
	{
		int size = static_cast<int>(namespaces.size()); // ������ ������ ������ size()
		for (int i = 0; i < size; i++)
		{
			if (namespaces[i]->name == name)
			{
				cout << "������������ ��� " << name << " ��� ���������� � ����������� " << endl;
				cout << endl;
				return true;
			}
		}
		return false;
	}

	void printer()
	{
		string result;
		int size = static_cast<int>(namespaces.size()); // ������ ������ ������ size()
		if (size == 0)
		{
			cout << "� ����������� ��� ��� �� ������ ������������ ���." << endl;
			return;
		}
		cout << "��������� ������������ ���" << endl;
		for (int i = 0; i < size; i++)
		{
			result += to_string(i + 1) + ". ";
			result += namespaces[i]->name + "\n\r";
		}
		cout << result << endl;;
	}
};

MyRepository::MyRepository(string name)
{
}


MyRepository::~MyRepository()
{
}
