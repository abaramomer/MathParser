#include "stdafx.h"
#include "OperationContainer.h"



bool OperationContainer::Contain(char operation)
{
	for (int i = 0; i < count; i++)
	{
		if (operations[i] == operation)
	return true;
	}
	return false;
}

