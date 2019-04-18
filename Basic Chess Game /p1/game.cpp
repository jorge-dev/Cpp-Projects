// Name:        I.M.A. Student
// Email:       istud999@mtroyal.ca
// Course:      COMP 1631-001
// Assignment:  #0
// Due Date:    October 2, 2050
// Instructor:  Some Body
//
// Source File: example_header_doc.cpp
#include <iostream>
#include "Board.h"
#include "Piece.h"
using namespace std;

int main()
{
    Board test;
    PiecePtr p = new Piece;
    char answerP = 'y';
    char answerM = 'y';
    char answerR = 'y';
    int x = 0;
    int y = 0;
     int xRemove = 0;
    int yRemove = 0;
    int fromX = 0;
    int fromY = 0;
    int toX = 0;
    int toY = 0;
    bool moved;
    bool removed;
    bool placed;
    cout << test;
   
    
    
    while (answerP != 'n')
    {
	cout <<"Gimme Coordinates x,y: (from 0 - 7 only!): ";
	cin >>x >>y;
	placed = test.place(p,x,y);
	while (!placed )
	{
	    cout << "Sorry that spot is taken. Try again."<<endl;
	
		
	    cout <<"Gimme Coordinates x,y: (from 0 - 7 only!): ";
	    cin >>x >>y;
	    placed = test.place(p,x,y);
	}
	
	cout <<"\nplace Successful"<<endl;
	cout << test;
	cout << "Wanna continue? (y/n): ";
	cin >> answerP;
	    
    }
    
   
    cout << "Wanna move? :";
    cin >> answerM;
    while (answerM != 'n')
    {
	cout <<"Gimme Coordinates x,y to move from: (from 0 - 7 only!): ";
	cin >>fromX >>fromY;

	cout <<"Gimme Coordinates x,y to move to: (from 0 - 7 only!): ";
	cin >>toX >>toY;
	moved = test.move(fromX,fromY,toX,toY);
	while (!moved )
	{
	    cout << "Sorry that spot is taken or what you are trying to move is empty. Try again."<<endl;
	
	    cout <<"Gimme Coordinates x,y to move from: (from 0 - 7 only!): ";
	    cin >>fromX >>fromY;

	    cout <<"Gimme Coordinates x,y to move to: (from 0 - 7 only!): ";
	    cin >>toX >>toY;
	    moved = test.move(fromX,fromY,toX,toY);
	    
	}
	
	cout <<"\nmove Successful"<<endl;
	cout << test;
	cout << "Wanna continue? (y/n): ";
	cin >> answerM;
    }

    
    cout << "Wanna remove? :";
    cin >> answerR;
    while (answerR != 'n')
    {
	cout <<"Gimme Coordinates x,y to remove: (from 0 - 7 only!): ";
	cin >>xRemove >>yRemove;
	removed = test.remove(xRemove,yRemove);

	while (!removed )
	{
	    cout << "Sorry that spot is empty. Try again."<<endl;
	    
	    
	    cout <<"Gimme Coordinates x,y to remove: (from 0 - 7 only!): ";
	    cin >>xRemove >>yRemove;
	    removed = test.remove(xRemove,yRemove);
	   
	}
	
	cout <<"\nremove Successful"<<endl;
	cout << test;
	cout << "Wanna continue? (y/n): ";
	cin >> answerR;
	
    }
    
    

    cout<<"\nThanks for playing, Game terminated."<<endl;
  return 0;
}
