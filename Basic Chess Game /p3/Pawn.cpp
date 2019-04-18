#include "Pawn.h"

Pawn::Pawn(bool col):Piece(col)
{
    hasMoved = false;
}

PiecePtr Pawn::clone()const 
{
    PiecePtr clonePiece;
    clonePiece = new Pawn(getColour());
    return clonePiece;
} 
 
char Pawn::getSymbol() const
{
    char symbol;
    
    if (!getColour())
	symbol = 'p';
    else 
	symbol = 'P';

    return symbol;
}


bool Pawn::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
{


    bool move=false;
    bool vertical = isVertical(fromX,fromY,toX,toY);
    bool diagonal = isDiagonal (fromX,fromY,toX,toY);
    bool forward = isForward(fromX,toX);
    bool occupied = b.isOccupied(toX,toY);
    int vDistance = vertDistance(fromX,toX);
    int hDistance = horizDistance(fromY,toY);
    if (vertical && !occupied)
    {
	if (fromX == MAXROWS -2 || fromX == 1)//boundary check
	{
	    if ((vDistance == 1 || vDistance == 2) && !hasMoved)// move check
	    {	
		move = true;
		hasMoved = true;
	    }
	}
	else 
	    if (vDistance == 1 && (getColour() == !forward))// move and direction check
		move = true;
    }
  
    else if (diagonal && occupied)
    {
	
	if (vDistance == 1 && hDistance == 1 )// distance & direction check
	{
	   

	    if (!getColour() && (fromX < toX))
		move = true;
	    else 
		if(getColour() && (fromX > toX))
		    move = true;
		
	}
    }

  
  
	
    
    return move;
}



