# include<iostream>
using namespace std;

int main()
{
	int number, i{ 2 };
	cout << "Input a integer number: ";
	cin >> number;

	cout << number << " = ";

	while (i <= number)
	{
		if (number % i == 0)
		{
			if (number / i == 1)
			{
				cout << i;
				break;
			}
			else
			{
				number /= i;
				cout << i << " * ";
			}
		}
		else
		{
			i++;
		}
	}

	return 0;
}