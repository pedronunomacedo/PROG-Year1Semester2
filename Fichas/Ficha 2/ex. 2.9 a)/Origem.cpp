# include <iostream>
using namespace std;

int main()
{
	int number, first_digit, last_digit;

	cout << "Input the 2 integer numbers: ";
	cin >> number;

	first_digit = number / 100;
	last_digit = number % 10;

	if (first_digit == last_digit)
	{
		cout << "The number " << number << " is a palindrome!";
	}
	else
	{
		cout << "The number " << number << " is not a palindrome!";
	}

	return 0;
}