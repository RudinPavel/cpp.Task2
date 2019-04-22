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
			cout << "Поле " << m->name << " было успешно добавлено в класс " << name << endl;
			cout << endl;
		}
	}

	void add(MyProperty* m)
	{
		if (checkExistance(m) && (check_name(m->name)))
		{
			properties.push_back(m);
			cout << "Свойство " << m->name << " был успешно добавлено в класс " << name << endl;
			cout << endl;
		}
	}

	void add(MyMethod* m) // принимает в себя указатель на экземпляр класса MyClass
	{
		if (checkExistance(m) && (check_name(m->name)))
		{
			methods.push_back(m);
			cout << "Метод " << m->name << " был успешно добавлен в класс " << name << endl;
			cout << endl;
		}
	}

	bool checkExistance(MyField* m)
	{
		int size = static_cast<int>(fields.size()); // почему нельзя просто size()
		for (int i = 0; i < size; i++)
		{
			if (fields[i]->name == m->name)
			{
				cout << "Поле " << m->name << " уже определено в классе " << name << endl;
				cout << endl;
				return false;
			}
		}
		return true;
	}

	bool checkExistance(MyProperty* m)
	{
		int size = static_cast<int>(properties.size()); // почему нельзя просто size()
		for (int i = 0; i < size; i++)
		{
			if (properties[i]->name == m->name)
			{
				cout << "Свойство " << m->name << " уже определено в классе " << name << endl;
				cout << endl;
				return false;
			}
		}
		return true;
	}

	bool checkExistance(MyMethod* m)
	{
		int size = static_cast<int>(methods.size()); // почему нельзя просто size()
		for (int i = 0; i < size; i++)
		{
			if (methods[i]->name == m->name)
			{
				cout << "Метод " << m->name << " уже определен в классе " << name << endl;
				cout << endl;
				return false;
			}
		}
		return true;
	}

	void printer()
	{
		cout << "Поля, свойства и методы " << endl;
	}
};

MyClass::MyClass()
{
}


MyClass::~MyClass()
{
}
