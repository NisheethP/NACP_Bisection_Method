#include "Equation.h"
#include "Operators.h"

Equation::Equation()
{
	eqnString = "";
}

void Equation::setEqn(std::string str)
{
	this->eqnString = str;
}

void Equation::toRPN()
{
	for (std::string::iterator iter = eqnString.begin(); iter != eqnString.end(); ++iter)
	{
		char charToken = *iter;
		Token token = charToToken(charToken);

		if (isTokenNumber(token))
		{
			std::string tempNum = "";

			while (isTokenNumber(token))
			{
				charToken = *iter;
				tempNum += charToken;
				token = charToToken(charToken);

				++iter;
			}

			output.push(tempNum);
		}

		if (isTokenOperator(token))
		{
			Operator oper = tokenToOper(token);
			while (opers.top().priorty >= oper.priorty)
			{
				std::string tok = "";
				tok += tokenToChar(opers.top().token);
				
				output.push(tok);
				opers.pop();
			}

			opers.push(tokenToOper(opers.top().token));
		}

		if (token == Token_LeftParan)
		{
			opers.push(Operators::operLeftParan);
		}

		if (token == Token_RightParan)
		{
			Token curOperator = Token_Null;
			while (true)
			{
				if (opers.top().token == Token_LeftParan)
				{
					opers.pop();
					break;
				}
				else
				{
					std::string tok = "";
					tok += tokenToChar(opers.top().token);

					output.push(tok);
					opers.pop();
				}
			}
		}
	}
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
	case Token_0:
		return '0';
	case Token_1:
		return '1';
	case Token_2:
		return '2';
	case Token_3:
		return '3';
	case Token_4:
		return '4';
	case Token_5:
		return '5';
	case Token_6:
		return '6';
	case Token_7:
		return '7';
	case Token_8:
		return '8';
	case Token_9:
		return '9';
	case Token_Decimal:
		return '.';
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
		token = Token((int)token + 1);		// Equivalent to token++
		if (tok == tokenToChar(token))
		{
			return token;
		}
	}

	return Token_Null;
}

bool isTokenOperator(Token tok)
{
	switch (tok)
	{
	case Token_Plus:
	case Token_Minus:
	case Token_Mult:
	case Token_Divide:
	case Token_Power:
	case Token_Square:
		return true;

	case Token_LeftParan:
	case Token_RightParan:
	case Token_Null:
	case Token_0:
	case Token_1:
	case Token_2:
	case Token_3:
	case Token_4:
	case Token_5:
	case Token_6:
	case Token_7:
	case Token_8:
	case Token_9:
	case Token_Decimal:
	default:
		return false;
	}
}

bool isTokenNumber(Token tok)
{
	switch (tok)
	{
	case Token_0:
	case Token_1:
	case Token_2:
	case Token_3:
	case Token_4:
	case Token_5:
	case Token_6:
	case Token_7:
	case Token_8:
	case Token_9:
	case Token_Decimal:
		return true;

	case Token_Plus:
	case Token_Minus:
	case Token_Mult:
	case Token_Divide:
	case Token_Power:
	case Token_Square:
	case Token_LeftParan:
	case Token_RightParan:
	case Token_Null:
	default:
		return false;
	}
}