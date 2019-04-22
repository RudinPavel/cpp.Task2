// Task 2.5.1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include <iostream>
#include <vector>
#include <string>

#include "MyRepository.h"
#include "MyNamespace.h"
#include "MyClass.h"
#include "MyField.h"
#include "MyProperty.h"
#include "MyMethod.h"

using namespace std;

void concrete_class_menu(MyClass *myClass)
{
	int x = 0;
	string current;
	bool answer = true;
	string helper = "";
	MyField *myField;
	MyProperty *myProperty;
	MyMethod *myMethod;

	while (answer)
	{
		cout << endl;
		cout << "����� " << myClass->get_name() << endl;
		cout << "1. ���������� ������ �����" << endl;
		cout << "2. ���������� ������ �������" << endl;
		cout << "3. ���������� ������ �������" << endl;
		cout << "4. ������� ����" << endl;
		cout << "5. ������� ��������" << endl;
		cout << "6. ������� �����" << endl;
		cout << "7. �������� ����" << endl;
		cout << "8. �������� ��������" << endl;
		cout << "9. �������� �����" << endl;
		cout << "10. ������� ����" << endl;
		cout << "11. ������� ��������" << endl;
		cout << "12. ������� �����" << endl;
		cout << "0. ��������� � ���� ������������ ���" << endl;
		cout << endl;

		cin >> x;

		switch (x)
		{
		case 1:
			myClass->printFields();
			break;

		case 2:
			myClass->printProperties();
			break;
		case 3:
			myClass->printMethods();
		case 4:
			cout << "�������� ��� ���� ��� ���������� � �����" << endl;
			cin >> helper;
			myField = new MyField(helper);
			myClass->add(myField);
			break;
		case 5:
			cout << "�������� ��� �������� ��� ���������� � �����" << endl;
			cin >> helper;
			myProperty = new MyProperty(helper);
			myClass->add(myProperty);
			break;
		case 6:
			cout << "�������� ��� ������ ��� ���������� � �����" << endl;
			cin >> helper;
			myMethod = new MyMethod(helper);
			myClass->add(myMethod);
			break;
		case 7:
			myClass->printFields();
			cout << "�������� ��� ���� ��� ���������" << endl;
			cin >> current;
			myField = myClass->findFieldByName(current);
			if (myField != NULL)
			{
				cout << "������� ����� ��� ��� ����" << endl;
				cin >> current;
				if (myClass->existField(current))
				{
					myClass->changeField(current);
					cout << "������� �������� ���� ������" << endl;
				}
			}
			else cout << "�� ������� �������� ���� ������" << endl;
			break;
		case 8:
			myClass->printProperties();
			cout << "�������� ��� �������� ��� ���������" << endl;
			cin >> current;
			myProperty = myClass->findPropertyByName(current);
			if (myProperty != NULL)
			{
				cout << "������� ����� ��� ��������" << endl;
				cin >> current;
				if (myClass->existProperty(current))
				{
					myClass->changeProperty(current);
					cout << "������� �������� �������� ������" << endl;
				}
			}
			else cout << "�� ������� �������� ��������" << endl;
			break;
		case 9:
			myClass->printMethods();
			cout << "�������� ��� ������ ��� ���������" << endl;
			cin >> current;
			myMethod = myClass->findMethodByName(current);
			if (myMethod != NULL)
			{
				cout << "������� ����� ��� ������" << endl;
				cin >> current;
				if (myClass->existMethod(current))
				{
					myClass->changeMethod(current);
					cout << "������� �������� ����� ������" << endl;
				}
			}
			else cout << "�� ������� �������� ����� ������" << endl;
			break;
		case 10:
			myClass->printFields();
			cout << "�������� ��� ���� ��� �������� �� ������" << endl;
			cin >> current;
			myClass->deleteField(current);
			break;
		case 11:
			myClass->printProperties();
			cout << "�������� ��� �������� ��� �������� �� ������" << endl;
			cin >> current;
			myClass->deleteProperty(current);
			break;
		case 12:
			myClass->printMethods();
			cout << "�������� ��� ������ ��� ��� �������� �� ������" << endl;
			cin >> current;
			myClass->deleteMethod(current);
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


void concrete_namespace_menu(MyNamespace *myNamespace)
{
	int x = 0;
	string current;
	bool answer = true;
	string helper = "";
	MyClass *myClass;

	while (answer)
	{
		cout << endl;
		cout << "������������ ��� " << myNamespace->get_name() << endl;
		cout << "1. ���������� ������ �������" << endl;
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
			myNamespace->printer();
			break;
		case 2:
			myNamespace->printer();
			cout << "�������� ��� ������, � ������� ������ �����" << endl;
			cin >> current;
			myClass = myNamespace->findClassByName(current);
			if (myClass != NULL)
			{
				cout << "��������� � ����� ��� � ������ " << current << endl;
				concrete_class_menu(myClass);
			}
			else cout << "�� ������� ����� � ����� � ������ " << current << endl;
			break;
		case 3:
			cout << "�������� ��� ������ ��� ���������� � ������������ ���" << endl;
			cin >> helper;  
			myClass = new MyClass(helper);
			myNamespace->add(myClass);
			break;
		case 4:
			myNamespace->printer();
			cout << "�������� ��� ������ ��� ���������" << endl;
			cin >> current;
			myClass = myNamespace->findClassByName(current);
			if (myClass != NULL)
			{
				cout << "������� ����� ��� ��� ������" << endl;
				cin >> current;
				if (myNamespace->exist(current))
				{
					myNamespace->change(current, myClass);
					cout << "������� �������� �����" << endl;
				}
			}
			else cout << "�� ������� �������� ��� ������" << endl;
			break;
		case 5:
			myNamespace->printer();
			cout << "�������� ��� ������ ��� �������� �� ������������ ���" << endl;
			cin >> current;
			myNamespace->deleteClass(current);
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

void namespaces_menu(MyRepository *myRepository)
{
	int x = 0;
	string current;
	bool answer = true;
	string helper = "";
	MyNamespace *myNamespace;

	while (answer)
	{
		cout << "������������ ��� ����������� " << myRepository->get_name() << endl;
		cout << "1. ���������� ������������ ���" << endl;
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
			myRepository->printer();
			break;
		case 2:
			myRepository->printer();
			cout << "�������� ��� ������������ ���, � ������� ������ �����" << endl;
			cin >> current;
			myNamespace = myRepository->findNamespaceByName(current);
			if (myNamespace != NULL) 
			{
				cout << "��������� � ������������ ��� � ������ " << current << endl;
				concrete_namespace_menu(myNamespace);
			}
			else cout << "�� ������� ����� � ������������ ��� � ������ " << current << endl;
			break;
		case 3:
			cout << "�������� ��� ������������ ��� ��� ���������� � �����������" << endl;
			cin >> helper;  
			myNamespace = new MyNamespace(helper);
			myRepository->add(myNamespace);
			break;
		case 4:
			myRepository->printer();
			cout << "�������� ��� ������������ ��� ��� ���������" << endl;
			cin >> current;
			myNamespace = myRepository->findNamespaceByName(current);
			if (myNamespace != NULL)
			{
				cout << "������� ����� ��� ��� ������������ ���" << endl;
				cin >> current;
				myRepository->change(current, myNamespace);
			}
			else cout << "�� ������� �������� ��� ������������ ���" << endl;
			break;
		case 5:
			myRepository->printer();
			cout << "�������� ��� ������������ ��� ��� �������� �� �����������" << endl;
			cin >> current;
			myRepository->deleteNamespace(current);
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

void main_menu(MyRepository *myRepository)
{
	int x = 0;
	bool answer = true;

	while (answer)
	{
		cout << endl;
		cout << "������� ���� ����������� " << myRepository->get_name() <<  endl;
		cout << "1. ������� � ������������ ���" << endl;
		cout << "0. ����� �� ���������" << endl;
		cout << endl;

		cin >> x;

		switch (x)
		{
		case 1:
			namespaces_menu(myRepository);
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

	MyRepository *test = new MyRepository("�������");  // �������� ������ �����������

	main_menu(test); // ����� ��������� ���� ����������

	cin.ignore(); 
	cin.ignore(); // ��� �������� �������
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