#pragma once
#ifndef _OPERATORS_H_
#define _OPERATORS_H_

#include "Equation.h"

Operator tokenToOper(Token tok);

class Operators
{
public:
	static Operator operPlus;
	static Operator operMinus;
	static Operator operDivide;
	static Operator operMultiply;
	static Operator operPower;
	static Operator operSquare;
	static Operator operLeftParan;
	static Operator operRightParan;
	static Operator operNegative;
};


#endif // !_OPERATORS_H_
