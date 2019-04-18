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

bool Board:: move (int fromX, int fromY, int toX, int toY)
{
    bool moved;
    bool moveSuccess;
    moveSuccess = canMove(fromX,fromY,toX,toY);
    
    if (moveSuccess)
    {
	grid[toX][toY] = grid[fromX][fromY];

	grid[fromX][fromY] = NULL;	
	moved = true;
    }
    else
	moved = false;
    
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
		     out << "P";
		 else
		     out << " ";
	     }//end if	 
	     else
	     {
		 out << " | ";
		 
		 if(grid[r][c] != NULL)
		     out << "P";
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

PiecePtr Board::getPiece(int x, int y) const
{
    PiecePtr piece;
    
    if (grid[x][y] == NULL)
	piece = NULL;
    else
	piece = grid[x][y];
    
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
		grid[i][j] = new Piece;
		*grid[i][j] = *other.grid[i][j];
		
	    }
	}
    }

}

bool Board::canMove (int fromX, int fromY, int toX, int toY)
{
    bool success;
    
    if (grid[toX][toY] == NULL && grid[fromX][fromY] != NULL)
    {

	success = true;
    }
    else 
	success = false;

    return success;
}


ostream& operator<< (ostream& out, const Board& b)
{
    b.write(out);
    return out;

}

