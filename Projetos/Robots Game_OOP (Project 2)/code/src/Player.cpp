//T01_G11
#include "../include/Player.h"

Player::Player() { }

Player::Player(int row, int col)
{
	playerRow = row;
	playerCol = col;
	playerSymbol = 'H';
	numLine = -1;
}

int Player::GetRow()
{
	return playerRow;
}

int Player::GetCol()
{
	return playerCol;
}


string Player::Movement() {
	cout << " ---------------------" << endl;
	cout << " |   Q  | W ^ |  E   |" << "  { Q: left superior diagonal || W: up || E: right superior diagonal }" << endl;
	cout << " |~~~~~~|~~~~~|~~~~~~|" << endl;
	cout << " | <- A |  S  | D -> |" << "  { A: left || S: stay in same position || D: right }" << endl;
	cout << " |~~~~~~|~~~~~|~~~~~~|" << endl;
	cout << " |   Z  | X v |  C   |" << "  { Z: left inferior diagonal || X: down || C: right inferior diagonal }" << endl;
	cout << " ---------------------" << endl;
	cout << "    CTRL + Z -> Exit " << endl;
	cout << endl << " What is the movement you want to do? : ";

	while (!(cin >> movement) || (movement != "W" && movement != "w" && movement != "X" && movement != "x" && movement != "A" && movement != "a" && movement != "D" && movement != "d" && movement != "Q" && movement != "q" && movement != "E" && movement != "e" && movement != "Z" && movement != "z" && movement != "C" && movement != "c" && movement != "S" && movement != "s")) {
		if (cin.eof()) { exit(1); }
		else {
			cin.clear(); cin.ignore(1000, '\n');
			cout << endl << " Invalid input! Please input another valid option: ";
		}
	} cout << endl;

	return movement;
}

bool Player::isAlive()
{
	if (playerSymbol == 'h') { return false; }
	else { return true; }
}

void Player::SetRowColSymbol(int row, int col, char symbol)
{
	playerRow = row; 
	playerCol = col;
	playerSymbol = symbol;
}

void Player::Move(string movement)
{
	if (movement == "Q" || movement == "q") {
		playerCol -= 1; playerRow -= 1;
	}
	else if (movement == "A" || movement == "a") {
		playerCol -= 1;
	}
	else if (movement == "Z" || movement == "z") {
		playerCol -= 1; playerRow += 1;
	}
	else if (movement == "W" || movement == "w") {
		playerRow -= 1;
	}
	else if (movement == "X" || movement == "x") {
		playerRow += 1;
	}
	else if (movement == "E" || movement == "e") {
		playerCol += 1; playerRow -= 1;
	}
	else if (movement == "D" || movement == "d") {
		playerCol += 1;
	}
	else if (movement == "C" || movement == "c") {
		playerCol += 1; playerRow += 1;
	}
}

void Player::Reset(string movement)
{
	if (movement == "Q" || movement == "q") {
		playerCol += 1; playerRow += 1;
	}
	else if (movement == "A" || movement == "a") {
		playerCol += 1;
	}
	else if (movement == "Z" || movement == "z") {
		playerCol += 1; playerRow -= 1;
	}
	else if (movement == "W" || movement == "w") {
		playerRow += 1;
	}
	else if (movement == "X" || movement == "x") {
		playerRow -= 1;
	}
	else if (movement == "E" || movement == "e") {
		playerCol -= 1; playerRow += 1;
	}
	else if (movement == "D" || movement == "d") {
		playerCol -= 1;
	}
	else if (movement == "C" || movement == "c") {
		playerCol -= 1; playerRow -= 1;
	}
}

char Player::GetSymbol()
{
	return playerSymbol;
}

void Player::setAsDead()
{
	playerSymbol = 'h';
}
