#pragma once

#include "MyClass.h"
#include "Element.h"
#include <string>
using namespace std;

class MyNamespace : public Element
{
public:
	void print() override; // ������ ��������

	void add(string name) override; // ���������� ��������

	virtual void add(string name, int i);

	void remove(int index) override; // �������� ��������

	void change(Element* e, string name)  override; // ��������� ��������

	void set_name(string name) override;

	string get_name() override; // ��������� ����� ��������

	bool not_exist(string name) override;

	Element* find_element_by_name(string name) override;

	int find_element_index_by_name(string name) override;

	MyNamespace(string name); // ����������� �������� �� ����� ���� virtual

	~MyNamespace() override; // ���������� ��������
private:
	string name; // ����
	vector<Element*> elements; // ������ ���������� �� ������
};
