# include<iostream>
# include<iomanip>
using namespace std;

int main() {
	int n = 1, grade, sum = 0; float average;
	cout << "Grade " << n << "? "; cin >> grade;
	while ((grade >= 0) && (grade <= 20)) // gama de classificações possíveis é [0..20]
	{
		sum = sum + grade; n++;
		cout << "Grade " << n << "? "; cin >> grade;
	};
	average = sum / n; cout << "Average = " << fixed << setprecision(1) << average << endl;
	return 0;
}