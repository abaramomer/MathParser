
#include "stdafx.h"
#include "Parser.h"
#include "Helper.h"
#include <string>
string syntaxError = "Syntax error";
string bracketsSructError = "Incorret bracket struct";

int Parser::OperationPriority(char c) 
{
	if (isFunction(c))
		return 5;
	switch (c) 
	{
		case '(':
			return 1;
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 3;
		case '^':
			return 4;
		default:
			return 0;
	}
}

string Parser::ConvertToPPN(string str) 
{
	int wasOperation = 0, np = 0;
	charIndex = 0; 
	int isNegative = 1;
	convertedString.clear();
	Stack<char> operationStack;
	inputString = str;
	char c = inputString[0];
	//if ((!isDigit(inputString[0])) && !isFunction(inputString[0]) && inputString[0] != '(' && inputString[0] != '-');
	//	return syntaxError;

	while (NextChar() != EOS_IN) 
	{
		if (currentSymbol == '-' && isNegative)
		{
			if (charIndex < 2 || !isDigit(inputString[charIndex - 2]))
			{
				Add(currentSymbol);
				isNegative = 0;
				wasOperation = 0;
				continue;
			}
		}
		if (isDigit(currentSymbol))
		{
			Add(currentSymbol);
			wasOperation = 0;
			continue;
		}

		else Add(32);

		switch (currentSymbol) 
		{
			case '(': 
				operationStack.push(currentSymbol); 
				np++; 
				isNegative = 1;
				wasOperation = 0; 
				break;
			case ')':
			{
				while ((currentSymbol = operationStack.pop()) != '(' && np > 0)
				{
					Add(currentSymbol);
				}
				np--;
				break;
			}
			default: 
				if (operations->Contain(currentSymbol) && !wasOperation)
				{
					isNegative = 1;
					while (OperationPriority(currentSymbol) <= OperationPriority(operationStack.top()))
					{
						Add(operationStack.pop());
					}
					if (OperationPriority(currentSymbol) > OperationPriority(operationStack.top()))
					{
						operationStack.push(currentSymbol);
					}
					break;
				}
				else
					return syntaxError;
		}
	}
	while (operationStack.top() != EOS)
		Add(operationStack.pop());
	if (np)
		return bracketsSructError;
	return "";
}

