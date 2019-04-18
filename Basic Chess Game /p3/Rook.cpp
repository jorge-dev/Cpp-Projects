#include "Rook.h"

Rook::Rook(bool col): Piece(col)
{
  
}

PiecePtr Rook::clone()const 
{
    PiecePtr clonePiece;
    clonePiece = new Rook(getColour());
    return clonePiece;
}

char Rook::getSymbol() const
{
    char symbol;
    
    if (!getColour())
	symbol = 'r';
    else 
	symbol = 'R';

    return symbol;
}


bool Rook::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
{

    bool move = false;
    bool vertical = isVertical(fromX,fromY,toX,toY);
    bool horizontal = isHorizontal(fromX,fromY,toX,toY);
    bool pathClear = isPathClear(b,fromX,fromY,toX,toY);

    if (vertical && pathClear)
	move = true;
    else if (horizontal && pathClear)
	move = true;
    else 
	move = false;
	    
    return move;
}

 
