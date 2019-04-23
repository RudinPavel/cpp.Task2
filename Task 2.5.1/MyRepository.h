#pragma once

#include <string>
#include <vector>
#include "MyNamespace.h"

class MyRepository : public Container
{
public:
	MyRepository(string name); // ����������� ������
	~MyRepository(); // ����������

	void add(MyNamespace* myNamespace); // �������� ������������ ���
	void deleteNamespace(string name); // ������� ������������, ������� ����� ������� �� �����

	int findIndexByName(string name);
	MyNamespace* findNamespaceByName(string name);

	bool exist(MyNamespace* m);
	bool exist(string name); // ��������� ������������� ����� ������������ ���� � �����������

	void printer(); // ���������� ������ ����������� ���
	void change(string name, MyNamespace* m); // �������� ������������ ���

	string get_name(); // �������� ��� �����������
	void set_name(string name);  // ���������� ��� �����������

private:
	string name; // ����
	vector<MyNamespace*> myNamespaces; // ������ ���������� �� ������������ ���
};

