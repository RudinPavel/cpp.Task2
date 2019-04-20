// Task 2.5.1.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check_name(string name); // Пример форвардной декларации

/*
5. Иерархия классов. Необходимо создать классы для описания элементов языка C#:
пространств имен, классов, полей, методов и свойств классов и т.д.
Классы принадлежат пространствам имен, в свою очередь каждое пространство имен знает список
своих классов. 
Предусмотреть операцию построения кода шаблона классов (с пустыми методами и свойствами).
Классы могут наследоваться друг от друга.
Для классов необходимо предусмотреть операцию проверки корректности класса
(например, если класс наследуется от абстрактного класса, то он должен перегрузить все
абстрактные методы и свойства и т.д.).
Интерфейс задачи должен представлять собой навигацию по дереву.
Любую сущность можно создать/изменить/удалить.
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
			cout << "Поле " << m->name << " было успешно добавлено в класс " << name << endl;
			cout << endl;
		}
	}

	void add(MyProperty *m) 
	{
		if (checkExistance(m) && (check_name(m->name)))
		{
			properties.push_back(m);
			cout << "Свойство " << m->name << " был успешно добавлено в класс " << name << endl;
			cout << endl;
		}
	}

	void add(MyMethod *m) // принимает в себя указатель на экземпляр класса MyClass
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

class MyNamespace //: Container
{
public:
	string name = "";
	vector<MyClass*> classes;

	MyNamespace(string name) 
	{
		this->name = name;  // -> это сокращение *.
	}

	void add(MyClass *m) // принимает в себя указатель на экземпляр класса MyClass
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


	bool checkExistance(MyClass *m)
	{
		int size = static_cast<int>(classes.size()); // почему нельзя просто size()
		for (int i = 0; i < size; i++)
		{
			if (classes[i]->name == m->name) 
			{
				cout <<"Класс " << m->name  <<" уже определен в пространстве имён " << name << endl;
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
			cout << "Успешно создан репозиторий с именем " << name << endl;
		}
	}

	void add(MyNamespace *m) // принимает в себя указатель на экземпляр класса MyClass
	{
		if (checkExistance(m) && check_name(m->name))
		{
			namespaces.push_back(m);
			cout << "Пространство имён " << m->name << " было успешно добавлено в репозиторий " << name << endl;
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
			cout << "Удалили пространство имён с именем " << name << endl;
			return;
		}
		cout << "Не удалось удалить пространство имён с именем " << name << endl;
	}

	bool checkExistance(MyNamespace *m)  // перегрузка функции
	{
		int size = static_cast<int>(namespaces.size()); // почему нельзя просто size()
		for (int i = 0; i < size; i++)
		{
			if (namespaces[i]->name == m->name)
			{
				cout << "Пространство имён " << m->name << " уже определено в репозитории " << name << endl;
				cout << endl;
				return false;
			}
		}
		return true;
	}

	bool checkExistance(string name) // перегрузка функции
	{
		int size = static_cast<int>(namespaces.size()); // почему нельзя просто size()
		for (int i = 0; i < size; i++)
		{
			if (namespaces[i]->name == name)
			{
				cout << "Пространство имён " << name << " уже определено в репозитории " << endl;
				cout << endl;
				return false;
			}
		}
		return true;
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
		cout << "Недопустимо добавить сущность. Имя сущности не может быть пустым." << endl;
		cout << endl;
		return false;
	}

	while (name[i]) 
	{
		if (name[i] == ' ')
		{
			cout << "Недопустимо добавить сущность. Имя сущности содержит пробелы." << endl;
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
		cout << "Класс " << myClass->name << endl;
		cout << "1. Посмотреть список полей" << endl;
		cout << "2. Посмотреть список свойств" << endl;
		cout << "3. Посмотреть список методов" << endl;
		cout << "4. Создать поле" << endl;
		cout << "5. Создать свойство" << endl;
		cout << "6. Создать метод" << endl;
		cout << "7. Изменить поле" << endl;
		cout << "8. Изменить свойство" << endl;
		cout << "9. Изменить метод" << endl;
		cout << "10. Удалить поле" << endl;
		cout << "11. Удалить свойство" << endl;
		cout << "12. Удалить метод" << endl;
		cout << "0. Вернуться в меню пространства имён" << endl;
		cout << endl;

		cin >> x;

		switch (x)
		{
		case 1:
			myClass->printer();
			break;
		/*case 2:
			myClass->printer();
			cout << "Выберите имя класса, в который хотите войти" << endl;
			cin >> current;


			cout << "-------------Вошли в класс --------------" << endl;
			break;
		case 3:
			cout << "Выберите имя класса для добавления в пространство имён" << endl;
			cin >> helper;
			myClass = new MyClass(helper);
			myNamespace->add(myClass);
			break;
		case 4:
			myNamespace->printer();
			cout << "Выберите имя класса для изменения" << endl;
			cin >> current;
			cout << "-------------Изменили класс --------------" << endl;
			break;
		case 5:
			myNamespace->printer();
			cout << "Выберите имя класса для удаления из пространства имён" << endl;
			cin >> current;
			myNamespace->deleteClass(current);
			break;*/
		case 0:
			answer = false;
			break;
		default:
			cout << "Нет такого варианта в разделе конкретного класса" << endl;
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
		cout << "Пространство имён " << myNamespace->name << endl;
		cout << "1. Посмотреть список классов" << endl;
		cout << "2. Перейти в класс" << endl;
		cout << "3. Создать класс" << endl;
		cout << "//4. Изменить класс" << endl;
		cout << "5. Удалить класс" << endl;
		cout << "0. Вернуться в меню пространств имён" << endl;
		cout << endl;

		cin >> x;

		switch (x)
		{
		case 1:
			myNamespace->printer();
			break;
		case 2:
			myNamespace->printer();
			cout << "Выберите имя класса, в который хотите войти" << endl;
			cin >> current;
			myClass = myNamespace->findClassByName(current);
			if (myClass != NULL)
			{
				cout << "Переходим в класс имён с именем " << current << endl;
				concrete_class_menu(myClass);
			}
			else cout << "Не удалось войти в класс с именем " << current << endl;
			break;
		case 3:
			cout << "Выберите имя класса для добавления в пространство имён" << endl;
			cin >> helper;  
			myClass = new MyClass(helper);
			myNamespace->add(myClass);
			break;
		case 4:
			myNamespace->printer();
			cout << "Выберите имя класса для изменения" << endl;
			cin >> current;
			myClass = myNamespace->findClassByName(current);
			if (myNamespace != NULL)
			{
				cout << "Введите новое имя для класса" << endl;
				cin >> current;
				if (myNamespace->checkExistance(current))
				{
					myClass->name = current;
					cout << "Успешно изменили класс" << endl;
				}
			}
			else cout << "Не удалось изменить имя пространства имён" << endl;
			break;
		case 5:
			myNamespace->printer();
			cout << "Выберите имя класса для удаления из пространства имён" << endl;
			cin >> current;
			myNamespace->deleteClass(current);
			break;
		case 0:
			answer = false;
			break;
		default:
			cout << "Нет такого варианта в разделе конкретного пространства имён" << endl;
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
		cout << "Пространства имён репозитория " << myRepository->name << endl;
		cout << "1. Посмотреть пространства имён" << endl;
		cout << "2. Перейти в пространство имён" << endl;
		cout << "3. Создать пространство имён" << endl;
		cout << "4. Изменить пространство имён" << endl;
		cout << "5. Удалить пространство имён" << endl;
		cout << "0. Вернуться в главное меню" << endl;
		cout << endl;

		cin >> x;

		switch (x)
		{
		case 1:
			myRepository->printer();
			break;
		case 2:
			myRepository->printer();
			cout << "Выберите имя пространства имён, в которое хотите войти" << endl;
			cin >> current;
			myNamespace = myRepository->findNamespaceByName(current);
			if (myNamespace != NULL) 
			{
				cout << "Переходим в пространство имён с именем " << current << endl;
				concrete_namespace_menu(myNamespace);
			}
			else cout << "Не удалось войти в пространство имён с именем " << current << endl;
			break;
		case 3:
			cout << "Выберите имя пространства имён для добавления в репозиторий" << endl;
			cin >> helper;  
			myNamespace = new MyNamespace(helper);
			myRepository->add(myNamespace);
			break;
		case 4:
			myRepository->printer();
			cout << "Выберите имя пространства имён для изменения" << endl;
			cin >> current;
			myNamespace = myRepository->findNamespaceByName(current);
			if (myNamespace != NULL)
			{
				cout << "Введите новое имя для пространства имён" << endl;
				cin >> current;
				if (myRepository->checkExistance(current))
				{
					myNamespace->name = current;
					cout << "Успешно изменили пространство имён" << endl;
				}
			}
			else cout << "Не удалось изменить имя пространства имён" << endl;
			break;
		case 5:
			myRepository->printer();
			cout << "Выберите имя пространства имён для удаления из репозитория" << endl;
			cin >> current;
			myRepository->deleteNamespace(current);
			break;
		case 0:
			answer = false;
			break;
		default:
			cout << "Нет такого варианта в разделе пространств имён" << endl;
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
		cout << "Главное меню репозитория " << myRepository->name <<  endl;
		cout << "1. Перейти в пространства имён" << endl;
		cout << "0. Выйти из программы" << endl;
		cout << endl;

		cin >> x;

		switch (x)
		{
		case 1:
			namespaces_menu(myRepository);
			break;
		case 0:
			cout << "Завершаем работу с программой" << endl;
			answer = false;
			break;
		default:
			cout << "Нет такого варианта в главном меню" << endl;
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian"); // установка локализации для корректного отображения русских символов

	MyRepository *test = new MyRepository("Учебный");  

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