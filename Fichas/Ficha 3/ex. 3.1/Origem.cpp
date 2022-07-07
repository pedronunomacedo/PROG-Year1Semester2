# include<iostream>
using namespace std;

double distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double s, area, a, b, c;

	a = distance(x1, y1, x2, y2);
	b = distance(x1, x3, y1, y3);
	c = distance(x2, x3, y2, y3);

	s = (a + b + c) / 2;

	area = sqrt(s * (s - a) * (s - b) * (s - c));

	return area;
}


int main()
{
	double x1, x2, x3, y1, y2, y3;
	char sep;
	cout << "Input the coordinates of the 3 vertices of a triangle ( (x1,y1),(x2,y2),(x3,y3) ): ";
	cin >> sep >> x1 >> sep >> y1 >> sep >> sep >> sep >> x2 >> sep >> y2 >> sep >> sep >> sep >> x3 >> sep >> y3 >> sep;

	if ((x1 == 0 && x2 == 0 && x3 == 0) || (y1 == 0 && y2 == 0 && y3 == 0) || (x1 / y1 == x2 / y2 && x2 / y2 == x3 / y3))
	{
		cout << "The points are collinear, so they can't build a triangle!";
	}
	else
		cout << "The area of the triangle is " << area(x1,y1,x2,y2,x3,y3) << " .";
	
	return 0;

}