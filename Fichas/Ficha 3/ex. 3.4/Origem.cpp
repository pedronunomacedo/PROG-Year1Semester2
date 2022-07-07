# include<iostream>
using namespace std;


double rounded(float x, unsigned n)
{
	return floor(x * pow(10,n) + 0.5) / pow(10,n);
}


int main()
{
	float x;
	unsigned n;

	cout << "Input a number: ";
	cin >> x;
	cout << "Input how many decimal places do you want: ";
	cin >> n;

	cout << "The number rounded to " << n << " decimal places is " << rounded(x, n);

	return 0;
}