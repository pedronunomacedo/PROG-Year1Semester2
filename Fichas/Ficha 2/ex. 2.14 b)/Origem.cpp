# include <iostream>
# include <iomanip>
using namespace std;


int numCasasDecimais(double number)
{
	int casas = 0;

	while (number < 1)
	{
		number = number * 10;
		casas++;
	}
	return casas;
}


int main()
{
	double n, delta, nMaxlter, rq{ 1 }, dif{}, rqn;
	int numberPrecision;

	cout << "Input the number you want to calculate the square: ";
	cin >> n;
	cout << "Input the number limit for aproximation: ";
	cin >> delta;
	cout << "Input the numbers of attempts: ";
	cin >> nMaxlter;

	numberPrecision = numCasasDecimais(delta);

	rqn = (rq + n / rq) / 2;

	while (dif >= delta || nMaxlter > 0)
	{
		rq = rqn;
		rqn = (rq + n / rq) / 2;
		dif = n - pow(rqn, 2);
		nMaxlter -= 1;
	}

	cout << endl << "The square root of " << n << " is, approximately, " << fixed << setprecision(numberPrecision) << rqn << endl;
	cout << "The square root of " << n << " using sqrt() is " << sqrt(n) << endl;

	return 0;
}