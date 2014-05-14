#include <string>
#include <iostream>

using namespace std;

class Calculator
{
	string convertedString;
	
public:
	double Calculate();
	void SetConvertedString(string str) { convertedString = str; }
};
