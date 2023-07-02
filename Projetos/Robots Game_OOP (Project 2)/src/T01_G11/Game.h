//T01_G11
#pragma once
#include<iostream>
#include<fstream>
#include <string>
#include<vector>
#include "Maze.h"
#include "Robot.h"
#include "Player.h"
#include "Post.h"
using namespace std;

class Game {
public:
	Game(); // Incialize the variables
	Game(const string & filename); // Build the vector of robots, find the inicial coordinates of the player and define the size of the maze
	int NumMaze(); // Ask for the number of the maze (user input) and check if it's a valid or not (it cannot have letters and has to be a number between 0 and 99). Return the intended maze number
	string MazeDirectory(int numMaze); // Receive the number of the maze and return it's directory (MAZE_XX.TXT)
	bool ValidateDirectory(string mazeDirectory); // Return true if the maze file exists and false otherwise
	string MazeDirectoryWinners(int numMaze); // Return the directory of the maze winners file
	bool Winners(int numMaze); // Verify if the maze winners file exists (return true if exists, false otherwise). And print hte maze winners file
	bool IsValid(); // Verify if the movement of the player is a valid one.
	bool Play(string mazeDirectory); // Start the game. Return true of the player wins or false otherwise
	void MoveRobots(); // Change the coordinates of the robot
	bool PlayerCollide(); // Verify if the player collided with a post or a robot. Return true if it collided and false otherwise
	void RobotCollide(); // Verify if the robot collided with the player, a post or another robot. Return true if it collided and false otherwise
	bool PlayerEscape(); // Verify if the player exited the maze throught the gate ('O')
	string GenerateWinnersLine(string name, string elapsedTime); // Return the new line containing the name of the player and his time
	void UpdateWinnersFile(string winnersLine, int numMaze, int elapsedTime); // Add the new line to the winners file
private:
	Maze maze;
	Player player;
	Robot robot;
	Post post;
	vector<Robot> RobotsVector;	vector<string> vectorWinnersFile;
	int numLine, positionOccupied, sizeVectorWinnersFile;
	string lineMaze, movement, winnersFileLine, numberToCompare;
	void showGameDisplay(); // Print the current maze
	bool valid;
};