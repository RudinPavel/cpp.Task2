#include "MyMethod.h"
#include <string>
using namespace std;


MyMethod::MyMethod(string name)
{
	this->name = name;
}

MyMethod::~MyMethod()
{
}

string MyMethod::get_name()
{
	return name;
}

void MyMethod::set_name(string name)
{
	this->name = name;
}
