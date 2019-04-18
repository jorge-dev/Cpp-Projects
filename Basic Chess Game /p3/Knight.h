/* 
===============================================================
The "Knight" class : represents the Knight

PUBLIC METHOD SPECIFICATION
   
   getSymbol: retruns the symbol for Knight

   clone: makes a clone or copy Knight piece and returns
          that copy
   
   canMove: check for Knight movement. if the move is successful
            returns true, else false.
	    if the move is in any direction and the move is 2 
	    spaces horizontally and 1 vertically or 1 horizontally
	    and 2 vertically,move returns true.
	    everyother movement move returns false.
    
=================================================================
*/ 
#ifndef KNIGHT_H
#define KNIGHT_H


class Knight;
#include "Board.h"
#include "Piece.h"
#include <iostream>
using namespace std;




class Knight: public Piece
{
public:
   Knight (bool col);
   
   PiecePtr clone()const ; 
   char getSymbol() const;
   bool canMove(const Board& b, int fromX, int fromY, int toX, int toY);
   
};


#endif
