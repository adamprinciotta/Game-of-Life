#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_
#include <iostream>
using std::istream;

enum class Organism {NONE, GESTATING, LIVING, DYING};


class GameBoard{
public:
	Organism get(unsigned row, unsigned col);
	void set(unsigned row, unsigned col, Organism status);	
	void initialBoard();
	void makeBoard();
	void updateBoard(int countGen);
	void checkNeigbors();


private:
	static const int activeRows = 18;
	static const int activeCols = 50;
	static const int totalRows = activeRows + 2;
	static const int totalCols = activeCols + 2;
	Organism board_[totalRows][totalCols];

};

#endif //GAMEOFLIFE_H_
