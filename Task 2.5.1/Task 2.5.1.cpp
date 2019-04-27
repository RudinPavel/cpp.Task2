// Task 2.5.1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include <iostream>
#include <vector>
#include <string>

#include "MyUtils.h"
#include "MyRepository.h"
#include "MyNamespace.h"
#include "MyClass.h"
#include "MyField.h"
#include "MyProperty.h"
#include "MyMethod.h"

using namespace std;

void concrete_class_menu(Element* e)
{
	int x = 0;
	bool answer = true;
	string helper = "";
	string value = "";
	Element* h;
	MyUtils* u = new MyUtils();

	while (answer)
	{
		cout << endl;
		cout << "����� " << e->get_name() << endl;
		cout << "1. ���������� ����������" << endl;
		cout << "2. ������� ����" << endl;
		cout << "3. ������� ��������" << endl;
		cout << "4. ������� �����" << endl;
		cout << "5. �������� ��������" << endl;
		cout << "6. ������� ��������" << endl;
		cout << "0. ��������� � ���� ������������ ���" << endl;
		cout << endl;

		cin >> x;

		switch (x)
		{
		case 1:
			e->print();
			break;
		case 2:
			cout << "�������� ��� ���� ��� ���������� � �����" << endl;
			cin >> helper;
			cout << "�������� ��� ���� ��� ���������� � �����" << endl;
			cin >> value;
			if (u->check_valid_name(helper) && e->not_exist(helper))
			{
				e->add(helper, Field, value);
			}
			else
			{
				cout << "�� ������� �������� ���� ����� " << helper << endl;
				cout << endl;
			}
			break;
		case 3:
			cout << "�������� ��� �������� ��� ���������� � �����" << endl;
			cin >> helper;
			cout << "�������� ��� �������� ��� ���������� � �����" << endl;
			cin >> value;
			if (u->check_valid_name(helper) && e->not_exist(helper))
			{
				e->add(helper, Property, value);
			}
			else
			{
				cout << "�� ������� �������� �������� � ����� " << helper << endl;
				cout << endl;
			}
			break;
		case 4:
			cout << "�������� ��� ������ ��� ���������� � �����" << endl;
			cin >> helper;
			cout << "�������� ��� ������������� �������� ��� ���������� � �����" << endl;
			cin >> value;
			if (u->check_valid_name(helper) && e->not_exist(helper))
			{
				e->add(helper, Method, value);
			}
			else
			{
				cout << "�� ������� �������� ����� � �����" << helper << endl;
				cout << endl;
			}
			break;
		case 5:
			e->print();
			cout << "�������� ��� �������� ��� ���������" << endl;
			cin >> helper;
			h = e->find_element_by_name(helper);
			if (h != NULL)
			{
				cout << "������� ����� ��� ��������" << endl;
				cin >> helper;
				e->change(h, helper);
			}
			else
			{
				cout << "�� ������� �������� ��� ��������" << endl;
				cout << endl;
			}
			break;
		case 6:
			e->print();
			cout << "�������� ��� �������� ��� ��������" << endl;
			cin >> helper;
			if (e->find_element_index_by_name(helper) != -1)
			{
				e->remove(e->find_element_index_by_name(helper));
			}
			else
			{
				cout << "�� ������� ������� �������� " << helper << endl;
				cout << endl;
			}
			break;
			break;
		case 0:
			answer = false;
			break;
		default:
			cout << "��� ������ �������� � ������� ����������� ������" << endl;
			break;
		}
	}
}

void concrete_namespace_menu(Element* e)
{
	int x = 0;
	string current;
	bool answer = true;
	string helper = "";
	Element* h;
	MyUtils* u = new MyUtils();

	while (answer)
	{
		cout << endl;
		cout << "������������ ��� " << e->get_name() << endl;
		cout << "1. ���������� ����������" << endl;
		cout << "2. ������� � �����" << endl;
		cout << "3. ������� �����" << endl;
		cout << "4. �������� �����" << endl;
		cout << "5. ������� �����" << endl;
		cout << "0. ��������� � ���� ����������� ���" << endl;
		cout << endl;

		cin >> x;

		switch (x)
		{
		case 1:
			e->print();
			break;
		case 2:
			e->print();
			cout << "�������� ��� ������, � ������� ������ �����" << endl;
			cin >> helper;
			h = e->find_element_by_name(helper);
			if (h != NULL)
			{
				cout << "��������� � ����� � ������ " << helper << endl;
				concrete_class_menu(h);
			}
			else
			{
				cout << "�� ������� ����� � ����� � ������ " << helper << endl;
				cout << endl;
			}
			break;
		case 3:
			cout << "�������� ��� ������ ��� ����������" << endl;
			cin >> helper;
			if (u->check_valid_name(helper) && e->not_exist(helper))
			{
				e->add(helper);
			}
			else
			{
				cout << "�� ������� �������� ����� " << helper << endl;
				cout << endl;
			}
			break;
		case 4:
			e->print();
			cout << "�������� ��� ������ ��� ���������" << endl;
			cin >> helper;
			h = e->find_element_by_name(helper);
			if (h != NULL)
			{
				cout << "������� ����� ��� ��� ������" << endl;
				cin >> helper;
				e->change(h, helper);
			}
			else
			{
				cout << "�� ������� �������� ��� ������" << endl;
				cout << endl;
			}
			break;
		case 5:
			e->print();
			cout << "�������� ��� ������ ��� �������� �� ������������ ���" << endl;
			cin >> helper;
			if (e->find_element_index_by_name(helper) != -1)
			{
				e->remove(e->find_element_index_by_name(helper));
			}
			else
			{
				cout << "�� ������� ������� ����� " << helper << endl;
				cout << endl;
			}
			break;
		case 0:
			answer = false;
			break;
		default:
			cout << "��� ������ �������� � ������� ����������� ������������ ���" << endl;
			break;
		}
	}
}

void namespaces_menu(Element* e)
{
	int x = 0;
	bool answer = true;
	string helper = "";
	Element *h;
	MyUtils* u = new MyUtils();

	while (answer)
	{
		cout << "������������ ��� ����������� " << e->get_name() << endl;
		cout << "1. ���������� ���������� �����������" << endl;
		cout << "2. ������� � ������������ ���" << endl;
		cout << "3. ������� ������������ ���" << endl;
		cout << "4. �������� ������������ ���" << endl;
		cout << "5. ������� ������������ ���" << endl;
		cout << "0. ��������� � ������� ����" << endl;
		cout << endl;

		cin >> x;

		switch (x)
		{
		case 1:
			e->print();
			break;
		case 2:
			e->print();
			cout << "�������� ��� ������������ ���, � ������� ������ �����" << endl;
			cin >> helper;
			h = e->find_element_by_name(helper);
			if (h != NULL) 
			{
				cout << "��������� � ������������ ��� � ������ " << helper << endl;
				concrete_namespace_menu(h);
			}
			else
			{
				cout << "�� ������� ����� � ������������ ��� � ������ " << helper << endl;
				cout << endl;
			}
			break;
		case 3:
			cout << "�������� ��� ������������ ��� ��� ���������� � �����������" << endl;
			cin >> helper;  
			if (u->check_valid_name(helper) && e->not_exist(helper))
			{
				e->add(helper);
			}
			else
			{
				cout << "�� ������� �������� ������������ ��� " << helper << endl;
				cout << endl;
			}
			break;
		case 4:
			e->print();
			cout << "�������� ��� ������������ ��� ��� ���������" << endl;
			cin >> helper;
			h = e->find_element_by_name(helper);
			if (h != NULL)
			{
				cout << "������� ����� ��� ��� ������������ ���" << endl;
				cin >> helper;
				e->change(h, helper);
			}
			else
			{
				cout << "�� ������� �������� ������������ ���" << endl;
				cout << endl;
			}
			break;
		case 5:
			e->print();
			cout << "�������� ��� ������������ ��� ��� ��������" << endl;
			cin >> helper;
			if (e->find_element_index_by_name(helper) != -1)
			{
				e->remove(e->find_element_index_by_name(helper));
			}
			else
			{
				cout << "�� ������� ������� ������������ ��� " << helper << endl;
				cout << endl;
			}
			break;
		case 0:
			answer = false;
			break;
		default:
			cout << "��� ������ �������� � ������� ����������� ���" << endl;
			break;
		}
	}
}

void main_menu(Element* e)
{
	int x = 0;
	bool answer = true;

	while (answer)
	{
		cout << endl;
		cout << "������� ���� ����������� " << e->get_name() << endl;
		cout << "1. ������� � ������������ ���" << endl;
		cout << "0. ����� �� ���������" << endl;
		cout << endl;

		cin >> x;

		switch (x)
		{
		case 1:
			namespaces_menu(e);
			break;
		case 0:
			cout << "��������� ������ � ����������" << endl;
			answer = false;
			break;
		default:
			cout << "��� ������ �������� � ������� ����" << endl;
			break;
		}
	}
}
	
int main()
{
	setlocale(LC_ALL, "Russian"); // ��������� ����������� ��� ����������� ����������� ������� ��������

	Element* test = new MyRepository("Test");  // �������� ������ �����������
	
	main_menu(test); // ����� ��������� ���� ����������

	cin.ignore(); 
	cin.ignore(); // ��� �������� �������
	delete test;
}
	

/*
	MyRepository *r = new MyRepository("TestRepository");
	MyNamespace *n = new MyNamespace("TestNamespace");
	MyClass *c = new MyClass("TestClass");
	*/

	/*
	n->add(c);
	n->add(c);
	r->add(n);
	r->add(n);
	*/

	/*
	check_name("hello");
	check_name("h allo");
	check_name("hall o");
	check_name(" hallo");
	


if (myRepository == nullptr)
{
	cout << "no way" << endl;
	return;
}

class Container
{
public:
	virtual void add() = 0;
	virtual bool check() = 0;
	virtual void remove() = 0;
	virtual void update() = 0;
};



//bool check_valid_name(string name); // ������ ���������� ����������

/*
5. �������� �������. ���������� ������� ������ ��� �������� ��������� ����� C#:
����������� ����, �������, �����, ������� � ������� ������� � �.�.
������ ����������� ������������� ����, � ���� ������� ������ ������������ ���� ����� ������
����� �������.
������������� �������� ���������� ���� ������� ������� (� ������� �������� � ����������).
������ ����� ������������� ���� �� �����.
��� ������� ���������� ������������� �������� �������� ������������ ������
(��������, ���� ����� ����������� �� ������������ ������, �� �� ������ ����������� ���
����������� ������ � �������� � �.�.).
��������� ������ ������ ������������ ����� ��������� �� ������.
����� �������� ����� �������/��������/�������.
*/