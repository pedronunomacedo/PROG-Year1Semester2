# include<iostream>
using namespace std;

int main()
{
	double smallest{ 10 }, largest{ 0 }, sum_power{ 0 }, sum{ 0 }, mean, stdev;
	int len{ 0 };
	bool not_zero = true;

	while(not_zero)
	{
		double number;
		cout << "Number ? ";
		cin >> number;

		if (number == 0)
		{
			not_zero = false;
		}
		else
		{
			if (number < smallest)
				smallest = number;
			if (number > largest)
				largest = number;

			sum += number;
			sum_power += pow(number, 2);
			len += 1;
		}


	}

	mean = sum / len;
	stdev = sqrt((sum_power - 2 * mean * sum + len * pow(mean, 2)) / len);

	cout << endl <<"The sum of all numbers is " << sum << ", the mean is " << mean << ", the standard deviation is " << stdev << ", the smallest number is " << smallest << " and the largest number is " << largest << " .";
	return 0;
}