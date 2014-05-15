#include <string>
#include <iostream>

using namespace std;

class Calculator
{
	string convertedString;
	
public:
	double Calculate(string *error);
	void SetConvertedString(string str) { convertedString = str; }
};
