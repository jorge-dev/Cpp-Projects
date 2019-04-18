#include "Board.h"
#include "Piece.h"
#include <gtest/gtest.h>
#include <iostream>

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
    
    piece = new Piece(BLACK);
    test.place (piece,1,0);
    EXPECT_EQ('p',test.getPiece(1,0)->getSymbol());
    test.remove(1,0);
   
    
    piece = new Piece(WHITE);
    test.place (piece,2,0);
     EXPECT_EQ('P',test.getPiece(2,0)->getSymbol());
     test.remove(2,0);

    piece = new Piece(BLACK);
    test.place (piece,3,0);
     EXPECT_EQ('p',test.getPiece(3,0)->getSymbol());
     test.remove(3,0);
    

}


TEST_F(test_Board, testIsOccupied)
{

    PiecePtr piece;
    bool pass = true;
    piece = new Piece(BLACK);
    test.place (piece,1,0);
    EXPECT_EQ(pass,test.isOccupied(1,0));
    test.remove(1,0);
   
    
    piece = new Piece(WHITE);
    test.place (piece,2,0);
    EXPECT_EQ(pass,test.isOccupied(2,0));
     test.remove(2,0);

    piece = new Piece(BLACK);
    test.place (piece,3,0);
    EXPECT_EQ(!pass, test.isOccupied(1,0));
     test.remove(3,0);
    

}


TEST_F(test_Board, testCopyConstructor)
{
    PiecePtr pieceW;
    
    pieceW = new Piece(WHITE);
    test.place(pieceW,1,1);
    pieceW = new Piece(BLACK);
    test.place(pieceW,2,2);
    Board copyTest(test);
    
    EXPECT_EQ('P', copyTest.getPiece(1,1)->getSymbol());

    EXPECT_EQ('p', copyTest.getPiece(2,2)->getSymbol());
    

}
 

TEST_F(test_Board, testMove)
{

    bool success = true;
    PiecePtr piece;
    PiecePtr pieceW;
//Black testing
    piece = new Piece(BLACK);
    test.place(piece,0,0);
    EXPECT_EQ(success, test.move(BLACK,0,0,2,0));

    piece = new Piece(BLACK);
    test.place(piece,2,0);
    EXPECT_EQ(success, test.move(BLACK,2,0,3,0));
    
    piece = new Piece(BLACK);
    pieceW = new Piece(WHITE);
    test.place(piece,1,1);
    test.place(pieceW,2,2);
    EXPECT_EQ(success, test.move(BLACK,1,1,2,2));

//White testing
    piece = new Piece(WHITE);
    test.place(piece,7,0);
    EXPECT_EQ(success, test.move(WHITE,7,0,5,0));

    piece = new Piece(WHITE);
    test.place(piece,5,0);
    EXPECT_EQ(success, test.move(WHITE,5,0,4,0));
    
    piece = new Piece(BLACK);
    pieceW = new Piece(WHITE);
    test.place(piece,4,1);
    test.place(pieceW,5,0);
    EXPECT_EQ(success, test.move(WHITE,5,0,4,1));
    
    
    
// false testing 
//Black testing
    piece = new Piece(BLACK);
    test.place(piece,0,7);
    EXPECT_EQ(!success, test.move(BLACK,0,7,3,7));

    piece = new Piece(BLACK);
    test.place(piece,2,6);
    EXPECT_EQ(!success, test.move(BLACK,2,6,1,6));
    
    piece = new Piece(BLACK);
    pieceW = new Piece(WHITE);
    test.place(piece,5,7);
    test.place(pieceW,4,6);
    EXPECT_EQ(!success, test.move(BLACK,5,7,4,6));

//White testing
    piece = new Piece(WHITE);
    test.place(piece,7,3);
    EXPECT_EQ(!success, test.move(WHITE,7,3,4,3));

    piece = new Piece(WHITE);
    test.place(piece,4,4);
    EXPECT_EQ(!success, test.move(WHITE,4,4,5,4));
    
    piece = new Piece(BLACK);
    pieceW = new Piece(WHITE);
    test.place(piece,2,2);
    test.place(pieceW,4,1);
    EXPECT_EQ(!success, test.move(WHITE,4,1,2,2));


}


TEST_F(test_Board, testPlace)
{
    PiecePtr piece;
    bool success = true;
    
    piece = new Piece(true);
    EXPECT_EQ(success, test.place(piece,0,0));
    
    piece = new Piece(true);
    EXPECT_EQ(success, test.place(piece,3,5));
    
    piece = new Piece(true);
    EXPECT_EQ(success, test.place(piece,5,7));
    
    piece = new Piece(true);
    EXPECT_EQ(!success, test.place(piece,3,5));
    
    piece = new Piece(true);
    EXPECT_EQ(!success, test.place(piece,5,7));
    
}

TEST_F(test_Board, testRemove)
{
    PiecePtr piece;
    bool success = true;
    
    piece = new Piece(true);
    test.place(piece,6,0);
    EXPECT_EQ(success,test.remove(6,0) );
    
    piece = new Piece(true);
    test.place(piece,1,0);
    EXPECT_EQ(success,test.remove(1,0) );

    piece = new Piece(true);
    test.place(piece,4,5);
    EXPECT_EQ(!success,test.remove(7,7) );

    piece = new Piece(true);
    test.place(piece,1,3);
    EXPECT_EQ(!success,test.remove(6,6) );
}

