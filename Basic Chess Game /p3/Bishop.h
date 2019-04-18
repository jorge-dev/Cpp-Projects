/* 
===============================================================
The "Bishop" class : represents the Piece Bishop.

PUBLIC METHOD SPECIFICATION
   
   getSymbol: retruns the symbol for Bishop

   clone: makes a clone or copy Bishop piece and returns
          that copy
   
   canMove: check for Bishop's movement. if the move is successful
            returns true, else false.
	    if the move is in any direction diagonally and there 
	    is not a piece in between the starting and finish 
	    position, move returns true 
	    everyother movement returns fasle.
    
=================================================================
*/ 
#ifndef BISHOP_H
#define BISHOP_H


class BISHOP;
#include "Board.h"
#include "Piece.h"
#include <iostream>
using namespace std;


class Bishop: public Piece
{
public:
   Bishop (bool col);

   char getSymbol() const;
   PiecePtr clone()const ;   
   bool canMove(const Board& b, int fromX, int fromY, int toX, int toY);
  
};


#endif
