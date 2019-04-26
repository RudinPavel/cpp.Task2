#pragma once

#include <vector>
#include <string>
using namespace std;

class Element
{
public:
	virtual void print() = 0; // печать сущности

	virtual void add(string name) = 0; // добавление сущности

	virtual void add(string name, int i) = 0;

	virtual void remove(int index) = 0; // удаление сущности

	virtual void change(Element* e, string name) = 0; // изменение сущности

	virtual void set_name(string name) = 0;

	virtual string get_name() = 0; // получение имени сущности

	virtual bool not_exist(string name) = 0;

	virtual Element* find_element_by_name(string name) = 0;

	virtual int find_element_index_by_name(string name) = 0;

	Element(); // конструктор сущности Не может быть virtual

	virtual ~Element(); // деструктор сущности
protected:
	string name;
	vector<Element*> elements;
};