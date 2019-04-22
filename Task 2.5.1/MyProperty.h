#pragma once
#include <string>
using namespace std;

class MyProperty
{
public:
	MyProperty(string name);
	~MyProperty();
	string get_name();
	void set_name(string name);
private:
	string name;
};
