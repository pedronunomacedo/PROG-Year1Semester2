# include<iostream>
# include <cmath>
using namespace std;

int main()
{
	int n;
	cout << "Input the number of first numbers do you want to calculate: ";
	cin >> n;

	float res{ 0 };
	int i{ 0 };
	while (i < n)
	{
		res += (float) 4 * pow(-1,i) / (2 * i + 1);

		i++;
	}

	cout << "The result of the first " << n << " number is " << res << " .";

	return 0;
}