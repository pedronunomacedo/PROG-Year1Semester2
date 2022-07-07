# include <iostream>
using namespace std;

int main()
{
	double a, b, res, int_min, int_max;
	cout << "First number: ";
	cin >> a;
	cout << "Second number: ";
	cin >> b;
	
	res = a + b;

	if (a > b)
	{
		int_min = b;
		int_max = a;
	}
	else
	{
		int_min = a;
		int_max = b;
	}

	if (res < int_min)
	{
		cout << endl << "sum underflow" << endl;
	}
	else
	{
		if (res > int_max)
		{
			cout << endl << "sum overflow" << endl;
		}
		else
		{
			if (b < 0)
			{
				cout << endl << a << " + (" << b << ") = " << res << endl;
			}
			else
			{
				cout << endl << a << " + " << b << " = " << res << endl;
			}
		}
	}
	return 0;
}