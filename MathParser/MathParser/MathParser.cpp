#include "stdafx.h"

#include <string>
#include "iostream"
#include "Parser.h"
#include <conio.h>

using namespace std;
int main(int argc, char* argv[])
{
	Parser Calculate;
	string s;
	cin >> s;
	
	Calculate.ConvertToPPN(s);
	cout << Calculate.GetConvertedString() << endl;
	cout << Calculate.Calculate() << endl;
	_getch();
	return 0;
}
