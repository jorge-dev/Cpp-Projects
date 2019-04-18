/**************************************************************
 *                    Olympic Hockey Teams Manager
 *
 * Author:        
 * email address: 
 * Course:        COMP 1633 - 001
 * Assignment:    4 Part 2
 * Due Date:      
 * Instructor:    P. Pospisil
 *
 * Filename:     a4p2.cpp
 *
 **************************************************************/

#include <fstream>
#include <iostream>
#include <cstring>
#include "HockeyList.h"
// #include "teamList.h"
#include "ioutil.h"
using namespace std;

void showMenu();
//******************************************************************************
// For doDisplay and doTopScorer it may seem strange or wrong that the
// HockeyList argument is being passed by const reference, but at this time 
// it is required. (it will be explained later in lectures)
//
// For those of you that don't believe this once you have a working version of
// doDisplay copy your directory and in the copy remove the const and & in both
// the prototype and header and try your program!!
//******************************************************************************
void doDisplay (const HockeyList &teamList);
// void doDisplay (PlayerPtr head);
void doMove (HockeyList &teamList, int listSize);
// void doMove (PlayerPtr &head, int listSize);
void doActivate (HockeyList &teamList, int listSize);
// void doActivate (PlayerPtr &head, int listSize);
void doUpdate (HockeyList &teamList, int listSize);
// void doUpdate (PlayerPtr &head, int listSize);
void doTopScorer (const HockeyList &teamList);
// void doTopScorer (PlayerPtr head);
void doQuit (HockeyList &teamList);
// void doQuit (PlayerPtr &head);

// int load (istream &infile, PlayerPtr &head);
// void write (ostream& outfile, PlayerPtr head);

int readPlayerNumber (int max);
char readTeam ();
int readPoints (const char []);

const char DISPLAY = 'd';
const char MOVE = 'm';
const char ACTIVATE = 'a';
const char UPDATE = 'u';
const char TOPSCORER = 's';
const char QUIT = 'q';

const int FILENAMELENGTH = 30;

int main ()
{
   char inputFileName[FILENAMELENGTH];
   ifstream inFile;
   char fakeStr[2], choice;
   bool eof;
   bool goodToGo = false;
   HockeyList OlympicTeamList;
//   PlayerPtr OlympicTeamList = NULL;
   int playersOnList;

   readString ("Enter name of input file: ", inputFileName, FILENAMELENGTH, 0, eof);
   if (static_cast<int>(strlen(inputFileName)) == 0)
   {
     goodToGo = true;
   }
   else
   {
      inFile.open(inputFileName);
      if (inFile.fail())
      {
         cout << "Unable to open " << inputFileName << " for input - Exiting" << endl;
      }
      else
      {
        playersOnList = OlympicTeamList.load(inFile);
//         playersOnList = load (inFile, OlympicTeamList);
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
           case DISPLAY    : doDisplay (OlympicTeamList);
                             break;
           case MOVE       : doMove (OlympicTeamList, playersOnList);
                             break;
           case ACTIVATE   : doActivate (OlympicTeamList, playersOnList);
                             break;
           case UPDATE     : doUpdate (OlympicTeamList, playersOnList);
                             break;
           case TOPSCORER  : doTopScorer (OlympicTeamList);
                             break;
           case QUIT       : doQuit (OlympicTeamList);
                             break;
           default         : cout << "Invalid menu choice - Try again" << endl;
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

void doDisplay (const HockeyList &teamList)
// void doDisplay (PlayerPtr head)
{
  teamList.display(cout);
//  displayTeams(head, cout);
  return;
}

void doMove (HockeyList &teamList, int listSize)
// void doMove (PlayerPtr &head, int listSize)
{
  PlayerNode player;
//   PlayerPtr player;
   int  playerListNumber;
   bool playerExists;
   char prompt[MAXNAMELEN+32];
   bool confirm,
        eof;

   cout << "************************************************************"
        << endl << endl;
   
   if (listSize == 0)
   {
     cout << "Empty list so no one to move" << endl << endl;
   }
   else
   {
     playerListNumber = readPlayerNumber(listSize);
     teamList.lookup(playerListNumber, player, playerExists);
//     search (head, playerListNumber, player, playerExists);
     if (!playerExists)
     {
       cout << "Player " << playerListNumber << " is not on the Olympic Teams list"
            << endl << endl;
     }
     else
     {
//       if (player->team != TEAMCHARS[INJURYLISTPOSITION])
//       {
         strncpy (prompt, "Move ", strlen("Move ")+1);
         strncat (prompt, player.name, MAXNAMELEN+1);
//         strncat (prompt, player->name, MAXNAMELEN+1);
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
           if (teamList.move(playerListNumber))
//           removePlayer(head, player);
//           player->team = TEAMCHARS[INJURYLISTPOSITION];
//           insertPlayer(head,player);
             cout << "Moved " << player.name << " to injury list" << endl << endl;
//             cout << "Moved " << player->name << " to injury list" << endl << endl;
           else
             cout << player.name << " is aleady on the Injury list" << endl << endl;
//             cout << player->name << " is aleady on the Injury list" << endl << endl;
         }
//       }
//       else
//       {
//         cout << player->name << " is aleady on the Injury list" << endl << endl;
//       }

     }
   }
   cout << "************************************************************"
        << endl << endl;
   
   return;
}

void doActivate (HockeyList &teamList, int listSize)
// void doActivate (PlayerPtr &head, int listSize)
{
  PlayerNode player;
//  PlayerPtr player;
  int playerListNumber;
  bool playerExists;
  char prompt[MAXNAMELEN+32];
  bool confirm,
    eof;
  char newTeam;
  
  cout << "************************************************************"
       << endl << endl;
  
  if (listSize == 0)
  {
    cout << "Empty list so no one to activate" << endl << endl;
  }
  else
  {
    playerListNumber = readPlayerNumber(listSize);
     teamList.lookup(playerListNumber, player, playerExists);
//    search (head, playerListNumber, player, playerExists);
    if (!playerExists)
    {
      cout << "Player " << playerListNumber 
           << " is not on the Olympic Teams list" << endl << endl;
    }
    else
//    else if (player->team == TEAMCHARS[INJURYLISTPOSITION])
    {
      strncpy (prompt, "Activate ", strlen("Activate ")+1);
      strncat (prompt, player.name, MAXNAMELEN+1);
//      strncat (prompt, player->name, MAXNAMELEN+1);
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
        newTeam = readTeam();
        if (!teamList.activate(playerListNumber, newTeam))
        {
          cout << player.name << " is already on an active roster"
               << endl << endl;
        }
//        removePlayer (head, player);
//        player->team = newTeam;
//        insertPlayer (head, player);
        else
        {
        cout << "Activated " << player.name << " to team "
//        cout << "Activated " << player->name << " to team ";
             << newTeam << endl << endl;
        }
      }
//    else
//    {
//      cout << player->name << " is already on an active roster"
//           << endl << endl;
//    }
    }
    
  }
  cout << "************************************************************"
       << endl << endl;
  
  return;
}

void doUpdate (HockeyList &teamList, int listSize)
//void doUpdate (PlayerPtr &head, int listSize)
{
  PlayerNode player;
//  PlayerPtr player;
  int playerListNumber;
  bool playerExists;
  char prompt[MAXNAMELEN+32];
  bool confirm,
    eof;
  int newgoals;
  int newassists;
  int newgoalsagainst;
  
  cout << "************************************************************"
       << endl << endl;

  if (listSize == 0)
  {
    cout << "Empty list so no one to update" << endl << endl;
  }
  else
  {
    playerListNumber = readPlayerNumber(listSize);

     teamList.lookup(playerListNumber, player, playerExists);
//    search (head, playerListNumber, player, playerExists);
    if (!playerExists)   // this should NEVER occur
     {
       cout << "Player " << playerListNumber 
            << " is not on the Olympic Teams list" << endl << endl;
     }
    else
    {
//      if (player->team != TEAMCHARS[INJURYLISTPOSITION])
//      {
         strncpy (prompt, "Update points for ", strlen("Update points for ")+1);
         strncat (prompt, player.name, MAXNAMELEN+1);
//         strncat (prompt, player->name, MAXNAMELEN+1);
         strncat (prompt, " (y/n)? ", strlen(" (y/n)? ")+1);
         do {
           confirm = readBool (prompt, eof);
         } while (eof);

         if (confirm)
         {
           newgoals = readPoints ("Enter goals to add: ");
           newassists = readPoints ("Enter assists to add: ");
           if (player.position == GOAL)
//           if (player->position == GOAL)
             newgoalsagainst = readPoints ("Enter goals against to add: ");
           else
             newgoalsagainst = 0;
//           player->goals += newgoals;
//           player->assists += newassists;
//           player->goalsAgainst += newgoalsagainst;
  
           if (teamList.update(playerListNumber, newgoals, newassists, newgoalsagainst))
//           removePlayer(head, player);
//           insertPlayer(head, player);
             cout << player.name << " updated" << endl << endl;
//           cout << player->name << " updated" << endl << endl;
           else
             cout << player.name << " is on injury reserve so can't be updated"
                  << endl << endl;
         }
//      }
//       else
//       {
//         cout << player.name << " is on injury reserve so can't be updated"
//              << endl << endl;
//       }
    }
  }
  
   cout << "************************************************************"
        << endl << endl;

   return;
}

void doTopScorer (const HockeyList &teamList)
//void doTopScorer (PlayerPtr head)
{
  PlayerNode first, next;
//  PlayerPtr first, next;
  bool playerExists, possible, nonGoalie;
  int index;
  
  cout << "************************************************************"
       << endl << endl;
  
  index = 1;
  teamList.lookup(index, first, playerExists);
  if (!playerExists || teamList.getTeam(index) == TEAMCHARS[INJURYLISTPOSITION])
//  if (!containsActivePlayers(head))
    cout << "There is no top scorer as there are no active players"
         << endl << endl;
  else
  {
    possible = true;
    nonGoalie = false;
    do
    {
     teamList.lookup(index, first, playerExists);
//      search(head, index, first, playerExists);
      if (playerExists)
      {
        if (teamList.getTeam(index) == TEAMCHARS[INJURYLISTPOSITION])
//        if (first->team == TEAMCHARS[INJURYLISTPOSITION])
        {
          possible = false;
        }
        else if (first.position != GOAL)
//        else if (first->position != GOAL)
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
     teamList.lookup(index, next, playerExists);
//      search(head, index, next, playerExists);
      while (playerExists && teamList.getTeam(index) != TEAMCHARS[INJURYLISTPOSITION])
//      while (playerExists && next->team != TEAMCHARS[INJURYLISTPOSITION])
      {
        if (next.position != GOAL)
//        if (next->position != GOAL)
        {
          if (next.goals + next.assists > first.goals + first.assists)
//          if (next->goals + next->assists > first->goals + first->assists)
          {
            first = next;
          }
        }
        index++;
     teamList.lookup(index, next, playerExists);
//      search(head, index, next, playerExists);
      }
      cout << "Top Scorer is:" << endl << endl;
      cout << first.name << " with " << first.goals + first.assists
//      cout << first->name << " with " << first->goals + first->assists
           << " total points" << endl << endl;
    }
    else
    {
      cout << "No top scorer - all active players are goaltenders" 
           << endl << endl;
    }
  }

  cout << "************************************************************"
       << endl << endl;
  
  return;
}

void doQuit (HockeyList &teamList)
// void doQuit (PlayerPtr &head)
{
   char outFileName[FILENAMELENGTH];
   ofstream outFile;
   bool eof;

   do {
     readString ("Enter name of output file: ", outFileName, FILENAMELENGTH, 1, eof);
     if (eof)
       cout << endl;
   } while (eof);
   outFile.open(outFileName);
   if (outFile.fail())
   {
      cout << "Unable to open " << outFileName << " for output - Exiting" << endl;
   }
   else
   {
     teamList.write(outFile);
//     write (outFile, head);
     outFile.close();
//     destroyList(head);
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
       cout << "**** Player number must be between 1 and " << max << " ****"
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

/*int load (istream& infxile, PlayerPtr& head)
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
