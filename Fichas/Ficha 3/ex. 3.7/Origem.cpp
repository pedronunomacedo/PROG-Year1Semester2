# include<iostream>
using namespace std;


bool readInt(int& x)
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(10000, '\n');
		return false;
	}
	else if (cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(10000, '\n');
		return false;
	}
	else
	{
		cin.clear();
		cin.ignore(10000, '\n');
		return true;
	}
}


int main()
{
	bool is_valid;
	int x;

	cout << "Input an integer number: " << endl;
	cin >> x;
	is_valid = readInt(x);
	while (1)
	{
		if (is_valid == true)
		{
			cout << "The integer " << x << " is valid!" << endl;
			break;
		}
		else
		{
			cout << "The integer is not valid!" << endl;
			cout << "Please input another integer number: " << endl;
			cin >> x;
			is_valid = readInt(x);
		}
	}
}