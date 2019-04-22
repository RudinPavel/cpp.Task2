#pragma once
#include <string>
using namespace std;

class MyProperty
{
public:
	MyProperty(string name);
	~MyProperty();
	string get_name();
private:
	string name;
};
