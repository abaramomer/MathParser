#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;
map <string, string> operations =
{
	{"s", "sin",  },
	{"c", "cos",  },
	{ "l", "ln",  },
	{ "a", "abs",  },
	{ "e", "exp" },
	{ "q", "sqrt" },
	{ "h", "sinh",  }

};
string Map(string mappingString)
{

	
	for (auto it = operations.begin(); it != operations.end(); ++it)
	{
		string operation = it->second;
		int index = 0, length = operation.length();
		while (true) 
		{

			index = mappingString.find(operation, index);
			if (index == string::npos)
				break;
		
			mappingString.replace(index, length, it->first);
			index = 0;
		}
	}

	
	return mappingString;
}