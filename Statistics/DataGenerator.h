#pragma once
class DataGenerator
{
public:
	DataGenerator();
	~DataGenerator();
	double getBernoulli(double);
	double getExponential(double);
	double getStdNormal();
	double getNormal(double, double);
private:
	double getRandomBetweenZeroAndOne();
};

