#pragma once

#include "MyClass.h"
#include "Container.h"
#include <string>
using namespace std;

class MyNamespace : public Container
{
public:
	MyNamespace(string name); // ����������� ������
	~MyNamespace(); // ���������� ������

	void add(MyClass* myClass); // �������� �����
	void deleteClass(string name); // ������� �����

	int findIndexByName(string name);
	MyClass* findClassByName(string name);

	bool exist(MyClass* m); 
	bool exist(string name); // ��������� ������������� ������ � ������������ ����

	void printer(); // ���������� ������ �������
	void change(string name, MyClass* m); // �������� �����

	string get_name(); // �������� ��� ������������ ����
	void set_name(string name);  // ���������� ��� ������������ ����

private:
	string name; // ����
	vector<MyClass*> myClasses; // ������ ���������� �� ������
};
