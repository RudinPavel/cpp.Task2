#pragma once

#include "MyClass.h"
#include <string>
using namespace std;

class MyNamespace
{
public:
	string name;
	MyNamespace();
	~MyNamespace();
	printer();
	findClassByName(string current);
	MyClass add(*MyClass m);
};

