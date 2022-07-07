//T01_G11
#include "Post.h"

Post::Post() { }

Post::Post(int row, int col, char type)
{
	rowPost = row;
	colPost = col;
	typePost = type;
}

int Post::getRow() const
{
	return rowPost;
}

int Post::getCol() const
{
	return colPost;
}

char Post::getSymbol() const
{
	return typePost;
}

void Post::setSymbol(char type)
{
	typePost = type;
}

bool Post::isElectrified() const
{
	if (typePost == '*') { return true; }
	else if (typePost == '+' || typePost == 'O') { return false; }
}
