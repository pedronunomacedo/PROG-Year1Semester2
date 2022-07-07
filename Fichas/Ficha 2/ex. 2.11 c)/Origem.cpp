# include<iostream>
using namespace std;

int factorial(int i)
{
	if (i > 1)
		return i * factorial(i - 1);
	else
		return 1;
}

int main()
{
	int n, i{ 0 };
	float x;
	float res{ 0 };

	cout << "How many first numbers do you want to calculate ? ";
	cin >> n;
	cout << "Input the value of x (e^(-x)): ";
	cin >> x;

	while (i < n)
	{
		res += (float) (pow(x, i) * pow(-1, i)) / factorial(i);
		i++;
	}

	cout << endl << "The result of the first " << n << " numbers is " << res << " ." << endl;

	return 0;
}