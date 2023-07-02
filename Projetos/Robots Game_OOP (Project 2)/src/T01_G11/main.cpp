//T01_G11
#include<iostream>
#include<ctime>
#include<fstream>
#include<string>
#include<iomanip>
#include "Game.h"
using namespace std;

// Print rules file
void rules() {
	string rulesLine;
	ifstream rulesFile; rulesFile.open("RULES.TXT"); // Open file
	cout << endl;

	while (!rulesFile.eof()) {
		getline(rulesFile, rulesLine);
		cout << rulesLine << endl; // Print every line of the file
	} cout << endl;
}

// Print the menu and ask for a option (user input). Check if it's a valid input or not (it can only be '0', '1' or '2') and return the intended option
int Menu() {
	string option; bool validInput{ true };
	cout << " Please input the number of the option you want: " << endl << " 1) Rules" << endl << " 2) Play" << endl << " 3) Winners" << endl << " 0) Exit" << endl << " Option: "; cin >> option; // Ask for an option

	while (validInput) {
		for (int i = 0; i < option.size(); i++) { // Verify if the input contains only digits
			if (!isdigit(option[i])) {
				validInput = false;
				break;
			}
		}
		if (validInput == true && (option == "0" || option == "1" || option == "2" || option == "3")) { break; } // Option is valid
		if (!validInput || (option != "0" && option != "1" && option != "2" && option != "3")) { // Option is not valid. Ask for a new one
			cout << endl << " Invalid option! Please input another option: "; cin >> option;
			validInput = true;
		}
	}
	return stoi(option);
}


int main() {
	for (int i = 0; i < 100; i++) { cout << endl; }
	cout << " Welcome to the Robots Game!" << endl << endl;

	bool PlayAgain{ true };
	while (PlayAgain) { // Cicle to verify if the player wants to play again
		time_t time1, time2, elapsedTime;
		bool mazeExist{ false };
		int option = Menu(), numMaze;
		string mazeDirectory, name, winnersLine, answer;
		Game game; // Create an object "game" of the class Game

		if (option == 0) { exit(1); } // User chooses to exit the program.
		else if (option == 1) { // User chooses to see the rules. Goes back to the menu.
			rules();
			PlayAgain = true;
		}
		else if (option == 2) { // User chooses to play. 
			while (!mazeExist) {
				numMaze = game.NumMaze(); // Number of the maze
				if (numMaze == 0) { // If the player wants to go back to the Menu
					cout << endl;
					PlayAgain = true; break;
				}
				mazeDirectory = game.MazeDirectory(numMaze); // Maze directory
				mazeExist = game.ValidateDirectory(mazeDirectory); // Validate maze directory
				if (!mazeExist) { // If the chosen maze doesn't exist
					cout << " MAZE_" << numMaze << " doesn't exist! Please try again!";
				}
			}

			if (numMaze != 0) { // If the number of the maze is not 0
				Game game(mazeDirectory);
				time1 = time(NULL); // Start counting the time
				if (game.Play(mazeDirectory)) { // Play the game
					time2 = time(NULL); // Stop counting the time 
					elapsedTime = time2 - time1; // Time to win
					cout << " YOU WON! GOOD JOB!" << endl;
					cout << " You took " << elapsedTime << "s to defeat the robots! " << endl;
					

					cout << " What is your name (15 characters)? "; cin >> setw(15) >> name; cout << endl; // Ask the player name
					winnersLine = game.GenerateWinnersLine(name, to_string(elapsedTime)); // Create winners line
					game.UpdateWinnersFile(winnersLine, numMaze, elapsedTime); // Add the new winnersLine to the file

				}
				else { // If the player losts the game
					cout << " YOU LOST! Better luck next time!" << endl;
				}
				cout << " Do you want to play again (Y/N) ? "; cin >> answer; // Ask the player if he/she wants to go again
				while (true) { // Verify if the answer is a valid input
					if (answer == "y" || answer == "Y") {
						PlayAgain = true;
						for (int i = 0; i < 100; i++) { cout << endl; }
						cout << " Have Another Go! " << endl << endl;
						break;
					}
					else if (answer == "n" || answer == "N") { PlayAgain = false; break; }
					else {
						cout << endl << " Answer not acceptable (Y or N)! Try again! "; cin >> answer;
					}
				}
			}
		}
		else if (option == 3) { // User chooses to see the winners.
			Game game;
			while (true) {
				numMaze = game.NumMaze(); // Number of the maze
				if (game.Winners(numMaze)) { // Print the file mazeWinners if it exists and go back to the Menu
					PlayAgain = true; break;
				}
			}
		}
	}
}