// T01_G11
# include<iostream>
# include<string>
# include<fstream>
# include<vector>
# include<ctime>
# include<iomanip>
using namespace std;

void rules() { // Print a quick explanation of the game.
	cout << endl << "------ RULES ------" << endl;
	cout << "You are placed in a maze made up of hight-voltage fences and posts. " << endl;
	cout << "There are also some interceptor robots that will try to destroy you. " << endl;
	cout << "If you touch the maze or any of the robots, you died and its the end of the game. The robots are also destroyed when they touch the fences/posts or when they collide with each other. " << endl;
	cout << "Every time you move to any direction (horizontally, vertically, or diagnally) to a contiguous cell, each robot moves one cell closer to your location, in wichever direction is the shortest path. " << endl;
	cout << "The robots have no vision sensors but they have an accurate odour sensor that allows them to follow you! ";
	cout << "There is one hope! Make the robots hit the maze or each other. " << endl;
	cout << "If all of them are destroyed, you WIN!" << endl << endl;
}

int Menu() { // Print the menu and ask for a option (user input). Check if it's a valid input or not (it can only be '0', '1' or '2') and return the intended option.
	string option; bool valid_input = true ;
	cout << " Please input the number of the option you want: " << endl << " 1) Rules" << endl << " 2) Play" << endl << " 0) Exit" << endl << " Option: "; cin >> option;

	while (valid_input) {
		for (int i = 0; i < option.size(); i++) {
			if (!isdigit(option[i])) {
				valid_input = false;
				break;
			}
		}
		if (valid_input == true && (option == "0" || option == "1" || option == "2")) { break; }
		if (!valid_input || (option != "0" && option != "1" && option != "2")){
			cout << endl << " Invalid option! Please input another option: "; cin >> option;
			valid_input = true;
		}
	}
	return stoi(option);
}

int Num_Maze() { // Ask for the number of the maze (user input) and check if it's a valid or not (it cannot have letters and has to be a number between 0 and 99). Return the intended maze number.
	string num_maze; bool invalid_input = true ;
	cout << endl << " Please input a number for the maze (0 to Go Back): "; cin >> num_maze;

	while (invalid_input || stoi(num_maze) > 99) {
		for (int c = 0; c < num_maze.size(); c++) {
			if (!isdigit(num_maze[c])) {
				cin.clear(); cin.ignore(1000, '\n');
				invalid_input = false;
				break;
			}
		}
		if (invalid_input == true) { break; }
		if (!invalid_input || stoi(num_maze) > 99) {
			cout << endl << " Invalid input! Please input another number (use only numbers): "; cin >> num_maze;
			invalid_input = true;
		}
	}
	cout << endl;
	return stoi(num_maze);
}

string Maze_Directory(int num_maze) { // Receive the number of the maze and return it's directory (MAZE_XX.TXT).
	string maze_directory;

	if ((num_maze >= 10 && num_maze <= 99) || to_string(num_maze) == "00" || to_string(num_maze) == "01" || to_string(num_maze) == "02" || to_string(num_maze) == "03" || to_string(num_maze) == "04" || to_string(num_maze) == "05" || to_string(num_maze) == "06" || to_string(num_maze) == "07" || to_string(num_maze) == "08" || to_string(num_maze) == "09") {
		maze_directory = string("../data/") + string("MAZE_") + to_string(num_maze) + string(".txt");
	}
	else if (num_maze > 0 && num_maze <= 9) {
		maze_directory = string("../data/") + string("MAZE_0") + to_string(num_maze) + string(".txt");
	}
	return maze_directory;
}

bool Validate_Directory(string maze_directory) { // Validate if certain directory exists. Return 'true' or 'false'.
	bool maze_exist = true ;

	ifstream myfile(maze_directory);
	if (!myfile.is_open()) {
		maze_exist = false;
	}
	myfile.close();
	return maze_exist;
}

string Movement() { // Print list of acceptable movements and ask the player for one (user input). Check if it's a valid input or not (it can only be 'q', 'w', 'e', 'a', 's', 'd', 'z', 'x', or 'c') and return the intended movement.
	string movement;
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
		if (cin.eof()){ exit(1); }
		else {
			cin.clear(); cin.ignore(1000, '\n');
			cout << endl << " Invalid input! Please input another valid option: ";
		}
	} cout << endl;
	return movement;
}

int Change_y(string movement, vector <int> player_identification) { // Receive the intended movement and current player coordinates. Calculate and return the y coordinate of new position.
	int y = 0 ;

	if (movement == "Q" || movement == "q") {
		y = player_identification[1] - 1;
	}
	else if (movement == "A" || movement == "a") {
		y = player_identification[1];
	}
	else if (movement == "Z" || movement == "z") {
		y = player_identification[1] + 1;
	}
	else if (movement == "W" || movement == "w") {
		y = player_identification[1] - 1;
	}
	else if (movement == "S" || movement == "s") {
		y = player_identification[1];
	}
	else if (movement == "X" || movement == "x") {
		y = player_identification[1] + 1;
	}
	else if (movement == "E" || movement == "e") {
		y = player_identification[1] - 1;
	}
	else if (movement == "D" || movement == "d") {
		y = player_identification[1];
	}
	else if (movement == "C" || movement == "c") {
		y = player_identification[1] + 1;
	}
	return y;
}

int Change_x(string movement, vector <int> player_identification) { // Receive the intended movement and current player coordinates. Calculate and return the x coordinate of new position.
	int x = 0;

	if (movement == "Q" || movement == "q") {
		x = player_identification[0] - 1;
	}
	else if (movement == "A" || movement == "a") {
		x = player_identification[0] - 1;
	}
	else if (movement == "Z" || movement == "z") {
		x = player_identification[0] - 1;
	}
	else if (movement == "W" || movement == "w") {
		x = player_identification[0];
	}
	else if (movement == "S" || movement == "s") {
		x = player_identification[0];
	}
	else if (movement == "X" || movement == "x") {
		x = player_identification[0];
	}
	else if (movement == "E" || movement == "e") {
		x = player_identification[0] + 1;
	}
	else if (movement == "D" || movement == "d") {
		x = player_identification[0] + 1;
	}
	else if (movement == "C" || movement == "c") {
		x = player_identification[0] + 1;
	}
	return x;
}

string Maze_Directory_Winners(int num_maze) { // Receive the number of the maze and return it's winner's file directory (MAZE_XX_WINNERS.TXT).
	string winners;

	if ((num_maze >= 10 && num_maze <= 99) || to_string(num_maze) == "00" || to_string(num_maze) == "01" || to_string(num_maze) == "02" || to_string(num_maze) == "03" || to_string(num_maze) == "04" || to_string(num_maze) == "05" || to_string(num_maze) == "06" || to_string(num_maze) == "07" || to_string(num_maze) == "08" || to_string(num_maze) == "09") {
		winners = string("../data/") + string("MAZE_") + to_string(num_maze) + string("_WINNERS.txt");
	}
	else if (num_maze > 0 && num_maze <= 9) {
		winners = string("../data/") + string("MAZE_0") + to_string(num_maze) + string("_WINNERS.txt");
	}
	return winners;
}

string Generate_winners_line(string name, string elapsedTime) { // Receive the name of the player and time spent and generate the winner's line to be added to the winner's file. Return the winner's line according to the format wanted (ie. name            �   10).
	string Winners_line = name; int name_size = name.size(); int num_spaces = 5 - elapsedTime.size();

	while (name_size < 15) {
		Winners_line += " ";
		name_size++;
	}
	Winners_line += " �";

	while (num_spaces > 0) {
		Winners_line += " ";
		num_spaces--;
	}
	Winners_line += elapsedTime;
	return Winners_line;
}

bool PlayAgain(bool player_alive) { // Ask the user if he wants to play again. Check if the input is valid and return true or false. 
	string answer; bool valid_answer = false, GoBack;
	if (player_alive) { cout << endl << " Great job! Do you want to play again (Y or N) ? "; }
	else { cout << endl << " Do you want to have another shot (Y or N)? "; } cin >> answer;

	while (!valid_answer) {
		if (answer == "y" || answer == "Y") { GoBack = true; valid_answer = true; }
		else if (answer == "n" || answer == "N") { GoBack = false; valid_answer = true; }
		else {
			cout << endl << " Answer not acceptable (Y or N)! Try again! "; cin >> answer;
		}
	}
	return GoBack;
}

int main() {
	for (int i = 0; i < 100; i++) { cout << endl; } 
	cout << " Welcome to the Robots Game!" << endl << endl;
	bool GoBack = true ;
	while (GoBack) { // Restart the program.
		// Declaration of all variables used.
		time_t time1, time2, elapsedTime;
		int option, num_maze, num_line = -1 , num_robots_alive = 0, robot_ID = 0, x = 0, y = 0, x_robot = 0, y_robot = 0, size_vector_winners_file;
		bool GoBack, maze_exist = false, winners_directory_exist, player_alive = true, not_allowed = true, score_inserted = false;
		string maze_directory, line_maze, movement, name, winners_directory, winners_line, winners_file_line, number_to_compare, answer;
		vector<int> player_identification(2); vector<string> vector_winnersFile;
		ifstream maze_file;

		option = Menu();
		if (option == 0) { exit(1); } // User chooses to exit the program.
		else if (option == 1) { // User chooses to see the rules. Goes back to the menu.
			rules();
			GoBack = true;
		}
		else if (option == 2) { // User chooses to play.
			GoBack = false;
			while (!maze_exist) { // Keep asking for the number of the maze (user input) until certain maze exists (0 to go back).
				num_maze = Num_Maze();
				if (num_maze == 0) {
					cout << endl;
					GoBack = true; break;
				}
				maze_directory = Maze_Directory(num_maze); maze_exist = Validate_Directory(maze_directory);
				if (!maze_exist) {
					cout << " Maze_" << num_maze << " doesn't exist! Please try again!";
				}
			}
			if (!GoBack) { // Start the game!
				maze_file.open(maze_directory); cout << endl;
				while (!maze_file.eof()) { // Go through the maze and count all the robots alive.
					getline(maze_file, line_maze);
					for (int i = 0; i < line_maze.length(); i++) {
						if (line_maze[i] == 'R') { num_robots_alive++; }
					}
				}
				maze_file.close(); maze_file.open(maze_directory);
				vector<string> maze; vector< vector<int> > robots_identification(num_robots_alive, vector<int>(3)); // Create one vector to store the maze (maze) and other to store all the robot cordinates (robots_identification).

				while (!maze_file.eof()) { // Go through the maze and store the player coordinates in a vector (player_identification = x, y) and the robots coordinates in another vector (robot_identification = ID, x, y).
					getline(maze_file, line_maze);
					num_line++; vector<int> robot_coordinates(3);

					for (int i = 0; i < line_maze.size(); i++) {
						if (line_maze[i] == 'H') {
							player_identification[0] = i; player_identification[1] = num_line - 1;
						}
						else if (line_maze[i] == 'R') {
							robot_ID++;
							robot_coordinates[0] = robot_ID; robot_coordinates[1] = i; robot_coordinates[2] = num_line - 1;
							robots_identification[robot_ID - 1] = robot_coordinates;
						}
					}
					if (num_line != 0) { maze.push_back(line_maze); }
				}
				time1 = time(NULL); // Start the time count.

				while (player_alive && num_robots_alive != 0) { // Game loop (every movement is a new cycle). Game ends when the player dies or all robots die.
					for (int i = 0; i < num_line; i++) { cout << "               " << maze[i] << endl; }; cout << endl; // Print the maze.

					movement = Movement(); // Ask for a movement.
					not_allowed = true;

					while (not_allowed) { // Calculate the new coordinates of the player according to the chosen movement. Player cannot move to a cell occupied with a dead robot ('r').
						x = Change_x(movement, player_identification); y = Change_y(movement, player_identification);
						if (maze[y][x] == 'r') {
							cout << endl << " Can't go there! " << endl << endl;
							movement = Movement();
							not_allowed = true;
						}
						else { not_allowed = false; }
					}
					if (maze[y][x] == 'R' || maze[y][x] == '*') { // A player dies when he hits a robot or a fence. The game ends.
						maze[y][x] = 'h'; maze[player_identification[1]][player_identification[0]] = ' ';
						player_alive = false;
					}
					else { // Player doesn't die. Move the player to the new coordinates and store them. Move all the robots one cell closer to the new player's location (shortest path).
						maze[player_identification[1]][player_identification[0]] = ' '; maze[y][x] = 'H'; // Move the player.
						player_identification[0] = x; player_identification[1] = y; // Store the new coordinates.

						for (int i = 0; i < num_robots_alive; i++) { // One robot at the time, calculate the new coordinates and move the robots to the new position.
							x_robot = robots_identification[i][1]; y_robot = robots_identification[i][2];

							if (x == x_robot && y < y_robot) { y_robot--; }
							else if (x == x_robot && y > y_robot) { y_robot++; }
							else if (y == y_robot && x < x_robot) { x_robot--; }
							else if (y == y_robot && x > x_robot) { x_robot++; }
							else if (x < x_robot && y < y_robot) { x_robot--; y_robot--; }
							else if (x > x_robot && y < y_robot) { x_robot++; y_robot--; }
							else if (x < x_robot && y > y_robot) { x_robot--; y_robot++; }
							else if (x > x_robot && y > y_robot) { x_robot++; y_robot++; }

							if (maze[y_robot][x_robot] == 'r' || maze[y_robot][x_robot] == '*') { // A robot dies when it hits a fence or a dead robot. It's coordinates are erased from the vector (robot_identification).
								maze[y_robot][x_robot] = 'r'; maze[robots_identification[i][2]][robots_identification[i][1]] = ' ';
								robots_identification.erase(robots_identification.begin() + i);
								num_robots_alive--; i--;
							}
							else if (maze[y_robot][x_robot] == 'R') { // When a robot collides with another alive robot they both die. Both coordinates are erased from the vector (robot_identification).
								maze[y_robot][x_robot] = 'r'; maze[robots_identification[i][2]][robots_identification[i][1]] = ' '; robots_identification.erase(robots_identification.begin() + i);
								num_robots_alive -= 2;

								for (int r = 0; r < robots_identification.size(); r++) { // Go through the vector and find out what robot we hit and erase that line.
									if (robots_identification[r][1] == x_robot && robots_identification[r][2] == y_robot) {
										robots_identification.erase(robots_identification.begin() + r); r--;
									}
								} i--;
							}
							else if (maze[y_robot][x_robot] == 'H' || maze[y_robot][x_robot] == 'h') { // If a robot hits the player the player dies and the game ends.
								maze[y_robot][x_robot] = 'h'; maze[robots_identification[i][2]][robots_identification[i][1]] = ' ';
								player_alive = false;
							}
							else { // When a robot doens't hit anything move him to the new coordinates and store them.
								maze[y_robot][x_robot] = 'R';  maze[robots_identification[i][2]][robots_identification[i][1]] = ' ';
								robots_identification[i][1] = x_robot; robots_identification[i][2] = y_robot;
							}
						}
					}
				}
				time2 = time(NULL); // Stop the time count.

				for (int i = 0; i < num_line; i++) { cout << "               " << maze[i] << endl; };  cout << endl; // Print the final maze.

				elapsedTime = time2 - time1; // Calculate the time elapsed since the maze was first shown until the game ended.
				if (player_alive) {
					winners_directory = Maze_Directory_Winners(num_maze); winners_directory_exist = Validate_Directory(winners_directory); // Get the directory for the winner's file of the current maze and check if it already exists.
					cout << " You WON! " << endl;
					if (!winners_directory_exist) { // If there isn't a winner's file for the current maze create one (with header).
						ofstream WinnersFile(winners_directory);
						WinnersFile << "Player          � Time" << endl << "----------------------";
						WinnersFile.close();
					}
					cout << " What is your name (15 characters)? "; cin >> setw(15) >> name;
					winners_line = Generate_winners_line(name, to_string(elapsedTime));
					fstream WinnersFile; WinnersFile.open(winners_directory);

					num_line = 0;
					while (!WinnersFile.eof()) { // Go through and store the content of the winner's file in a vector (vector_winnersFile).
						getline(WinnersFile, winners_file_line);
						if (!winners_file_line.empty()) { vector_winnersFile.insert(vector_winnersFile.begin() + num_line, winners_file_line); }
						num_line++;
					}
					WinnersFile.close(); WinnersFile.open(winners_directory);
					if (vector_winnersFile.size() == 2) { vector_winnersFile.insert(vector_winnersFile.begin() + num_line, winners_line); } // If there are only two lines (header), add the winner's line at the bottom.
					else { // If there are more than 2 lines.
						size_vector_winners_file = vector_winnersFile.size();

						for (int line = 2; line < size_vector_winners_file; line++) { // Go through the vector (vector_winnersFile) and compare the times before adding the new line (Starts in line = 2 to ignore the header). 
							for (int caracter = 17; caracter < 22; caracter++) { // Get the time from the line that is stored in the vector.
								if (vector_winnersFile[line][caracter] != ' ') { number_to_compare += vector_winnersFile[line][caracter]; }
							}
							if (elapsedTime < stoi(number_to_compare)) { // Compare the time spent by the player with the time in the vector's line. If the player's time is lower, add the winner's line before that vector's line.
								vector_winnersFile.insert(vector_winnersFile.begin() + line, winners_line);
								score_inserted = true; break;
							}
						}
						if (!score_inserted) { vector_winnersFile.insert(vector_winnersFile.begin() + vector_winnersFile.size(), winners_line); } // If the winner's line wasn't inserted, add it at the end (it means all the previous stored times are lower).
					}
					for (int line = 0; line < vector_winnersFile.size(); line++) { WinnersFile << vector_winnersFile[line] << endl; } // Write the vector content to the file (replacing the old text).
					WinnersFile.close();
				}
				else { cout << " You LOST! Better LUCK next time! "; } // If the player isn't alive after the end of the game, they lost.
				if (PlayAgain(player_alive)) { // If the player wants to play again, restart the program.
					GoBack = true;
					for (int i = 0; i < 100; i++) { cout << endl; }
					cout << " Have another go. Good luck!" << endl;
				}
				else { break; } // If the player doesn't want to play again, end the program.
			} cout << endl;
		}
	}
}