/* 
===============================================================
The "King" class : represents the Piece King.

PUBLIC METHOD SPECIFICATION
   
   getSymbol: retruns the symbol for King

   clone: makes a clone or copy King piece and returns
          that copy
   
   canMove: check for Queen's movement. if the move is successful
            returns true, else false.
	    if the move is in any direction and only one space 
	    move returns true.
	    everyother movement, move returns fasle.
    
=================================================================
*/ 
#ifndef KING_H
#define KING_H


class King;
#include "Board.h"
#include "Piece.h"
#include <iostream>
using namespace std;




class King: public Piece
{
public:
   King (bool col);

   char getSymbol() const;
   bool canMove(const Board& b, int fromX, int fromY, int toX, int toY);
   PiecePtr clone()const ; 

};


#endif
