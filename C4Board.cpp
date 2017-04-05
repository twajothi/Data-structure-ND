/* Thibault Joseph Twahirwa
 * Cse20312
 *  Class for the Connect 4 board
*/



#include "C4Board.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include "C4Col.h"
using namespace std;

C4Board::C4Board() { //default constructor
	numCols = 7;
    computer = 0;
   
	for(int i= 0;i< numCols;i++) {
		C4Col board[i]; 
	}
}
C4Board::~C4Board() {
     //delete[]  board; 
}
int C4Board::ComputerAction() { // once playing with a computer 
	return (rand()%numCols); //    random numbers generated in case you are playing with computer
}
void C4Board::display() { //displays intro to game
	cout << "Welcome to Connect 4: Text Edition!" << endl;

}
int C4Board::getCols() {

	return numCols; //returns the number of columns
}
void C4Board::play() {         //play the game
	int Choice = 0,  won = 0;
	int turn;

	display();
	setComputer();
	while(Choice!=-1&&won==0) {
		turn = (turn%2) + 1;
		if(turn==1) {
			userChar = 'X';
			cout << "Player " << turn << " - your turn : ";
			cin >> Choice;
		} else {
			if(computer) {
				Choice = ComputerAction();
			} else {
				cout << "Player " << turn << " - your turn: ";
				cin >> Choice;
			}
			userChar = 'O';
		}
		if(Choice>0&&Choice<=numCols) { 
			board[Choice-1]+=userChar;
			display();
			cout << (*this);
		} else if(Choice==-1) {
			cout << "Thank you for playing!" << endl;

		} else {
			cin.clear();
			cin.ignore();
			cout << "Error: Inacceptable input! turn skipped..." << endl;
		}
		cout << endl;
		won = winner();
	}
	if(won) {

		cout << "Congratulations Player " << won << ", you win!" << endl;
	}
}
void C4Board::setComputer() { //determines if Computer is active in game
	cout << " Do you wnat to play with Computer? (1- yes; 0- no)" << endl;
	cin >> computer;
	if(computer!=1&&computer!=0) {
		cout << " invalid input" << endl;
	}
}
int C4Board::winner() { 
	int playerOneMarks = 0; // initialize trackers 
	int playerTwoMarks = 0;

	for(int i=0;i<numCols;i++) { //check for vertical win
		for(int j=0;j<(board[i].getMaxDiscs());j++) {
			if(board[i].getDisc(j)=='X') { 
				playerOneMarks++;
				break;
			} else if(board[i].getDisc(j)=='O') { 
				playerTwoMarks++;
				break;
			} else { 
				playerOneMarks = 0; 
				playerTwoMarks = 0; 
			}
			if(playerOneMarks==4) {  
				return 1; 
			} else if(playerTwoMarks==4) {
				return 2; 
			} 
		}
	}
	playerOneMarks=0;
	playerTwoMarks=0;
	for(int j=0;j<(board[0].getMaxDiscs());j++) { //check for horizontal win 
		for(int i=0;i<numCols;i++) {
			if(board[i].getDisc(j)=='X') { 
				playerOneMarks++;
				break;
			} else if(board[i].getDisc(j)=='O') { 
				playerTwoMarks++;
				break;
			} else {
				playerOneMarks = 0; 
				playerTwoMarks = 0; 
			}
			if(playerOneMarks==4) {
				return 1; 
			} else if(playerTwoMarks==4) {
				return 2;
			} 
		}
	}
	playerOneMarks=0;
	playerTwoMarks=0;
	for(int j=0;j<(board[0].getMaxDiscs());j++) { //diagonal winner check 
		for(int i=j;i<numCols;i++) {
			if(board[i].getDisc(j)=='X') { //player 1 mark
				playerOneMarks++;
				break;
			} else if(board[i].getDisc(j)=='O') { //player 2 mark
				playerTwoMarks++;
				break;
			} 
			if(playerOneMarks==4) {
				return 1; //player 1 has won
			} else if(playerTwoMarks==4) {
				return 2; //player 2 has won
			} 
		}
	}
	playerOneMarks = 0;
	playerTwoMarks = 0;

	for(int j=0;j<(board[0].getMaxDiscs());j++) { //diagonal bottom-left to top-right victory
		for(int i=numCols-1;i>=0;i--) {
			if(board[i].getDisc(j)=='X') { //player 1 mark
				playerOneMarks++;
				break;
			} else if(board[i].getDisc(j)=='O') { //player 2 mark
				playerTwoMarks++;
				break;
			} 
			if(playerOneMarks==4) {
				return 1; //player 1 has won
			} else if(playerTwoMarks==4) {
				return 2; //player 2 has won
			} 
		}
	}

	return 0; //no winner detected
}
ostream &operator<<(ostream &output, C4Board &b ) {
	for(int i=1;i<=b.numCols;i++) {
		output << "  #" << i;
	}
	output << endl;
	for(int i=b.board[0].getMaxDiscs()-1;i>=0;i--) {
		for(int j=0;j<b.numCols;j++) {
			output << " | " << b.board[j].getDisc(i);
			if(j==b.numCols-1) {
				output << " |";
			}
		}
		output << endl;
	}
return output;
}
