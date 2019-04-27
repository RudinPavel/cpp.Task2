// Task 2.5.1.cpp: определяет точку входа для консольного приложения.
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
		cout << "Класс " << e->get_name() << endl;
		cout << "1. Посмотреть содержимое" << endl;
		cout << "2. Создать поле" << endl;
		cout << "3. Создать свойство" << endl;
		cout << "4. Создать метод" << endl;
		cout << "5. Изменить сущность" << endl;
		cout << "6. Удалить сущность" << endl;
		cout << "0. Вернуться в меню пространства имён" << endl;
		cout << endl;

		cin >> x;

		switch (x)
		{
		case 1:
			e->print();
			break;
		case 2:
			cout << "Выберите имя поля для добавления в класс" << endl;
			cin >> helper;
			cout << "Выберите тип поля для добавления в класс" << endl;
			cin >> value;
			if (u->check_valid_name(helper) && e->not_exist(helper))
			{
				e->add(helper, Field, value);
			}
			else
			{
				cout << "Не удалось добавить поле класс " << helper << endl;
				cout << endl;
			}
			break;
		case 3:
			cout << "Выберите имя свойства для добавления в класс" << endl;
			cin >> helper;
			cout << "Выберите тип свойства для добавления в класс" << endl;
			cin >> value;
			if (u->check_valid_name(helper) && e->not_exist(helper))
			{
				e->add(helper, Property, value);
			}
			else
			{
				cout << "Не удалось добавить свойство в класс " << helper << endl;
				cout << endl;
			}
			break;
		case 4:
			cout << "Выберите имя метода для добавления в класс" << endl;
			cin >> helper;
			cout << "Выберите тип возвращаемого значения для добавления в класс" << endl;
			cin >> value;
			if (u->check_valid_name(helper) && e->not_exist(helper))
			{
				e->add(helper, Method, value);
			}
			else
			{
				cout << "Не удалось добавить метод в класс" << helper << endl;
				cout << endl;
			}
			break;
		case 5:
			e->print();
			cout << "Выберите имя сущности для изменения" << endl;
			cin >> helper;
			h = e->find_element_by_name(helper);
			if (h != NULL)
			{
				cout << "Введите новое имя сущности" << endl;
				cin >> helper;
				e->change(h, helper);
			}
			else
			{
				cout << "Не удалось изменить имя сущности" << endl;
				cout << endl;
			}
			break;
		case 6:
			e->print();
			cout << "Выберите имя сущности для удаления" << endl;
			cin >> helper;
			if (e->find_element_index_by_name(helper) != -1)
			{
				e->remove(e->find_element_index_by_name(helper));
			}
			else
			{
				cout << "Не удалось удалить сущность " << helper << endl;
				cout << endl;
			}
			break;
			break;
		case 0:
			answer = false;
			break;
		default:
			cout << "Нет такого варианта в разделе конкретного класса" << endl;
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
		cout << "Пространство имён " << e->get_name() << endl;
		cout << "1. Посмотреть содержимое" << endl;
		cout << "2. Перейти в класс" << endl;
		cout << "3. Создать класс" << endl;
		cout << "4. Изменить класс" << endl;
		cout << "5. Удалить класс" << endl;
		cout << "0. Вернуться в меню пространств имён" << endl;
		cout << endl;

		cin >> x;

		switch (x)
		{
		case 1:
			e->print();
			break;
		case 2:
			e->print();
			cout << "Выберите имя класса, в который хотите войти" << endl;
			cin >> helper;
			h = e->find_element_by_name(helper);
			if (h != NULL)
			{
				cout << "Переходим в класс с именем " << helper << endl;
				concrete_class_menu(h);
			}
			else
			{
				cout << "Не удалось войти в класс с именем " << helper << endl;
				cout << endl;
			}
			break;
		case 3:
			cout << "Выберите имя класса для добавления" << endl;
			cin >> helper;
			if (u->check_valid_name(helper) && e->not_exist(helper))
			{
				e->add(helper);
			}
			else
			{
				cout << "Не удалось добавить класс " << helper << endl;
				cout << endl;
			}
			break;
		case 4:
			e->print();
			cout << "Выберите имя класса для изменения" << endl;
			cin >> helper;
			h = e->find_element_by_name(helper);
			if (h != NULL)
			{
				cout << "Введите новое имя для класса" << endl;
				cin >> helper;
				e->change(h, helper);
			}
			else
			{
				cout << "Не удалось изменить имя класса" << endl;
				cout << endl;
			}
			break;
		case 5:
			e->print();
			cout << "Выберите имя класса для удаления из пространства имён" << endl;
			cin >> helper;
			if (e->find_element_index_by_name(helper) != -1)
			{
				e->remove(e->find_element_index_by_name(helper));
			}
			else
			{
				cout << "Не удалось удалить класс " << helper << endl;
				cout << endl;
			}
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

void namespaces_menu(Element* e)
{
	int x = 0;
	bool answer = true;
	string helper = "";
	Element *h;
	MyUtils* u = new MyUtils();

	while (answer)
	{
		cout << "Пространства имён репозитория " << e->get_name() << endl;
		cout << "1. Посмотреть содержимое репозитория" << endl;
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
			e->print();
			break;
		case 2:
			e->print();
			cout << "Выберите имя пространства имён, в которое хотите войти" << endl;
			cin >> helper;
			h = e->find_element_by_name(helper);
			if (h != NULL) 
			{
				cout << "Переходим в пространство имён с именем " << helper << endl;
				concrete_namespace_menu(h);
			}
			else
			{
				cout << "Не удалось войти в пространство имён с именем " << helper << endl;
				cout << endl;
			}
			break;
		case 3:
			cout << "Выберите имя пространства имён для добавления в репозиторий" << endl;
			cin >> helper;  
			if (u->check_valid_name(helper) && e->not_exist(helper))
			{
				e->add(helper);
			}
			else
			{
				cout << "Не удалось добавить пространство имён " << helper << endl;
				cout << endl;
			}
			break;
		case 4:
			e->print();
			cout << "Выберите имя пространства имён для изменения" << endl;
			cin >> helper;
			h = e->find_element_by_name(helper);
			if (h != NULL)
			{
				cout << "Введите новое имя для пространства имён" << endl;
				cin >> helper;
				e->change(h, helper);
			}
			else
			{
				cout << "Не удалось изменить пространство имён" << endl;
				cout << endl;
			}
			break;
		case 5:
			e->print();
			cout << "Выберите имя пространства имён для удаления" << endl;
			cin >> helper;
			if (e->find_element_index_by_name(helper) != -1)
			{
				e->remove(e->find_element_index_by_name(helper));
			}
			else
			{
				cout << "Не удалось удалить пространство имён " << helper << endl;
				cout << endl;
			}
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

void main_menu(Element* e)
{
	int x = 0;
	bool answer = true;

	while (answer)
	{
		cout << endl;
		cout << "Главное меню репозитория " << e->get_name() << endl;
		cout << "1. Перейти в пространства имён" << endl;
		cout << "0. Выйти из программы" << endl;
		cout << endl;

		cin >> x;

		switch (x)
		{
		case 1:
			namespaces_menu(e);
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

	Element* test = new MyRepository("Test");  // создание нового репозитория
	
	main_menu(test); // вызов основного меню приложения

	cin.ignore(); 
	cin.ignore(); // для удобства отладки
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



//bool check_valid_name(string name); // Пример форвардной декларации

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