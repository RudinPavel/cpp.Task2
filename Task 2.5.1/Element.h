#pragma once

#include <vector>
#include <string>
using namespace std;

class Element
{
public:
	virtual void print() = 0; // печать сущности
	virtual void add(Element* e) = 0; // добавление сущности
	virtual void remove(Element* e) = 0; // удаление сущности
	virtual void change(Element* e, string name) = 0; // изменение сущности
	virtual string get_name() = 0; // получение имени сущности
	virtual Element* find_element_by_name(string name) = 0;
	Element(); // конструктор сущности
	~Element(); // деструктор сущности
private:
	string name;
	vector<Element*> elements;
};

