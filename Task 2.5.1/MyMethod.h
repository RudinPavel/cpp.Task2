#pragma once
#include <string>
using namespace std;

class MyMethod
{
public:
	MyMethod(string name);
	~MyMethod();
	string get_name();
private:
	string name;
};
