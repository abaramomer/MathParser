#include "stdafx.h"

#include <string>
#include "iostream"
#include "Menu.h"
#include <conio.h>

using namespace std;

void mainMenu()
{
	char choise = 0;

	while (choise != '4')
	{
		clearConsole();
		printMenuString("1. Calculator");
		printMenuString("3. Help");
		printMenuString("2. Help");
		printMenuString("4. Exit");

		cin >> choise;
		switch (choise)
		{
		case '1':
			calculator();
			break;
		default:
			break;
		}
	}
}
int main(int argc, char* argv[])
{
	mainMenu();
	return 0;
}
