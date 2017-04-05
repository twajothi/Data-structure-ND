/*
 * Thibault Joseph Twahirwa 
 * cse 20312 
 * lab 1
 * header file for class C4Board 
 *
 */
#include "C4Col.h"
#include <iostream>
#ifndef _C4Board_H_
#define _C4Board_H_

using std::ostream;
using std::istream;

class C4Board {
      friend ostream & operator<<( ostream &, C4Board &);
      friend istream & operator>>( istream &, C4Board &);


    public :
       C4Board();       // constructor  
       ~C4Board();     // default deconstructor  
       void display(); // function to display the current board 
       void play();    // allows two players to play this game
       void setComputer(); // chosen when human against computer
       int getCols();    //get number of columns 

    private : 
        int numCols;
        C4Col board [7];
        int computer;   // to check once computer is active
        int ComputerAction(); // computer playing generating random position
        int winner();        // identify the winner 
        char userChar;     // players's symbols
};

#endif
