#include "stdafx.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#define M_PI 3.14159265
#define M_e 2.7182818284
#include "DataGenerator.h"



// Constructor
DataGenerator::DataGenerator()
{
	std::srand(std::time(0));
	std::rand();
}

// Destructor
DataGenerator::~DataGenerator()
{
}

double DataGenerator::getBernoulli(double p = 0.5)
{
	return (p >= getRandomBetweenZeroAndOne()) ? 0 : 1;
}

double DataGenerator::getExponential(double lambda = 1)
{
	return -(1 / lambda)*std::log(1 - getRandomBetweenZeroAndOne());
}

double DataGenerator::getStdNormal()
{
	auto f = [](double x)
	{
		return (2 / (sqrt(2 * M_PI)))*exp(-(1 / 2)*pow(x, 2));
	};
	auto g = [](double x)
	{
		return exp(-x);
	};

	double x = 0.0;
	double y = 0.0;
	do
	{
		double u = getRandomBetweenZeroAndOne();
		x = getExponential(1);
		y = u * 2 * sqrt(M_e / (2 * M_PI))*g(x);
	} while (y > f(x));
	if (getBernoulli(0.5))
	{
		return x;
	}
	else {
		return -x;
	}
	return 0.0;
}

double DataGenerator::getNormal(double my, double sigma)
{
	return my + sigma * getStdNormal();
}

double DataGenerator::getRandomBetweenZeroAndOne()
{
	double random_variable = std::rand();
	return (double)(random_variable / RAND_MAX);
}
