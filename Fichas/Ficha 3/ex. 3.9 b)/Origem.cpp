# include<iostream>
using namespace std;

bool LeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return true;  // Leap Year
	}
	else
	{
		return false;
	}
}


int NumDays(int month, int year)
{
	int days;

	if (month == 2)
	{
		if (LeapYear(year))
			days = 29;
		else
		{
			days = 28;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		days = 30;
	}
	else
	{
		days = 31;
	}
	return days;
}


int main()
{
	int month, year;
	cout << "Input the month and the year: ";
	cin >> month >> year;

	cout << "The number of days of the month corresponding to the number " << month << " of the year " << year << " is " << NumDays(month, year);
}