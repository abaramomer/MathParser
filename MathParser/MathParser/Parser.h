
#include <string>
#include <iostream>
const char EOS = 0x01, EOS_IN = 0x02;
const int sz = 400;
using namespace std;

template <class T> class Stack
{      //stack
	T stack[sz];
	int istack;
	friend class Parser;

	void push(T x) {
		if (istack<sz)
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

//this class converts to PPN & Calculateulates expression
class Parser
{
	char currentSymbol; 
	string str_in, convertedString;
	int currentStringNumber;

	char NextChar()
	{
		if (currentStringNumber < str_in.length())
			currentSymbol = str_in[currentStringNumber++];
		else
			currentSymbol = EOS_IN;
		return currentSymbol;
	}
	void Add(char c) { convertedString += c; }
	int OperationPriority(char c);

public:
	void ConvertToPPN(string);
	float Calculate();
	string GetConvertedString()const { return convertedString; }
};

