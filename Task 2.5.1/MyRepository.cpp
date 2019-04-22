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
			cout << "Успешно создан репозиторий с именем " << name << endl;
		}
	}

	void add(MyNamespace* m) // принимает в себя указатель на экземпляр класса MyClass
	{
		if (exist(m) && check_name(m->name))
		{
			namespaces.push_back(m);
			cout << "Пространство имён " << m->name << " было успешно добавлено в репозиторий " << name << endl;
			cout << endl;
		}
	}

	void change(string name)
	{
		if (exist(name))
			return;
		this->name = name;
		cout << "Успешно присвоили новое имя" << endl;
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
			cout << "Удалили пространство имён с именем " << name << endl;
			return;
		}
		cout << "Не удалось удалить пространство имён с именем " << name << endl;
	}

	bool exist(MyNamespace * m)  // перегрузка функции
	{
		int size = static_cast<int>(namespaces.size()); // почему нельзя просто size()
		for (int i = 0; i < size; i++)
		{
			if (namespaces[i]->name == m->name)
			{
				cout << "Пространство имён " << m->name << " уже определено в репозитории " << name << endl;
				cout << endl;
				return true;
			}
		}
		return false;
	}

	bool exist(string name) // перегрузка функции
	{
		int size = static_cast<int>(namespaces.size()); // почему нельзя просто size()
		for (int i = 0; i < size; i++)
		{
			if (namespaces[i]->name == name)
			{
				cout << "Пространство имён " << name << " уже определено в репозитории " << endl;
				cout << endl;
				return true;
			}
		}
		return false;
	}

	void printer()
	{
		string result;
		int size = static_cast<int>(namespaces.size()); // почему нельзя просто size()
		if (size == 0)
		{
			cout << "В репозитории еще нет ни одного пространства имён." << endl;
			return;
		}
		cout << "Доступные пространства имён" << endl;
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
