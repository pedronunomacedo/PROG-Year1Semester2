# include <iostream>
# include <ctime>
using namespace std;


int main()
{
	srand(time(NULL));

	int operand1, operand2, result, answer;
	double t1, t2;
	double tResposta;

	operand1 = rand() % 8 + 2;
	operand2 = rand() % 8 + 2;

	result = operand1 * operand2;

	cout << operand1 << " * " << operand2 << " = ";
	t1 = time(NULL);
	cin >> answer;
	t2 = time(NULL);

	tResposta = t2 - t1;

	if (answer != result)
		cout << endl << "Very bad" << endl;
	else if (tResposta < 5)
		cout << endl << "Good" << endl;
	else if (tResposta > 5 && tResposta <= 10)
		cout << endl << "Satisfactory" << endl;
	else
		cout << endl << "Insufficient" << endl;

	return 0;
}