#pragma once

#include "MyClass.h"
#include <string>
using namespace std;

class MyNamespace
{
public:
	MyNamespace(string name); // конструктор класса
	~MyNamespace(); // деструктор класса

	void add(MyClass* myClass); // добавить класс
	void deleteClass(string name); // удалить класс

	int findIndexByName(string name);
	MyClass* findClassByName(string name);

	bool exist(MyClass* m); 
	bool exist(string name); // проверить существование класса в пространстве имен

	void printer(); // напечатать список классов
	void change(string name); // изменить класс

	string get_name(); // получить имя пространства имен
	void set_name(string name);  // установить имя пространства имен

private:
	string name; // поле
	vector<MyClass*> myClasses; // вектор указателей на классы
};
