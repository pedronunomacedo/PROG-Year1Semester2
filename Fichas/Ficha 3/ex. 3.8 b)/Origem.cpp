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


bool readFraction(int numerator, int denominator)
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(10000, '\n');
		return false;
	}
	else
	{
		return true;
	}
}


int main()
{
	int num1, num2;
	char div;
	cout << "Please input the fraction you want to calculate (num1 / num2): ";
	cin >> num1 >> div >> num2;

	if (div == '/')
	{
		readFraction(num1,num2);
		int numerador = num1 / GCD(num1, num2);
		int denominador = num2 / GCD(num1, num2);
		if (denominador == 1)
		{
			cout << "The fraction reduced is " << numerador << "." << endl;
		}
		else
		{
			cout << "The fraction reduced is " << numerador << "/" << denominador << "." << endl;
		}
	}
	else
	{
		readFraction(0,0);
	}
}