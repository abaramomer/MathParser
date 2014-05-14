
#include "stdafx.h"
#include "Calculator.h"
#include "Helper.h"
#include "AssemblerCalculator.h"
#include "FunctionsMap.h"
#include <string>
#include <iostream>
#include <stack>

using namespace std;
double Calculator::Calculate()
{
	double seconfArgument, firstArgument, res = 0.0;
	int i;
	
	stack <float> values;
	string number;
	number.clear();
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
			values.push((float)atof(number.c_str()));
			number.clear();
			if (i >= convertedString.length())
				break;                 //end of the input string

			if (convertedString[i] == 32)
				continue;
		}
		firstArgument = values.top();
		values.pop();
		if (!OneArgumentFunctions(convertedString[i], firstArgument, &res))
		{
			seconfArgument = values.top();
			values.pop();
			TwoArgumentFunctions(convertedString[i], firstArgument, seconfArgument, &res);
		}
	
		values.push(res);
	}
	return values.top();
}