#include "Board.h"
#include "Piece.h"
#include <gtest/gtest.h>
#include <iostream>
//#include <cstring>
//#include <fstream>

class test_Piece : public testing::Test {
protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
    //PiecePtr piece;
    //Piece test(true);
    Board test;
};
 

TEST_F(test_Piece, testGetSymbol)
{
    Piece pieceB(BLACK);
    Piece pieceW(WHITE);
    char symbolW ='P';
    char symbolB ='p';
    
    EXPECT_EQ(symbolB, pieceB.getSymbol());
    EXPECT_EQ(symbolW, pieceW.getSymbol());
	
    
}


TEST_F(test_Piece, testGetColour)
{
    // bool white = WHITE;
     bool black = BLACK;
    Piece pieceB(BLACK);
    Piece pieceW(WHITE);
    
    EXPECT_EQ(black, pieceB.getColour());
    
  
    
}

TEST_F(test_Piece, testCanMoveBlackPiece)
{
    //PiecePtr pieceB;
    //PiecePtr pieceW;
    PiecePtr white;//= new Piece(WHITE);
    PiecePtr black;// = new Piece(BLACK);
    bool passed=true;
// passed
    black = new Piece(BLACK);
    test.place(black,0,0);
    EXPECT_EQ(passed,black->canMove(test,0,0,2,0));//move 2 spaces from beggining
    
    black = new Piece(BLACK);
    test.place(black,2,0);
    EXPECT_EQ(passed,black->canMove(test,2,0,3,0));//move 1 space

    black = new Piece(BLACK);
    test.place(black,4,0);
    EXPECT_EQ(passed,black->canMove(test,4,0,4,1));//move 1 space horizontally ->

    black = new Piece(BLACK);
    test.place(black,2,7);
    EXPECT_EQ(passed,black->canMove(test,2,7,2,6));//move 1 space horizontally <-

    black = new Piece(BLACK);
    white = new Piece(WHITE);
    test.place(black,2,1);
    test.place(white,3,2);
    EXPECT_EQ(passed,black->canMove(test,2,1,3,2));//move 1 space


//!passed

    black = new Piece(BLACK);
    // test.place(black,0,0);
    EXPECT_EQ(!passed,black->canMove(test,0,0,3,0));//move more than 2 spaces from beggining
    
    black = new Piece(BLACK);
    //test.place(black,2,0);
    EXPECT_EQ(!passed,black->canMove(test,2,0,1,0));//move 1 space back

     black = new Piece(BLACK);
    test.place(black,3,0);
    EXPECT_EQ(!passed,black->canMove(test,2,0,3,0));//move on occupied

    black = new Piece(BLACK);
    //test.place(black,2,0);
    EXPECT_EQ(!passed,black->canMove(test,2,0,4,0));//move 2 spaces after initial posiotion

    black = new Piece(BLACK);
    //test.place(black,2,0);
    EXPECT_EQ(!passed,black->canMove(test,7,0,8,0));//move outside bounds

    black = new Piece(BLACK);
    //test.place(black,2,0);
    EXPECT_EQ(!passed,black->canMove(test,-2,0,-9,9));//negative coordinates

    black = new Piece(BLACK);
    white = new Piece(WHITE);
    test.place(white,2,1);
    test.place(black,3,2);
    EXPECT_EQ(!passed,black->canMove(test,3,2,2,1));//move 1 space


/*
    black = new Piece(BLACK);
    test.place(black,4,0);
    EXPECT_EQ(passed,black->canMove(test,4,0,4,1));//move 1 space horizontally ->

    black = new Piece(BLACK);
    test.place(black,2,7);
    EXPECT_EQ(passed,black->canMove(test,2,7,2,6));//move 1 space horizontally <-
*/


}

TEST_F(test_Piece, testCanMoveWhitePiece)
{
    //PiecePtr pieceB;
    //PiecePtr pieceW;
    PiecePtr white;//= new Piece(WHITE);
    PiecePtr black;// = new Piece(BLACK);
    bool passed=true;    


// passed
    white = new Piece(WHITE);
    test.place(white,7,7);
    EXPECT_EQ(passed,white->canMove(test,7,7,5,7));//move 2 spaces from beggining
    
    white = new Piece(WHITE);
    test.place(white,5,3);
    EXPECT_EQ(passed,white->canMove(test,5,3,4,3));//move 1 space

    white = new Piece(WHITE);
    test.place(white,5,0);
    EXPECT_EQ(passed,white->canMove(test,5,0,5,1));//move 1 space horizontally ->

    white = new Piece(WHITE);
    test.place(white,4,7);
    EXPECT_EQ(passed,white->canMove(test,4,7,4,6));//move 1 space horizontally <-


    white = new Piece(WHITE);
    black = new Piece(BLACK);
    test.place(white,5,4);
    test.place(black,4,5);
    EXPECT_EQ(passed,white->canMove(test,5,4,4,5));//move 1 back diagonally


// !passed
    white = new Piece(WHITE);
    //test.place(white,7,7);
    EXPECT_EQ(!passed,white->canMove(test,7,7,4,7));//move more than 2 spaces from beggining
    
    white = new Piece(WHITE);
    //test.place(white,5,3);
    EXPECT_EQ(!passed,white->canMove(test,5,3,6,3));//move 1 space back

    white = new Piece(WHITE);
    //test.place(white,5,3);
    EXPECT_EQ(!passed,white->canMove(test,5,3,3,3));//move 2 spaces after init position

    white = new Piece(WHITE);
    //test.place(white,5,3);
    EXPECT_EQ(!passed,white->canMove(test,5,3,9,3));// out bounds

     white = new Piece(WHITE);
    //test.place(white,5,3);
    EXPECT_EQ(!passed,white->canMove(test,-5,3,-6,3));
    
    white = new Piece(WHITE);
    black = new Piece(BLACK);
    test.place(black,5,4);
    test.place(white,4,5);
    EXPECT_EQ(!passed,white->canMove(test,4,5,5,4));//move back diagonally


/*
    white = new Piece(WHITE);
    test.place(white,5,0);
    EXPECT_EQ(passed,white->canMove(test,5,0,5,1));//move 1 space horizontally ->

    white = new Piece(WHITE);
    test.place(white,4,7);
    EXPECT_EQ(passed,white->canMove(test,4,7,4,6));//move 1 space horizontally <-
*/

}

