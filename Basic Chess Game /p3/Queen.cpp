#include "Queen.h"

Queen::Queen(bool col):Piece(col)
{
    
}

PiecePtr Queen::clone()const 
{
    PiecePtr clonePiece;
    clonePiece = new Queen(getColour());
    return clonePiece;
} 

char Queen::getSymbol() const
{
    char symbol;
    
    if (!getColour())
	symbol = 'q';
    else 
	symbol = 'Q';

    return symbol;
}


bool Queen::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
{

    bool move=false;
    bool vertical = isVertical(fromX,fromY,toX,toY);
    bool horizontal = isHorizontal(fromX,fromY,toX,toY);
    bool diagonal = isDiagonal (fromX,fromY,toX,toY);
    bool pathClear = isPathClear(b,fromX,fromY,toX,toY);

    if (vertical && pathClear)
	move = true;
    else if (horizontal && pathClear)
	move = true;
    else if (diagonal && pathClear)
	move = true;

    return move;
}
