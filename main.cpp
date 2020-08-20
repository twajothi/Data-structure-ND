// Thibault Joseph Twahirwa
// Lab 4, cse20312
//
// main driver 
// generate board fromfile input and solve 

#include <iostream>
#include "Puzzle.h"
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{

    // read in a filename from the user. Do not run the program if the file does not exist
    ifstream inFile;    // object for reading from a file
    string puzName;
    cout << "\nPlease enter the full file name of the textfile containing the sudoku puzzle.\nFilename: ";
    cin >> puzName;
    inFile.open(puzName.c_str(), ios::in);  // opens the puzzlefile for input
    if(! inFile) {
        cout << "Error File does not exist."<< endl;
        return 1;
    }

    inFile.close();
    Puzzle sudoku( puzName );
    sudoku.solve();

    return 0;
}
