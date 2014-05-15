#include "stdafx.h"
#include "AssemblerCalculator.h"
#include <math.h>
#include <string>
using namespace std;
string rangeError = "incorrect function range";

string OneArgumentFunctions(char c, double firstArgument, double *result)
{
	double res;
	switch (c)
	{
		case 's':
			res = Sin(firstArgument);
			break;
		case 'c':
			res = Cos(firstArgument);
			break;
		case 'e':
			res = Exp(firstArgument);
			break;
		case 'h':
			res = Sinh(firstArgument);
			break;
		case 'q':
			res = Sqrt(firstArgument);
			break;
		case 'a':
			res = Abs(firstArgument);
			break;
		case 't':
			res = Tan(firstArgument);
			break;
		case 'd':
			res = Cot(firstArgument);
			break;
		case 'y':
			res = Cosh(firstArgument);
			break;
		case 'l':
			res = Ln(firstArgument);
			break;
		case 'r':
			firstArgument = Abs(firstArgument);
			if (firstArgument < 1.0)
				res = ArcTan(firstArgument);
			else
				return rangeError;
			break;
		case 'k':
			firstArgument = Abs(firstArgument);
			if (firstArgument < 1.0)
				res = ArcSin(firstArgument);
			else
				return rangeError;
			break;
		case 'b':
			firstArgument = Abs(firstArgument);
			if (firstArgument < 1)
				res = ArcCos(firstArgument);
			else
				return rangeError;
			break;
		default:
			return "n";
			break;
	}
	*result = res;
	return "";
}
string TwoArgumentFunctions(char c, double firstArgument, double secondArgument, double *result)
{
	double res;
	switch (c)
	{
	case '+':
		res = Add(firstArgument, secondArgument);
		break;
	case '-':
		res = Sub(firstArgument, secondArgument);
		break;
	case '*':
		res = Multiply(firstArgument, secondArgument);
		break;
	case '/':
		if (secondArgument == (double)0)
			return "Zero div";
		res = Divide(firstArgument, secondArgument);
		break;
	case '^':
		res = Pow(firstArgument, secondArgument);
		break;
	default:
		return "n";
		break;
	}
	*result = res;
	return "";
}