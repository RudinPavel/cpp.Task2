#pragma once
#include "MyField.h"
#include "MyProperty.h"
#include "MyMethod.h"
#include <vector>
#include <string>
using namespace std;

class MyClass
{
public:
	MyClass(string name); // ����������� ������
	~MyClass(); // ���������� ������

	void add(MyField* myClass); // �������� ����
	void add(MyProperty* myProperty); // �������� ��������
	void add(MyMethod* myMethod); // �������� �����

	void deleteField(string name); // ������� ����
	void deleteProperty(string name); // ������� ��������
	void deleteMethod(string name); // ������� �����

	int findFieldIndexByName(string name);
	MyField* findFieldByName(string name);

	int findPropertyIndexByName(string name);
	MyProperty* findPropertyByName(string name);

	int findMethodIndexByName(string name);
	MyMethod* findMethodByName(string name);

	bool existField(MyField* m);
	bool existField(string name); // ��������� ������������� ������ � ������������ ����

	bool existProperty(MyProperty* m);
	bool existProperty(string name); // ��������� ������������� ������ � ������������ ����

	bool existMethod(MyMethod* m);
	bool existMethod(string name); // ��������� ������������� ������ � ������������ ����

	void printFields(); // ���������� ������ �����
	void printProperties(); // ���������� ������ �������
	void printMethods(); // ���������� ������ �������

	void changeField(string name); // ���������� ������ �����
	void changeProperty(string name); // ���������� ������ �������
	void changeMethod(string name); // ���������� ������ �������

	string get_name(); // �������� ��� ������������ ����
	void set_name(string name);  // ���������� ��� ������������ ����

private:
	string name; 
	vector<MyField*> myFields;
	vector<MyProperty*> myProperties;
	vector<MyMethod*> myMethods;
};

