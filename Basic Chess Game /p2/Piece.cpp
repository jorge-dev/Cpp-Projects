#include "Board.h"
#include "Piece.h"

Piece::Piece(bool col)
{
    colour = col;
    hasMoved = false;
}

char Piece::getSymbol() const
{
    char symbol;
    
    if (colour == BLACK)
	symbol = 'p';
    else 
	symbol = 'P';

    return symbol;
}
bool Piece::getColour() const
{
    bool color;
    char symbol;
    symbol = getSymbol();

    if (symbol == 'p')
	color = BLACK;
    else
	color = WHITE;
    
    return color;
    
    
}

bool Piece::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
{

    bool move=false;
    bool vertical = isVertical(fromX,fromY,toX,toY);
    bool horizontal = isHorizontal(fromX,fromY,toX,toY);
    bool diagonal = isDiagonal (fromX,fromY,toX,toY);
    bool forward = isForward(fromX,toX);
    bool occupied = b.isOccupied(toX,toY);
    int vDistance = vertDistance(fromX,toX);
    int hDistance = horizDistance(fromY,toY);
    if (vertical && !occupied)
    {
	if (fromX == MAXROWS -1 || fromX == 0)//boundary check
	{
	    if (vDistance == 1 || vDistance == 2)// move check
		move = true;
	}
	else 
	    if (vDistance == 1 && (getColour() == !forward))// move and direction check
		move = true;
    }
  
    else if (horizontal)
    {
	if (!occupied && (fromY == MAXCOLS -1 || fromY == 0))
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


//---------------------private-------------------------------------------------

bool Piece::isVertical (int fromX, int fromY, int toX, int toY) const
{
    bool vertical;
  
    if (fromX != toX && fromY == toY)
	vertical = true;
    else
	vertical = false;
    
    return vertical;
}

bool Piece::isHorizontal (int fromX, int fromY, int toX, int toY) const
{
    bool horizontal;
  
    if (fromX == toX && fromY != toY)
      
	horizontal = true;
    else
	horizontal = false;
    
    return horizontal;
 
}

bool Piece::isDiagonal (int fromX, int fromY, int toX, int toY) const
{
    bool diagonal;
 
    if (fromX > toX && fromY > toY )
	diagonal = true;

    else if (fromX < toX && fromY > toY )
	diagonal = true;
	 
    else if (fromX > toX && fromY < toY )
	diagonal = true;

    else  if (fromX < toX && fromY < toY )
	diagonal = true;
    else
	diagonal = false;

    return diagonal;
  
}

bool Piece::isForward (int fromX, int toX) const
{
    bool forward;
    
    if (fromX - toX > 0)
	forward = false; //up
    else
	forward = true;//down
  
    return forward;
}

int Piece::vertDistance (int fromX, int toX) const
{
    double vDistance;

    vDistance = fromX - toX;
    
     
    return static_cast<int>(abs(vDistance));
}

int Piece::horizDistance (int fromY, int toY) const
{
    double hDistance;
    
    hDistance = fromY - toY;
    

    return static_cast<int>(abs(hDistance));
}
