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
	Token_LeftParan,
	Token_RightParan,
	Token_Power,
	Token_Square,
	Token_Null
};

char tokenToChar(Token tok);
Token charToToken(char tok);

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
	std::queue<double> output;

	void toRPN();
public:
	Equation();

	void setEqn(std::string);
	~Equation();
};


#endif // !_EQUATION_H_
