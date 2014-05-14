#include "stdafx.h"

#include <string>
#include "iostream"
#include "Parser.h"
#include "Calculator.h"
#include "OperationsMap.h"
#include <conio.h>

using namespace std;
int main(int argc, char* argv[])
{
	Parser parser;
	Calculator calculator;
	string s;
	cin >> s;

	s = Map(s);

	parser.ConvertToPPN(s);
	cout << parser.GetConvertedString() << endl;
	calculator.SetConvertedString(parser.GetConvertedString());
	cout << calculator.Calculate() << endl;


	_getch();
	return 0;
}
