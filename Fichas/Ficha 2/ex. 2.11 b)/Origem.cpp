# include<iostream>
using namespace std;

int factorial(int n)
{
	if (n > 1)
		return n * factorial(n - 1);
	else
		return 1;
}


int main()
{
	int n, i{ 0 };
	float res{ 0 };
	cout << "Input how many first numbers do you want to calculate: ";
	cin >> n;

	while (i < n)
	{
		res += (float) 1 / factorial(i);
		i++;
	}

	cout << "The result of the first " << n << " numbers is " << res << " .";

	return 0;
}