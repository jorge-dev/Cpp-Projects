/*
 ===============================================================
The "Board" class : represents an 8 x 8 Board of pointers.

PUBLIC METHOD SPECIFICATION
    move: given from and to coordinates, it moves the piece from 
          from coordinates to to coordinates,if successfull returns
	  true else false
    
    isOccupied: checks if a position in board is NULL or not.
                if not NULL return true else false;
		
    remove: removes a piece from a board only if the given piece
            is not NULL. returns true is successful, else otherwise
    
    write: displays a 8 x 8 board 

    place: places a piece in the board if the position where the piece
           is going to be placed is not occupied. returns true if
	   successful, false otherwise.

    getPiece: returns a copy of a piece from a specified position
              returns a copy pointer to that location, if location
	      is NULL, the pointer returned is also NULL.
    
=================================================================
*/

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
