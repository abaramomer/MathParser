
#include "stdafx.h"
#include "Parser.h"
#include "Helper.h"
#include <string>
//
//the priopity of the operation
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

void Parser::ConvertToPPN(string str) 
{
	int was_op = 0, np = 0;    //if there were operations & brackets  
	currentStringNumber = 0;                   //index of input string
	convertedString.clear();
	Stack<char> operationStack;
	str_in = str;

	if ((!isDigit(str_in[0])) && !isFunction(str_in[0]) && str_in[0] != '(')
		throw "Ошибка синтаксиса";

	while (NextChar() != EOS_IN) 
	{
		if (isDigit(currentSymbol)) 
		{
			Add(currentSymbol);
			was_op = 0;
			continue;
		}

		else
		{
			Add(32);
		}
			
			
		switch (currentSymbol) 
		{
		case '(': 
			operationStack.push(currentSymbol); 
			np++; 
			was_op = 0; 
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
			if (operations->Contain(currentSymbol) && !was_op)
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
				throw "Ошибка синтаксиса";
		}
	}
	while (operationStack.top() != EOS)
		Add(operationStack.pop());
	if (np)
		throw "Нарушение скобочной структуры";
}

