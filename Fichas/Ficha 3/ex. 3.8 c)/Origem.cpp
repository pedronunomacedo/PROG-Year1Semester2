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
	int num1, num2, num3, num4, numerador, denominador;
	char op1, op2, op3,par_a,par_f;
	
	cout << "Input the fraction you want to calculate ( (...)/(...) ): ";
	cin >> par_a >>  num1 >> op1 >> num2 >> par_f >> op2 >> par_a >> num3 >> op3 >> num4 >> par_f;

	if (op1 == '+')
	{
		numerador = num1 + num2;
	}
	else if (op1 == '-')
	{
		numerador = num1 - num2;
	}
	else if (op1 == '*')
	{
		numerador = num1 * num2;
	}
	else if (op1 == '/')
	{
		numerador = num1 / num2;
	}

	if (op3 == '+')
	{
		denominador = num3 + num4;
	}
	else if (op3 == '-')
	{
		denominador = num3 - num4;
	}
	else if (op3 == '*')
	{
		denominador = num3 * num4;
	}
	else if (op3 == '/')
	{
		denominador = num3 / num4;
	}

	cout << "The result is " << numerador / GCD(numerador, denominador) << "/" << denominador / GCD(numerador, denominador);

}