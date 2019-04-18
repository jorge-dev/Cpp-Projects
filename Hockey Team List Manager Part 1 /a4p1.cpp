/**************************************************************
 *                    Olympic Hockey Teams Manager
 *
 * Author:        Jorge Avila         
 * email address: javil686@mtroyal.ca
 * Course:        COMP 1633 - 001
 * Assignment:    4 Part 1
 * Due Date:      March 7
 * Instructor:    P. Pospisil
 *
 * Filename:     a4p1.cpp
 *
 **************************************************************/

#include <fstream>
#include <iostream>
#include <cstring>
#include "HockeyList.h"
//#include "teamList.h"
#include "ioutil.h"
using namespace std;

void showMenu();
void doMove(HockeyList &teamList, int listSize);
void doActivate (HockeyList &teamList, int listSize);
void doUpdate (HockeyList &teamList, int listSize);
void doTopScorer (HockeyList teamList);
void doQuit (HockeyList teamList);

//  void doDisplay (PlayerPtr head);
//  void doMove (PlayerPtr &head, int listSize);
//  void doActivate (PlayerPtr &head, int listSize);
//  void doUpdate (PlayerPtr &head, int listSize);
//  void doTopScorer (PlayerPtr head);
//  void doQuit (PlayerPtr &head);

//  int load (istream &infile, PlayerPtr &head);
//  void write (ostream& outfile, PlayerPtr head);

int readPlayerNumber (int max);
char readTeam ();
int readPoints (const char []);

const char DISPLAY = 'd';
const char MOVE = 'm';
const char ACTIVATE = 'a';
const char UPDATE = 'u';
const char TOPSCORER = 's';
const char QUIT = 'q';

const int INJURY_LIST_POSITION = 3;
const int FILENAME_LENGTH = 30;

int main ()
{

    char inputFileName[FILENAME_LENGTH];
    ifstream inFile;
    char fakeStr[2], choice;
//  PlayerPtr OlympicTeamList = NULL;
    HockeyList teamList; //change 
    bool eof;
    bool goodToGo = false;
    int playersOnList;
    
    readString ("Enter name of input file: ", inputFileName, 
		FILENAME_LENGTH, 0, eof);
    if (static_cast<int>(strlen(inputFileName)) == 0)
    {
	goodToGo = true;
    }
    else
    {
	inFile.open(inputFileName);
	if (inFile.fail())
	{
	    cout << "Unable to open " << inputFileName 
		 << " for input - Exiting" << endl;
	}
	else
	{
	    playersOnList = teamList.load(inFile);
//          playersOnList =load (inFile, OlympicTeamList);
	    inFile.close();
	    goodToGo = true;
	}
    }
    if (goodToGo)
    {
	do
	{
	    showMenu();
	    readString("\nYour Choice:  ",fakeStr, 1, 1, eof);
	    choice = fakeStr[0];
	    choice = static_cast <char> (tolower(choice));
	    switch (choice)
	    {
	    case DISPLAY    : teamList.display(cout); 
//                            doDisplay (OlympicTeamList);
		break;
	    case MOVE       : doMove (teamList, playersOnList);
//		              doMove (OlympicTeamList, playersOnList);
		break;
	    case ACTIVATE   : doActivate (teamList, playersOnList);
//                            doActivate (OlympicTeamList,playersOnList);
		break;
	    case UPDATE     : doUpdate (teamList, playersOnList);
//                            doUpdate (OlympicTeamList, playersOnList);
		break;
	    case TOPSCORER  : doTopScorer (teamList);
//                            doTopScorer (OlympicTeamList);
		break;
	    case QUIT       : doQuit (teamList);
//                            doQuit (OlympicTeamList);
		break;
	    default         : cout << "Invalid menu choice - Try again" 
				   << endl;
		break;
	    }
	}
	while (choice != QUIT);

    }
    return 0;
}

void showMenu()
{
    cout << endl;
    cout << "Olympic Teams List Manager:" << endl << endl;
    cout << "d) display list" << endl;
    cout << "m) move a player to injury reserve" << endl;
    cout << "a) activate a player from injury reserve" << endl;
    cout << "u) update player points" << endl;
    cout << "s) show top scorer" << endl << endl;
    cout << "q) quit" << endl << endl;
 
    return;
}

//  void doDisplay (PlayerPtr head)
//  {
    
//  displayTeams(head, cout);
//  return;
//  }

void doMove(HockeyList &teamList, int listSize)
//void doMove(PlayerPtr &head, int listSize)
{
//  PlayerPtr player;
    PlayerNode player;
    int  playerListNumber;
    bool playerExists;
    char prompt[MAXNAMELEN+32];
    char teamChar; //change
    bool confirm,
        eof,
	isEven;

    cout <<"************************************************************"
	 << endl << endl;
   
    if (listSize == 0)
    {
	cout << "Empty list so no one to move" << endl << endl;
    }
    else
    {
	playerListNumber = readPlayerNumber(listSize);
	teamList.lookup(playerListNumber, player, playerExists); //change
//      search (head, playerListNumber, player, playerExists);

	if (!playerExists)
	{
	    cout << "Player " << playerListNumber 
		 << " is not on the Olympic Teams list"
		 << endl << endl;
	}
	else
	{
	    teamChar = teamList.getTeam(playerListNumber); //change
	    
	    if (teamChar != TEAMCHARS[INJURY_LIST_POSITION])
//	    if (player->team != TEAMCHARS[INJURY_LIST_POSITION])
	    {
		strncpy (prompt, "Move ", strlen("Move ")+1);
		strncat (prompt, player.name, MAXNAMELEN+1);
//		strncat (prompt, player->name, MAXNAMELEN+1);
		strncat (prompt, " to Injury Reserve (y/n)? ", 
			 strlen(" to Injury Reserve (y/n)? ")+1);
		do
		{
		    confirm = readBool(prompt, eof);
		    if (eof)
		    {
			cout << endl
			     << "**** Ignoring ctrl-d - to abort the program type ctrl-c ****"
			     << endl;
		    }
		} while (eof);
      
		if (confirm)
		{
		    isEven = teamList.move(playerListNumber); //change
		    if (isEven)
		    {
//			removePlayer(head, player);
//			player->team = TEAMCHARS[INJURY_LIST_POSITION];
//			insertPlayer(head,player);

			cout << "Moved " << player.name 
			     << " to injury list" << endl << endl;

//                      cout << "Moved " << player->name
//			     << " to injury list" << endl << endl;
		    }
		    else
			cout <<player.name 
			     << " is aleady on the Injury list" << endl 
			     << endl;
		}
	    }
//	    else
//	      {
//	      cout <<player->name << " is aleady on the Injury list" 
//                 << endl << endl;
//	      }
	}
    }
    cout <<"************************************************************"
	 << endl << endl;
   
    return;
}

void doActivate (HockeyList &teamList, int listSize)
//void doActivate (PlayerPtr &head, int listSize)
{
//  PlayerPtr player;
    PlayerNode player;
    int playerListNumber;
    bool playerExists;
    char prompt[MAXNAMELEN+32];
    char teamChar;
    bool confirm,
	eof,
	isEven;
    char newTeam;
  
    cout <<"************************************************************"
	 << endl << endl;
  
    if (listSize == 0)
    {
	cout << "Empty list so no one to activate" << endl << endl;
    }
    else
    {
	playerListNumber = readPlayerNumber(listSize);

	teamList.lookup(playerListNumber, player, playerExists); //change
//	search (head, playerListNumber, player, playerExists);
	
	teamChar = teamList.getTeam(playerListNumber); //change
	

	if (!playerExists)
	{
	    cout << "Player " << playerListNumber 
		 << " is not on the Olympic Teams list" << endl << endl;
	}

	
	else if (teamChar != TEAMCHARS[INJURY_LIST_POSITION])
//	else if (player->team == TEAMCHARS[INJURY_LIST_POSITION])
	{
	    strncpy (prompt, "Activate ", strlen("Activate ")+1);
	    strncat (prompt, player.name, MAXNAMELEN+1);
//          strncat (prompt, player->name, MAXNAMELEN+1);
	    strncat (prompt, " (y/n)? ", strlen(" (y/n)? ")+1);

	    do
	    {
		confirm = readBool(prompt, eof);
		if (eof)
		{
		    cout << endl
			 << "**** Ignoring ctrl-d - to abort the program type ctrl-c ****"
			 << endl;
		}
	    } while (eof);
      
	    if (confirm)
	    {
		//change
		isEven = teamList.activate(playerListNumber,teamChar); 
		if (isEven)
		{
		    newTeam = readTeam();
//	            removePlayer (head, player);
//		    player->team = newTeam;
//		    insertPlayer (head, player);

		    cout << "Activated " <<player.name << " to team " 
			 << newTeam << endl << endl;

//		    cout << "Activated " << player->name << " to team " 
//			 << newTeam << endl << endl;
		}
		else
		{
		    cout << player.name 
			 << " is already on an active roster"
			 << endl << endl;
		}
	    }
	}
//	else
//	{
//	    cout << /*player->name*/player.name 
//               << " is already on an active roster"
//		 << endl << endl;
//	}
    
    }
    cout <<"************************************************************"
	 << endl << endl;
  
    return;
}

void doUpdate (HockeyList &teamList, int listSize)
//void doUpdate (PlayerPtr &head, int listSize)
{
//  PlayerPtr player;
    PlayerNode player;
    int playerListNumber;
    bool playerExists;
    char prompt[MAXNAMELEN+32];
    char teamChar;
    bool confirm,
	 eof,
	 isEven;
    int newgoals;
    int newassists;
    int newgoalsagainst;
  
    cout <<"************************************************************"
	 << endl << endl;

    if (listSize == 0)
    {
	cout << "Empty list so no one to update" << endl << endl;
    }
    else
    {
	playerListNumber = readPlayerNumber(listSize);
	teamList.lookup(playerListNumber, player, playerExists); //change
//	search (head, playerListNumber, player, playerExists);
	
	if (!playerExists)   // this should NEVER occur
	{
	    cout << "Player " << playerListNumber 
		 << " is not on the Olympic Teams list" << endl << endl;
	}
	else
	{
	    
	    teamChar = teamList.getTeam(playerListNumber); //change
	    
	    
	    if (teamChar != TEAMCHARS[INJURY_LIST_POSITION])
		
//	    if (player->team != TEAMCHARS[INJURY_LIST_POSITION])
	    {
		strncpy (prompt, "Update points for ", 
			 strlen("Update points for ")+1);
		strncat (prompt, player.name, MAXNAMELEN+1);
//              strncat (prompt, player->name, MAXNAMELEN+1);
		strncat (prompt, " (y/n)? ", strlen(" (y/n)? ")+1);
		do {
		    confirm = readBool (prompt, eof);
		} while (eof);
		if (confirm)
		{
		    //change
		    isEven = teamList.update(playerListNumber,
					     player.goals,player.assists,
					     player.goalsAgainst); 
		    if (isEven)
		    {
			newgoals = readPoints ("Enter goals to add: ");
			newassists = readPoints ("Enter assists to add: ");
			if (player.position == GOAL)
//                      if (player->position == GOAL)
			    newgoalsagainst = readPoints ("Enter goals against to add: ");
			else
			{
			    newgoalsagainst = 0;
//			    player->goals += newgoals;
//			    player->assists += newassists;
//			    player->goalsAgainst += newgoalsagainst;
           
//			    removePlayer(head, player);
//			    insertPlayer(head, player);

			    cout <<player.name << " updated" << endl 
				 << endl;

//			    cout << player->name << " updated" << endl 
//                               << endl;
			}
		    
		    }
		    
		    else
		    {
			cout <<player.name << " is on injury reserve so can't be updated"
			     << endl << endl;
		    }
		}
	    }
//	    else
//	    {
//		cout << player->name 
//                   << " is on injury reserve so can't be updated"
//		     << endl << endl;
//	    }
	}
    }
  
    cout << "************************************************************"
	 << endl << endl;

    return;
}

void doTopScorer (HockeyList teamList)
//void doTopScorer (PlayerPtr head)
{
    //PlayerPtr first, next;
    PlayerNode player;
    PlayerNode pFirst,pNext;
    bool playerExists, possible, nonGoalie;
    int index;
    char teamChar;
  
    cout <<"************************************************************"
	 << endl << endl;
  
    index = 1;
    teamChar = teamList.getTeam(index); //change
    if (teamChar == TEAMCHARS[INJURY_LIST_POSITION]) //change
//  if (!containsActivePlayers(head))
	cout << "There is no top scorer as there are no active players"
	     << endl << endl;
    else
    {
	possible = true;
	nonGoalie = false;
	do
	{
	    cout<<"you are in do while loop"<<endl;
	    teamList.lookup(index, player, playerExists); //change    
//	    search(head, index, first, playerExists);
	    pFirst = player; //change
	    teamChar = teamList.getTeam(index); //change

	    if (playerExists)
	    {
		if (teamChar == TEAMCHARS[INJURY_LIST_POSITION]) //change
//		if (first->team == TEAMCHARS[INJURY_LIST_POSITION])
		{
		    possible = false;
		}
		else if (pFirst.position != GOAL)
//              else if (first->position != GOAL)
		{
		    nonGoalie = true;
		}
		else
		    index++;
	    }
	} while (playerExists && !nonGoalie && possible);

	if (nonGoalie)
	{
	    index++;
	    
	    teamList.lookup(index, player, playerExists); //change
//	    search(head, index, next, playerExists);
	    pNext = player; //change
	    teamChar = teamList.getTeam(index); //change


	    while (playerExists && teamChar != 
		   TEAMCHARS[INJURY_LIST_POSITION])
//          while (playerExists && next->team != 
//		   TEAMCHARS[INJURY_LIST_POSITION])
	    {
		if (pNext.position != GOAL)
//              if (next->position != GOAL)
		{
		    if (pNext.goals + pNext.assists > 
			pFirst.goals + pFirst.assists)
//		    if (next->goals + next->assists > 
//                      first->goals + first->assists)
		    {
			pFirst = pNext;
//			first = next;
		    }
		}
		index++;
		teamList.lookup(index, player, playerExists); //change
//		search(head, index, next, playerExists);
		teamChar = teamList.getTeam(index); //change    
		

	    }

	    cout << "Top Scorer is:" << endl << endl;
	    cout << pFirst.name << " with " 
		 << pFirst.goals + pFirst.assists
		 << " total points" << endl << endl;
//	    cout << "Top Scorer is:" << endl << endl;
//	    cout << first->name << " with " 
//               << first->goals + first->assists
//		 << " total points" << endl << endl;
	    
	}
	else
	{
	    cout << "No top scorer - all active players are goaltenders" 
		 << endl << endl;
	}
    }

    cout <<"************************************************************"
	 << endl << endl;
  
    return;
}

void doQuit (HockeyList teamList)
//void doQuit (PlayerPtr &head)
{
//  PlayerPtr player;
    PlayerNode player;
    char outFileName[FILENAME_LENGTH];
    ofstream outFile;
    bool eof ;
  bool found;
  int playerPosition;

    do {
	readString ("Enter name of output file: ", outFileName, 
		    FILENAME_LENGTH, 1, eof);
	if (eof)
	    cout << endl;
    } while (eof);
    outFile.open(outFileName);
    if (outFile.fail())
    {
	cout << "Unable to open " << outFileName 
	     << " for output - Exiting" << endl;
    }
    else
    {
	
	playerPosition = 1; 
	teamList.lookup(playerPosition,player,found); //change
//	search (head, playerPosition, player, found);
	while (found)
	{
	    teamList.write(outFile); //change

//	    outFile << player->team << ' '
//	            << player->position<< ' '
//	            << player->goals<< ' '
//	            << player->assists<< ' '
//	            << player->goalsAgainst<< ' '
//	            << player->name<< endl;

	playerPosition++;

	teamList.lookup(playerPosition,player,found);
//	search (head, playerPosition, player, found);
    }
	
	outFile.close();
//	destroyList(head);
    }      

    return;
}


int readPlayerNumber (int max)
{
    int p;
    bool pOK,
        eof;

    p = readInt("Enter Player number: ", eof);
    !eof ? pOK = (p > 0 && p <= max): pOK = false;

    while (!pOK || eof)
    {
	if (eof)
	    cout << endl
		 << "**** Ignoring ctrl-d - to abort the program type ctrl-c ****"
		 << endl;
	else
	    cout << "**** Player number must be between 1 and " 
		 << max << " ****"
		 << endl;
	p = readInt("Enter Player number: ", eof);
	!eof ? pOK = (p > 0 && p <= max): pOK = false;
    }
    return p;
}

int readPoints (const char prompt[])
{
    int p;
    bool pOK = false,
        eof;

    do
    {
	p = readInt(prompt, eof);
	if (eof)
	{
	    cout << endl
		 << "**** Ignoring ctrl-d - to abort the program type ctrl-c ****"
		 << endl;
	}
	else if (p < 0)
	    cout << "**** All player points must be greater than or equal to 0 ****"
		 << endl;
	else
	    pOK = (p >= 0);
    } while (eof || !pOK);

    return p;
}

char readTeam ()
{
    char fakeStr[2], c;
    bool cOK, eof;
  
    readString("Enter team (C/F/U): ",fakeStr, 1, 1, eof);
    c = fakeStr[0];
    cOK = ((c == 'C') || (c == 'F') || (c == 'U'));
    while (!cOK)
    {
	cout << "**** Team must be one of C(anada), F(inland) or U(SA) ****" << endl;
	readString("Enter team (C/F/U): ",fakeStr, 1, 1, eof);
	c = fakeStr[0];
	cOK = ((c == 'C') || (c == 'F') || (c == 'U'));
    }
    return c;
}
/*
  int load (istream& infile, PlayerPtr& head)
  {
  char pName[MAXNAMELEN+1];
  char pTeam;
  char pPos;
  int pGoals;
  int pAssists;
  int pGoalsAgainst;
  char junk;
  PlayerPtr curr;
  int count = 0;

  infile >> pTeam;
  while (!infile.eof())
  {
  count++;
  infile >> pPos >> pGoals >> pAssists >> pGoalsAgainst;
  infile.get (junk);
  infile.getline(pName, MAXNAMELEN+1, '\n');
  curr = createPlayer (pName, pTeam, pPos, pGoals, pAssists, pGoalsAgainst);
  insertPlayer (head, curr);
  infile >> pTeam;
  }
  return count;
  }

  void write (ostream& outfile, PlayerPtr head)
  {
  PlayerPtr temp = head;

  while (temp != NULL)
  {
  outfile << temp->team << " ";
  outfile << temp->position << " ";
  outfile << temp->goals << " ";
  outfile << temp->assists << " ";
  outfile << temp->goalsAgainst << " ";
  outfile << temp->name << endl;

  temp = temp->next;
  }
  return;
  }

*/
