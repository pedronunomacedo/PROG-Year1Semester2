# include <iostream>
# include <iomanip>
using namespace std;

int main()
{
	float A, B, C, mean;
	cout << "Please input 3 integer numbers \n";
	cout << "A ? ";
	cin >> A;
	cout << "B ? ";
	cin >> B;
	cout << "C ? ";
	cin >> C;
	mean = (A + B + C) / 3;
	cout.precision(3);
	cout << "mean = " << setprecision(5) << mean << endl;
	cout << "A-mean = " << A - mean << endl;
	cout << "B-mean = " << B - mean << endl;
	cout << "C-mean = " << C - mean;
	return 0;
}