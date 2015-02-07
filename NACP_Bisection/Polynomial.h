#pragma once

#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include <vector>

using doubleVector = std::vector<double>;

class Polynomial
{
	int degree;
	doubleVector coeffs;
	double curBestRoot;
public:
	Polynomial(int p_Degree = 0);

	void setCoeffs(doubleVector vec);
	double value(double root);

	void root_Bisection();

	double getBestRoot();

	~Polynomial();
};

#endif