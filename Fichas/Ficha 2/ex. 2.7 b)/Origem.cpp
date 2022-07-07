# include<iostream>
# include<cmath>
using namespace std;

int main()
{
	cout << "The prime numbers until 1000 are: " << endl;

	for (int num = 2; num < 1000; num++)
	{
		bool IS_PRIME = true;

		for (int i = 2; i < num; i++)
		{
			if (num % i == 0)
			{
				IS_PRIME = false;
				break;
			}
		}

		if (IS_PRIME == true)
		{
			cout << num << endl; 
		}
	}

	return 0;
}