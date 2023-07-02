//T01_G11
#pragma once

class Post {
public:
	Post();
	Post(int row, int col, char type); // Inicialize each post
	int getRow() const; // Return the row of the post
	int getCol() const; // Retrun the col of the post
	char getSymbol() const; // get char representation of the post( '+', '*' or 'O')
	void setSymbol(char type); // Set symbol of the post
	bool isElectrified() const; // Return true if symbol = '*', or false if symbol = '+' or symbol = 'O'
private:
	int rowPost, colPost;
	char typePost; // '*' - electrified; '+'- non-electrified
};