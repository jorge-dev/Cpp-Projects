/* 
===============================================================
The "Queen" class : represents the Piece Queen.

PUBLIC METHOD SPECIFICATION
   
   getSymbol: retruns the symbol for Queen

   clone: makes a clone or copy Queen piece and returns
          that copy
   
   canMove: check for Queen movement. if the move is successful
            returns true, else false.
	    if the move is in any direction and and there is not 
	    a piece in between the starting and finish position,
	    move returns true
	    everyother movement move returns false.
    
=================================================================
*/ 
#ifndef QUEEN_H
#define QUEEN_H


class Queen;
#include "Board.h"
#include "Piece.h"
#include <iostream>
using namespace std;


class Queen: public Piece
{
public:
   Queen (bool col);
   
   PiecePtr clone()const ; 
   char getSymbol() const;
   bool canMove(const Board& b, int fromX, int fromY, int toX, int toY);
 
};


#endif
