#ifndef PIECE_H
#define PIECE_H


class Piece;
#include "Board.h"
#include <iostream>
#include <cmath>
using namespace std;


#define WHITE true
#define BLACK false

class Piece
{
public:
   Piece (bool col);

   char getSymbol() const;
   bool getColour() const;

   bool canMove(const Board& b, int fromX, int fromY, int toX, int toY);
   
private:
   bool colour;
   bool hasMoved;

   bool isVertical (int fromX, int fromY, int toX, int toY) const;
   bool isHorizontal (int fromX, int fromY, int toX, int toY) const;
   bool isDiagonal (int fromX, int fromY, int toX, int toY) const;
   bool isForward (int fromX, int toX) const;
   int vertDistance (int fromX, int toX) const;
   int horizDistance (int fromY, int toY) const;
};


#endif
