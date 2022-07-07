#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>
#include <math.h>


using namespace std;

int main()
{
	const unsigned int NUM_PRECISION = 6;
	int ang = 0;

	cout << fixed << setprecision(NUM_PRECISION);
	cout << "ang     " << "sen        " << "cos        " << "tan" << endl;

	while (ang <= 90)
	{
		if (ang == 0)
		{
			cout << ' ' << ang << "   " << sin(ang * M_PI / 180) << "   " << cos(ang * M_PI / 180) << "   " << tan(ang * M_PI / 180) << endl;
			ang = ang + 15;
		}
		else if (ang < 90)
		{
			cout << ang << "   " << sin(ang * M_PI / 180) << "   " << cos(ang * M_PI / 180) << "   " << tan(ang * M_PI / 180) << endl;
			ang = ang + 15;
		}
		else if (ang == 90)
		{
			cout << ang << "   " << sin(ang * M_PI / 180) << "   " << cos(ang * M_PI / 180) << "   " << "infinito" << endl;
			break;
		}
	}

	return 0;
}