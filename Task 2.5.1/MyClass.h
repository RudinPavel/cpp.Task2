#pragma once
#include "MyField.h"
#include "MyProperty.h"
#include "MyMethod.h"
#include "Element.h"
#include <vector>
#include <string>
using namespace std;

class MyClass : public Element
{
public:
	void print() override; // печать сущности

	void add(string name, MyClassMemberType t, string value); // добавление сущности

	void add(string name);

	void remove(int index) override; // удаление сущности

	void change(Element* e, string name)  override; // изменение сущности

	void set_name(string name) override;

	string get_name() override; // получение имени сущности

	bool not_exist(string name) override;

	Element* find_element_by_name(string name) override;

	int find_element_index_by_name(string name) override;

	MyClass(string name); // конструктор сущности Не может быть virtual

	~MyClass() override; // деструктор сущности

	void set_value(string name) override;

	string get_value() override; // получение имени сущности

private:
	string name; 
	vector<Element*> elements;
};

