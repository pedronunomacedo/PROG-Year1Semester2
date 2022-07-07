# include<iostream>
using namespace std;

int main()
{
	int len;
	double smallest{ 10 }, largest{ 0 }, sum_power{ 0 }, sum{ 0 }, mean, stdev;

	cout << "How many numbers do you want to input? ";
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		double number;
		cout << "Number ? ";
		cin >> number;

		if (number < smallest)
			smallest = number;
		if (number > largest)
			largest = number;

		sum += number;
		sum_power += pow(number, 2);
	}

	mean = sum / len;
	stdev = sqrt((sum_power - 2 * mean * sum + len * pow(mean, 2)) / len);

	cout << "The sum of all numbers is " << sum << ", the mean is " << mean << ", the standard deviation is " << stdev << ", the smallest number is " << smallest << " and the largest number is " << largest << " .";
	return 0;
}