# include<iostream>
using namespace std;


double GCD(double n1, double n2)
{
	double smallest, largest, menor{ 0 };

	if (n1 == n2)
	{
		return n1;
	}
	else if (n1 == 0 || n2 == 0)
	{
		if (n1 == 0)
			return n2;
		else
			return n1;
	}
	else
	{
		if (n1 > n2)
		{
			smallest = n2;
			largest = n1;
		}
		else
		{
			smallest = n1;
			largest = n2;
		}

		while (smallest != largest)
		{
			menor = smallest;
			largest = largest - smallest;
			if (largest <= smallest)
			{
				smallest = largest;
				largest = menor;
			}
		}

		return menor;
	}

}



int main()
{
	double n1, n2, smallest, largest;

	cout << "Input two numbers: ";
	cin >> n1 >> n2;

	cout << endl << "The greatest common divisor between " << n1 << " and " << n2 << " is " <<  GCD(n1, n2) << ".";

	return 0;
}