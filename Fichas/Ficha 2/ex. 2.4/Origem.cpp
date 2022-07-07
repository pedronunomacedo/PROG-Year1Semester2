# include <iostream>
using namespace std;

int main()
{
	double weight, cost{ 0 };
	cout << "Input the weight of the merchandise (g): ";
	cin >> weight;

	if (weight < 0)
	{
		cout << "Invalid weight!";
	}
	else
	{
		if (weight == 0)
		{
			cost = 0;
		}
		else
		{
			if (weight < 500 && weight == 500)
			{
				cost = 5;
			}
			else
			{
				if (weight == 501 && weight > 501 && weight < 1000 && weight == 1000)
				{
					double additional_weight = weight - 500;
					cost = 5 + (additional_weight * (1.5 / 100));
				}
				else
				{
					double addicional_weight = weight - 1000;
					cost = 12.5 + (addicional_weight * (5.0 / 250));
				}
			}
		}
	}

	cout << "The cost of transportaion is " << cost << " .";
	return 0;
}