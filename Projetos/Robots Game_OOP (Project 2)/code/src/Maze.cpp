//T01_G11
#include "../include/Maze.h"

Maze::Maze() { }

Maze::Maze(int numRows, int numCols)
{
	numLine = 0;
	numRowsMaze = numRows;
	numColsMaze = numCols;
}

void Maze::setRowCol(int Row, int Col)
{
	numRowsMaze = Row;
	numColsMaze = Col;
}

void Maze::VectorPosts(string mazeDirectory)
{
	ifstream mazeFile; mazeFile.open(mazeDirectory);
	while (!mazeFile.eof()) {
		getline(mazeFile, lineMaze);
		for (int i = 0; i < lineMaze.size(); i++) {
			if (lineMaze[i] == '+') { Post post(numLine, i, '+'); PostsVector.push_back(post); }
			else if (lineMaze[i] == '*') { Post post(numLine, i, '*'); PostsVector.push_back(post); }
			else if (lineMaze[i] == 'O') { Post post(numLine, i, 'O'); PostsVector.push_back(post); }
		}

		numLine++;
	}
	mazeFile.close();
}

int Maze::getnumRows() const
{
	return numRowsMaze;
}

int Maze::getnumCols() const
{
	return numColsMaze;
}
