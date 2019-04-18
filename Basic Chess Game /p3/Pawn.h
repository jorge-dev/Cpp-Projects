/* 
===============================================================
The "Pawn" class : represents the Piece Pawn.

PUBLIC METHOD SPECIFICATION
   
   getSymbol: retruns the symbol for Pawn

   clone: makes a clone or copy Pawn piece and returns
          that copy
   
   canMove: check for Pawn's movement. if the move is successful
            returns true, else false.
	    if Pawn is in starting position and the move 1 or 2
	    forward spaces, move returns true.
	    if Pawn has moved and the move is one space forward,
	    move returns true.
	    if Pawn is in any position and the move is diagonal
	    forward and a different color piece is in the position
	    wanted to move to, move returns true.
	    everyother movement is false.
    
=================================================================
*/
#ifndef PAWN_H
#define PAWN_H


class Pawn;
#include "Piece.h"
#include "Board.h"
#include <iostream>
using namespace std;



class Pawn: public Piece
{
public:
   Pawn (bool col);

   
   char getSymbol() const;

   bool canMove(const Board& b, int fromX, int fromY, int toX, int toY);
   
   PiecePtr clone()const ; 
    
private:
   
   bool hasMoved;

};


#endif
