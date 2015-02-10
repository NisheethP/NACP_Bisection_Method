#pragma once

#ifndef _EQUATION_H_
#define _EQUATION_H_

#include <stack>
#include <queue>
#include <string>

enum Token
{
	Token_Plus,
	Token_Minus,
	Token_Mult,
	Token_Divide,
	Token_Negative,
	Token_LeftParan,
	Token_RightParan,
	Token_Power,
	Token_Square,
	Token_0,
	Token_1,
	Token_2,
	Token_3,
	Token_4,
	Token_5,
	Token_6,
	Token_7,
	Token_8,
	Token_9,
	Token_Decimal,
	Token_Null
};

char tokenToChar(Token tok);
Token charToToken(char tok);

bool isTokenOperator(Token tok);
bool isTokenNumber(Token tok);

struct Operator
{
	Token token;
	int operandsNo;
	bool isLeftAssociative;
	int priorty;
};

class Equation
{
	std::string eqnString;
	std::stack<Operator> opers;
	std::queue<std::string> output;

	void toRPN();
public:
	Equation();

	void setEqn(std::string);
	~Equation();
};


#endif // !_EQUATION_H_
