/*
 ===============================================================
The "Piece" class : represents an abstraction for a chess Piece.

PUBLIC METHOD SPECIFICATION
   
   getSymbol: retruns the symbol of a piece

   getColour: retruns a bool value representing a color.
              true is white, false is black.
   
   clone: makes a clone or copy of a specified piece and returns
          that copy
   
   canMove: checks for a pieces defined rules to determined it 
            a move is valid or not.
    
=================================================================
*/
#ifndef PIECE_H
#define PIECE_H


class Piece;
#include "Board.h"
#include <iostream>
#include <cmath>
using namespace std;


#define WHITE true
#define BLACK false

typedef Piece* PiecePtr;

class Piece
{
public:
   Piece (bool col);

  virtual char getSymbol() const = 0;
  bool getColour() const;
  virtual PiecePtr clone()const =0; 
  virtual bool canMove(const Board& b, int fromX, int fromY, int toX, int toY)=0;
   

private:
   bool colour;


protected:
 bool isPathClear(const Board& b, int fromX, int fromY, int toX, int toY)const;
   bool isVertical (int fromX, int fromY, int toX, int toY) const;
   bool isHorizontal (int fromX, int fromY, int toX, int toY) const;
   bool isDiagonal (int fromX, int fromY, int toX, int toY) const;
   bool isForward (int fromX, int toX) const;
   int vertDistance (int fromX, int toX) const;
   int horizDistance (int fromY, int toY) const;
};


#endif
