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
	void print() override; // ������ ��������

	void add(string name, MyClassMemberType t, string value); // ���������� ��������

	void add(string name);

	void remove(int index) override; // �������� ��������

	void change(Element* e, string name)  override; // ��������� ��������

	void set_name(string name) override;

	string get_name() override; // ��������� ����� ��������

	bool not_exist(string name) override;

	Element* find_element_by_name(string name) override;

	int find_element_index_by_name(string name) override;

	MyClass(string name); // ����������� �������� �� ����� ���� virtual

	~MyClass() override; // ���������� ��������

	void set_value(string name) override;

	string get_value() override; // ��������� ����� ��������

private:
	string name; 
	vector<Element*> elements;
};

