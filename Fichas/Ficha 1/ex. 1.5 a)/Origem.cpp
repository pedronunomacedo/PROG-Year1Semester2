# include <iostream>
using namespace std;

int main() {
	int days, hours, minutes, seconds, hour_1, minute_1, second_1, hour_2, minute_2, second_2;
	days = 0;
	hours = 0;
	minutes = 0;
	seconds = 0;
	hour_1 = 0;
	minute_1 = 0;
	second_1 = 0;
	hour_2 = 0;
	minute_2 = 0;
	second_2 = 0;

	cout << "Time1 (hours minutes seconds) ? ";
	cin >> hour_1 >> minute_1 >> second_1;
	cout << "Time1 (hours minutes seconds) ? ";
	cin >> hour_2 >> minute_2 >> second_2;

	seconds = second_1 + second_2;
	minutes = minute_1 + minute_2;
	hours = hour_1 + hour_2;

	if (seconds > 60) {
		minutes = minutes + 1;
		seconds = seconds - 60;
	}

	if (minutes > 60) {
		hours = hours + 1;
		minutes = minutes - 60;
	}

	if (hours > 24){
		hours = hours - 24;
		days = days + 1;
	}

	cout << "Time1 + Time2 = " << days << " days, " << hours << " hours, " << minutes << " minutes and "<< seconds << " seconds";

	return 0;
}