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
		this->name = name;  // -> это сокращение *.
	}

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

MyNamespace::MyNamespace()
{
}


MyNamespace::~MyNamespace()
{
}
