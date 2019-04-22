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

//bool check_name(string name); // ������ ���������� ����������

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


bool check_valid_name(string name) 
{
	int i = 0;

	int size = static_cast<int>(name.size());
	if (size == 0)
	{
		cout << "����������� �������� ��������. ��� �������� �� ����� ���� ������." << endl;
		cout << endl;
		return false;
	}

	while (name[i]) 
	{
		if (name[i] == ' ')
		{
			cout << "����������� �������� ��������. ��� �������� �������� �������." << endl;
			cout << endl;
			return false;
		}
		i++;
	}
	return true;
}

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
		cout << "����� " << myClass->name << endl;
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
			myClass->printer();
			break;
		/*case 2:
			myClass->printer();
			cout << "�������� ��� ������, � ������� ������ �����" << endl;
			cin >> current;


			cout << "-------------����� � ����� --------------" << endl;
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
			cout << "-------------�������� ����� --------------" << endl;
			break;
		case 5:
			myNamespace->printer();
			cout << "�������� ��� ������ ��� �������� �� ������������ ���" << endl;
			cin >> current;
			myNamespace->deleteClass(current);
			break;*/
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
		cout << "������������ ��� " << myNamespace->name << endl;
		cout << "1. ���������� ������ �������" << endl;
		cout << "2. ������� � �����" << endl;
		cout << "3. ������� �����" << endl;
		cout << "//4. �������� �����" << endl;
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
			if (myNamespace != NULL)
			{
				cout << "������� ����� ��� ��� ������" << endl;
				cin >> current;
				if (myNamespace->exist(current))
				{
					myClass->name = current;
					cout << "������� �������� �����" << endl;
				}
			}
			else cout << "�� ������� �������� ��� ������������ ���" << endl;
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
		cout << "������������ ��� ����������� " << myRepository->name << endl;
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
				myRepository->change(current);
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
		cout << "������� ���� ����������� " << myRepository->name <<  endl;
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
*/