
#include "stdafx.h"
#include "Calculator.h"
#include "Helper.h"
#include "AssemblerCalculator.h"
#include "FunctionsMap.h"
#include <string>
#include <iostream>
#include <stack>

using namespace std;
double Calculator::Calculate(string *error)
{
	double secondArgument, firstArgument, res = 0.0;
	int i;
	
	stack <float> values;
	string number;
	for (i = 0; i < convertedString.length(); ++i)
	{
		char c = convertedString[i];
		if (c == 32)
			continue;
		while (i < convertedString.length() && isDigit(convertedString[i]))
		{
			number += convertedString[i++];
		}
		if (!number.empty())
		{
			values.push(atof(number.c_str()));
			number.clear();
			if (i >= convertedString.length())
				break;      

			if (convertedString[i] == 32)
				continue;
		}
		firstArgument = values.top();
		values.pop();
		*error = OneArgumentFunctions(convertedString[i], firstArgument, &res);
		if ((*error) == "n")
		{
			secondArgument = values.top();
			values.pop();
			*error = TwoArgumentFunctions(convertedString[i], secondArgument, firstArgument, &res);
			if (*error != "")
				return 0.0;
		}
		else
		{
			if (*error != "")
				return 0.0;
		}
		values.push(res);
	}
	*error = "";
	return values.top();
}