#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Robot {
	int x, y, id;
	bool alive;
};

struct Human {
	int x, y;
	bool alive;
};

struct Post {
	int x, y;
};

struct Maze {
	int x, y;
	int nrRobots;
	int nrPosts;
	char *map;
	bool robotsAlive;
	struct Post *posts;
	struct Human hum;
	struct Robot *robs;
};

struct Play {
	int dy, dx;
};

template<typename T> std::istream& read(T &var) {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    return (std::cin >> var);
}

int getMazeNr() {
	int mazenr;
	do {
		cout << endl;
		cout << "Maze number? ";
	} while(!read(mazenr) || mazenr < 0 || mazenr > 99);
	return mazenr;
}       

bool contains(char *list, char test) {
	int i = 0;
	while(list[i]) {
		if(list[i] == test)
			return true;
		i++;
	}
	return false;
}

ifstream openMaze(int mazenr) {

	char maze[15] = "MAZE_%02d.txt";
	sprintf(maze, maze, mazenr);
	cout << "Opening file: " << maze << "..." << endl;
	ifstream mazef(maze, std::ifstream::in);	
	return mazef;
}

bool checkValidChar(char c) {
	static char validChars[] = 
		{'H', 'R', '*', ' ', '\r', '\t', '\n', '\0'};
	return contains(validChars, c);
}

void destroyMaze(struct Maze &mz) {
	free(mz.map);
	free(mz.robs);
	free(mz.posts);
	memset(&mz, 0, sizeof(struct Maze));
}

bool readMaze(ifstream &mazef, struct Maze &mz) {

	// get size
	int x, y;
	char throwaway; // consume "x"
	mazef >> x >> throwaway >> y;
	cout << "Maze size is " << x << " by " << y << endl;
	
	// allocated
	char *mazearray = (char *) 
		malloc(sizeof(char) * x * y);
	
	// read all chars, and count robots
	int ctr = 0;
	int nrRobots = 0;
	int nrPosts = 0;
	char c;
	while(mazef.get(c)) {
		
		// check for valid
		if(!checkValidChar(c))
			cout << "WARN: invalid char " << (int) c 
			<< "found, but continuing..." << endl;
		
		if(c == '\r' || c == '\n' || c == '\t')
			continue;
		
		// check for bad size
		if(ctr >= x * y) {
			cout << "Already read x * y chars, but"
			<< " non whitespace chars remain... giving up..." << endl;		
			free(mazearray);
			return 0;
		}

		// fill maze		
		mazearray[ctr] = c;
		ctr++;
		
		// counters
		// robot?
		if(c == 'R')
			nrRobots++;		
		
		// post?
		else if(c == '*')
			nrPosts++;
	}
	mazef.close();

	// init some stuff	
	mz.x = x;
	mz.y = y;
	mz.nrRobots = nrRobots;	
	mz.nrPosts = nrPosts;
	mz.robotsAlive = true;
	mz.map = mazearray; // must free() this array at the end
	mz.robs = (struct Robot *) 
		malloc(sizeof(struct Robot) * nrRobots);
	mz.posts = (struct Post *) 
		malloc(sizeof(struct Post) * nrPosts);			
			
	// init robots and human
	int rbCtr = 0, postCtr = 0;
	for(int i = 0; i < mz.x; i++)
		for(int j = 0; j < mz.y; j++) {
			char mzChar = mz.map[( mz.y * i ) + j];
			if(mzChar == 'R') {
				mz.robs[rbCtr].alive = true;
				mz.robs[rbCtr].x = i;
				mz.robs[rbCtr].y = j;
				mz.robs[rbCtr].id = rbCtr + 1;
				rbCtr++;
			
			} else if(mzChar == '*') {
				mz.posts[postCtr].x = i;
				mz.posts[postCtr].y = j;
				postCtr++;
				
			} else if(mzChar == 'H') {
				mz.hum.alive = true;
				mz.hum.x = i;
				mz.hum.y = j;
			}
		}

	return 1;
}

int getMaze(struct Maze &mz) {
    cout << "Lets play! Pick a maze number..." << endl;
    memset(&mz, 0, sizeof(struct Maze));
    int mazenr = getMazeNr();
    ifstream mazef = openMaze(mazenr);
    if(!mazef.is_open()) {
        cout << "ERR: could not open file..." << endl;
        return 0;
    }

    cout << "File opened..." << endl;
    if(readMaze(mazef, mz)) {
   	 cout << "Maze read!" << endl;
   	 return 1;
    } else {
	 cout << "Error reading maze..." << endl;    
	 return 0;
    }
}

void updateMaze(struct Maze &mz) {

	// blank it
	memset(mz.map, ' ', mz.x * mz.y);
		
	// place human
	mz.map[ mz.y * mz.hum.x + mz.hum.y ] = 'H';		
		
	// place posts 
	for(int i = 0; i < mz.nrPosts; i++) {
		struct Post *pst = &(mz.posts[i]);
		mz.map[ mz.y * pst->x + pst->y ] = '*';
	}		
		
	// place robots
	for(int i = 0; i < mz.nrRobots; i++) {
		struct Robot *rb = &(mz.robs[i]);
		mz.map[ mz.y * rb->x + rb->y ] = (rb->alive) ? 'R': 'r';
	}	
}

void printMaze(struct Maze &mz) {
	updateMaze(mz);
	for(int i = 0; i < mz.x; i++) {
		for(int j = 0; j < mz.y; j++)
			cout << mz.map[( mz.y * i ) + j];
		cout << endl;
	}
}

struct Play convertPlay(char play) {

	// toUpper
	if(play > 'Z')
		play -= 0x20;
	
	int deltaX = 0;
	int deltaY = 0;	

	// move in y? (deltaX due to coordinate system)
	if(play == 'Q' || play == 'W' || play == 'E')
		deltaX = -1;
		
	else if(play == 'Z' || play == 'X' || play == 'C')
		deltaX = 1;
	
	// move in x? (deltaY due to coordinate system)
	if(play == 'Q' || play == 'A' || play == 'Z')
		deltaY = -1;
		
	else if(play == 'E' || play == 'D' || play == 'C')
		deltaY = 1;
	
	// move
	struct Play pl;
	pl.dx = deltaX;
	pl.dy = deltaY;
	return pl;
}

struct Play getPlay() {
	static char validPlayChars[] 
		= {'Q', 'W', 'E', 'D', 'S', 'A', 'Z', 'X', 'C', 
		   'q', 'w', 'e', 'd', 's', 'a', 'z', 'x', 'c', '\0'};
	char play;
	do {
		cout << "Play?" << endl;
	} while(!read(play) || !contains(validPlayChars, play)) ; 
	return convertPlay(play);
}

bool validMove(struct Play pl, struct Maze &mz) {

	char targetX = mz.hum.x + pl.dx;
	char targetY = mz.hum.y + pl.dy;
	if(targetX < 0 || targetX > mz.x || targetY < 0 || targetY > mz.y) {
		return false;
	}
		
	if(mz.map[ mz.y * targetX + targetY ] == '*')
		return false;
	else
		return true;
}

bool collide(struct Robot &rb1, struct Robot &rb2) {
	if(rb1.x == rb2.x && rb1.y == rb2.y) {
		rb1.alive = false;
		cout << "Robot " << rb1.id << " died!" << endl;
		return true;
	}	
	return false;
}

bool collide(struct Robot &rb1, struct Post &post1) {
	if(rb1.x == post1.x && rb1.y == post1.y) {
		rb1.alive = false;
		cout << "Robot " << rb1.id << " died!" << endl;
		return true;
	}	
	return false;
}

bool collide(struct Robot &rb1, struct Human &hum) {
	if(rb1.x == hum.x && rb1.y == hum.y) {
		hum.alive = false;
		cout << "Human died!" << endl;
		return true;
	}	
	return false;
}

void doPlay(struct Play pl, struct Maze &mz) {
	
	// play has already been validated
	
	// Move human ////////////////////////////////////
	mz.hum.x += pl.dx;
	mz.hum.y += pl.dy;
	
	// check if human moved INTO a robot, if so, end /
	for(int i = 0; i < mz.nrRobots; i++)
		if(collide(mz.robs[i], mz.hum))
			return;
	
	// Move robots ///////////////////////////////////
	for(int i = 0; i < mz.nrRobots; i++) {
		if(mz.robs[i].alive) {			
			int robX = mz.hum.x - mz.robs[i].x;
			int robY = mz.hum.y - mz.robs[i].y;
			mz.robs[i].x += (robX/abs(robX));
			mz.robs[i].y += (robY/abs(robY));
		}
	}
	
	// Collide robots ///////////////////////////////////
	for(int i = 0; i < mz.nrRobots; i++) {
		if(!mz.robs[i].alive)
			continue;			
			
		// colide with other robs
		for(int j = i + 1; j < mz.nrRobots; j++)
			collide(mz.robs[i], mz.robs[j]);
			
		// colide with posts
		for(int j = 0; j < mz.nrPosts; j++)
			collide(mz.robs[i], mz.posts[j]);
	}
	
	// check for at least one alive robot
	mz.robotsAlive = false;
	for(int i = 0; i < mz.nrRobots && mz.robotsAlive == false; i++)
		if(mz.robs[i].alive)
			mz.robotsAlive = true;
			
	// check human alive after robots move
	for(int i = 0; i < mz.nrRobots; i++)
		collide(mz.robs[i], mz.hum);
	
	return;
}

enum MenuChoice {M_PLAY, M_RULES, M_EXIT};
enum MenuChoice menu() {
    int menuOption;
    cout << "Menu" << endl;
    cout << "1) Play!" << endl;
    cout << "2) Rules" << endl;
    cout << "3) Exit" << endl;
    while(!read(menuOption) || menuOption < 1 || menuOption > 3) {
        if(cin.eof())
            return M_EXIT;
    }

    enum MenuChoice choices[3]
        = {M_PLAY, M_RULES, M_EXIT};
    return choices[menuOption - 1];
}

void printRules() {
	cout << "Run away from the robots!" << endl;
	cout << "Control movement in 8 directions with: " << endl;
	cout << " Q | W | E - (Up Left   |     Up     | Up Right  )" << endl;
	cout << " A | S | D - (Left      | Don't Move | Right     )" << endl;
	cout << " Z | X | C - (Down Left |     Up     | Down Right)" << endl;
	cout << endl;
}

int game(struct Maze &mz) {
    
    /// loop
    printMaze(mz);
    while(mz.hum.alive && mz.robotsAlive) {    	        
        struct Play pl = getPlay();
        
      	// Check if human moves to valid position
        if(validMove(pl, mz)) {
	        doPlay(pl, mz);
	        printMaze(mz);	        
	} else {
		cout << "You can't move there! Try again!" << endl;
	}
    }
    
    return (mz.hum.alive) ? 1 : 0;
}

int main() {

    srand(time(0));

    // repeat the game as long as the user desires
    bool exit = 0;
    while(!exit) {
        enum MenuChoice choice = menu();
        if(choice == M_PLAY) {
        
		struct Maze mz1;
		if(getMaze(mz1)) {
		    cout << "Starting game!" << endl;
	            printf("Player %s!\n", game(mz1) ? "Wins!" : "Loses :(");
	        }
	        destroyMaze(mz1);

        } else if(choice == M_RULES) {
            printRules();

        } else {
            exit = 1;
        }
    }
    return 0;
} 


