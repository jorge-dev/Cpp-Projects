#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"


#include <gtest/gtest.h>
#include <iostream>
//#include <cstring>
//#include <fstream>

class test_Pieces : public testing::Test {
protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
    
    PiecePtr pieceB;
    PiecePtr pieceW;
    Board test;
};

TEST_F(test_Pieces, testCanMoveKnight)
{

   
    bool pass=true;
//--------------------True-------------------    
        

    pieceW = new Knight(WHITE);//2h 1v rightUp
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,3,6));
    test.remove(4,4);

    pieceW = new Knight(WHITE);//2h 1v rightDown
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,5,6));
    test.remove(4,4);

    pieceW = new Knight(WHITE);//2h 1v leftUp
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,3,2));
    test.remove(4,4);

    pieceW = new Knight(WHITE);//2h 1v leftDown
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,5,2));
    test.remove(4,4);

    pieceW = new Knight(WHITE);//1h 2v righttUp
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,2,5));
    test.remove(4,4);
    
    pieceW = new Knight(WHITE);//1h 2v rightDown
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,6,5));
    test.remove(4,4);

    pieceW = new Knight(WHITE);//1h 2v leftUp
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,2,3));
    test.remove(4,4);

    pieceW = new Knight(WHITE);//1h 2v leftDown
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,6,3));
    test.remove(4,4);

//----------------False------------------------
    
    pieceW = new Knight(WHITE);//2h 2v rightUp
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,2,6));
    test.remove(4,4);

    pieceW = new Knight(WHITE);//2h 2v rightDown
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,6,6));
    test.remove(4,4);

    pieceW = new Knight(WHITE);//2h 2v leftUp
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,2,2));
    test.remove(4,4);

    pieceW = new Knight(WHITE);//2h 2v leftDown
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,6,2));
    test.remove(4,4);

    pieceW = new Knight(WHITE);//1h 3v righttUp
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,1,5));
    test.remove(4,4);
    
    pieceW = new Knight(WHITE);//1h 3v rightDown
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,7,5));
    test.remove(4,4);

    pieceW = new Knight(WHITE);//1h 3v leftUp
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,1,3));
    test.remove(4,4);

    pieceW = new Knight(WHITE);//1h 3v leftDown
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,7,3));
    test.remove(4,4);

    pieceW = new Knight(WHITE);
    test.place(pieceW,4,4);//up
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,0,4));
    test.remove(4,4);

    pieceW = new Knight(WHITE);//down
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,7,4));
    test.remove(4,4);

    pieceW = new Knight(WHITE);//diagonal up right
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,1,7));
    test.remove(4,4);

    pieceW = new Knight(WHITE);//diagonal up left
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,0,0));
    test.remove(4,4);

    pieceW = new Knight(WHITE);//diagonal down right
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,7,7));
    test.remove(4,4);

    pieceW = new Knight(WHITE);//diagonal down left
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,7,1));
    test.remove(4,4);

    pieceW = new Knight(WHITE);//right
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,4,7));
    test.remove(4,4);

    pieceW = new Knight(WHITE);
    test.place(pieceW,4,4);//left
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,4,0));
    test.remove(4,4);
   



}


TEST_F(test_Pieces, testCanMoveRook)
{

   
    bool pass=true;
//--------------------True-------------------    
    pieceW = new Rook(WHITE);
    test.place(pieceW,7,3);//up
    EXPECT_EQ(pass, pieceW->canMove(test,7,3,1,3));
    test.remove(7,3);

    pieceW = new Rook(WHITE);//down
    test.place(pieceW,1,3);
    EXPECT_EQ(pass, pieceW->canMove(test,1,3,7,3));
    test.remove(1,3);

    pieceW = new Rook(WHITE);//right
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,4,7));
    test.remove(4,4);

    pieceW = new Rook(WHITE);
    test.place(pieceW,4,4);//left
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,4,0));
    test.remove(4,4);
   

//----------------False------------------------
    pieceW = new Rook(WHITE);
    test.place(pieceW,7,3);//up
    pieceW = new Rook(WHITE);
    test.place(pieceW,4,3);//up
    EXPECT_EQ(!pass, pieceW->canMove(test,7,3,1,3));
    test.remove(7,3);
    test.remove(4,3);

    pieceW = new Rook(WHITE);//down
    test.place(pieceW,1,3);
    pieceW = new Rook(WHITE);
     test.place(pieceW,4,3);
    EXPECT_EQ(!pass, pieceW->canMove(test,1,3,7,3));
    test.remove(1,3);
    test.remove(4,3);

    pieceW = new Rook(WHITE);//right
    test.place(pieceW,4,4);
    pieceW = new Rook(WHITE);
    test.place(pieceW,4,5);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,4,7));
    test.remove(4,4);
    test.remove(4,5);

    pieceW = new Rook(WHITE);
    test.place(pieceW,4,4);//left
    pieceW = new Pawn(WHITE);
    test.place(pieceW,4,1);//up
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,4,0));
    test.remove(4,4);
    test.remove(4,2);


}

TEST_F(test_Pieces, testCanMoveKing)
{

   
    bool pass=true;
//--------------------True-------------------    
    pieceW = new King(WHITE);
    test.place(pieceW,4,4);//up
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,3,4));
    test.remove(4,4);

    pieceW = new King(WHITE);//down
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,5,4));
    test.remove(4,4);

    pieceW = new King(WHITE);//diagonal up right
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,3,5));
    test.remove(4,4);

    pieceW = new King(WHITE);//diagonal up left
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,3,3));
    test.remove(4,4);

    pieceW = new King(WHITE);//diagonal down right
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,5,5));
    test.remove(4,4);

    pieceW = new King(WHITE);//diagonal down left
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,5,3));
    test.remove(4,4);



    pieceW = new King(WHITE);//right
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,4,5));
    test.remove(4,4);

    pieceW = new King(WHITE);
    test.place(pieceW,4,4);//left
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,4,3));
    test.remove(4,4);
   

//----------------False------------------------
    pieceW = new King(WHITE);
    test.place(pieceW,4,4);//up
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,2,4));
    test.remove(4,4);

    pieceW = new King(WHITE);//down
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,6,4));
    test.remove(4,4);

    pieceW = new King(WHITE);//diagonal up right
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,2,6));
    test.remove(4,4);

    pieceW = new King(WHITE);//diagonal up left
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,2,2));
    test.remove(4,4);

    pieceW = new King(WHITE);//diagonal down right
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,6,6));
    test.remove(4,4);

    pieceW = new King(WHITE);//diagonal down left
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,6,2));
    test.remove(4,4);

    pieceW = new King(WHITE);//right
    test.place(pieceW,4,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,4,7));
    test.remove(4,4);

    pieceW = new King(WHITE);
    test.place(pieceW,4,4);//left
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,4,2));
    test.remove(4,4);


}


TEST_F(test_Pieces, testCanMoveQueen)
{

   
    bool pass=true;
//--------------------True-------------------    
    pieceW = new Queen(WHITE);
    test.place(pieceW,4,4);//up
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,0,4));
    test.remove(4,4);

    pieceW = new Queen(WHITE);//down
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,7,4));
    test.remove(4,4);

    pieceW = new Queen(WHITE);//diagonal up right
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,1,7));
    test.remove(4,4);

    pieceW = new Queen(WHITE);//diagonal up left
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,0,0));
    test.remove(4,4);

    pieceW = new Queen(WHITE);//diagonal down right
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,7,7));
    test.remove(4,4);

    pieceW = new Queen(WHITE);//diagonal down left
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,7,1));
    test.remove(4,4);



    pieceW = new Queen(WHITE);//right
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,4,7));
    test.remove(4,4);

    pieceW = new Queen(WHITE);
    test.place(pieceW,4,4);//left
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,4,0));
    test.remove(4,4);
   

//----------------False------------------------
    pieceW = new Queen(WHITE);
    test.place(pieceW,4,4);//up
    pieceW = new Queen(WHITE);
    test.place(pieceW,2,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,0,4));
    test.remove(4,4);
    test.remove(2,4);

    pieceW = new Queen(WHITE);//down
    test.place(pieceW,4,4);
    pieceW = new Queen(WHITE);
    test.place(pieceW,5,4);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,7,4));
    test.remove(4,4);
    test.remove(5,4);

    pieceW = new Queen(WHITE);//diagonal up right
    test.place(pieceW,4,4);
    pieceW = new Queen(WHITE);
    test.place(pieceW,2,6);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,1,7));
    test.remove(4,4);
    test.remove(2,6);

    pieceW = new Queen(WHITE);//diagonal up left
    test.place(pieceW,4,4);
    pieceW = new Queen(WHITE);
    test.place(pieceW,2,2);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,0,0));
    test.remove(4,4);
    test.remove(2,2);

    pieceW = new Queen(WHITE);//diagonal down right
    test.place(pieceW,4,4);
    pieceW = new Queen(WHITE);
    test.place(pieceW,6,6);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,7,7));
    test.remove(4,4);
    test.remove(6,6);

    pieceW = new Queen(WHITE);//diagonal down left
    test.place(pieceW,4,4);
    pieceW = new Queen(WHITE);
    test.place(pieceW,6,2);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,7,1));
    test.remove(4,4);
    test.remove(6,2);

    pieceW = new Queen(WHITE);//right
    test.place(pieceW,4,4);
    pieceW = new Queen(WHITE);
    test.place(pieceW,4,6);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,4,7));
    test.remove(4,4);
    test.remove(4,6);

    pieceW = new Queen(WHITE);
    test.place(pieceW,4,4);//left
    pieceW = new Pawn(WHITE);
    test.place(pieceW,4,2);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,4,0));
    test.remove(4,4);
    test.remove(4,2);
   


}





TEST_F(test_Pieces, testCanMoveBishop)
{

   
    bool pass=true;
//--------------------True-------------------    
    

    

    pieceW = new Bishop(WHITE);//diagonal up right
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,1,7));
    test.remove(4,4);

    pieceW = new Bishop(WHITE);//diagonal up left
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,0,0));
    test.remove(4,4);

    pieceW = new Bishop(WHITE);//diagonal down right
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,7,7));
    test.remove(4,4);

    pieceW = new Bishop(WHITE);//diagonal down left
    test.place(pieceW,4,4);
    EXPECT_EQ(pass, pieceW->canMove(test,4,4,7,1));
    test.remove(4,4);


//----------------False------------------------

    pieceW = new Bishop(WHITE);//diagonal up right
    test.place(pieceW,4,4);
    pieceW = new Queen(WHITE);
    test.place(pieceW,2,6);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,1,7));
    test.remove(4,4);
    test.remove(2,6);

    pieceW = new Bishop(WHITE);//diagonal up left
    test.place(pieceW,4,4);
    pieceW = new Queen(WHITE);
    test.place(pieceW,2,2);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,0,0));
    test.remove(4,4);
    test.remove(2,2);

    pieceW = new Bishop(WHITE);//diagonal down right
    test.place(pieceW,4,4);
    pieceW = new Queen(WHITE);
    test.place(pieceW,6,6);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,7,7));
    test.remove(4,4);
    test.remove(6,6);

    pieceW = new Bishop(WHITE);//diagonal down left
    test.place(pieceW,4,4);
    pieceW = new Queen(WHITE);
    test.place(pieceW,6,2);
    EXPECT_EQ(!pass, pieceW->canMove(test,4,4,7,1));
    test.remove(4,4);
    test.remove(6,2);



}



TEST_F(test_Pieces, testCanMovePawnBlack)
{
    bool passed = true;
    // passed
    pieceB = new Pawn(BLACK);
    test.place(pieceB,1,0);
    EXPECT_EQ(passed,pieceB->canMove(test,1,0,2,0));//move 2 spaces from beggining
    test.remove(1,0);

    pieceB = new Pawn(BLACK);
    test.place(pieceB,2,0);
    EXPECT_EQ(passed,pieceB->canMove(test,2,0,3,0));//move 1 space
    test.remove(2,0);

    pieceB = new Pawn(BLACK);
    pieceW = new Pawn(WHITE);
    test.place(pieceB,2,1);
    test.place(pieceW,3,2);
    EXPECT_EQ(passed,pieceB->canMove(test,2,1,3,2));//move 1 space
    test.remove(2,1);
    test.remove(3,2);

//!passed

    pieceB = new Pawn(BLACK);
    test.place(pieceB,1,0);
    EXPECT_EQ(!passed,pieceB->canMove(test,1,0,4,0));//move more than 2 spaces from beggining
    test.remove(1,0);

    pieceB = new Pawn(BLACK);
    test.place(pieceB,3,0);
    EXPECT_EQ(!passed,pieceB->canMove(test,3,0,2,0));//move 1 space back
    test.remove(3,0);
    
    pieceB = new Pawn(BLACK);
    test.place(pieceB,2,0);
    pieceB = new Pawn(BLACK);
    test.place(pieceB,3,0);
    EXPECT_EQ(!passed,pieceB->canMove(test,2,0,3,0));//move on occupied
    test.remove(3,0);
    test.remove(2,0);
    
    pieceB = new Pawn(BLACK);
    test.place(pieceB,2,0);
    EXPECT_EQ(!passed,pieceB->canMove(test,2,0,4,0));//move 2 spaces after initial posiotion
    test.remove(2,0);

    pieceB = new Pawn(BLACK);
    test.place(pieceB,2,0);
    EXPECT_EQ(!passed,pieceB->canMove(test,2,0,8,0));//move outside bounds
    test.remove(2,0);

    pieceB = new Pawn(BLACK);
    test.place(pieceB,2,0);
    EXPECT_EQ(!passed,pieceB->canMove(test,-2,0,-9,9));//negative coordinates
    test.remove(2,0);

    pieceB = new Pawn(BLACK);
    pieceW = new Pawn(WHITE);
    test.place(pieceW,2,1);
    test.place(pieceB,3,2);
    EXPECT_EQ(!passed,pieceB->canMove(test,3,2,2,1));//move 1 space
    test.remove(2,1);
    test.remove(3,2);
   
}

TEST_F(test_Pieces, testCanMovePawnWhite)
{
    bool passed = true;
    // passed
    pieceW = new Pawn(WHITE);
    test.place(pieceW,6,0);
    EXPECT_EQ(passed,pieceW->canMove(test,6,0,4,0));//move 2 spaces from beggining
    test.remove(6,0);

    pieceW = new Pawn(WHITE);
    test.place(pieceW,6,0);
    EXPECT_EQ(passed,pieceW->canMove(test,6,0,5,0));//move 1 space
    test.remove(6,0);

    pieceB = new Pawn(BLACK);
    pieceW = new Pawn(WHITE);
    test.place(pieceB,2,1);
    test.place(pieceW,3,2);
    EXPECT_EQ(passed,pieceW->canMove(test,3,2,2,1));//move 1 space diagonal
    test.remove(2,1);
    test.remove(3,2);

//!passed

    pieceW = new Pawn(WHITE);
    test.place(pieceW,6,0);
    EXPECT_EQ(!passed,pieceW->canMove(test,6,0,3,0));//move more than 2 spaces from beggining
    test.remove(6,0);

    pieceW = new Pawn(WHITE);
    test.place(pieceW,5,0);
    EXPECT_EQ(!passed,pieceW->canMove(test,5,0,6,0));//move 1 space back
    test.remove(5,0);
    
    pieceW = new Pawn(WHITE);
    test.place(pieceW,5,0);
    pieceW = new Pawn(WHITE);
    test.place(pieceW,4,0);
    EXPECT_EQ(!passed,pieceW->canMove(test,5,0,4,0));//move on occupied
    test.remove(5,0);
    test.remove(4,0);
    
    pieceW = new Pawn(WHITE);
    test.place(pieceW,5,0);
    EXPECT_EQ(!passed,pieceW->canMove(test,5,0,3,0));//move 2 spaces after initial posiotion
    test.remove(5,0);

   

    pieceW = new Pawn(WHITE);
    test.place(pieceW,2,0);
    EXPECT_EQ(!passed,pieceW->canMove(test,-2,0,-9,9));//negative coordinates
    test.remove(2,0);

    pieceB = new Pawn(BLACK);
    pieceW = new Pawn(WHITE);
    test.place(pieceW,2,1);
    test.place(pieceB,3,2);
    EXPECT_EQ(!passed,pieceW->canMove(test,2,1,3,2));//move 1 space
    test.remove(2,1);
    test.remove(3,2);
   
}


TEST_F(test_Pieces, testGetSymbol)
{
    char symbolPawnWhite = 'P';
    char symbolKingWhite = 'K';
    char symbolQueenWhite = 'Q' ;
    char symbolBishopWhite = 'B' ;
    char symbolKnightWhite = 'N';
    char symbolRookWhite = 'R' ;
    char symbolPawnBlack = 'p';
    char symbolKingBlack = 'k';
    char symbolQueenBlack = 'q';
    char symbolBishopBlack = 'b';
    char symbolKnightBlack = 'n';
    char symbolRookBlack = 'r';

    PiecePtr pawnW;
    PiecePtr kingW;
    PiecePtr queenW;
    PiecePtr bishopW;
    PiecePtr knightW;
    PiecePtr rookW;
    
    PiecePtr pawnB;
    PiecePtr kingB;
    PiecePtr queenB;
    PiecePtr bishopB;
    PiecePtr knightB;
    PiecePtr rookB;

    pawnB = new Pawn(BLACK);
    pawnW  = new Pawn(WHITE);
    knightB  = new Knight(BLACK);
    knightW  = new Knight(WHITE);
    kingB  = new King(BLACK);
    kingW  = new King(WHITE);
    bishopB  = new Bishop(BLACK);
    bishopW  = new Bishop(WHITE);
    queenB  = new Queen(BLACK);
    queenW  = new Queen(WHITE);
    rookB  = new Rook(BLACK);
    rookW  = new Rook(WHITE);
    

    EXPECT_EQ(symbolPawnBlack, pawnB->getSymbol());
    EXPECT_EQ(symbolPawnWhite, pawnW->getSymbol());

    EXPECT_EQ(symbolKingBlack, kingB->getSymbol());
    EXPECT_EQ(symbolKingWhite, kingW->getSymbol());

    EXPECT_EQ(symbolQueenBlack, queenB->getSymbol());
    EXPECT_EQ(symbolQueenWhite, queenW->getSymbol());

    EXPECT_EQ(symbolKnightBlack, knightB->getSymbol());
    EXPECT_EQ(symbolKnightWhite, knightW->getSymbol());

    EXPECT_EQ(symbolBishopBlack, bishopB->getSymbol());
    EXPECT_EQ(symbolBishopWhite, bishopW->getSymbol());

    EXPECT_EQ(symbolRookBlack, rookB->getSymbol());
    EXPECT_EQ(symbolRookWhite, rookW->getSymbol());
	
    
}

