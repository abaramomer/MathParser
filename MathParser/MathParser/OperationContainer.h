#pragma once
#include "Menu.h"
using namespace std;

class OperationContainer
{
public:
	OperationContainer()
	{
		operations[0] = '+';
		operations[1] = '-';
		operations[2] = '*';
		operations[3] = '/';
		operations[4] = '^';
		count = 5;
		char *chars = functionsArray();
		while (chars[count - 5] != '$')
		{
			operations[count] = chars[count - 5];
			count++;
		}
	
	}
	bool Contain(char operation);

private:
	char operations[100];
	int count;
};
