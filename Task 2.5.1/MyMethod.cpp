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
