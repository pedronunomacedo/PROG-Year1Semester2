# include <iostream>
using namespace std;

int main()
{
	double n, delta, nMaxlter, rq{ 1 }, dif{}, rqn;
	cout << "Input the number you want to calculate the square: ";
	cin >> n;
	cout << "Input the number limit for aproximation: ";
	cin >> delta;
	cout << "Input the numbers of attempts: ";
	cin >> nMaxlter;

	rqn = (rq + n / rq) / 2;

	while (dif > delta || nMaxlter > 0)
	{
		rq = rqn;
		rqn = (rq + n / rq) / 2;
		dif = n - pow(rqn, 2);
		nMaxlter -= 1;
	}

	cout << "The square root of " << n << " is, approximately, " << rqn << " .";

	return 0;
}