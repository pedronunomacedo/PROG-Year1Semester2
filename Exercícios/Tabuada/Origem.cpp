# include <iostream>
using namespace std;

int main()
{
	int num{ 2 }, j{ 10 };

	while (num < 10)
	{
		int i{ 1 };
		while (i < j)
		{
			cout << num << " * " << i << " = " << num * i << endl;
			i = i + 1;
		}
		if (num < 9)
		{
			cout << "--------" << endl;
		}
		num = num + 1;
	}
}