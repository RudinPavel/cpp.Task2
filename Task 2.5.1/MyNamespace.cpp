#include "MyNamespace.h"

#include <string>
#include <vector>
#include <iostream>
#include "MyUtils.h"

using namespace std;

MyNamespace::MyNamespace(string name)
{
	if (MyUtils::check_valid_name(name))
	{
		this->name = name;
		cout << "Успешно создан репозиторий с именем " << name << endl;
	}
}

MyNamespace::~MyNamespace()
{
	cout << "Успешно удалили пространство имён" << endl;
}

void MyNamespace::add(MyClass* myClass)
{
	if (!exist(myClass->get_name()) && MyUtils::check_valid_name(myClass->get_name()))
	{
		myClasses.push_back(myClass);
		cout << "Класс " << myClass->get_name() << " было успешно добавлен в пространство имен " << name << endl;
		cout << endl;
	}
}

void MyNamespace::deleteClass(string name)
{
	int position = findIndexByName(name);

	if (position != -1)
	{
		MyClass* n = findClassByName(name);
		this->myClasses.erase(this->myClasses.begin() + position);
		delete n;
		cout << "Удалили класс с именем " << name << endl;
		return;
	}
	cout << "Не удалось удалить класс с именем " << name << endl;
}

int MyNamespace::findIndexByName(string name)
{
	int size = static_cast<int>(myClasses.size());
	for (int i = 0; i < size; i++)
	{
		if (myClasses[i]->get_name() == name)
		{
			return i;
		}
	}
	return -1;
}

MyClass* MyNamespace::findClassByName(string name)
{
	int size = static_cast<int>(myClasses.size());
	for (int i = 0; i < size; i++)
	{
		if (myClasses[i]->get_name() == name)
		{
			return myClasses[i];
		}
	}
	return NULL;
}

bool MyNamespace::exist(MyClass* m)
{
	int size = static_cast<int>(myClasses.size()); // почему нельзя просто size()
	for (int i = 0; i < size; i++)
	{
		if (myClasses[i]->get_name() == m->get_name())
		{
			cout << "Класс " << m->get_name() << " уже определен в пространстве имён " << name << endl;
			cout << endl;
			return true;
		}
	}
	return false;
}

bool MyNamespace::exist(string name)
{
	int size = static_cast<int>(myClasses.size()); // почему нельзя просто size()
	for (int i = 0; i < size; i++)
	{
		if (myClasses[i]->get_name() == name)
		{
			cout << "Класс " << name << " уже определен в пространстве имён " << this->name << endl;
			cout << endl;
			return true;
		}
	}
	return false;
}

void MyNamespace::printer()
{
	string result;
	int size = static_cast<int>(myClasses.size()); // почему нельзя просто size()
	if (size == 0)
	{
		cout << "В пространстве имен нет ни одного класса." << endl;
		return;
	}
	cout << "Доступные классы" << endl;
	for (int i = 0; i < size; i++)
	{
		result += to_string(i + 1) + ". ";
		result += myClasses[i]->get_name() + "\n\r";
	}
	cout << result << endl;
}

void MyNamespace::change(string name)
{
	if (exist(name))
		return;
	this->name = name;
	cout << "Успешно присвоили новое имя" << endl;
}

string MyNamespace::get_name()
{
	return name;
}

void MyNamespace::set_name(string name)
{
	this->name = name;
}





/*
class MyNamespace1 //: Container
{
public:
	string name = "";
	vector<MyClass*> classes;

	void add(MyClass* m) // принимает в себя указатель на экземпляр класса MyClass
	{
		if (checkExistance(m) && (check_name(m->name)))
		{
			classes.push_back(m);
			cout << "Класс " << m->name << " был успешно добавлен в пространство имён " << name << endl;
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

	bool checkExistance(string name) // перегрузка функции
	{
		int size = static_cast<int>(classes.size()); // почему нельзя просто size()
		for (int i = 0; i < size; i++)
		{
			if (classes[i]->name == name)
			{
				cout << "Класс " << name << " уже определен в пространстве имен " << endl;
				cout << endl;
				return false;
			}
		}
		return true;
	}


	bool checkExistance(MyClass* m)
	{
		int size = static_cast<int>(classes.size()); // почему нельзя просто size()
		for (int i = 0; i < size; i++)
		{
			if (classes[i]->name == m->name)
			{
				cout << "Класс " << m->name << " уже определен в пространстве имён " << name << endl;
				cout << endl;
				return false;
			}
		}
		return true;
	}

	void printer()
	{
		string result;
		int size = static_cast<int>(classes.size()); // почему нельзя просто size()
		if (size == 0)
		{
			cout << "В пространстве имен еще нет ни одного класса." << endl;
			return;
		}
		cout << "Доступные классы" << endl;
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
			cout << "Удалили класс с именем " << name << endl;
			return;
		}
		cout << "Не удалось удалить класс с именем " << name << endl;
	}

};
*/