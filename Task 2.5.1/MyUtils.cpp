#include "MyUtils.h"
#include <iostream>


MyUtils::MyUtils()
{
}


MyUtils::~MyUtils()
{
}

bool MyUtils::check_valid_name(string name)
{
	int i = 0;

	int size = static_cast<int>(name.size());
	if (size == 0)
	{
		cout << "����������� �������� ��������. ��� �������� �� ����� ���� ������." << endl;
		cout << endl;
		return false;
	}

	while (name[i])
	{
		if (name[i] == ' ')
		{
			cout << "����������� �������� ��������. ��� �������� �������� �������." << endl;
			cout << endl;
			return false;
		}
		i++;
	}
	return true;
}
