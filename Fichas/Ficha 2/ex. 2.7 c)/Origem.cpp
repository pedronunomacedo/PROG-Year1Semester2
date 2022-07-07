# include<iostream>

using namespace std;

int main()
{
	int i, n = 2, c = 0;

	cout << "The first 100 primes are: " << endl;

	while (c < 99)
	{
		bool isPrime = true;

		for (i = 2; i <= sqrt(n); i++)
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
			cout << n << endl;
			n++;
			c++;
		}
	}

	return 0;
}