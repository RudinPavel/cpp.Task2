// Task 2.5.1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check_name(string name); // ������ ���������� ����������

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

class Container 
{  
public:
	virtual void add() = 0;
	virtual bool check() = 0;
	virtual void remove() = 0;
	virtual void update() = 0;
};

class MyField
{
public:
	string name = "";
	
	MyField(string name)
	{
		this->name = name;
	}
};

class MyProperty
{
public:
	string name = "";

	MyProperty(string name)
	{
		this->name = name;
	}
};

class MyMethod 
{
public:
	string name = "";
	
	MyMethod(string name)
	{
		this->name = name;
	}
};

class MyClass  : Container
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

	void add(MyField *m)
	{
		if (checkExistance(m) && (check_name(m->name)))
		{
			fields.push_back(m);
			cout << "���� " << m->name << " ���� ������� ��������� � ����� " << name << endl;
			cout << endl;
		}
	}

	void add(MyProperty *m) 
	{
		if (checkExistance(m) && (check_name(m->name)))
		{
			properties.push_back(m);
			cout << "�������� " << m->name << " ��� ������� ��������� � ����� " << name << endl;
			cout << endl;
		}
	}

	void add(MyMethod *m) // ��������� � ���� ��������� �� ��������� ������ MyClass
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

class MyNamespace //: Container
{
public:
	string name = "";
	vector<MyClass*> classes;

	MyNamespace(string name) 
	{
		this->name = name;  // -> ��� ���������� *.
	}

	void add(MyClass *m) // ��������� � ���� ��������� �� ��������� ������ MyClass
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


	bool checkExistance(MyClass *m)
	{
		int size = static_cast<int>(classes.size()); // ������ ������ ������ size()
		for (int i = 0; i < size; i++)
		{
			if (classes[i]->name == m->name) 
			{
				cout <<"����� " << m->name  <<" ��� ��������� � ������������ ��� " << name << endl;
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

class MyRepository //: Container
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

	void add(MyNamespace *m) // ��������� � ���� ��������� �� ��������� ������ MyClass
	{
		if (checkExistance(m) && check_name(m->name))
		{
			namespaces.push_back(m);
			cout << "������������ ��� " << m->name << " ���� ������� ��������� � ����������� " << name << endl;
			cout << endl;
		}
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

	bool checkExistance(MyNamespace *m)  // ���������� �������
	{
		int size = static_cast<int>(namespaces.size()); // ������ ������ ������ size()
		for (int i = 0; i < size; i++)
		{
			if (namespaces[i]->name == m->name)
			{
				cout << "������������ ��� " << m->name << " ��� ���������� � ����������� " << name << endl;
				cout << endl;
				return false;
			}
		}
		return true;
	}

	bool checkExistance(string name) // ���������� �������
	{
		int size = static_cast<int>(namespaces.size()); // ������ ������ ������ size()
		for (int i = 0; i < size; i++)
		{
			if (namespaces[i]->name == name)
			{
				cout << "������������ ��� " << name << " ��� ���������� � ����������� " << endl;
				cout << endl;
				return false;
			}
		}
		return true;
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
			result +=  namespaces[i]->name + "\n\r";
		}
		cout << result << endl;;
	}
};


bool check_name(string name) 
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
				if (myNamespace->checkExistance(current))
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
				if (myRepository->checkExistance(current))
				{
					myNamespace->name = current;
					cout << "������� �������� ������������ ���" << endl;
				}
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

	MyRepository *test = new MyRepository("�������");  

	main_menu(test);

	cin.ignore();
	cin.ignore();
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
*/