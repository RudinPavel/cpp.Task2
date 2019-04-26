#pragma once

#include "MyClass.h"
#include "Element.h"
#include <string>
using namespace std;

class MyNamespace : public Element
{
public:
	MyNamespace(string name); // ����������� ������
	~MyNamespace(); // ���������� ������

	void print() override; // ������ ��������

	void add(Element* e) override; // �������� ������������ ���

	void remove(Element* e) override; // ������� ������������, ������� ����� ������� �� �����

	void change(Element* e, string name) override; // ������� ������������, ������� ����� ������� �� �����

	Element* find_element_by_name(string name) override;

	//void add(MyClass* myClass); // �������� �����
	//void deleteClass(string name); // ������� �����

	//int findIndexByName(string name);
	//MyClass* findClassByName(string name);

	//bool exist(MyClass* m); 
	//bool exist(string name); // ��������� ������������� ������ � ������������ ����

	//void printer(); // ���������� ������ �������
	//void change(string name, MyClass* m); // �������� �����

	string get_name(); // �������� ��� ������������ ����
	void set_name(string name);  // ���������� ��� ������������ ����

private:
	string name; // ����
	vector<Element*> elements; // ������ ���������� �� ������
};
