//T01_G11
#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include "Post.h"
using namespace std;

class Maze {
public:
	Maze();
	Maze(int numRows, int numCols); // Inicialize the variables of the size of the maze
	void setRowCol(int Row, int Col); // Receive the size of the maze
	void VectorPosts(string maze_directory); // Create a vector of posts
	int getnumRows() const; // Return the numbers of rows of the maze
	int getnumCols() const; // Return the numbers of cols of the maze
	vector<Post> PostsVector; // Create a vector of posts
private:
	int numRowsMaze, numColsMaze, numLine;
	string lineMaze;
};