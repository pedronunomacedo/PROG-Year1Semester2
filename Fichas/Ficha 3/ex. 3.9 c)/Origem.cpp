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


int DayOfTheWeek(int d, int m, int y)
{
	int s, a, c{ 0 };
	double ds;
	
	s = y / 100;  // 2 primeiros digitos (20)
	a = y % (10 * 10);  // 2 últimos dígitos (21)
	
	if (LeapYear(y))
	{
		if (m == 1)
			c = 6;
		else if (m == 2)
			c = 2;
		else if (m == 3)
			c = 3;
		else if (m == 4)
			c = 6;
		else if (m == 5)
			c = 1;
		else if (m == 6)
			c = 4;
		else if (m == 7)
			c = 6;
		else if (m == 8)
			c = 2;
		else if (m == 9)
			c = 5;
		else if (m == 10)
			c = 0;
		else if (m == 11)
			c = 3;
		else if (m == 12)
			c = 5;
	}
	else
	{
		switch (m) 
		{
			case 1: c = 0;
			case 2: c = 3;
			case 3: c = 3;
			case 4: c = 6;
			case 5: c = 1;
			case 6: c = 4;
			case 7: c = 6;
			case 8: c = 2;
			case 9: c = 5;
			case 10: c = 0;
			case 11: c = 3;
			case 12: c = 5;
		}
		/*if (m == 1)
			c = 0;
		else if (m == 2)
			c = 3;
		else if (m == 3)
			c = 3;
		else if (m == 4)
			c = 6;
		else if (m == 5)
			c = 1;
		else if (m == 6)
			c = 4;
		else if (m == 7)
			c = 6;
		else if (m == 8)
			c = 2;
		else if (m == 9)
			c = 5;
		else if (m == 10)
			c = 0;
		else if (m == 11)
			c = 3;
		else if (m == 12)
			c = 5;*/
	}

	ds = (floor(5 * a / 4) + c + d - 2*(s % 4) + 7);

	return ds;
}


int main()
{
	int day, month, year, dayofweek;
	char sep;

	cout << "Input a date (dd/mm/yyyy): ";
	cin >> day >> sep >> month >> sep >> year;  // (11/12/2021)

	dayofweek = DayOfTheWeek(day, month, year);

	if (dayofweek == 0)
		cout << "Today is Saturday!";
	else if (dayofweek == 1)
		cout << "Today is Sunday!";
	else if (dayofweek == 2)
		cout << "Today is Monday!";
	else if (dayofweek == 3)
		cout << "Today is Tuesday!";
	else if (dayofweek == 4)
		cout << "Today is Wednesday!";
	else if (dayofweek == 5)
		cout << "Today is Thursday!";
	else if (dayofweek == 6)
		cout << "Today is Friday!";
}