//T01_G11
#include "../include/Robot.h"

Robot::Robot() {  }

Robot::Robot(int row, int col, char symbol)
{
	rowRobot = row;
	colRobot = col;
	this-> symbol = symbol;
	robotCounter++;
	id = robotCounter;
}


int Robot::getID()
{
	return id;
}

char Robot::getSymbol()
{
	return symbol;
}

int Robot::getRow()
{
	return rowRobot;
}

int Robot::getCol()
{
	return colRobot;
}

bool Robot::isAlive()
{
	if (symbol == 'r') {return false; }
	else if (symbol == 'R') { return true; }
}

void Robot::setAsDead()
{
	symbol = 'r';
}

void Robot::Move(int colPlayer, int rowPlayer)
{
	beforeRowRobot = rowRobot; beforeColRobot = colRobot;
	if (colPlayer == colRobot && rowPlayer < rowRobot) { rowRobot--; }
	else if (colPlayer == colRobot && rowPlayer > rowRobot) { rowRobot++; }
	else if (rowPlayer == rowRobot && colPlayer < colRobot) { colRobot--; }
	else if (rowPlayer == rowRobot && colPlayer > colRobot) { colRobot++; }
	else if (colPlayer < colRobot && rowPlayer < rowRobot) { colRobot--; rowRobot--; }
	else if (colPlayer > colRobot && rowPlayer < rowRobot) { colRobot++; rowRobot--; }
	else if (colPlayer < colRobot && rowPlayer > rowRobot) { colRobot--; rowRobot++; }
	else if (colPlayer > colRobot && rowPlayer > rowRobot) { colRobot++; rowRobot++; }
}

void Robot::Reset()
{
	rowRobot = beforeRowRobot;
	colRobot = beforeColRobot;
}
