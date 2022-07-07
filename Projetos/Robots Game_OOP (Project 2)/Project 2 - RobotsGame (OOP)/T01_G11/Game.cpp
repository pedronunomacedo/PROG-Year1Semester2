//T01_G11
#include "Game.h"

Game::Game() {
	numLine = 0;
	positionOccupied = 0;
}

Game::Game(const string & filename)
{
	ifstream mazeFile; mazeFile.open(filename);

	// Build the robots vector, find the incial coordinates of the player and define the size of the maze
	while (!mazeFile.eof()) {
		getline(mazeFile, lineMaze);
		for (int i = 0; i < lineMaze.size(); i++) {
			if (lineMaze[i] == 'r') { Robot robot(numLine, i, 'r'); RobotsVector.push_back(robot); }
			else if (lineMaze[i] == 'R') { Robot robot(numLine, i, 'R'); RobotsVector.push_back(robot); }
			else if (lineMaze[i] == 'H') { player.SetRowColSymbol(numLine, i, 'H'); }
		}
		numLine++;
	}

	maze.setRowCol(numLine-1, lineMaze.size()); // Set the size of the maze
	mazeFile.close();
}

int Game::NumMaze() {
	string numMaze; bool invalidInput{ true };
	cout << endl << " Please input a number for the maze (0 to Go Back): "; cin >> numMaze; // Ask the number of the maze

	// Keep asking the number of the maze, until the number is a valid input
	while (invalidInput) {

		for (int c = 0; c < numMaze.size(); c++) { // Verify if the numbers contains only digits
			if (!isdigit(numMaze[c])) {
				cin.clear(); cin.ignore(1000, '\n');
				invalidInput = false;
				break;
			}
		}
		if (invalidInput && stoi(numMaze) >= 0 && stoi(numMaze) <= 99) { break; } // If the number is a valid input and an existing maze
		if (!invalidInput || stoi(numMaze) > 99) {
			cout << endl << " Invalid input! Please input another number (use only numbers): "; cin >> numMaze;
			invalidInput = true;
		}		
	} cout << endl;

	return stoi(numMaze);
}

string Game::MazeDirectory(int numMaze) { // Receive the number of the maze and return it's directory (MAZE_XX.TXT).
	string mazeDirectory;

	if ((numMaze >= 10 && numMaze <= 99) || to_string(numMaze) == "00" || to_string(numMaze) == "01" || to_string(numMaze) == "02" || to_string(numMaze) == "03" || to_string(numMaze) == "04" || to_string(numMaze) == "05" || to_string(numMaze) == "06" || to_string(numMaze) == "07" || to_string(numMaze) == "08" || to_string(numMaze) == "09") {
		mazeDirectory = "MAZE_" + to_string(numMaze) + ".TXT";
	}
	else if (numMaze > 0 && numMaze <= 9) {
		mazeDirectory = "MAZE_0" + to_string(numMaze) + ".TXT";
	}
	return mazeDirectory;
}

bool Game::ValidateDirectory(string mazeDirectory) {
	bool mazeExist{ true };

	ifstream myFile(mazeDirectory);
	if (!myFile.is_open()) { // Try to open the maze file
		mazeExist = false;
	}
	myFile.close();
	return mazeExist;
}

string Game::MazeDirectoryWinners(int numMaze) {
	string winners;

	if ((numMaze >= 10 && numMaze <= 99) || to_string(numMaze) == "00" || to_string(numMaze) == "01" || to_string(numMaze) == "02" || to_string(numMaze) == "03" || to_string(numMaze) == "04" || to_string(numMaze) == "05" || to_string(numMaze) == "06" || to_string(numMaze) == "07" || to_string(numMaze) == "08" || to_string(numMaze) == "09") {
		winners = "MAZE_" + to_string(numMaze) + "_WINNERS.TXT";
	}
	else if (numMaze > 0 && numMaze <= 9) {
		winners = "MAZE_0" + to_string(numMaze) + "_WINNERS.TXT";
	}
	return winners;
}

bool Game::Winners(int numMaze)
{
	bool Not0{ true };
	while (Not0) {
		if (numMaze == 0) { return true; } // Go back to the Menu
		string mazeDirectoryWinners = MazeDirectoryWinners(numMaze), winnersLine;
		bool winnersFileValidate = ValidateDirectory(mazeDirectoryWinners);
		if (!winnersFileValidate) { cout << " This maze doesn't exist! "; return false; }
		else {
			Not0 = false;
			ifstream winnersFile; winnersFile.open(mazeDirectoryWinners);
			while (!winnersFile.eof()) {
				getline(winnersFile, winnersLine);
				cout << " " << winnersLine << endl;
			}
		}
	}

	return true;
}

bool Game::IsValid()
{
	for (int i = 0; i < RobotsVector.size(); i++) {
		robot = RobotsVector[i];
		if (robot.getRow() == player.GetRow() && robot.getCol() == player.GetCol() && robot.getSymbol() == 'r') {
			player.Reset(movement);
			cout << " You can't go there!" << endl; showGameDisplay();
			valid = false; break;
		}
		else { valid = true; }
	}
	for (int i = 0; i < maze.PostsVector.size(); i++) {
		post = maze.PostsVector[i];
		if (post.getRow() == player.GetRow() && post.getCol() == player.GetCol() && post.getSymbol() == '+') {
			player.Reset(movement);
			cout << " You can't go there!" << endl; showGameDisplay();
			valid = false; break;
		}
	}
	return valid;
}

bool Game::Play(string mazeDirectory)
{
	maze.VectorPosts(mazeDirectory);
	while (player.isAlive() && !PlayerEscape()) {
		showGameDisplay();
		valid = false;
		while (!valid) {
			movement = player.Movement();
			player.Move(movement);
			valid = IsValid();
		} 
		// Check if the player dies
		if (PlayerCollide()) {
			player.setAsDead();
		}

		// Move robots and verify the movements
		MoveRobots();
	}
	showGameDisplay(); cout << endl; // Show the current maze



	return player.isAlive(); // Final state of the player (alive or dead)
}

void Game::MoveRobots()
{
	for (int i = 0; i < RobotsVector.size(); i++) {
		robot = RobotsVector[i]; 
		
		if (robot.isAlive()) {
			robot.Move(player.GetCol(), player.GetRow());

			if (robot.getCol() == player.GetCol() && robot.getRow() == player.GetRow()) {
				player.setAsDead();
			}
			for (int k = 0; k < maze.PostsVector.size(); k++) {
				post = maze.PostsVector[k];

				if (robot.getCol() == post.getCol() && robot.getRow() == post.getRow()) {
					if (post.getSymbol() == '*' || post.getSymbol() == 'O') {
						robot.Reset();
					}
					robot.setAsDead();
				}
			}

			for (int j = i + 1; j < RobotsVector.size(); j++) {
				Robot robot2 = RobotsVector[j];

				if (robot.getCol() == robot2.getCol() && robot.getRow() == robot2.getRow()) {
					robot.setAsDead(); robot2.setAsDead();
				}
				RobotsVector[j] = robot2;
			}

		}

		RobotsVector[i] = robot;
	}

	RobotCollide();
}

bool Game::PlayerCollide()
{
	bool collide{ false };
	for (int k = 0; k < maze.PostsVector.size(); k++) {
		post = maze.PostsVector[k];

		if (post.getCol() == player.GetCol() && post.getRow() == player.GetRow() && post.isElectrified()) {  // Poste eletrificado ( * )
			collide = true;
			player.Reset(movement);
			post.setSymbol('+');
			maze.PostsVector[k] = post;
			break;
		}
		maze.PostsVector[k] = post;
	}
	for (int k = 0; k < RobotsVector.size(); k++) {
		robot = RobotsVector[k];

		if (robot.getCol() == player.GetCol() && robot.getRow() == player.GetRow()) {
			collide = true; 
			robot.setAsDead();
			break;
		}
		RobotsVector[k] = robot;
	}
	
	return collide;
}

void Game::RobotCollide()
{

	for (int i = 0; i < RobotsVector.size(); i++) {
		robot = RobotsVector[i];

		if (robot.getCol() == player.GetCol() && robot.getRow() == player.GetRow()) {
			player.setAsDead(); 
		}
		for (int k = 0; k < maze.PostsVector.size(); k++) {
			post = maze.PostsVector[k];

			if (robot.getCol() == post.getCol() && robot.getRow() == post.getRow()) {
				if (post.getSymbol() == '*') {
					robot.Reset();
					post.setSymbol('+');
					maze.PostsVector[k] = post; // Não está a funcionar!
				}
				else if (post.getSymbol() == 'O') {
					robot.Reset();
				}
				robot.setAsDead();
			}
		}

		for (int j = i + 1; j < RobotsVector.size(); j++) {
			Robot robot2 = RobotsVector[j];
			
			if (robot.getCol() == robot2.getCol() && robot.getRow() == robot2.getRow()) {
				robot.setAsDead(); robot2.setAsDead();
			}
			RobotsVector[j] = robot2;
			RobotsVector[i] = robot;
		}
	}
}

bool Game::PlayerEscape()
{
	bool escape{ false };
	for (int k = 0; k < maze.PostsVector.size(); k++) {
		post = maze.PostsVector[k];

		if (post.getCol() == player.GetCol() && post.getRow() == player.GetRow() && post.getSymbol() == 'O') {  // Poste eletrificado ( * )
			escape = true;
			break;
		}
	}

	return escape;
}

string Game::GenerateWinnersLine(string name, string elapsedTime)
{
	string winnersLine{ name }; int nameSize = name.size(); int numSpaces = 5 - elapsedTime.size();

	while (nameSize < 15) {
		winnersLine += " ";
		nameSize++;
	}
	winnersLine += " –";

	while (numSpaces > 0) {
		winnersLine += " ";
		numSpaces--;
	}
	winnersLine += elapsedTime;

	return winnersLine;
}

void Game::UpdateWinnersFile(string winnersLine, int numMaze, int elapsedTime)
{
	bool scoreInserted{ false };
	string mazeDirectoryWinners = MazeDirectoryWinners(numMaze);
	if (!ValidateDirectory(mazeDirectoryWinners)) { // If there isn't a winner's file for the current maze create one (with header).
		ofstream WinnersFile(mazeDirectoryWinners);
		WinnersFile << "Player          – Time" << endl << "----------------------";
		WinnersFile.close();
	}
	fstream WinnersFile; WinnersFile.open(mazeDirectoryWinners);
	
	numLine = 0;
	while (!WinnersFile.eof()) { // Go through and store the content of the winner's file in a vector (vector_winnersFile).
		getline(WinnersFile, winnersFileLine);
		if (!winnersFileLine.empty()) { vectorWinnersFile.insert(vectorWinnersFile.begin() + numLine, winnersFileLine); }
		numLine++;
	}
	WinnersFile.close(); WinnersFile.open(mazeDirectoryWinners);
	if (vectorWinnersFile.size() == 2) { vectorWinnersFile.insert(vectorWinnersFile.begin() + numLine, winnersLine); } // If there are only two lines (header), add the winner's line at the bottom.
	else { // If there are more than 2 lines.
		sizeVectorWinnersFile = vectorWinnersFile.size();

		for (int line = 2; line < sizeVectorWinnersFile; line++) { // Go through the vector (vector_winnersFile) and compare the times before adding the new line (Starts in line = 2 to ignore the header). 
			numberToCompare = "";
			for (int caracter = 17; caracter < 22; caracter++) { // Get the time from the line that is stored in the vector.
				if (vectorWinnersFile[line][caracter] != ' ') { numberToCompare += vectorWinnersFile[line][caracter]; }
			}
			if (elapsedTime < stoi(numberToCompare)) { // Compare the time spent by the player with the time in the vector's line. If the player's time is lower, add the winner's line before that vector's line.
				vectorWinnersFile.insert(vectorWinnersFile.begin() + line, winnersLine);
				scoreInserted = true; break;
			}
		}
		if (!scoreInserted) { vectorWinnersFile.insert(vectorWinnersFile.begin() + vectorWinnersFile.size(), winnersLine); } // If the winner's line wasn't inserted, add it at the end (it means all the previous stored times are lower).
	}
	for (int line = 0; line < vectorWinnersFile.size(); line++) { WinnersFile << vectorWinnersFile[line] << endl; } // Write the vector content to the file (replacing the old text).
	WinnersFile.close();
}

void Game::showGameDisplay() {

	for (int i = 0; i < maze.getnumRows()+1; i++) {
		cout << "        ";
		for (int j = 0; j < maze.getnumCols()+1; j++) {
			positionOccupied = 0;
			if (i == player.GetRow() && j == player.GetCol()) {
				cout << player.GetSymbol(); positionOccupied = 1;
			}
			if (positionOccupied != 1) {
				for (int k = 0; k < RobotsVector.size(); k++) {
					robot = RobotsVector[k];

					if (robot.getCol() == j && robot.getRow() == i) {
						cout << robot.getSymbol(); positionOccupied = 1; break;
					}
				}
				if (positionOccupied != 1) {
					for (int k = 0; k < maze.PostsVector.size(); k++) {
						post = maze.PostsVector[k];

						if (post.getCol() == j && post.getRow() == i) {
							cout << post.getSymbol(); positionOccupied = 1;  break;
						}
					}
				}
			}
			if (positionOccupied != 1) {
				cout << " ";
			}
		}
		cout << endl;
	}
}
