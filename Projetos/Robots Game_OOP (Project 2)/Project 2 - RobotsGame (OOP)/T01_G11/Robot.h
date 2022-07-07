//T01_G11
#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

class Robot {
public:
	Robot();
	Robot(int row, int col, char symbol); // Inicialize one robot
	int getID(); // Return the ID of the robot
	char getSymbol(); // get char representation of robot (R if alive, r if dead)
	int getRow(); // Return the row of the robot
	int getCol(); // Return the col of the robot
	bool isAlive() ; // Return true if the robot is alive, false otherwise
	void setAsDead(); // If the robot dies, update is state
	void Move(int colPlayer, int rowPlayer); // Move the robot
	void Reset(); // Undo the movement of the robot

private:
	int robotCounter, id, numLine, rowRobot, colRobot, beforeRowRobot, beforeColRobot;
	bool alive;
	string lineMaze;
	char symbol;
};