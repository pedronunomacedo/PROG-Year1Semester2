#include <iostream>

using namespace std;

int contaDigitos(int number)
{
	int contador = 1;

	while (number >= 10)
	{
		contador++;
		number = number / 10;
	}

	return contador;
}

int main20()
{
	int n;
	int dms;
	int dMs;
	bool capicua = true;

	cout << "Insira um numero: ";
	cin >> n;

	dMs = n / pow(10, (contaDigitos(n) - 1));
	dms = fmod(fmod(n, pow(10, (contaDigitos(n) - 1))), pow(10, (contaDigitos(n) - 2)));
	n = n / 10 - n / pow(10, (contaDigitos(n) - 1)) * (contaDigitos(n) - 1);

	if (dms != dMs)
		capicua = false;

	while (n > 10)
	{

		n = n / 10 - n / pow(10, (contaDigitos(n) - 1)) * (contaDigitos(n) - 1);
		dMs = n / pow(10, (contaDigitos(n) - 1));
		dms = fmod(fmod(n, pow(10, (contaDigitos(n) - 1))), pow(10, (contaDigitos(n) - 2)));

		if (dms != dMs)
		{
			capicua = false;
			break;
		}
	}

	if (capicua == true)
		cout << "O numero e uma capicua" << endl;
	else
	{
		cout << "O numero nao e uma capicua" << endl;
		cout << dms;
		cout << dMs;
	}


	return 0;

}