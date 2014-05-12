
#include "stdafx.h"
#include "Parser.h"
#include "Calculator.h"
#include <string>
bool isDigit(char c)
{
	if ((c >= '0' && c <= '9') || c == '.')
		return true;
	return false;
}

//the priopity of the operation
int Parser::OperationPriority(char c) 
{
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

//convert to PPN
void Parser::ConvertToPPN(string str) 
{
	int was_op = 0, np = 0;    //if there were operations & brackets  
	iin = 0;                   //index of input string
	convertedString.clear();
	Stack<char> op_stack;
	str_in = str;

	if ((!isDigit(str_in[0])) && str_in[0] != '(')
		throw "Ошибка синтаксиса";

	while (nxtc() != EOS_IN) 
	{
		if (isDigit(currentSymbol)) 
		{
			Add(currentSymbol);
			was_op = 0;
			continue;
		}
		else 
			Add(32);
		switch (currentSymbol) 
		{
		case '(': 
			op_stack.push(currentSymbol); 
			np++; 
			was_op = 0; 
			break;
		case '*': case '/': case '+': case '-': case '^':
			if (iin == str_in.length())
				throw "Ошибка синтаксиса";

			if (!was_op) 
			{
				was_op = 1;
				while (OperationPriority(currentSymbol) <= OperationPriority(op_stack.top())) 
				{
					Add(op_stack.pop());
				}
				if (OperationPriority(currentSymbol) > OperationPriority(op_stack.top()))
				{
					op_stack.push(currentSymbol);
				}
				break;
			}
			else 
				throw "Ошибка синтаксиса";

		case ')':
		{
			if (was_op)
				throw "Ошибка синтаксиса";
			else
			while ((currentSymbol = op_stack.pop()) != '(' && np > 0)
			{
				Add(currentSymbol);
			}
			np--;
			break;
		}
		default: 
			{
				throw "Недопустимая литера во входной строке";
			}
		}
	}
	while (op_stack.top() != EOS)
		Add(op_stack.pop());
	if (np)
		throw "Нарушение скобочной структуры";
}

//Calculateulate
float Parser::Calculate() 
{
	float n1, n, res = 0.0; 
	int i;
	Stack<float> val_stack;
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
			val_stack.push((float)atof(number.c_str()));
			number.clear();
			if (i >= convertedString.length())
				break;                 //end of the input string

			if (convertedString[i] == 32)
				continue;
		}
		n = val_stack.pop();         //the first current number
		n1 = val_stack.pop();        //the second current number
		switch (convertedString[i])
		{
			case '+': 
				res = Fadd(n1, n);
				break;
			case '-': 
				res = Sub(n1, n);
				break;
			case '*': 
				res = Multiply(n1, n); 
				break;
			case '/': 
				res = Divide(n1, n); 
				break;
			case '^':
				res = pow(n1, n);
				break;
			default: 
				throw "Ошибка";
		}
		val_stack.push(res);
	}
	return val_stack.pop();
}
