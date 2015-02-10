#include "Equation.h"


Equation::Equation()
{
}

void Equation::setEqn(std::string str)
{
	this->eqnString = str;
}

Equation::~Equation()
{
}

char tokenToChar(Token tok)
{
	switch (tok)
	{
	case Token_Plus:
		return '+';
	case Token_Minus:
		return '-';
	case Token_Mult:
		return '*';
	case Token_Divide:
		return '/';
	case Token_LeftParan:
		return '(';
	case Token_RightParan:
		return ')';
	case Token_Power:
		return '^';
	case Token_Square:
		return char(253);
	case Token_Null:
		return char(254);
	default:
		return char(254);
	}
}

Token charToToken(char tok)
{
	Token token = Token(0);
	
	while (token != Token_Null)
	{
		token = Token ((int)token + 1);		// Equivalent to token++
		if (tok == tokenToChar(token))
		{
			return token;
		}
	}

	return Token_Null;
}