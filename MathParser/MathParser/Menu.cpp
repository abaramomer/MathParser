#include "stdafx.h"
#include "stdlib.h"
#include "Parser.h"
#include <map>
#include "Calculator.h"
#include "OperationsMap.h"
#include "Menu.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int operationsCount;

void printMenuString(string printedString)
{
	cout << printedString << endl;
}
char* functionsArray()
{
	char chars[100];
	int count = 0;
	for (auto it = functions.begin(); it != functions.end(); ++it)
	{
		if (it->first[0] != '3')
		{
			chars[count] = it->first[0];
			count++;
		}
		chars[count] = '$';
	}
	return chars;
}
void clearConsole()
{
	system("cls");
}

void calculate(string convertedString, map<string, string> *history)
{
	Calculator calculator;
	string error;
	//printMenuString(convertedString);
	calculator.SetConvertedString(convertedString);
	double result = calculator.Calculate(&error);
	if (error == "")
	{
		history->insert(std::pair<string, string>(std::to_string(operationsCount), std::to_string(result)));
		printMenuString("Result: " + std::to_string(result));
	}
	else
	{
		printMenuString(error);
	}
}
void calculator()
{
	clearConsole();
	string calculatorCommand;
	Parser parser;
	map<string, string> historyTable;
	operationsCount = 0;
	historyTable.clear();
	while (calculatorCommand != "exit")
	{
		printMenuString("Input expression");
		cin >> calculatorCommand;
		transform(calculatorCommand.begin(), calculatorCommand.end(), calculatorCommand.begin(), ::tolower);
		if (calculatorCommand == "history")
		{
			for (auto it = historyTable.begin(); it != historyTable.end(); ++it)
				printMenuString(it->first + " - " + it->second);
		}
		else
		{
			calculatorCommand = ReplaceFunctions(calculatorCommand);
			calculatorCommand = InsertHistory(calculatorCommand, historyTable);
			string parseResult = parser.ConvertToPPN(calculatorCommand);
			if (parseResult == "")
			{
				operationsCount++;
				calculate(parser.GetConvertedString(), &historyTable);
			}
			printMenuString(parseResult);
		}
	}
}
void help()
{
	clearConsole();
	ifstream stream("help.txt");
	string readedString;
	while (!stream.eof())
	{
		getline(stream, readedString);
		printMenuString(readedString);
	}
	stream.close();
	_gettch();
}
