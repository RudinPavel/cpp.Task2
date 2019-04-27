#pragma once

#include <vector>
#include <string>
#include "Element.h"

using namespace std;

class MyRepository : public Element
{
public:
	void print() override; // печать сущности

	void add(string name) override; // добавление сущности

	virtual void add(string name, MyClassMemberType t, string value);

	void remove(int index) override; // удаление сущности

	void change(Element* e, string name)  override; // изменение сущности

	void set_name(string name) override;

	string get_name() override; // получение имени сущности

	bool not_exist(string name) override;

	Element* find_element_by_name(string name) override;

	int find_element_index_by_name(string name) override;

	MyRepository(string name); // конструктор сущности Не может быть virtual

	~MyRepository() override; // деструктор сущности

	string get_value();

	void set_value(string value);

private:
	string name; // поле
	vector<Element*> elements; // вектор указателей на пространства имён
};

