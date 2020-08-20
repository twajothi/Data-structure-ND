// Thibault Joseph Twahirwa
//
// Puzzle class
// has constructor, solver, print

#ifndef PUZZLE_H
#define PUZZLE_H

#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;
class Puzzle			
{
	public:
		Puzzle( string );		// constructor takes in file that has few content
		void solve();			// solves the sudoku puzzle
		void printBoard();		// prints results and initial tables
	
    private:
		void checkPosVals();		// check possibilities and create a 3D vector of possibilities
	
		void checkHoriz();		// helper function to remove possibilities if contained in column
		void checkVert();		// helper function to remove possibilities if contained in row
		void checkminigrid();		// helper funciton to remove possibilities if contained in minigrid
		bool solveInit();		// helper function to fill in singletons
		bool solveHoriz();		// helper function to fill in singletons if contained in column (all return true if solution added)
		bool solveVert();		// helper function to fill in singletons if contained in row
		bool solveminigrid();		// helper function to fill in singletons if contained in minigrid

		vector< vector<int> > board;		// board is stored as a 2D vector
		vector< vector< vector<int> > > possibleVals;	// 3d vector that stores the possible valid vales for each cell in the puzzle
        ifstream inFile;                        // object for reading a file
};

#endif
