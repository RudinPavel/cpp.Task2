#pragma once

#include <string>
using namespace std;

static class MyUtils
{
public:
	MyUtils();
	~MyUtils();
	bool static check_valid_name(string name);
};

