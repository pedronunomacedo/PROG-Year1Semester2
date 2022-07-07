#include <iostream>

using namespace std;

int main1()
{
	int i, n = 2, c = 0, primes = 0;

	cout << " Os numeros primos ate 10000" << endl;

	while (c < 10000)
	{
		bool isPrime = true;

		for (i = 2; i <= sqrt(n); ++i)
		{
			if (n % i == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime == false)
		{
			n++;
			c++;
		}
		else if (isPrime == true)
		{
			cout << n << ' ';
			n++;
			c++;
			primes++;
		}
	}

	cout << primes << endl;

	cout << endl;

	return 0;
}