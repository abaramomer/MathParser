#include "stdafx.h"
#include "AssemblerCalculator.h"
double Add(double a, double b)
{
	double result;
	_asm
	{
		fld a;
		fadd b;
		fstp result;
	}
	return result;
}

double Sub(double a, double b)
{
	double result;
	_asm
	{
		fld a;
		fsub b;
		fstp result;
	}
	return result;
}

double Multiply(double a, double b)
{
	double result;
	_asm
	{
		fld a;
		fmul b;
		fstp result;
	}
	return result;
}

double Divide(double a, double b)
{
	double result;
	_asm
	{
		fld a;
		fdiv b;
		fstp result;
	}
	return result;
}

double Sin(double a)
{
	double result;
	_asm
	{
		fld a;
		fsin;
		fstp result;
	}
	return result;
}

double Cos(double a)
{
	double result;
	_asm
	{
		fld a;
		fcos;
		fstp result;
	}
	return result;
}
double Exp(double a)
{
	double result;
	_asm
	{     
		fld a
		fldl2e
		fmul
		fld st
		frndint
		fsub st(1), st
		fxch st(1)
		f2xm1
		fld1
		fadd
		fscale
		fstp result
		
	}
	return result;
}
double Sqrt(double a)
{
	double result;
	_asm
	{
		fld a
		fsqrt
		fstp result
			
	}
	return result;
}
double Sinh(double a)
{
	return Sub(Exp(a), Exp(-a)) / 2;
}