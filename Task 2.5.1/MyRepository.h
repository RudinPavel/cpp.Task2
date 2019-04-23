#pragma once

#include <string>
#include <vector>
#include "MyNamespace.h"

class MyRepository : public Container
{
public:
	MyRepository(string name); // конструктор класса
	~MyRepository(); // деструктор

	void add(MyNamespace* myNamespace); // добавить пространство имён
	void deleteNamespace(string name); // удалить пространство, которое будет найдено по имени

	int findIndexByName(string name);
	MyNamespace* findNamespaceByName(string name);

	bool exist(MyNamespace* m);
	bool exist(string name); // проверить существование имени пространства имен в репозитории

	void printer(); // напечатать список пространств имён
	void change(string name, MyNamespace* m); // изменить пространство имён

	string get_name(); // получить имя репозитория
	void set_name(string name);  // установить имя репозитория

private:
	string name; // поле
	vector<MyNamespace*> myNamespaces; // вектор указателей на пространства имён
};

