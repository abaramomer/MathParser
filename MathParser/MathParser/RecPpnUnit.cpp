#include "string.h"
//get the next character
char TStr2PPN::nextChar() {
	if (iin <= instr.Length()) return curc = instr[iin++];
	return curc = '\0';
}

//get the output string
string TStr2PPN::get_outstr(){ return outstr; }

//convert to PPN
void TStr2PPN::convert(char *str) {
	try {
		instr = str;
		outstr.SetLength(0);
		iin = 1;
		nextChar();
		//begin the convertation
		begin();
		if (iin != (instr.Length() + 1) || curc != '\0') {
			throw Exception("Syntax error");
		}
		if (!isalpha(instr[instr.Length()]) && instr[instr.Length()] != ')') {
			throw Exception("Syntax error");
		}
	}
	catch (...) { throw; }
}

//handle plus & minus
void TStr2PPN::begin() {
	try {
		mult_div();
		while (curc == '+' || curc == '-') {
			char temp = curc;
			nextChar();
			mult_div();
			outstr += temp;
		}
	}
	catch (...) { throw; }
}

//handle multiplication & division
void TStr2PPN::mult_div() {
	try {
		symbol();
		while (curc == '*' || curc == '/') {
			char temp = curc;
			nextChar();
			symbol();
			outstr += temp;
		}
	}
	catch (...) { throw; }
}

//handle characters
void TStr2PPN::symbol() {
	try {
		if (curc == '(') {
			nextChar();
			begin();
			if (curc != ')') {
				throw Exception("Error: wrong number of brackets");
			}
			else nextChar();
		}
		else
		if (isalpha(curc)) {
			outstr += curc;
			nextChar();
		}
		else { throw Exception("Syntax error"); }
	}
	catch (...) { throw; }
}