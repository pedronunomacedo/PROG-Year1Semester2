# include<iostream>
using namespace std;

int isPrime(int n)
{
	bool prime{ true };

	for (int i = 2; i <= int(sqrt(n)); i++)
	{
		if (n % i == 0)
			prime = false;
	}

	return prime;
}

int main()
{
	int number;
	cout << "Input a number: ";
	cin >> number;

	if (isPrime(number) == true)
		cout << "The number " << number << " is prime.";
	else
		cout << "The number " << number << " is not prime.";

	return 0;
}