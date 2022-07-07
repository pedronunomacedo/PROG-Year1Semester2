# include <iostream>
using namespace std;

int main()
{
	double a, b, c, d, e, f, x, y;
	cout << "a ? ";
	cin >> a;
	cout << "b ? ";
	cin >> b;
	cout << "c ? ";
	cin >> c;
	cout << "d ? ";
	cin >> d;
	cout << "e ? ";
	cin >> e;
	cout << "f ? ";
	cin >> f;

	if (((-a / b) == (-d / e)) && ((c / b) == (b / e)))
	{
		cout << "inconsistent system";
	}
	else
	{
		if (((-a / b) == (-d / e)) && ((c / b) != (b / e)))
		{
			cout << "impossible system";
		}
		else
		{
			x = (c * e - b * f) / (a * e - b * d);
			y = (a * f - c * d) / (a * e - b * d);
			cout << " x = " << x << " and y = " << y << " . ";
		}
	}
	return 0;
}