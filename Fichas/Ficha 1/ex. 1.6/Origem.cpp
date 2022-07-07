# include <iostream>
# include <cmath>
using namespace std;


int main()
{
	double x1{ 0 }, x2{ 0 }, x3{ 0 }, y1{ 0 }, y2{ 0 }, y3{ 0 }, a{ 0 }, b{ 0 }, c{ 0 }, s{ 0 }, area{ 0 };
	char sep;

	cout << "Input the coordinates of the 3 vertices of a triangle ( (x1,y1),(x2,y2),(x3,y3) ): ";
	cin >> sep >> x1 >> sep >> y1 >> sep >> sep >> sep >> x2 >> sep >> y2 >> sep >> sep >> sep >> x3 >> sep >> y3 >> sep;

	a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	b = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
	c = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));

	s = ((a + b + c) / 2); 

	area = sqrt( s * (s - a) * (s - b) * (s - c) );

	if ((x1 == 0 && x2 == 0 && x3 == 0) || (y1 == 0 && y2 == 0 && y3 == 0) || (x1 / y1 == x2 / y2 && x2 / y2 == x3 / y3))
	{
		cout << "The points are collinear, so they can't build a triangle!";
	}
	else
		cout << "The area of the triangle is " << area << " .";
	

	return 0;
}