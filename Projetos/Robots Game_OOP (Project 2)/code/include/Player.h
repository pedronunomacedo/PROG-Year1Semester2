//T01_G11
#pragma once
#include<iostream>
#include<string>
using namespace std;

class Player {
public:
	Player();
	Player(int row, int col); // Inicialize the coordinates of the player
	int GetRow(); // Return the row of the player
	int GetCol(); // Return the col of the player
	string Movement(); // Ask and verify the movement inputed
	bool isAlive(); // Return true if player is alive, or false otherwise
	void SetRowColSymbol(int row, int col, char symbol); // Update the row, col and the symbol of the player
	void Move(string movement); // Move the player
	void Reset(string movement); // Undo the player movement
	char GetSymbol(); // Return the symbol of the player ('H' or 'h')
	void setAsDead(); // If the player dies, update his state
private:
	int playerRow, playerCol, numLine;
	char playerSymbol;
	string movement, lineMaze;
};