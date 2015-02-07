#include "Polynomial.h"
#include <cmath>

Polynomial::Polynomial(int p_Degree)
{
	degree = p_Degree;
}

void Polynomial::setCoeffs(doubleVector vec)
{
	coeffs = vec;
}

double Polynomial::value(double root)
{
	double val = 0;

	for (int i = 0; i < degree+1; i++)
	{
		val += coeffs[i] * std::pow(root, i);
	}

	return val;
}

void Polynomial::root_Bisection()
{
	double posRoot = -1001, negRoot = -1001;
	
	if (value(0) >= 0)
		posRoot = 0;
	else
		negRoot = 0;
	
	if (posRoot == 0)
	{
		for (int i = 0; i < 1000; i++)
		{
			if (value(i) < 0.f)
				negRoot = i;
		}

		if (negRoot == -1001)
		{
			for (int i = 0; i > -1000; i--)
			{
				if (value(i) < 0)
					negRoot = i;
			}
		}
	}

	else if (negRoot == 0)
	{
		for (int i = 0; i < 1000; i++)
		{
			if (value(i) > 0)
				posRoot = i;
		}

		if (posRoot == -1001)
		{
			for (int i = 0; i > -1000; i--)
			{
				if (value(i) > 0)
					posRoot = i;
			}
		}
	}

	for (int iter = 0; iter < 400; iter++)
	{
		double tempRoot = (posRoot + negRoot) / 2;
		double tempVal = value(tempRoot);

		if (tempVal < 0)
			negRoot = tempRoot;
		else
			posRoot = tempRoot;

		curBestRoot = tempRoot;

		if (tempVal == 0.0f)
			break;
	}
}

double Polynomial::getBestRoot()
{
	return curBestRoot;
}

Polynomial::~Polynomial()
{
}