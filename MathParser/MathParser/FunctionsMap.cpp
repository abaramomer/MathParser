#include "stdafx.h"
#include "AssemblerCalculator.h"
#include <math.h>
bool OneArgumentFunctions(char c, double firstArgument, double *result)
{
	switch (c)
	{
		case 's':
			*result = Sin(firstArgument);
			break;
		case 'c':
			*result = Cos(firstArgument);
			break;
		case 'e':
			*result = Exp(firstArgument);
			break;
		case 'h':
			*result = Sinh(firstArgument);
			break;
		case 'q':
			*result = Sqrt(firstArgument);
			break;
		default:
			return false;
			break;
	}
	return true;
}
bool TwoArgumentFunctions(char c, double firstArgument, double secondArgument, double *result)
{
	switch (c)
	{
	case '+':
		*result = Add(firstArgument, secondArgument);
		break;
	case '-':
		*result = Sub(firstArgument, secondArgument);
		break;
	case '*':
		*result = Multiply(firstArgument, secondArgument);
		break;
	case '/':
		*result = Divide(firstArgument, secondArgument);
		break;
	case '^':
		*result = pow(firstArgument, secondArgument);
		break;
	default:
		return false;
		break;
	}
	return true;
}