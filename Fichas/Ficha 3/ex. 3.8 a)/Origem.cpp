# include<iostream>
using namespace std;


bool readFraction(int numerator, int denominator)
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(10000, '\n');
		return false;
	}
	else
	{
		return true;
	}
}


int main()
{
	int num1, num2;
	char div;
	cout << "Please input the fraction you want to calculate (num1 / num2): ";
	cin >> num1 >> div >> num2;

	if (div == '/')
	{
		readFraction(num1, num2);
	}
	else
	{
		readFraction(0, 0);
	}
}