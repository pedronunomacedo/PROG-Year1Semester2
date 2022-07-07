# include <iostream>
using namespace std;

int main()
{
	double a, b, c, max, min, meio;

	cout << "Insira 3 numeros: ";
	cin >> a >> b >> c;

	if (a > b)
		if (a > c)
			if (c > b)
			{
				max = a;
				min = b;
				meio = c;
			}
			else
			{
				max = a;
				min = c;
				meio = b;
			}


		else
		{
			max = c;
			min = b;
			meio = a;
		}
	else
		if (b > c)
			if (a > c)
			{
				max = b;
				min = c;
				meio = a;
			}
			else
			{
				max = b;
				min = a;
				meio = c;
			}
		else
		{
			max = c;
			min = a;
			meio = b;
		}

	cout << "Sequencia por ordem decrescente: " << max << ' ' << meio << ' ' << min << endl;

	return 0;
}