#pragma once

#include "MyClass.h"
#include "Element.h"
#include <string>
using namespace std;

class MyNamespace : public Element
{
public:
	MyNamespace(string name); // конструктор класса
	~MyNamespace(); // деструктор класса

	void print() override; // печать сущности

	void add(Element* e) override; // добавить пространство имён

	void remove(Element* e) override; // удалить пространство, которое будет найдено по имени

	void change(Element* e, string name) override; // удалить пространство, которое будет найдено по имени

	Element* find_element_by_name(string name) override;

	//void add(MyClass* myClass); // добавить класс
	//void deleteClass(string name); // удалить класс

	//int findIndexByName(string name);
	//MyClass* findClassByName(string name);

	//bool exist(MyClass* m); 
	//bool exist(string name); // проверить существование класса в пространстве имен

	//void printer(); // напечатать список классов
	//void change(string name, MyClass* m); // изменить класс

	string get_name(); // получить имя пространства имен
	void set_name(string name);  // установить имя пространства имен

private:
	string name; // поле
	vector<Element*> elements; // вектор указателей на классы
};
