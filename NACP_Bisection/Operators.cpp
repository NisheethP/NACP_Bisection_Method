#include "Operators.h"

/*OPERATOR ORDER - {Token, OperandNo, isLeftAssociative, priorty}*/

Operator Operators::operPlus =		{Token_Plus,	2, true,	 1 };
Operator Operators::operMinus =		{ Token_Minus,	2, true,	 1 };
Operator Operators::operDivide =	{ Token_Divide,	2, true,	 2 };
Operator Operators::operMultiply =	{ Token_Mult,	2, true,	 3 };
Operator Operators::operPower =		{ Token_Power,	2, false,	 4 };
Operator Operators::operSquare =	{ Token_Square,	1, false,	 4 };