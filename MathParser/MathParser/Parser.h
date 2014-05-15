
#include <string>
#include <iostream>
#include "OperationContainer.h"
const char EOS = 0x01, EOS_IN = 0x02;

using namespace std;

template <class T> class Stack
{    
	T stack[3000];
	int istack;
	friend class Parser;

	void push(T x) {
		if (istack<3000)
			stack[istack++] = x;
	}
	T pop()
	{
		if (istack>0)
			return stack[--istack];
		else
			return EOS;
	}
	T top()const
	{
		if (istack>0)
			return stack[istack - 1];
		else
			return EOS;
	}
public:
	Stack()
	{
		istack = 0;
	}
};

class Parser
{
	char currentSymbol; 
	string inputString, convertedString;
	int charIndex;
	OperationContainer *operations = new OperationContainer();

	char NextChar()
	{
		if (charIndex < inputString.length())
			currentSymbol = inputString[charIndex++];
		else
			currentSymbol = EOS_IN;
		return currentSymbol;
	}
	void Add(char c) { convertedString += c; }
	int OperationPriority(char c);

public:
	string ConvertToPPN(string);
	
	string GetConvertedString()const { return convertedString; }
};

