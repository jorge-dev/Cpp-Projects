#include "King.h"

King::King(bool col):Piece(col)
{
    
}


PiecePtr King::clone()const 
{
    PiecePtr clonePiece;
    clonePiece = new King(getColour());
    return clonePiece;
} 

char King::getSymbol() const
{
    char symbol;
    
    if (!getColour())
	symbol = 'k';
    else 
	symbol = 'K';

    return symbol;
}


bool King::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
{
    bool move = false;
    bool vertical = isVertical(fromX,fromY,toX,toY);
    bool horizontal = isHorizontal(fromX,fromY,toX,toY);
    bool diagonal = isDiagonal (fromX,fromY,toX,toY);
    int vDistance = vertDistance(fromX,toX);
    int hDistance = horizDistance(fromY,toY);

    if (vertical && vDistance == 1)
	move = true;
    else if (horizontal && hDistance == 1)
	move = true;
    else if (diagonal && (vDistance == 1 && hDistance == 1))
	move = true;
    return move;
}

