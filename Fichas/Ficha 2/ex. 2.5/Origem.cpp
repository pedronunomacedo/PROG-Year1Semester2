# include <iostream>
# include <cmath>
using namespace std;

int main()
{
	cout << "Solutions of Ax^2 + Bx + C = 0" << endl;

	double A, B, C, res1, res2;
	cout << "Insert the coefficients (A B C): ";
	cin >> A >> B >> C;

	double raiz = sqrt(pow(B, 2) - 4 * A * C);

	if (raiz == 0)
	{
		res1 = -B / 2 * A;
		cout << "The equation has 2 equal roots: " << res1 << " and " << res1;
	}
	else
	{
		if (raiz > 0)
		{
			res1 = (-B - raiz) / 2 * A;
			res2 = (-B + raiz) / 2 * A;
			cout << "The equation has 2 roots: " << res1 << " and " << res2;
		}
		else
		{
			double num_positive = -(pow(B, 2) - 4 * A * C);
			cout << "The equation has 2 complex roots: " << -B / 2 * A << " + " << sqrt(num_positive) << "i and " << -B / 2 * A << " - " << sqrt(num_positive) << "i";
		}
	}

	return 0;
}