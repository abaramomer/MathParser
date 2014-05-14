#include "stdafx.h"
#include "AvaibleOperations.h"

bool AvaibleOperations::Contain(char operation)
{
	for (int i = 0; i < count; i++)
	{
		if (operations[i] == operation)
			return true;
	}
	return false;
}

