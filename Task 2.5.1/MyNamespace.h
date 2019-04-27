#pragma once

#include "MyClass.h"
#include "Element.h"
#include <string>
using namespace std;

class MyNamespace : public Element
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

	MyNamespace(string name); // конструктор сущности Не может быть virtual

	~MyNamespace() override; // деструктор сущности

	void set_value(string value) override;

	string get_value() override; // получение имени сущности
private:
	string name; // поле
	vector<Element*> elements; // вектор указателей на классы
};
