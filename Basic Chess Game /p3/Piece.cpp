#include "Board.h"
#include "Piece.h"

Piece::Piece(bool col)
{
    colour = col;

}

bool Piece::getColour() const
{
 
    return colour;
    
}
//---------------------private-------------------------------------------------


bool Piece::isPathClear(const Board& b, int fromX, int fromY, int toX, int toY)const
{
    bool clear = true;
    bool vertical = isVertical(fromX,fromY,toX,toY);
    bool horizontal = isHorizontal(fromX,fromY,toX,toY);
    bool diagonal = isDiagonal (fromX,fromY,toX,toY);
    bool forward = isForward(fromX,toX);//true goes down, false goes up
    bool sideForward  = (fromY < toY);//true goes right
    bool occupied = b.isOccupied(toX,toY);
     int num = 0;

    if (vertical )
    {
	if(forward)
	{
	    
	   
	    for (int j = fromX+1; (j < toX ); j++)
	    {
		occupied = b.isOccupied(j,toY);
		if (occupied)
		    num++;
	    }
	    if(num != 0)
		clear = false;
	   
	}

	else
	{
	    
	   
	    for (int i = fromX-1; (i != toX); i--)
	    {
	
		occupied = b.isOccupied(i,toY);
		if (occupied)
		    num++;
		   
	    }
	
	    if (num != 0)
		clear =false;
	  
	    
	}
    }
//-------------------horizontal------------------------
    
   else if (horizontal )
    {
	num = 0;
	if(sideForward)
	{
	
	    for (int j = fromY+1; (j != toY); j++)
	    {
		occupied = b.isOccupied(toX,j);
		if (occupied)
		    num++;
	
		
	    }
	    if (num != 0)
		clear = false;
	   
	}
	else
	{
	
	    for (int i = fromY-1; (i != toY); i--)
	    {
		occupied = b.isOccupied(toY,i);
		if (occupied)
		    num++;
	
	    }
	    if (num != 0)
		clear = false;

	    
	}
    }

//---------------------diagonal----------------------------
    

    else if (diagonal )
    {
	 
//-----------------UpRight-------------------------------
	if ((fromX > toX)&& (fromY < toY))
	{
	   
	   
	    for(int i = fromX-1, j = fromY+1;
		(i != toX && j != toY) && clear;
		i--, j++)
	    {

		occupied = b.isOccupied(i,j);
		
		if (occupied)
		    
		    clear =false;
	    }//end for

	}//end if
//-----------------DownLeft-------------------------------    
	else if ((fromX < toX)&& (fromY > toY))
	{
	    

	    for(int i = fromX+1, j = fromY-1;
		(i != toX && j != toY) && clear;
		i++,j--)
	    {

		occupied = b.isOccupied(i,j);
		if (occupied)
		    clear =false;

	    }//end for

	} //end else if


	else if ((fromX > toX)&& (fromY > toY))
	{


	    for(int i = fromX-1, j = fromY-1;
		(i != toX  && j != toY) && clear;
		i--,j--)
	    {

		occupied = b.isOccupied(i,j);
		
		if (occupied)
		    clear =false;

	    }//end for
	}//end else if

//-----------------DownRight-------------------------------
	else if ((fromX < toX)&& (fromY < toY))
	{


	    for(int i = fromX+1, j = fromY+1;
		(i != toX && j != toY) && clear;
		i++,j++)
	    {

		occupied = b.isOccupied(i,j);
		if (occupied)
		    clear =false;

	    }//end for
	}//end else if
    }




    return clear;
}

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
    int vDistance = vertDistance(fromX,toX);
    int hDistance = horizDistance(fromY,toY);



    if (vDistance == hDistance)
    { 
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
    }
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
