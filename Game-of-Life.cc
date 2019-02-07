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

void GameBoard::checkNeigbors(GameBoard Gboard){
	int neighbors = 0;
	for(int i = 1; i < totalRows - 1; i++){
		for(int j = 1; j < totalCols - 1; j++){
			if(board_[i-1][j-1] == Organism::LIVING || board_[i-1][j-1] == Organism::DYING)
				neighbors++;

			if(board_[i][j-1] == Organism::LIVING || board_[i][j-1] == Organism::DYING)
				neighbors++;
			
			if(board_[i+1][j-1] == Organism::LIVING || board_[i+1][j-1] == Organism::DYING)
				neighbors++;
			
			if(board_[i-1][j] == Organism::LIVING || board_[i-1][j] == Organism::DYING)
				neighbors++;
			
			if(board_[i-1][j+1] == Organism::LIVING || board_[i-1][j+1] == Organism::DYING)
				neighbors++;
			
			if(board_[i+1][j] == Organism::LIVING || board_[i+1][j] == Organism::DYING)
				neighbors++;

			if(board_[i][j+1] == Organism::LIVING || board_[i][j+1] == Organism::DYING)
				neighbors++;
			
			if(board_[i+1][j+1] == Organism::LIVING || board_[i+1][j+1] == Organism::DYING)
				neighbors++;

			if ((neighbors < 2 || neighbors > 3) && board_[i][j] == Organism::LIVING)
				Gboard.set(i, j, Organism::DYING);
			
			//else if ((neighbors == 2 || neighbors == 3) && board_[i][j] == Organism::NONE)
				//Gboard.set(i, j, Organism::GESTATING);
				
			cout << neighbors;
			neighbors = 0;
			
		}
			
	}			
		
}

void GameBoard::updateBoard(int countGen, GameBoard Gboard){
	cout << ESC << "[H" << "Generation " << countGen << ":" << endl;

	for(int i = 0; i < totalRows - 1; i++){
		for(int j = 0; j < totalCols - 1; j++){
			if(board_[i][j] == Organism::GESTATING)
				Gboard.set(i, j, Organism::LIVING);
	
			else if (board_[i][j] == Organism::DYING)
				Gboard.set(i, j, Organism::NONE);
		}
	
	}

	for(int x = 0; x < totalCols; x++){
			if(x == 0 || x == totalCols - 1)
				cout << "+";
			else	
				cout << "-";
		}
					 
		for(int i = 1; i < totalRows - 1; i++){
			cout << "\n|";
			for(int j = 1; j < totalCols - 1; j++){
				if(board_[i][j] == Organism::LIVING || board_[i][j] == Organism::GESTATING)
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
	int countGen = 1;
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
	
	

	while(countGen < generations){
		cout << ESC << "[23;1H" << ESC << "[K" << "Press RETURN to continue";
		while (cin.get() != '\n') {            
			//intentionally empty loop body
	 	}	
		Gboard.checkNeigbors(Gboard);
		Gboard.updateBoard(countGen, Gboard);
		countGen++;
	} 
	//check neighbors

return 0;
}
