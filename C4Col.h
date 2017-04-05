//Author : Thibault joseph twahirwa .
 // cse 20312  lab 1 
// -----------------------------------------
// File: C4Col.h 
// CLASS PROVIDED: C4Col.h --------
//
// CONSTRUCTOR  for C4Col class:
// C4C
//
// MODIFICATION MEMBER FUNCTIONS FOR C4Col class
//   int isFull()
//   postcondition : 
//
//   char getDist(int)
//   postcontition : 
//
//   void addDisc(char)
//   postcondition:
//
//CONSTANT MEMBER FUNCTIONS FOR C4COL class 
//
//  int Maxdiscs;
//  int numDisc;
//
//
#ifndef _C4COL_H_
#define _C4COL_H_
 
class C4Col{
	public:
       C4Col();                      //Default constructor  
       ~C4Col();                    // Deconstructor 
       C4Col operator+=(char);  
       int isFull();                 //check if column is full return 1 if full and 0 otherwise
	   char getDisc(int a);   // Returns element  from a given colum 
       int getMaxDiscs();      // get the maxDisc 
	   void addDisc(char newDisc);           // add one of following characters :'X' or 'O' O
       int getNumDisc();             // returns the number of discs available in column
	private:
	
		int maxDiscs;               // maximum number of discs, 
		int numDiscs;               // current number of discs available
		char Discs[6];              // storage area for disc chars
};

#endif 
  
