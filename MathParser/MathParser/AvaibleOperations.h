#pragma once


class AvaibleOperations
{
public:
	AvaibleOperations()
	{
		operations[0] = '+';
		operations[1] = '-';
		operations[2] = '*';
		operations[3] = '/';
		operations[4] = '^';
		operations[5] = 's';
		operations[6] = 'c';
		operations[7] = 'l';
		operations[8] = 'q';
		operations[9] = 'e';
		operations[10] = 'h';
		count = 11;
	}
	bool Contain(char operation);

private:
	char operations[100];
	int count;
};
