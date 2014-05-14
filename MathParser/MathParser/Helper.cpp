#include "stdafx.h"
#include "Helper.h"

bool isDigit(char c)
{
	if ((c >= '0' && c <= '9') || c == '.')
		return true;
	return false;
}
bool isFunction(char c)
{
	if (c >= 'a' && c <= 'z')
		return true;
	return false;
}