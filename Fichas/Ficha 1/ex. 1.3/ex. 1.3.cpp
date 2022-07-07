# include <iostream>
# include <cmath>
using namespace std;

int main() {
	float density, radius, M;
	double pi1 = M_PI;
	cout << "Input a number for the mass of the material, in kg/m^3: ";
	cin >> density;
	cout << "Input a number for the radius of the material, in m: ";
	cin >> radius;
	M = (4 * density * M_PI * pow(radius, 3)) / 3;
	cout << "The value of M is " << M << ".";

	return 0;
}