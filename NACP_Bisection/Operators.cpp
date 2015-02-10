#include "Operators.h"

/*OPERATOR ORDER - {Token, OperandNo, isLeftAssociative, priorty}*/

Operator Operators::operLeftParan =		{ Token_LeftParan,	0, false,	-5 };
Operator Operators::operRightParan =	{ Token_RightParan,	0, false,	-5 };
Operator Operators::operPlus =			{ Token_Plus,		2, true,	1 };
Operator Operators::operMinus =			{ Token_Minus,		2, true,	1 };
Operator Operators::operDivide =		{ Token_Divide,		2, true,	2 };
Operator Operators::operMultiply =		{ Token_Mult,		2, true,	3 };
Operator Operators::operPower =			{ Token_Power,		2, false,	4 };
Operator Operators::operSquare =		{ Token_Square,		1, false,	4 };
Operator Operators::operNegative =		{ Token_Square,		1, true,	5 };

Operator tokenToOper(Token tok)
{
	switch (tok)
	{
	case Token_Plus:
		return Operators::operPlus;
	case Token_Minus:
		return Operators::operMinus;
	case Token_Mult:
		return Operators::operDivide;
	case Token_Divide:
		return Operators::operMultiply;
	case Token_Power:
		return Operators::operPower;
	case Token_Square:
		return Operators::operSquare;
	}
}