// Name:        Jorge Avila
// Email:       javil686@mtroyal.ca
// Course:      COMP 1633-001
// Assignment:  #5
// Due Date:    April 9, 2017
// Instructor:  Paul Pospisil
//
// Source File: game.cpp

/*
Purpose:    A simplified chess game with a simple UI and 2 player mode.

Detail:    This game relies on the most important chess rules but doesnt
           check for check mate, special chess moves like capturing
	   en passant and castling or pawn promotion.
	   The chess piece rmove rules used in the game are the following
	   
	   King: can move any direction one step at a time.
	   Queen: can move any direction.
	   Bishop: move diagonally up and down
	   Knight(Horse): moves L-like moves. can move either 2 spaces 
	                 Horizontally and one vertically or 1 space 
			 horizontally and 2 spaces vertically.
	   Rook(Tower): move multiple steps horizontally or vertically
	   Pawn: can move 2 spaces for its first move and only one
	         space after. It can move diagonally forward one space 
		 only if there is an opponent piece in that position. 

Known Bugs || Assumptions
No known bugs



*/



#include <iostream>

#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "ioutil.h"
#include "helper.h"

using namespace std;


int main()
{
    Board test;

   
    bool turn = WHITE;
    bool answer = false;
    int fromX =0;
    int toX = 0;
    int fromY =0;
    int toY = 0;

    PiecePtr blackPiece=NULL;
    PiecePtr whitePiece=NULL;
    bool gameOver = false;
    bool move = false;
    initChess(test,blackPiece,whitePiece);    
    cout << test;

    cout <<"===================================================="
	 <<"\n                  GAME INFO                       "
	 <<endl;

    cout <<"1) White Pieces are represented by UpperCase letters"
	 <<endl
	 <<"located at the bottom of table."<<endl<<endl;
   
     cout <<"2) Black Pieces are represented by LowerCase letters"
	 <<endl
	  <<"located at the top of table."<<endl<<endl;
   
     cout << "3) To exit the game, type -1,-1 in coordinates"
	  <<endl<<endl;
     cout <<"===================================================="
	  <<endl<<endl;

     cout<<"WHITE starts"<<endl<<endl;
   

    do
    {
	if (turn)
	    cout << "It's WHITE's turn"<<endl<<endl;
	else
	    cout << "It's BLACK's turn"<<endl<<endl;

	cout <<"**************   From   ***************"<<endl<<endl;;
	fromX = readFromX();
	fromY = readFromY();
	answer = confirmQuit(fromX,fromY);

	cout <<endl;
	

	if (!answer)
	{
	    cout <<endl<<"**************   To   ***************"<<endl<<endl;;
	    toX = readToX();
	    toY = readToY();
	    answer = confirmQuit(toX,toY);
	    cout <<endl;
	}

	if (!answer)
	{
	    move = test.move(turn,fromX,fromY,toX,toY);

	    gameOver = isKingDead(test);
	    
	    if(move)
	    {

		cout << test;
   		
	    }
	    
	    if (!move)
	    {
		cout<<endl
		    <<"-------------------------------------------------"
		    <<endl
		    <<"Sorry, that move is not allowed "
		    <<endl
		    <<"or what you are trying to move is empty."
		    <<endl
		    <<"Please Try again. "
		    <<endl
		    <<"--------------------------------------------------"
		    << endl<<endl;
		
		turn =!turn;
	    }

	    	
	}
    
	cout<<endl;
	
	turn = !turn;
	
	
    }while(!answer && !gameOver);
    if (gameOver)
    {  
	cout<<"======================================" 
	    <<endl<<endl
	    << "GAME OVER. the King has been killed!"
	      << endl
	      << "The winner is ";
	
	if (!turn == WHITE)
	    cout <<"WHITE"<<endl;
	else
	    cout << "BLACK"<<endl;

	cout<<endl
	    << "Thanks for playing"
	    <<endl << endl
	    <<"======================================"<< endl; ;
	
    }  
    else
	cout<<endl
	    << "Thanks for playing!"
	    <<endl << endl;
      
   
    
    

 return 0;
}
/*
********************************************************************************
Function: confirmQuit

Purpose: checks if coordinates are both -1 

Details: if coordinates are -1 it propts a confirmation and if y is typed 
         it returns true.

Input: 2 integers - x: x coordinate
                  - y: y coordinate

Return a bool - answer


********************************************************************************
*/
bool confirmQuit(int x,int y)
{
    bool answer =false;
    if(x == -1  && y == -1)
	answer = exitGame();
    
    return answer;
}

/*
********************************************************************************
Function: readFromX

Purpose: reads and error check for a from X coordinate input 

Details: uses ioutil to check for invalid inputs and checks for out of 
        bound coordinates. returns an integer until all conditions are met


Return an int - x:  from x coordinate.


********************************************************************************
*/
int readFromX ()
{
    int x;
    bool xOK;
    bool ctrlD = false;
    
	x = readInt (fromXPrompt, ctrlD);
	
	xOK = ((x >= -1) &&  (x < MAXROWS) );

	while (ctrlD || !xOK)
	{
	    if (ctrlD)
	    {
	       cout << endl
	       << "**** Ignoring ctrl-d - to abort the program type ctrl-c ****"
	       << endl;
	    }

	    else
		cout << "**** X coordinate can't be greater than " 
		     << MAXROWS-1 
		     <<" and less than -1"<<" ****"
		     << endl;

	    x = readInt (fromXPrompt, ctrlD);
	    xOK = ((x >= -1) &&  (x < MAXROWS) );
	    
	    
	}

    return x;
}


/*
********************************************************************************
Function: readToX

Purpose: reads and error check for a to X coordinate input 

Details: uses ioutil to check for invalid inputs and checks for out of 
        bound coordinates. returns an integer until all conditions are met


Return an int - x:  to x coordinate.


********************************************************************************
*/
int readToX ()
{
     int x;
     
     bool xOK;
     bool ctrlD = false;
     
     x = readInt (toXPrompt, ctrlD);
     xOK = ((x < MAXROWS) && (x >= -1));
     
     while (!xOK || ctrlD )
     {
	 if (ctrlD)
	 {
	     cout << endl
		  << "**** Ignoring ctrl-d - to abort the program type ctrl-c ****"
		  << endl;
	 }
	 
	 else
	 {
	     cout << "**** X coordinate can't be greater than " 
		  << MAXROWS-1 
		  <<" and less than -1"<<" ****"
		  << endl;
	 }
	 x = readInt (fromXPrompt, ctrlD);
	 xOK = ((x < MAXROWS) && (x >= -1));
	    
	    
     }
    return x;

}


/*
********************************************************************************
Function: readFromY

Purpose: reads and error check for a from Y coordinate input 

Details: uses ioutil to check for invalid inputs and checks for out of 
        bound coordinates. returns an integer until all conditions are met


Return an int - y:  from y coordinate.


********************************************************************************
*/
int readFromY ()
{
    int y;
    bool yOK;
    bool ctrlD = false;
    
	y = readInt (fromYPrompt, ctrlD);
	yOK = (y < MAXCOLS && y >= -1);

	while (ctrlD || !yOK)
	{
	    if (ctrlD)
	    {
	       cout << endl
	       << "**** Ignoring ctrl-d - to abort the program type ctrl-c ****"
	       << endl;
	    }

	    else
		cout << "**** Y coordinate can't be greater than " 
		     << MAXCOLS-1  
		     <<" and less than -1"<<" ****"
		     << endl;

	    y = readInt (fromYPrompt, ctrlD);
	    yOK = (y < MAXCOLS && y >= -1);
	}	    

    return y;

}


/*
********************************************************************************
Function: readToY

Purpose: reads and error check for a to Y coordinate input 

Details: uses ioutil to check for invalid inputs and checks for out of 
        bound coordinates. returns an integer until all conditions are met


Return an int - y:  to y coordinate.


********************************************************************************
*/
int readToY()
{
    int y;
    bool yOK;
    bool ctrlD = false;
        
	y = readInt (fromYPrompt, ctrlD);
	yOK = (y < MAXCOLS && y >= -1);

	while (ctrlD || !yOK)
	{
	    if (ctrlD)
	    {
	       cout << endl
	       << "**** Ignoring ctrl-d - to abort the program type ctrl-c ****"
	       << endl;
	    }

	    else
		cout << "**** Y coordinate can't be greater than " 
		     << MAXCOLS-1  
		     <<" and less than -1"<<" ****"
		     << endl;

	    y = readInt (fromYPrompt, ctrlD);
	    yOK = (y < MAXCOLS && y >= -1);
	}   


    return y;
}


/*
********************************************************************************
Function: exitGame

Purpose: reads and error check for a y/n input and returns true/false 

Details: uses ioutil to check for invalid inputs 


Return an bool - exit:  true if 'y'. false if 'n'.


********************************************************************************
*/
bool exitGame()
{
    bool exit = false;
    bool ctrlD = false;

    exit = readBool(quitPrompt,ctrlD);
    while (ctrlD)
    {
	if (ctrlD)
	{
	    cout << endl
		 << "**** Ignoring ctrl-d - to abort the program type ctrl-c ****"
		 << endl;
	}
	exit = readBool(quitPrompt,ctrlD);
    }

    return exit;
}


/*
********************************************************************************
Function: isKingDead

Purpose: checks the board for kings and if one of them is removed it returns 
         a true

Details: checks the board and counts the number of kings in the board, if the 
         numbe is less than 2 it returns true else returns false

Input: const Board - t

Return an bool - dead.


********************************************************************************
*/ 
bool isKingDead (const Board& t)
{
    bool dead = false;
    PiecePtr position;
    int numKings = 0;
    

    for (int i = 0; i < MAXROWS;i++)
    {
	for (int j = 0; j < MAXROWS;j++)
	{
       
	    
	    if (t.isOccupied(i,j))
	    {
		position = t.getPiece(i,j);
		if ((position -> getSymbol()== 'K' ||
		     position -> getSymbol()== 'k'))
		{
		    numKings++;
		    
		}
		delete position;
	    }
	  	    
	    
	}
	
    }

    if (numKings < 2)
	dead = true;

       return dead;
}


/*
********************************************************************************
Function: initChess

Purpose: initializes a board with 2 set of board pieces(Black/White) in its 
         corresponding position.

Input: const Board - test.
       PiecePtr - BlackPiece
       PiecePtr - whitePiece




********************************************************************************
*/ 
void initChess (Board& test,PiecePtr blackPiece, PiecePtr whitePiece)
{
   
   for (int i = 0; i < MAXROWS;i++)
    {
	for (int j = 0; j < MAXROWS;j++)
	{
	    if (i == 1)
	    {
		whitePiece = new Pawn(WHITE);
		test.place(whitePiece,MAXROWS-2,j);
	    }

	    if (i == MAXROWS -2)
	    {
		blackPiece = new Pawn(BLACK);
		test.place(blackPiece,1,j);
	    }
	    }
	
    }
   
//------------Black-------------------------
   blackPiece = new Rook(BLACK);
   test.place(blackPiece,0,0);
   blackPiece = new Rook(BLACK);
   test.place(blackPiece,0,7);

   blackPiece = new Knight(BLACK);
   test.place(blackPiece,0,1);
   blackPiece = new Knight(BLACK);
   test.place(blackPiece,0,6);

   blackPiece = new Bishop(BLACK);
   test.place(blackPiece,0,2);
   blackPiece = new Bishop(BLACK);
   test.place(blackPiece,0,5);

   blackPiece = new Queen(BLACK);
   test.place(blackPiece,0,3);

   blackPiece = new King(BLACK);
   test.place(blackPiece,0,4);


//------------------Whites----------------
   whitePiece = new Rook(WHITE);
   test.place(whitePiece,7,0);
   whitePiece = new Rook(WHITE);
   test.place(whitePiece,7,7);

   whitePiece = new Knight(WHITE);
   test.place(whitePiece,7,1);
   whitePiece = new Knight(WHITE);
   test.place(whitePiece,7,6);

   whitePiece = new Bishop(WHITE);
   test.place(whitePiece,7,2);
   whitePiece = new Bishop(WHITE);
   test.place(whitePiece,7,5);

   whitePiece = new Queen(WHITE);
   test.place(whitePiece,7,3);

   whitePiece = new King(WHITE);
   test.place(whitePiece,7,4);

   
}





