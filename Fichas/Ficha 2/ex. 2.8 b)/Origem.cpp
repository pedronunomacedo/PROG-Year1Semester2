#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>
#include <math.h>


using namespace std;

int main()
{
	const unsigned int NUM_PRECISION = 6;
	double inf_limit, sup_limit, interval;

	cout << "Input the inferior limit: ";
	cin >> inf_limit;
	cout << "Input the superior limit: ";
	cin >> sup_limit;
	cout << "What's the interval of the angles? ";
	cin >> interval;

	cout << fixed << setprecision(NUM_PRECISION);
	cout << "ang     " << "sen        " << "cos        " << "tan" << endl;

	while (inf_limit <= sup_limit)
	{
		if (inf_limit == 0)
		{
			cout << ' ' << inf_limit << "   " << sin(inf_limit * M_PI / 180) << "   " << cos(inf_limit * M_PI / 180) << "   " << tan(inf_limit * M_PI / 180) << endl;
			inf_limit = inf_limit + interval;
		}
		else if (inf_limit < 90)
		{
			cout << inf_limit << "   " << sin(inf_limit * M_PI / 180) << "   " << cos(inf_limit * M_PI / 180) << "   " << tan(inf_limit * M_PI / 180) << endl;
			inf_limit = inf_limit + 15;
		}
		else if (inf_limit == 90)
		{
			cout << inf_limit << "   " << sin(inf_limit * M_PI / 180) << "   " << cos(inf_limit * M_PI / 180) << "   " << "infinito" << endl;
			break;
		}
	}

	return 0;
}