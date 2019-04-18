/* 
===============================================================
The "Rook" class : represents the Piece Rook.

PUBLIC METHOD SPECIFICATION
   
   getSymbol: retruns the symbol for Rook

   clone: makes a clone or copy Rook piece and returns
          that copy
   
   canMove: check for Rook movement. if the move is successful
            returns true, else false.
	    if the move is in any direction vertically or horizontally 
	    and and there is not a piece in between the starting 
	    and finish position,move returns true
	    everyother movement move returns false.
    
=================================================================
*/ 
#ifndef ROOK_H
#define ROOK_H


class Rook;
#include "Board.h"
#include "Piece.h"
#include <iostream>

using namespace std;




class Rook: public Piece
{
public:
   Rook (bool col);

   PiecePtr clone()const;
   char getSymbol() const;
   bool canMove(const Board& b, int fromX, int fromY, int toX, int toY);
   
};


#endif
