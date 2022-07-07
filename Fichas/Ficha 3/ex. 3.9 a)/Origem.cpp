# include<iostream>
using namespace std;


bool LeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	int year;
	cout << "Input a year: ";
	cin >> year;

	if (LeapYear(year))
	{
		cout << "The year " << year << " is a leap year!";
	}
	else
	{
		cout << "The year " << year << " is not a leap year!";
	}
}