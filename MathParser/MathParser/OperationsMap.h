
#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;
map <string, string> functions =
{
	{"s", "sin",  },
	{ "3.141592", "pi" },
	{"c", "cos",  },
	{ "l", "ln",  },
	{ "a", "abs",  },
	{ "e", "exp" },
	{ "q", "sqrt" },
	{ "h", "sinh" },
	{"y", "cosh"},
	{ "d", "cot" },
	{ "t", "tan" },
	{ "b", "acos" },
	{ "k", "asin" },
	{"r", "atan"},

};
string ReplaceFunctions(string mappingString)
{	
	for (auto it = functions.begin(); it != functions.end(); ++it)
	{
		string operation = it->second;
		int index = 0, length = operation.length();
		while (true) 
		{

			index = mappingString.find(operation, index);
			if (index == string::npos)
				break;
		
			mappingString.replace(index, length, it->first);
			index = 0;
		}
	}
	return mappingString;
}
string InsertHistory(string mappingString, map<string, string> history)
{
	for (auto it = history.begin(); it != history.end(); ++it)
	{
		string operation = "_" + it->first;
		int index = 0, length = operation.length();
		while (true)
		{

			index = mappingString.find(operation, index);
			if (index == string::npos)
				break;
			mappingString.replace(index, length, it->second);
			index = 0;
		}
	}
	return mappingString;
}