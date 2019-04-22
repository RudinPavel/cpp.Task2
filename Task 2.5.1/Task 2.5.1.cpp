// Task 2.5.1.cpp: определяет точку входа для консольного приложения.
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

//bool check_name(string name); // Пример форвардной декларации

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


bool check_valid_name(string name) 
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
				if (myNamespace->exist(current))
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
				myRepository->change(current);
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

	MyRepository *test = new MyRepository("Учебный");  // создание нового репозитория

	main_menu(test); // вызов основного меню приложения

	cin.ignore(); 
	cin.ignore(); // для удобства отладки
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