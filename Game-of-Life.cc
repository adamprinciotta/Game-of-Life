#include <iostream>
#include <string>
#include "Game-of-Life.h"
using std::cout;
using std::cin;
using std::endl;

static const char ESC = 27; //at the start

//cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl; //just before displaying the initial board
//cout << ESC << "[H" << "Generation " << some variable << ":" << endl; //just before displaying each board after the initial

//cout << ESC << "[23;1H" << ESC << "[K"
//<< "Press RETURN to continue";
//while (cin.get() != ‘\n') {            // intentionally empty loop body   }


//while (cin.get() != '\n') { }
Organism GameBoard::get(unsigned row, unsigned col){
	return board_[row][col];
}
void GameBoard::set(unsigned row, unsigned col, Organism status){
	board_[row][col]=status;
}


void GameBoard::initialBoard(){
	for(int i = 0; i < totalRows; i++){
		for(int j = 0; j < totalCols; j++){
			set(i,j,Organism::NONE);
		}
	}
}
void GameBoard::makeBoard(){
	cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;
	for(int x = 0; x < totalCols; x++){
		if(x == 0 || x == totalCols - 1)
			cout << "+";
		else	
			cout << "-";
	}
				 
	for(int i = 1; i < totalRows - 1; i++){
		cout << "\n|";
		for(int j = 1; j < totalCols - 1; j++){
			if(board_[i][j] == Organism::LIVING)
				cout << "*";
			else
				cout << " ";
		}
		cout << "|";
	} 
	cout << endl;
	for(int x = 0; x < totalCols; x++){
		if(x == 0 || x == totalCols - 1)
			cout << "+";
		else	
			cout << "-";
	}
	cout << endl;
}


int main(){
	
	GameBoard Gboard;
	Gboard.initialBoard();

	int initOrg;
	int generations;
	int x;
	int y;

	cout << "How many organisms intitally?: ";
	cin >> initOrg;
	cout << endl;

	cout << "Locations?: ";
	
	for(int i = 0; i < initOrg; i++){
		cin >> x >> y;
		cout << x << " " << y << endl;
		Gboard.set(x + 1, y + 1, Organism::LIVING);

	}
	
	cout << "Generations?: ";
	cin >> generations;
	cout << endl;

	Gboard.makeBoard();
	//make updateBoard
	//check neighbors

return 0;

}
