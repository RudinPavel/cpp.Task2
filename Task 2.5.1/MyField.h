#pragma once
class Container;
#include <string>
#include "Container.h"
using namespace std;

class MyField : public Container
{
public:
	MyField(string name);
	~MyField();
	string get_name();
	void set_name(string name);
	void print_all();
private:
	string name;
};

