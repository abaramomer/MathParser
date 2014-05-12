#include "stdafx.h"
#include "Calculator.h"
float Fadd(float a, float b)
{
	float result;
	_asm
	{
		fld a;
		fadd b;
		fstp result;
	}
	return result;
}

float Sub(float a, float b)
{
	float result;
	_asm
	{
		fld a;
		fsub b;
		fstp result;
	}
	return result;
}

float Multiply(float a, float b)
{
	float result;
	_asm
	{
		fld a;
		fmul b;
		fstp result;
	}
	return result;
}

float Divide(float a, float b)
{
	float result;
	_asm
	{
		fld a;
		fdiv b;
		fstp result;
	}
	return result;
}