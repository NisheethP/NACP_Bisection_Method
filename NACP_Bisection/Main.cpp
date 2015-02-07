#include "Button.h"
#include "Functions.h"
#include "Equation.h"
#include <iostream>
#include "Polynomial.h"


int main()
{
	SetDefaultColour();

	int degree = 0;
	doubleVector coefs;

	std::cout << "Enter degree of the equation: ";
	std::cin >> degree;
	std::cout << std::endl << "Enter the coefficient of - ";
	for (int i = 0; i < degree+1; i++)
	{
		float coef;
		std::cout << "\n\t\tx raised to power of " << i << ": ";
		std::cin >> coef;

		coefs.push_back(coef);
	}

	Polynomial eqn(degree);

	eqn.setCoeffs(coefs);

	eqn.root_Bisection();

	std::cout << "\n\nRoot = " << eqn.getBestRoot();
	
	PressAnyKey();
	return 0;
}