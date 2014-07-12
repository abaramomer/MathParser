#include "stdafx.h"
#include "AssemblerCalculator.h"
double result;

double Add(double a, double b)
{ 
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
	_asm
	{
		fld a
		fcos
		fstp result
	}
	return result;
}
double ArcTan(double a)
{
	_asm
	{
		fld a
		fld a
		fpatan
		fstp result
	}
	return result;
}
double ArcTan2(double a)
{
	_asm
	{
		fld a
		fld a
		fpatan
		fstp result
	}
	return result;
}
double ArcCos(double a)
{
	_asm
	{
		fld   a
		fld1
		fadd  ST(0), ST(1)
		fld1
		fsub  ST(0), ST(2)
		fmulp ST(1), ST(0)
		fsqrt
		fxch
		fpatan
		fstp result
	}
	return result;
}
double ArcSin(double a)
{
	_asm
	{
		fld a
		fld1
		fadd  st(0), st(1)
		fld1
		fsub  st(0), st(2)
		fmulp st(1), st(0)
		fsqrt
		fpatan
		fstp result
	}
	return result;
}
double Abs(double a)
{
	_asm
	{
		fld a
		fchs
		fstp result
	}
	return result;
}
double Exp(double a)
{
	 
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
	_asm
	{
		fld a
		fsqrt
		fstp result
			
	}
	return result;
}

double Ln(double a)
{
	_asm
	{
		fldlg2
		fld   a
		fyl2x
		fstp result
	}
	return result;
}
double Pow(double a, double b)
{
	_asm
	{
		fld b
		fld a
		fyl2x
		fld st(0)
		frndint
		fsubr st(1), st
		fxch st(1)
		fchs
		f2xm1
		fld1
		faddp st(1), st
		fscale
		fstp result
	}
	return result;
}
double Tan(double a)
{
	return Divide(Sin(a), Cos(a));
}

double Cot(double a)
{
	return Divide(Cos(a), Sin(a));
}
double Cosh(double a)
{
	return Add(Exp(a), Exp(-a));
}
double Sinh(double a)
{
	return Sub(Exp(a), Exp(-a)) / 2;
}