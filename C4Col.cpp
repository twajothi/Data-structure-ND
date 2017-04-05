/*Thibault joseph Twahirwa
 * CSE 20312, lab1
 * implementation of member function 
 * for class C4Col.h
 */



#include <iostream>
#include <iomanip>
#include "C4Col.h"

using namespace std;
  C4Col::C4Col(){  
        numDiscs = 0;           // initialize each column with 0 discs and max capacity discs is 6
        maxDiscs = 6;
       for ( int i = 0; i <= 5; i++){
        Discs[i] = ' ';        //  set disc value in each column to empty
    }
  }
 C4Col::~C4Col(){
 // delete columns content
 }
 C4Col C4Col::operator+=(char c){
   addDisc(c);
   return (*this);
}

// int isFull ()
int C4Col::isFull() {
    if ( numDiscs >=6){
        return 1;
    }  
   else return 0;
}

// int getMaxDiscs()
int C4Col::getMaxDiscs () {
     return maxDiscs;
   }  

// Char getDisc
char C4Col::getDisc(int a) {  
    if (a >=0&&a <=5){
    return Discs[a];
    } else {
     cout <<  "Error : out of range selection." << endl;
    }
}
// addDisc 
void C4Col::addDisc( char newDisc ) {
    if ( isFull()){  cout << " this column is full " << endl;
    } else { 
    Discs[numDiscs] = newDisc;
    numDiscs++;
    }
}

// int C4Col::getNumDisc
int C4Col::getNumDisc() {
  return (numDiscs);       
 }
