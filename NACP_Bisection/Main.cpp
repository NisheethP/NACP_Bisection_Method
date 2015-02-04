#include "Button.h"
#include "Functions.h"
#include "Equation.h"
#include <iostream>

int main()
{
	Equation eqn1;
	eqn1.setStr("(()(()))");

	findRoot(eqn1);

	PressAnyKey();
	return 0;
}