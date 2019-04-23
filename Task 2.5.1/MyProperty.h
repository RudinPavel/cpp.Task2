#pragma once
#include <string>
#include "Container.h"
using namespace std;

class MyProperty : public Container
{
public:
	MyProperty(string name);
	~MyProperty();
	string get_name();
	void set_name(string name);
private:
	string name;
};
