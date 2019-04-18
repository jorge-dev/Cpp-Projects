#ifndef BOARD_H
#define BOARD_H

class Board;
#include "Piece.h"
#include <iostream>
using namespace std;

#define MAXROWS 8
#define MAXCOLS 8

typedef Piece* PiecePtr;

class Board
{
public:
   Board();
   Board (const Board& other);
   ~Board();


   bool move (bool colour ,int fromX, int fromY, int toX, int toY);
   bool place (const PiecePtr& p, int x, int y);
   bool remove (int x, int y);
 
   void write (ostream& out) const;
   bool isOccupied (int x, int y) const;
   PiecePtr getPiece(int x, int y) const;
   
   Board& operator= (const Board& other);
   

private:
   PiecePtr grid[MAXROWS][MAXCOLS];

   void initBoard();
   void clearBoard();
   void copyBoard(const Board& other);

};

ostream& operator<< (ostream& out, const Board& b);

#endif
