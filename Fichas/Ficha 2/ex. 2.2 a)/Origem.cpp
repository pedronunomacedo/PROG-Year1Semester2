# include <iostream>
using namespace std;

int main() {
	int i{ 0 }, z{ 0 }, s, b{ 0 }, v, smallest, biggest;
	float numbers[3];

	cout << "Input 3 numbers : ";
	for (i; i < 3; ++i) {
		cin >> numbers[i];
	}


	char small = '9';
	char large = '0';

	for (int j = 0; j < 3; j++)
	{
		if (numbers[j] > large)
			large = numbers[j];
	}

	for (int j = 0; j < 2; j++)
	{
		if (numbers[j] < small)
			small = numbers[j];

	cout << "The smallest number in the array is " << small << " and the largest one is " << large << " .";

	return 0;
}