# include <iostream>
# include <cmath>
using namespace std;

int main()
{
	int n;
	cout << "Input a number: ";
	cin >> n;


	double raiz = sqrt(n);
	int i{ 2 };
	bool IS_PRIME = true;

	for (i; i < raiz; i++)
	{
		if (n % i == 0)
		{
			IS_PRIME = false;
			break;
		}
	}

	if (IS_PRIME == true)
	{
		cout << "The number " << n << " is a prime number.";
	}
	else
	{
		cout << "The number " << n << " it's not a prime number.";
	}
}