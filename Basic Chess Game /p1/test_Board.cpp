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
 


TEST_F(test_Board, testCopyConstructor)
{
    PiecePtr piece1;
    PiecePtr piece2;
    PiecePtr piece3;
    PiecePtr piece4;
    bool copy = true;
    bool copy2 = true;
    piece1 =new Piece;
    test.place(piece1 ,1,1);

    piece2  = new Piece;
    test.place(piece2 ,2,2);

    Board copyTest(test);

    piece3 = new Piece;
    EXPECT_EQ(!copy, copyTest.place(piece3 ,1,1));
    piece4 = new Piece;
    EXPECT_EQ(!copy2, copyTest.place(piece4 ,2,2));
    

}



TEST_F(test_Board, testMove)
{

    bool success = true;
    PiecePtr piece;

    piece = new Piece;
    test.place(piece,0,0);
    EXPECT_EQ(success, test.move(0,0,1,1));

    piece = new Piece;
    test.place(piece,2,2);
    EXPECT_EQ(success, test.move(2,2,3,3));
    
    piece = new Piece;
    test.place(piece,4,4);
    EXPECT_EQ(!success, test.move(4,4,3,3));
    
    piece = new Piece;
    test.place(piece,5,5);
    EXPECT_EQ(!success, test.move(5,5,1,1));

    piece = new Piece;
    test.place(piece,7,7);
    EXPECT_EQ(!success, test.move(3,4,0,7));
    
}


TEST_F(test_Board, testPlace)
{
    PiecePtr piece;
    bool success = true;
    
    piece = new Piece;
    EXPECT_EQ(success, test.place(piece,0,0));
    
    piece = new Piece;
    EXPECT_EQ(success, test.place(piece,3,5));
    
    piece = new Piece;
    EXPECT_EQ(success, test.place(piece,5,7));
    
    piece = new Piece;
    EXPECT_EQ(!success, test.place(piece,3,5));
    
    piece = new Piece;
    EXPECT_EQ(!success, test.place(piece,5,7));
    
}

TEST_F(test_Board, testRemove)
{
    PiecePtr piece;
    bool success = true;
    
    piece = new Piece;
    test.place(piece,6,0);
    EXPECT_EQ(success,test.remove(6,0) );
    
    piece = new Piece;
    test.place(piece,1,0);
    EXPECT_EQ(success,test.remove(1,0) );

    piece = new Piece;
    test.place(piece,4,5);
    EXPECT_EQ(!success,test.remove(7,7) );

    piece = new Piece;
    test.place(piece,1,3);
    EXPECT_EQ(!success,test.remove(6,6) );
}

