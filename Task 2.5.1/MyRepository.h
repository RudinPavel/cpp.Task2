#pragma once

#include <vector>
#include <string>
#include "Element.h"

class MyRepository : public Element
{
public:
	MyRepository(string name); // ����������� ������
	~MyRepository(); // ����������

	void print() override; // ������ ��������

	void add(Element* e) override; // �������� ������������ ���

	void remove(Element* e) override; // ������� ������������, ������� ����� ������� �� �����

	void change(Element* e, string name) override; // ������� ������������, ������� ����� ������� �� �����

	Element* find_element_by_name(string name) override;
									  
									  
									  
									  
									  
									  
									  
									  
	//int findIndexByName(string name);
	//MyNamespace* findNamespaceByName(string name);

	//bool exist(MyNamespace* m);
	//bool exist(string name); // ��������� ������������� ����� ������������ ���� � �����������

	//void printer(); // ���������� ������ ����������� ���
	//void change(string name, MyNamespace* m); // �������� ������������ ���

	string get_name(); // �������� ��� �����������
	void set_name(string name);  // ���������� ��� �����������

private:
	string name; // ����
	vector<Element*> myNamespaces; // ������ ���������� �� ������������ ���
};

