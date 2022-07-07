# include <iostream>
using namespace std;

int main()
{
	double a, b, c;
	cout << " Input the 3 sides of the triangle: " << endl;
	cout << "First side: ";
	cin >> a;
	cout << "Second side: ";
	cin >> b;
	cout << "Third side: ";
	cin >> c;

	double min1, min2, max;
	if (a < b)
	{
		if (b < c)
		{
			min1 = a;
			min2 = b;
			max = c;
		}
		else
			min1 = a;
			min2 = c;
			max = b;
	}
	else
		if (b < c)
		{
			if (a < c)
			{
				min1 = b;
				min2 = a;
				max = c;
			}
			else
				min1 = b;
				min2 = c;
				max = a;
		}

	double lenght;
	if (min1 + min2 <= max || a <= 0 || b <= 0 || c <= 0)
	{
		cout << "It's not possible to calculate the lenght!";
	}
	else
		lenght = a + b + c;
		cout << "The lenght of the triangle is " << lenght;

	return 0;
}