#pragma once
#include <string>
using namespace std;

class MyField
{
public:
	MyField(string name);
	~MyField();
	string get_name();
private:
	string name;
};

