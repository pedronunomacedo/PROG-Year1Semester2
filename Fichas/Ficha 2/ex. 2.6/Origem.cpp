# include <iostream>
# include <iomanip>
using namespace std;

int main()
{
	float n, q, j;
	cout << "Years: ";
	cin >> n;
	cout << "Amount deposited ($): ";
	cin >> q;
	cout << "Anual interest rate (%): ";
	cin >> j;

	float anos = n;
	float montante_atual = q;
	while (anos > 0)
	{
		montante_atual = montante_atual * (1 + j / 100);
		anos--;
	}

	float win = montante_atual - q;
	cout.precision(4);
	cout << "Ganhou " << fixed << setprecision(2) << win << " $ from the bank.";

	return 0;
}