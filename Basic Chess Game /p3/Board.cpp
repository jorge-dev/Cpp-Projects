/*
 ===============================================================
The "Board" class : represents an 8 x 8 Board of pointers.

PRIVATE METHOD SPECIFICATION
    
     initBoard: initializes each board pointer to NULL.
     
     clearBoard: deletes any dinamyc pointers and set those 
                 pointers to Null
		 
     copyBoard: given a board class, it creates a copy of 
                an  existing board and copies its values to 
		the new board

=================================================================
*/


#include "Board.h"
#include <iostream>

Board::Board()
{

    initBoard();
    
}
Board ::Board (const Board& other)
{
    initBoard();
    copyBoard(other);
}
Board::~Board()
{
    clearBoard();
}

Board& Board:: operator = (const Board& other)
{

        
    if (this != &other)
    {

	clearBoard();

	copyBoard(other);

    }
    

    return (*this);
}

bool Board:: move (bool colour ,int fromX, int fromY, int toX, int toY)
{
    bool moved = false;

    PiecePtr piece;
    PiecePtr dest;
    piece = grid[fromX][fromY];
     
    if (isOccupied(fromX,fromY)&&(piece->getColour()==colour) )
    {
	if (piece->canMove(*this,fromX,fromY,toX,toY))
	{
	    
	    if (!isOccupied(toX,toY))
	    {
		grid[toX][toY] = grid[fromX][fromY];
		grid[fromX][fromY] = NULL;
		moved = true;
	      		    
	    }
	    else 
	    {
		dest = grid[toX][toY];
		if(dest->getColour() != colour)
		{	
		    remove(toX,toY);
		    grid[toX][toY] = grid[fromX][fromY];
		    grid[fromX][fromY] = NULL;
		    moved = true;
       
		}// end if 
		 
		    
		
	    }//end else
	    
	}//end if

    }// end out if

 
    return moved;
}

bool Board::place (const PiecePtr& p, int x, int y)
{
    bool placed;
    
    if (grid[x][y] == NULL)
    {
	grid[x][y] = p;
	placed = true;
    }
    else
	placed = false;
    return placed;
}

bool Board::remove (int x, int y)
{
    bool removed;
    if (grid[x][y] != NULL)
    {	
	delete grid[x][y];
	grid[x][y] = NULL;
	removed = true;
    }
    else
	removed = false;
    
    return removed;
}

void Board::write (ostream& out) const
{

    PiecePtr position;
    out <<endl<<endl;
//-----------------------------------
// top numbers
    out<<" ";
    for (int x = 0; x < MAXROWS; x++)
    {
	out<<"   "<<x;
    }
    out << endl;
//-----------------------------------------
//bottom separators
    out <<"  ";
    for (int x = 0; x < MAXROWS; x++)
    {
	out<<"+---";
    }
    out <<"+";
    out << endl;

//------------------------------------------
//printing array
    for(int r = 0; r < MAXROWS; r++)
    {
	for(int c = 0; c < MAXCOLS; c++)
	{
	    if (c == 0 )
	    {
		out << r << " | "; 
		 
		if(grid[r][c] != NULL)
		{
		     
		    position = grid[r][c];
		    out << position->getSymbol();
		}
		else
		    out << " ";
	    }//end if	 
	    else
	    {
		out << " | ";
		 
		if(grid[r][c] != NULL)
		{   
		    position = grid[r][c];
		    out << position->getSymbol();
		}
		else
		    out << " ";
	    }//end else

	}//end for

	out<<" |";
	out<<endl;
	out <<"  ";
	for (int x = 0; x < MAXROWS; x++)
	{
	    out<<"+---";
	}
	out <<"+";
	out << endl;
    }//end for
    out <<endl<<endl;

}


bool Board::isOccupied (int x, int y) const
{
    bool occupied;
    
    if ( grid[x][y] == NULL)
	occupied = false;
    else
	occupied= true;

    return occupied;
}

PiecePtr Board::getPiece(int x, int y) const
{
    PiecePtr piece;
    
    if (grid[x][y] == NULL)
	piece = NULL;
    else
	piece = grid[x][y]->clone();
    
    return piece;

}


//---------------Private--------------------------------

void Board::initBoard()
{

    int i;
    int j;
    
    for (i = 0; i < MAXROWS ; i++)
    {
	for (j = 0; j < MAXCOLS ; j++)
	{
	    grid[i][j] = NULL;
	}
	
    }
    

}
void Board::clearBoard()
{
    for (int i = 0; i < MAXROWS ; i++)
    {
	for (int j = 0; j < MAXCOLS ; j++)
	{
	    delete grid[i][j];
	    grid[i][j] = NULL;
	}

    }

}
void Board::copyBoard(const Board& other)
{

    for (int i = 0; i < MAXROWS; i++)
    {
	for (int j = 0; j < MAXCOLS; j++)
	{
	    if (other.grid[i][j] != NULL)
	    {

		grid[i][j]=other.grid[i][j]->clone();

		
	    }
	}
    }

}


ostream& operator<< (ostream& out, const Board& b)
{
    b.write(out);
    return out;

}
