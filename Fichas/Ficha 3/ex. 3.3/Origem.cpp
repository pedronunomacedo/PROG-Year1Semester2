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


double raizQuad(double n, double precision, int nMaxIter)
{
	double rq{ 1 }, rqn, dif;
	int contador{ 2 };

	rqn = (rq + n / rq) / 2;
	dif = n - pow(rqn, 2);

	while (dif >= precision || nMaxIter > 0)
	{
		rq = rqn;
		rqn = (rq + n / rq) / 2;
		dif = n - pow(rqn, 2);
		nMaxIter -= 1;
	}

	return rqn;
}


int main()
{
	double n, delta;
	int numberPrecision, nMaxIter;

	cout << "Input the number you want to calculate the square: ";
	cin >> n;
	cout << "Input the number limit for aproximation: ";
	cin >> delta;
	cout << "Input the numbers of attempts: ";
	cin >> nMaxIter;

	numberPrecision = numCasasDecimais(delta);


	cout << endl << "The square root of " << n << " is, approximately, " << fixed << setprecision(numberPrecision) << raizQuad(n, delta, nMaxIter) << endl;
	cout << "The square root of " << n << " using sqrt() is " << sqrt(n) << endl;

	return 0;
}