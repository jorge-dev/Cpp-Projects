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

     Piece piece(colour);
     Piece dest(colour);
    
     


     if (piece.canMove(*this,fromX,fromY,toX,toY)&&isOccupied(fromX,fromY))
     {
	 piece = *grid[fromX][fromY];
	 if (!isOccupied(toX,toY) && (piece.getColour() == colour))
	 {
	     grid[toX][toY] = grid[fromX][fromY];
	     grid[fromX][fromY] = NULL;
	     moved = true;
	      		    
	 }
	 else 
	 {
	     dest = *grid[toX][toY];
	     if(dest.getColour() != colour)
	     {	
		 remove(toX,toY);
		 grid[toX][toY] = grid[fromX][fromY];
		 grid[fromX][fromY] = NULL;
		 moved = true;
       
	     }// end if 
		 
		    
		
	 }//end else
	    
     }//end if



 
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
    
    Piece position(true) ;
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
		     
		     position = *grid[r][c];
		     out << position.getSymbol();
		 }
		 else
		     out << " ";
	     }//end if	 
	     else
	     {
		 out << " | ";
		 
		 if(grid[r][c] != NULL)
		 {   
		     position = *grid[r][c];
		     out << position.getSymbol();
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
    PiecePtr piece = new Piece(true);
    
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

    bool colour = true;
   
    for (int i = 0; i < MAXROWS; i++)
    {
	for (int j = 0; j < MAXCOLS; j++)
	{
	    if (other.grid[i][j] != NULL)
	    {
		colour = other.grid[i][j] -> getColour();
		grid[i][j]= new Piece(colour);


	    }
	}
    }

}


ostream& operator<< (ostream& out, const Board& b)
{
    b.write(out);
    return out;

}
