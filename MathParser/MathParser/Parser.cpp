
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
	convertedString.clear();
	Stack<char> operationStack;
	inputString = str;

	if ((!isDigit(inputString[0])) && !isFunction(inputString[0]) && inputString[0] != '(')
		return syntaxError;

	while (NextChar() != EOS_IN) 
	{
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

