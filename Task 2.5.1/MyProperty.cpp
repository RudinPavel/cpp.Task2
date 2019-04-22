#include "MyProperty.h"
#include <string>
using namespace std;

MyProperty::MyProperty(string name)
{
	this->name = name;
}

MyProperty::~MyProperty()
{
}

string MyProperty::get_name()
{
	return name;
}

void MyProperty::set_name(string name)
{
}
