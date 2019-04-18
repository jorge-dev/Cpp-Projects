#include "Bishop.h"

Bishop::Bishop(bool col): Piece(col)
{
}


PiecePtr Bishop::clone()const 
{
    PiecePtr clonePiece;
    clonePiece = new Bishop(getColour());
    return clonePiece;
} 

char Bishop::getSymbol() const
{
    char symbol;
    
    if (!getColour())
	symbol = 'b';
    else 
	symbol = 'B';

    return symbol;
}

bool Bishop::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
{
    
    bool move=false;
    
    bool diagonal = isDiagonal (fromX,fromY,toX,toY);
    bool pathClear = isPathClear(b,fromX,fromY,toX,toY);

    if (diagonal && pathClear)
	move = true;
    
    return move;
}
