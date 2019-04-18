#include "Knight.h"

Knight::Knight(bool col):Piece(col)
{
  
}


PiecePtr Knight::clone()const 
{
    PiecePtr clonePiece;
    clonePiece = new Knight(getColour());
    return clonePiece;
}

char Knight::getSymbol() const
{
    char symbol;
    
    if (!getColour())
	symbol = 'n';
    else 
	symbol = 'N';

    return symbol;
}


bool Knight::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
{

    bool move=false;

    int vDistance = vertDistance(fromX,toX);
    int hDistance = horizDistance(fromY,toY);
   
   
    if (hDistance == 2)
    {
	if(vDistance == 1)
	    move = true;
    }
    else if (hDistance == 1)
    {
	if (vDistance == 2)
	    move = true;
    }
    else
	move = false;
    
    
    return move;
}
