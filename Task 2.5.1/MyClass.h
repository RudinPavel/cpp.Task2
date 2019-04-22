#pragma once
#include "MyField.h"
#include "MyProperty.h"
#include "MyMethod.h"
#include <vector>
#include <string>
using namespace std;

class MyClass
{
public:
	MyClass(string name); // конструктор класса
	~MyClass(); // деструктор класса

	void add(MyField* myClass); // добавить поле
	void add(MyProperty* myProperty); // добавить свойство
	void add(MyMethod* myMethod); // добавить метод

	void deleteField(string name); // удалить поле
	void deleteProperty(string name); // удалить свойство
	void deleteMethod(string name); // удалить метод

	int findFieldIndexByName(string name);
	MyField* findFieldByName(string name);

	int findPropertyIndexByName(string name);
	MyProperty* findPropertyByName(string name);

	int findMethodIndexByName(string name);
	MyMethod* findMethodByName(string name);

	bool existField(MyField* m);
	bool existField(string name); // проверить существование класса в пространстве имен

	bool existProperty(MyProperty* m);
	bool existProperty(string name); // проверить существование класса в пространстве имен

	bool existMethod(MyMethod* m);
	bool existMethod(string name); // проверить существование класса в пространстве имен

	void printFields(); // напечатать список полей
	void printProperties(); // напечатать список свойств
	void printMethods(); // напечатать список методов

	void changeField(string name); // напечатать список полей
	void changeProperty(string name); // напечатать список свойств
	void changeMethod(string name); // напечатать список методов

	string get_name(); // получить имя пространства имен
	void set_name(string name);  // установить имя пространства имен

private:
	string name; 
	vector<MyField*> myFields;
	vector<MyProperty*> myProperties;
	vector<MyMethod*> myMethods;
};

