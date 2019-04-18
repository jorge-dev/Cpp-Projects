#include "Board.h"
#include "Board.h"
#include "Piece.h"
#include "Board.h"
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

class test_Board : public testing::Test {
protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
    Board test;
};
 

TEST_F(test_Board, testgetPiece)
{

    PiecePtr piece;
    
    piece = new Pawn(BLACK);
    test.place (piece,1,0);
    EXPECT_EQ('p',test.getPiece(1,0)->getSymbol());
    test.remove(1,0);
   
    
    piece = new Knight(WHITE);
    test.place (piece,2,0);
     EXPECT_EQ('N',test.getPiece(2,0)->getSymbol());
     test.remove(2,0);

    piece = new Queen(BLACK);
    test.place (piece,3,0);
     EXPECT_EQ('q',test.getPiece(3,0)->getSymbol());
     test.remove(3,0);
    

}


TEST_F(test_Board, testIsOccupied)
{

    PiecePtr piece;
    bool pass = true;
    piece = new Pawn(BLACK);
    test.place (piece,1,0);
    EXPECT_EQ(pass,test.isOccupied(1,0));
    test.remove(1,0);
   
    
    piece = new Knight(WHITE);
    test.place (piece,2,0);
    EXPECT_EQ(pass,test.isOccupied(2,0));
     test.remove(2,0);

    piece = new Queen(BLACK);
    test.place (piece,3,0);
    EXPECT_EQ(!pass, test.isOccupied(1,0));
     test.remove(3,0);
    

}


TEST_F(test_Board, testCopyConstructor)
{
    PiecePtr pieceW;
    
    pieceW = new Pawn(WHITE);
    test.place(pieceW,1,1);
    pieceW = new King(WHITE);
    test.place(pieceW,2,2);
    Board copyTest(test);
    
    EXPECT_EQ('P', copyTest.getPiece(1,1)->getSymbol());

    EXPECT_EQ('K', copyTest.getPiece(2,2)->getSymbol());
    

}


TEST_F(test_Board, testMove)
{


    bool success = true;
    PiecePtr piece;
    PiecePtr pieceW;
//---------Pawn-------------------------- 
    piece = new Pawn(BLACK);
    pieceW = new Pawn(WHITE);
    test.place(piece,1,1);
    test.place(pieceW,2,2);
    EXPECT_EQ(success, test.move(BLACK,1,1,2,2));
    test.remove(1,1);
    test.remove(2,2);
   
    piece = new Pawn(BLACK);
    pieceW = new Pawn(BLACK);
    test.place(piece,1,1);
    test.place(pieceW,2,2);
    EXPECT_EQ(!success, test.move(BLACK,1,1,2,2));
    test.remove(1,1);
    test.remove(2,2);

//---------King-------------------------- 
    piece = new King(BLACK);
    pieceW = new King(WHITE);
    test.place(piece,4,4);
    test.place(pieceW,5,5);
    EXPECT_EQ(success, test.move(BLACK,4,4,5,5));
    test.remove(4,4);
    test.remove(5,5);
   
    piece = new King(BLACK);
    pieceW = new King(BLACK);
    test.place(piece,4,4);
    test.place(pieceW,5,5);
    EXPECT_EQ(!success, test.move(BLACK,4,4,5,5));
    test.remove(4,4);
    test.remove(5,5);

//---------Queen-------------------------- 
    piece = new Queen(BLACK);
    pieceW = new Queen(WHITE);
    test.place(piece,4,4);
    test.place(pieceW,7,7);
    EXPECT_EQ(success, test.move(BLACK,4,4,7,7));
    test.remove(4,4);
    test.remove(7,7);
   
    piece = new Queen(BLACK);
    pieceW = new Queen(BLACK);
    test.place(piece,4,4);
    test.place(pieceW,7,7);
    EXPECT_EQ(!success, test.move(BLACK,4,4,7,7));
    test.remove(4,4);
    test.remove(7,7);

//---------Bishop-------------------------- 
    piece = new Bishop(BLACK);
    pieceW = new Bishop(WHITE);
    test.place(piece,4,4);
    test.place(pieceW,5,5);
    EXPECT_EQ(success, test.move(BLACK,4,4,5,5));
    test.remove(4,4);
    test.remove(5,5);
   
    piece = new Bishop(BLACK);
    pieceW = new Bishop(BLACK);
    test.place(piece,4,4);
    test.place(pieceW,5,5);
    EXPECT_EQ(!success, test.move(BLACK,4,4,5,5));
    test.remove(4,4);
    test.remove(5,5);


//---------Rook-------------------------- 
    piece = new Rook(BLACK);
    pieceW = new Rook(WHITE);
    test.place(piece,4,4);
    test.place(pieceW,2,4);
    EXPECT_EQ(success, test.move(BLACK,4,4,2,4));
    test.remove(4,4);
    test.remove(2,4);
   
    piece = new Rook(BLACK);
    pieceW = new Rook(BLACK);
    test.place(piece,4,4);
    test.place(pieceW,2,4);
    EXPECT_EQ(!success, test.move(BLACK,4,4,2,4));
    test.remove(4,4);
    test.remove(2,4); 

//---------Knight-------------------------- 
    piece = new Knight(BLACK);
    pieceW = new Knight(WHITE);
    test.place(piece,4,4);
    test.place(pieceW,3,6);
    EXPECT_EQ(success, test.move(BLACK,4,4,3,6));
    test.remove(4,4);
    test.remove(3,6);
   
    piece = new Knight(BLACK);
    pieceW = new Knight(BLACK);
    test.place(piece,4,4);
    test.place(pieceW,3,6);
    EXPECT_EQ(!success, test.move(BLACK,4,4,3,6));
    test.remove(4,4);
    test.remove(5,5);   


}


TEST_F(test_Board, testPlace)
{
    PiecePtr piece;
    bool success = true;
    
    piece = new Pawn(true);
    EXPECT_EQ(success, test.place(piece,0,0));
    
    piece = new Pawn(true);
    EXPECT_EQ(success, test.place(piece,3,5));
    
    piece = new Pawn(true);
    EXPECT_EQ(success, test.place(piece,5,7));
    
    piece = new Pawn(true);
    EXPECT_EQ(!success, test.place(piece,3,5));
    
    piece = new Pawn(true);
    EXPECT_EQ(!success, test.place(piece,5,7));
    
}

TEST_F(test_Board, testRemove)
{
    PiecePtr piece;
    bool success = true;
    
    piece = new Pawn(true);
    test.place(piece,6,0);
    EXPECT_EQ(success,test.remove(6,0) );
    
    piece = new Pawn(true);
    test.place(piece,1,0);
    EXPECT_EQ(success,test.remove(1,0) );

    piece = new Pawn(true);
    test.place(piece,4,5);
    EXPECT_EQ(!success,test.remove(7,7) );

    piece = new Pawn(true);
    test.place(piece,1,3);
    EXPECT_EQ(!success,test.remove(6,6) );
}

/*
TEST_F(test_HockeyList, testWrite)
{
    EXPECT_EQ(13, load);
    
}
*/
