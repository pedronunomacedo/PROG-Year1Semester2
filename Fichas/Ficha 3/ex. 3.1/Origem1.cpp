#include <iostream>

using namespace std;


double distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double s, a, b, c, vArea;

	a = distance(x1, y1, x2, y2);
	b = distance(x1, y1, x3, y3);
	c = distance(x2, y2, x3, y3);
	s = (a + b + c) / 2;

	vArea = sqrt(s * (s - a) * (s - b) * (s - c));

	return vArea;

}



int main1()
{
	double x1, y1, x2, y2, x3, y3;

	cout << "Insira coordenadas de 3 pontos" << endl;
	cout << "x1 y1 ? ";
	cin >> x1 >> y1;
	cout << "x2 y2 ? ";
	cin >> x2 >> y2;
	cout << "x3 y3 ? ";
	cin >> x3 >> y3;

	cout << "Area = " << area(x1, y1, x2, y2, x3, y3) << endl;

	return 0;
}