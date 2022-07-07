# include<iostream>
using namespace std;

int main()
{
	int seq, sum = 0, smallest = 10, largest = 0, len = 0, n, sum_power = 0;
	double stdev, mean;

	while (true)
	{
		cout << "Insert number of the sequence (CTRL-Z to end): ";
		cin >> n;

		if (cin.fail())  // Testa se o último cin falhou. Caso tenha falhado (cin.fail() = true), caso contrário (cin.fail() = false).
		{
			if (cin.eof())  //  Testa se a operação cin está a tentar acabar de ler o ficheiro. Isto é, se o cin for válido (cin.eof() = true).
				break;
			else
			{
				cin.clear();
				cin.ignore(100000, '\n');
				cout << "Invalid number, please try again!" << endl;
				continue;
			}
		}
		sum += n;
		if (n > largest)
			largest = n;
		if (n < smallest)
			smallest = n;
		sum_power += pow(n, 2);
		len += 1;
	}
	mean = (double)sum / len;

	stdev = sqrt((sum_power - 2 * sum * mean + pow(mean, 2) * len) / len);
	cout << "sum = " << sum << endl << "mean = " << mean << endl << "standard deviation = " << stdev << endl << "smallest = " << smallest << endl << "largest = " << largest;

	return 0;
}