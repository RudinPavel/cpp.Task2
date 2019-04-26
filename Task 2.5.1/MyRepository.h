#pragma once

#include <vector>
#include <string>
#include "Element.h"

class MyRepository : public Element
{
public:
	MyRepository(string name); // конструктор класса
	~MyRepository(); // деструктор

	void print() override; // печать сущности

	void add(Element* e) override; // добавить пространство имён

	void remove(Element* e) override; // удалить пространство, которое будет найдено по имени

	void change(Element* e, string name) override; // удалить пространство, которое будет найдено по имени

	Element* find_element_by_name(string name) override;
									  
									  
									  
									  
									  
									  
									  
									  
	//int findIndexByName(string name);
	//MyNamespace* findNamespaceByName(string name);

	//bool exist(MyNamespace* m);
	//bool exist(string name); // проверить существование имени пространства имен в репозитории

	//void printer(); // напечатать список пространств имён
	//void change(string name, MyNamespace* m); // изменить пространство имён

	string get_name(); // получить имя репозитория
	void set_name(string name);  // установить имя репозитория

private:
	string name; // поле
	vector<Element*> myNamespaces; // вектор указателей на пространства имён
};

