#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

#define LEN_NOME_JOGADOR 15

/*****************************************************************
                         MAZE FUNCTIONS
 *****************************************************************/

vector<vector<char>> load_maze(const string &filename)
{
    /* Load the maze from the file. The symbols used in the file are; 'H'-player; 'R'-robot; '*'-fence or post. As the game is loaded, each robot must be assigned a sequential identification number (to be stored in the internal data structures of the program), starting with 1. */
    vector<vector<char>> maze;

    std::ifstream f(filename);
    while(!f.eof()) {
        string line;
        getline(f, line);
        if(line.empty())
            break;
        vector<char> row;
        for(char ch: line)
            row.push_back(ch);
        maze.push_back(row);
        // ignorei a parte do robot id
    }
    return maze;
}

void print_maze(const vector<vector<char>> &maze)
{
    cout << endl;
    for(const vector<char>& row: maze) {
        for(char ch: row)
            cout << ch;
        cout << endl;
    }
}

void where_is_player(const vector<vector<char>> &maze, int &x, int &y)
{
    for(y = 0; y < (int)maze.size(); y++)
        for(x = 0; x < (int)maze[0].size(); x++)
            if(maze[y][x] == 'H')
                return;
}

bool move_player(vector<vector<char>> &maze, int dx, int dy)
{
    // 1. encontra jogador
    int x, y;
    where_is_player(maze, x, y);
    maze[y][x] = ' ';
    // 2. Verifica que existe e atualiza
    if(maze[y+dy][x+dx] != ' ') {  // morre
        maze[y+dy][x+dx] = 'h';
        return false;
    }
    else {
        maze[y+dy][x+dx] = 'H';
        return true;
    }
}

bool move_robots(vector<vector<char>> &maze)
{
    int jogador_x, jogador_y;
    where_is_player(maze, jogador_x, jogador_y);

    int x, y;
    for(y = 0; y < (int)maze.size(); y++) {
        for(x = 0; x < (int)maze[0].size(); x++)
            if(maze[y][x] == 'R') {
                maze[y][x] = ' ';
                int dx = (x < jogador_x) - (x > jogador_x);
                int dy = (y < jogador_y) - (y > jogador_y);
                switch(maze[y+dy][x+dx]) {
                    case ' ': maze[y+dy][x+dx] = 'R'; break;
                    case '*': maze[y+dy][x+dx] = ' '; break;  // robot vai contra fence -> morre
                    case 'H': maze[y+dy][x+dx] = 'h'; return false;  // termina jogo
                    default: maze[y+dy][x+dx] = 'r'; break;
                }
                break;
            }
    }
    return true;
}

bool no_more_robots(const vector<vector<char>> &maze)
{
    for(const vector<char> &row: maze)
        for(char ch: row)
            if(ch == 'R')
                return false;
    return true;
}

/*****************************************************************
                         PLAY FUNCTIONS
 *****************************************************************/

bool tecla_para_movimento(char key, int &dx, int &dy)
{
    switch(key) {
        case 't': dx = -1; dy = -1; break;
        case 'y': dx = 0; dy = -1; break;
        case 'u': dx = 1; dy = -1; break;
        case 'g': dx = -1; dy = 0; break;
        case 'h': dx = 0; dy = 0; break;
        case 'j': dx = 1; dy = 0; break;
        case 'b': dx = -1; dy = 1; break;
        case 'n': dx = 0; dy = 1; break;
        case 'm': dx = 1; dy = 1; break;
        default: return false;
    }
    return true;
}

bool play(const string &filename)
{
    vector<vector<char>> maze = load_maze(filename);
    while(true) {  // gameloop
        print_maze(maze);
        int dx, dy;
        char key;
        do {
            cout << "Movement? ";
            cin >> key;
            key = tolower(key);
        } while(!tecla_para_movimento(key, dx, dy));

        // Move the player to the new position and, if necessary, update his/her status (he/she died).
        if(!move_player(maze, dx, dy)) {
            print_maze(maze);
            cout << "Sorry - you die!\n";
            return false;
        }

        // If the player is still alive, move one robot after the other
        if(!move_robots(maze)) {
            print_maze(maze);
            cout << "Sorry - you got caught!\n";
            return false;
        }

        if(no_more_robots(maze)) {
            print_maze(maze);
            cout << "You won!\n";
            return true;
        }
    }
}

void print_rules()
{
    cout << "\n";
    cout << "=== RULES ===\n";
    cout << "- You must avoid the robots\n";
    cout << "- You cannot  avoid the robots\n";
    cout << "- Use keys T,Y,U ; G,H,J ; B,N,M to control the player\n";
    cout << "- Exit the game by pressing the end-of-file key\n";
    cout << "Continue?";
    getchar(); getchar();
}

/*****************************************************************
                         INPUT/OUTPUT
 *****************************************************************/

bool file_exists(const string &filename)
{
    return std::ifstream(filename).good();
}

string format_level(int level)
{
    ostringstream os;
    os << "MAZE_" << setw(2) << setfill('0') << level << ".txt";
    return os.str();
}

int ask_level()
{
    int level;
    while(true) {
        cout << "\nWhich level? ";
        cin >> level;

        if(level == 0)
            return 0;
        if(file_exists(format_level(level)))
            return level;
        cout << "Level " << level << " not implemented yet! - choose another please\n";
    }
}

void gravar_winner(int level, const string& name, int time)
{
    ostringstream os;
    os << "MAZE_" << setw(2) << setfill('0') << level << "_WINNER.txt";

    string filename = os.str();
    bool write_header = !file_exists(filename);
    std::ofstream f(filename, ios_base::app);
    if(write_header) {
        f << "Player         - Time\n";
        f << "---------------------\n";
    }
    f << setw(LEN_NOME_JOGADOR) << left << name << setw(4) << right << time << endl;
}

/*****************************************************************
                         MAIN
 *****************************************************************/

int main()
{
    string name;

    // Ask the name of the player; note: the name may have more than one word but its length is limited to 15
    cout << "Please write your name: ";
    do {
        getline(cin, name);
        if(name.length() > LEN_NOME_JOGADOR)
            name = name.substr(0, LEN_NOME_JOGADOR);
    } while(name.empty());

    // Show a menu with 3 options: 1) Rules; 2) Play; 0) Exit. The action corresponding to each option is obvious.
    int choice;
    do {
        cout << "\n=== MENU ===\n1) Rules\n2) Play\n0) Exit\n";
        cout << "Choice: ";
        cin >> choice;
        switch(choice) {
            case 1: print_rules(); break;
            case 2: {
                /* When the user chooses to play the game, the program must ask the number (an integer value) of the maze to use, build automatically the name of the file where the maze is saved (the name must have the format MAZE_XX.TXT; see below) and verify that the file exists; the number must be asked repeatedly until either the corresponding maze file is found or the user input is 0 (zero). In this last case, the initial menu must be shown again. */
                int level = ask_level();
                if(level > 0) {
                    time_t before_time, after_time;
                    time(&before_time);

                    if(play(format_level(level))) {
                        time(&after_time);
                        int seconds = difftime(after_time, before_time);
      std::ofstream outfile;
                        gravar_winner(level, name, seconds);
                    }
                }
            }
        }
    } while(choice != 0);
}
