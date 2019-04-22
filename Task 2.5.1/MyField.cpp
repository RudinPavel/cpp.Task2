#include "MyField.h"
#include <string>
using namespace std;

MyField::MyField(string name)
{
	this->name = name;
}

MyField::~MyField()
{
}

string MyField::get_name()
{
	return name;
}

void MyField::set_name(string name)
{
}
