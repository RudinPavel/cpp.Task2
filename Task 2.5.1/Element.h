#pragma once

#include <vector>
#include <string>
using namespace std;

class Element
{
public:
	virtual void print() = 0; // ������ ��������
	virtual void add(Element* e) = 0; // ���������� ��������
	virtual void remove(Element* e) = 0; // �������� ��������
	virtual void change(Element* e, string name) = 0; // ��������� ��������
	virtual string get_name() = 0; // ��������� ����� ��������
	virtual Element* find_element_by_name(string name) = 0;
	Element(); // ����������� ��������
	~Element(); // ���������� ��������
private:
	string name;
	vector<Element*> elements;
};

