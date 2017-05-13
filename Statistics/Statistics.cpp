// Statistics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "DataGenerator.h"

int main(int argc, char *argv[])
{
	using std::cout;
	using std::cin;

	enum Mode
	{
		IDLE,
		BERNOULLI,
		EXPONENTIAL,
		STANDARDNORM,
		NORMAL
	};

	DataGenerator dg;
	std::string in;
	double parameters[]{ 0,0 };



	while (true)
	{
		Mode mode = IDLE;
		int numberOfDataPoints = 0;

		cout << "Please select distribution type:\n" <<
			"\'b\' = Bernoulli\n" <<
			"\'e\' = Exponential\n" <<
			"\'s\' = Standardnormal\n" <<
			"\'n\' = Normal\n" <<
			"\'x\' = Exit program\n";
		cin >> in;
		switch (in.at(0))
		{
		case 'b':
			mode = BERNOULLI;
			cout << "Please enter parameter p\n";
			cin >> parameters[0];
			break;
		case 'e':
			mode = EXPONENTIAL;
			cout << "Please enter parameter lambda\n";
			cin >> parameters[0];
			break;
		case 's':
			mode = STANDARDNORM;
			break;
		case 'n':
			mode = NORMAL;
			cout << "Please enter parameter my\n";
			cin >> parameters[0];
			cout << "Please enter parameter sigma square\n";
			cin >> parameters[1];
			break;
		case 'x':
			exit(0);
			break;
		default:
			break;
		}
		cout << "How many data points?\n";

		cin >> numberOfDataPoints;

		cout << "Generation starts now.\n";

		std::ofstream myfile("data.csv");
		if (myfile.is_open())
		{

			for (int i = 0; i < numberOfDataPoints; i++)
			{
				switch (mode)
				{
				case IDLE:
					break;
				case BERNOULLI:
					myfile << dg.getBernoulli(parameters[0]) << "\n";
					break;
				case EXPONENTIAL:
					myfile << dg.getExponential(parameters[0]) << "\n";
					break;
				case STANDARDNORM:
					myfile << dg.getStdNormal() << "\n";
					break;
				case NORMAL:
					myfile << dg.getNormal(parameters[0], parameters[1]) << "\n";
					break;
				default:
					break;
				}
			}
		}
		myfile.close();
	}

	return 0;
}