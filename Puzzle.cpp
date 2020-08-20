// thibault Joseph Twahirwa
// CSE 20312, Lab 4
//
// Puzzle class implementation


#include <iostream>
#include <fstream>
#include "Puzzle.h"

using namespace std;

Puzzle::Puzzle( string puzzleFile )		        // constructor 
{
    inFile.open(puzzleFile.c_str(), ios::in);   // opens the puzzlefile for input
    int tempVar;                                // temporary variable used to store puzzle values
    vector<int> temp;                           // temporary vector stores each row one at a time
    for(int i=0; i<9; i++) {
        temp.clear();                           // clear the previous row out
        for(int j=0; j<9; j++) {
            inFile >> tempVar;                  // read in row i one variable at a time
            temp.push_back(tempVar);            // add the row variables to tempVect
        }
        board.push_back(temp);                  //construct board 
    }
    inFile.close();                
}

void Puzzle::solve()
{
    checkPosVals();					// gets the initial possibilities established
    checkHoriz();
    checkVert();
    checkminigrid();
    cout << endl << "Original given board: " << endl << endl;

    printBoard();

    while( solveInit() || solveHoriz() || solveVert() || solveminigrid() )		// while the solving functions can still add solutions
    {
        checkPosVals();
        checkHoriz();
        checkVert();
        checkminigrid();
    }
    cout << "Final solved  board: " << endl << endl;
    printBoard();
}

void Puzzle::checkPosVals()				// fills the 3dimensional vector with possibilities 1-9
{
    vector<int> temp1;				        
    vector< vector<int> > temp2;			
    possibleVals.clear();					// clear the possibilities

    for( int row = 0; row < board.size(); row++ )
    {
        for( int col = 0; col < board[row].size(); col++ )
        {
            if( board[row][col] == 0 )	// only need to list possibilities for zero spaces
            {
                for( int i = 1; i <= 9; i++ )	// values of 1 through 9
                {
                    temp1.push_back(i);
                }
            }
            temp2.push_back( temp1 );	// populating 2D vector with 1D vectors
            temp1.clear();			// clear this vector
        }
        possibleVals.push_back( temp2 );		// populating the possibilities 3D vector with 2D vectors
        temp2.clear();				// clear this vector
    }	
}

void Puzzle::checkHoriz()				// at every position, check possibilities based on horizontal members
{
    for( int row = 0; row < board.size(); row++ )
    {
        for( int col = 0; col < board[row].size(); col++ )
        {
            for( int i = 0; i < 9; i++ )		// checking every column (horizontal)
            {
                if( col == i )	continue;			// skip checking
                else if( board[row][i] == 0 )	continue;	
                else
                {
                    for( int j = 0; j < possibleVals[row][col].size(); j++ )	// for every possibility remaining
                    {
                        if( board[row][i] == possibleVals[row][col][j] )
                        {
                            possibleVals[row][col].erase( possibleVals[row][col].begin() + j );	// remove that possibility if found in row
                        }
                    }
                }
            }
        }
    }
}

void Puzzle::checkVert()				// at every position, check possibilities based on vertical members
{
    for( int row = 0; row < board.size(); row++ )
    {
        for( int col = 0; col < board[row].size(); col++ )
        {
            for( int i = 0; i < 9; i++ )		// checking every row (vertical)
            {
                if( row == i )	continue;			
                else if( board[i][col] == 0 )	continue;	
                else
                {
                    for( int j = 0; j < possibleVals[row][col].size(); j++ )	// for every possibility remaining
                    {
                        if( board[i][col] == possibleVals[row][col][j] )
                        {
                            possibleVals[row][col].erase( possibleVals[row][col].begin() + j );	// remove that possibility if found in row
                        }
                    }
                }
            }
        }
    }
}

void Puzzle::checkminigrid()				// at every position, check possibilities based on containing minigrid
{
    int gridSize = 3;
    int colStart;					// find the beginning column index
    int rowStart;					// find the beginning row index

    for( int row = 0; row < board.size(); row++ )
    {
        for( int col = 0; col < board[row].size(); col++ )
        {
            if( row < gridSize )		rowStart = 0;			// determine the row and col to begin the search
            else if( row < 2*gridSize )	rowStart = gridSize;
            else				rowStart = 2*gridSize;

            if( col < gridSize )		colStart = 0;
            else if( col < 2*gridSize )	colStart = gridSize;
            else				colStart = 2*gridSize;

            for( int r = rowStart; r < (rowStart + 3); r++ )		// row within minigrid
            {
                for( int c = colStart; c < (colStart + 3); c++ )	// column within minigrid
                {
                    if( row == r && col == c )	continue;	// skip checking against itself
                    else if( board[r][c] == 0 )	continue;	// zero spaces cannot help us
                    else
                    {
                        for( int j = 0; j < possibleVals[row][col].size(); j++ )	// for every possibility remaining
                        {
                            if( board[r][c] == possibleVals[row][col][j] )
                            {
                                possibleVals[row][col].erase( possibleVals[row][col].begin() + j );	// remove that possibility if found in row
                            }
                        }
                    } 
                }
            }
        }
    }
}

bool Puzzle::solveInit()				// enter solutions if there are single possibilities
{
    bool boolReturn = false;

    for( int row = 0; row < board.size(); row++ )
    {
        for( int col = 0; col < board[row].size(); col++ )
        {
            if( possibleVals[row][col].size() == 1 )	// singleton that can be chosen right away
            {
                board[row][col] = possibleVals[row][col][0];
                boolReturn = true;
            }
        }
    }

    return boolReturn;
}

bool Puzzle::solveHoriz()				// fill in the board based on singletons in each column
{
    bool unique = false;				// if unique possibility (singeton) found
    bool boolReturn = false;			// boolean to return true if sol added
    for( int row = 0; row < board.size(); row++ )
    {
        for( int col = 0; col < board[row].size(); col++ )
        {
            for( int currPoss = 0; currPoss < possibleVals[row][col].size(); currPoss++ )		// for every possibility in the current index
            {
                for( int i = 0; i < 9; i++ )				// checking every column (horizontal)
                {
                    if( col == i )	continue;				// skip checking against itselfi
                    else if( possibleVals[row][i].size() == 0 )	continue;	// skip empty
                    else
                    {
                        for( int checkPoss = 0; checkPoss < possibleVals[row][i].size(); checkPoss++ )	// for every possibility being checked
                        {
                            if( possibleVals[row][col][currPoss] == possibleVals[row][i][checkPoss] )	
                            {
                                unique = false;
                                break;
                            }
                            else	unique = true;
                        }

                        if( !unique ) 	break;	
                    }
                }

                if( unique )		// we have a unique possibility in the row
                {
                    board[row][col] = possibleVals[row][col][currPoss];
                    boolReturn = true;
                    unique = false;
                }
            }
        }
    }

    return boolReturn;
}

bool Puzzle::solveVert()				// fill in the board based on singletons in each row
{
    bool unique = false;				// if unique possibility (singleton) found
    bool boolReturn = false;			
   for( int row = 0; row < board.size(); row++ )
    {
        for( int col = 0; col < board[row].size(); col++ )
        {
            for( int currPoss = 0; currPoss < possibleVals[row][col].size(); currPoss++ )		// for every possibility in the current index
            {
                for( int i = 0; i < 9; i++ )		// checking every row (vertical)
                {
                    if( row == i )				continue;		// skip checking against itself
                    else if( possibleVals[i][col].size() == 0 )	continue;		// skip empty
                    else
                    {
                        for( int checkPoss = 0; checkPoss < possibleVals[i][col].size(); checkPoss++ )	// for every possibility being checked
                        {
                            if( possibleVals[row][col][currPoss] == possibleVals[i][col][checkPoss] )	
                            {
                                unique = false;
                                break;
                            }
                            else	unique = true;	
                        }	

                        if( !unique ) 	break;
                    }
                }

                if( unique )		// we have a unique possibility in the row
                {
                    board[row][col] = possibleVals[row][col][currPoss];	
                    boolReturn = true;
                    unique = false;
                }
            }
        }
    }

    return boolReturn;
}

bool Puzzle::solveminigrid()				// at every position, isolate possibilities based on containing minigrid
{
    int gridSize = 3;
    int colStart;					
    int rowStart;					

    bool unique = false;				
    bool boolReturn = false;			

    for( int row = 0; row < board.size(); row++ )
    {
        for( int col = 0; col < board[row].size(); col++ )
        {
            if( row < gridSize )		rowStart = 0;			// determine the row and col to begin the search
            else if( row < 2*gridSize )	rowStart = gridSize;
            else				rowStart = 2*gridSize;

            if( col < gridSize )		colStart = 0;
            else if( col < 2*gridSize )	colStart = gridSize;
            else				colStart = 2*gridSize;

            for( int currPoss = 0; currPoss < possibleVals[row][col].size(); currPoss++ )	// for every possibility in the current position
            {
                for( int r = rowStart; r < (rowStart + 3); r++ )		// row within minigrid
                {	
                    for( int c = colStart; c < (colStart + 3); c++ )	// column within minigrid
                    {
                        if( row == r && col == c )		continue;	// skip checking against itself
                        else if( possibleVals[r][c].size() == 0 )	continue;	// skip empty
                        else
                        {
                            for( int checkPoss = 0; checkPoss < possibleVals[r][c].size(); checkPoss++ )	// for every possibility being checked
                            {
                                if( possibleVals[row][col][currPoss] == possibleVals[r][c][checkPoss] )	
                                {
                                    unique = false;
                                    break;
                                }
                                else	unique = true;
                            }

                            if( !unique ) 	break;
                        } 
                    }

                    if( !unique )	break;
                }

                if( unique )
                {
                    board[row][col] = possibleVals[row][col][currPoss];
                    boolReturn = true;
                    unique = false;
                }
            }
        }
    }

    return boolReturn;
}

void Puzzle::printBoard()				// prints the 2D board to the screen
{
    int RowCounter = 0;				
    int colCounter = 0;
    cout << " -------------------------" << endl;
    cout << " |";	
    for( int i = 0; i < board.size(); i++ )
    {
        if( RowCounter == 3 )
        {
            cout << " -------------------------" << endl;
            RowCounter = 0;		
        }
        for( int j = 0; j < board[i].size(); j++ )
        {
            if( colCounter == 3 )	
            {
                cout << " |";			
                colCounter = 0;
            }			
            cout << " " << board[i][j];
            colCounter++;
        }

        cout << " |";	
        RowCounter++;
        cout << endl;
    }
    cout << " -------------------------" << endl << endl;	
}

