#include "HockeyList.h"
#include <gtest/gtest.h>
//#include <iostream>
//#include <cstring>
//#include <fstream>

class test_HockeyList : public testing::Test {
protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
    HockeyList test;
};
 

TEST_F(test_HockeyList, testLoad)
{
    ifstream infile;
    infile.open("team_rosters.txt");
    int load = test.load(infile);
    
    infile.close();
    EXPECT_EQ(13, load);
    
}


TEST_F(test_HockeyList, testDisplay)
{
    stringstream out("Team Canada:\n1:\t Meghan Agosta           9   goals   6   assists   \n2:\t Marie-Philip Poulin     7   goals   2   assists   \n3:\t Jocelyne Larocque       0   goals   3   assists   \n4:\t Shannon Szabados        0   goals   1   assists   3   goals against\n\nTeam Finland:\n5:\t Susanna Tapani          1   goals   4   assists   \n6:\t Riikka Nieminen         7   goals   5   assists   \n7:\t Anni Keisala            0   goals   0   assists   5   goals against\n\nTeam USA:\n8:\t Amanda Kessel           4   goals   3   assists   \n9:\t Alex Rigsby             0   goals   0   assists   5   goals against\n10:\t Gigi Marvin             0   goals   1   assists   \n\nInjury Reserve:\n11:\t Anna Kilponen           0   goals   2   assists   \n12:\t Brianna Decker          2   goals   4   assists   \n13:\t Genevieve Lacasse       0   goals   0   assists   4   goals against\n\n");
    stringstream in;
    
    int load;
    ifstream infile;
    infile.open("team_rosters.txt");
    load = test.load(infile);
    
   infile.close();
   test.display(in);
   EXPECT_EQ(out.str(),in.str());
}


TEST_F(test_HockeyList, testWrite)
{
    stringstream out("C f 9 6 0 Meghan Agosta \nC f 7 2 0 Marie-Philip Poulin \nC d 0 3 0 Jocelyne Larocque \nC g 0 1 3 Shannon Szabados \nF f 1 4 0 Susanna Tapani \nF f 7 5 0 Riikka Nieminen \nF g 0 0 5 Anni Keisala \nU f 4 3 0 Amanda Kessel \nU g 0 0 5 Alex Rigsby \nU d 0 1 0 Gigi Marvin \nI d 0 2 0 Anna Kilponen \nI f 2 4 0 Brianna Decker \nI g 0 0 4 Genevieve Lacasse \n");
    stringstream in;
    
    int load;
    ifstream infile;
    infile.open("team_rosters.txt");
    load = test.load(infile);
    
   infile.close();
   test.write(in);
   EXPECT_EQ(out.str(),in.str());


}


TEST_F(test_HockeyList, testLookup)
{
    int load;
    PlayerNode player;
    bool found,
	success = true;
    ifstream infile;
    infile.open("team_rosters.txt");
    load = test.load(infile);
    
    test.lookup(2, player,found);
    EXPECT_EQ('f', player.position);
    EXPECT_EQ(7, player.goals);
    EXPECT_EQ(2, player.assists);
    EXPECT_EQ(success, found);

    test.lookup(13, player,found);
    EXPECT_EQ('g', player.position);
    EXPECT_EQ(0, player.goals);
    EXPECT_EQ(0, player.assists);
    EXPECT_EQ(success, found);

    test.lookup(14, player,found);
    EXPECT_EQ(!success, found);
  
}

TEST_F(test_HockeyList, testMove)
{

    bool pass= true;
    bool fail = false;
    ifstream infile;
    int load ;
    infile.open("team_rosters.txt");
    load = test.load(infile);
    infile.close();
    EXPECT_EQ(pass, test.move(3));
    EXPECT_EQ(pass, test.move(8));
    EXPECT_EQ(pass, test.move(5));
    EXPECT_EQ(fail, test.move(13));
    EXPECT_EQ(fail, test.move(12));

}

TEST_F(test_HockeyList, testActivate)
{
    bool pass= true;
    bool fail = false;
    ifstream infile;
    int load;
    infile.open("team_rosters.txt");
    load = test.load(infile);
    infile.close();
    EXPECT_EQ(pass, test.activate(11,'C'));
    EXPECT_EQ(pass, test.activate(12,'F'));
    EXPECT_EQ(fail, test.activate(4,'U'));
    EXPECT_EQ(fail, test.activate(1,'C'));
    EXPECT_EQ(fail, test.activate(6,'F'));
}

TEST_F(test_HockeyList, testUpdate)
{
    bool pass= true;
    bool fail = false;
    ifstream infile;
    int load ;
    infile.open("team_rosters.txt");
    load = test.load(infile);
    infile.close();
    
 
    EXPECT_EQ(pass, test.update(2,2,2,0));
    EXPECT_EQ(pass, test.update(5,5,5,0));
    EXPECT_EQ(pass, test.update(8,5,5,0));
    EXPECT_EQ(pass, test.update(4,5,5,5));
    EXPECT_EQ(fail, test.update(12,6,6,6));
    EXPECT_EQ(fail, test.update(13,5,2,1));
}

TEST_F(test_HockeyList, testGetTeam)
{

    int load ;
    ifstream infile;
    infile.open("team_rosters.txt");
    load = test.load(infile);
    
    infile.close();

    EXPECT_EQ('C', test.getTeam(4));
    EXPECT_EQ('F', test.getTeam(5));
    EXPECT_EQ('U', test.getTeam(9));
    EXPECT_EQ('I', test.getTeam(12));
}
