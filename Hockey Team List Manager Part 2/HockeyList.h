/* 
   Name:        Jorge Avila
   Email:       javil686@mtroyal.ca
   Course:      COMP 1633-001
   Assignment:  #4
   Due Date:    March 21, 2018
   Instructor:  Paul Pospisil

   Source File: a4p2.cpp

   The "HOCKEYLIST" class holds the player information from 3  Woman Hockey 
   teams and injury reserve   =  Team CANANDA, USA, FINLAND and INJURY RESERVE.

   PUBLIC METHOD SPECIFICATION:
      
       load: initializes every tema with its corresponding players if any exist
             (returns the number total number of players)

       write: writes the information of every Team player into a file using the 
              following format: "team letter, position, goals, assists, goals agianst,
	                         name ".
				 
       display: displays all players organized by teams and assigns a number to every 
                player.
		
       move: moves a player from a specifeid country teams and moves them into the injury list
             (returns true if the player was found and is a member of a country team,
	      and false if its in the injury reserve list or player not found).
       
       activate: moves a player from the injury list into a specified country team
                 (returns true if the player was found and is in the injury reserve list, 
		  and false if its not in the injury reserve list or player not found)
		  
       update: updates active(players memeber of country teamas) players' goals, assists, 
               and -if goalie- its goals against.
               (returns true if the player is found and is a member of a country team,
	        and false if the player is in the injury reserve list or not found )
		
       lookup: looks for a player in the list using its position and if found, 
               retruns PlayerNode loaded with its information
	       
       getTeam: determines a  player's team when given the player's position in the list
                (returns the corresponding team first letter if found; 

*/


#ifndef HOCKEYLIST_H
#define HOCKEYLIST_H

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAXNAMELEN = 25;
const int MINNAMELEN = 1;

const int NUMTEAMS = 4;
const int INJURYLISTPOSITION = NUMTEAMS-1;

typedef char teamname[MAXNAMELEN+1];		// one team name is a c-string

const teamname TEAMS[NUMTEAMS] = {"Team Canada:",		
                                  "Team Finland:", 
                                  "Team USA:",
                                  "Injury Reserve:" };

const char TEAMCHARS[NUMTEAMS] = {'C', 'F', 'U', 'I'};

const char FORWARD = 'f';
const char DEFENCE = 'd';
const char GOAL = 'g';

const int NAMEWIDTH = 26;
const int TEAMWIDTH = 6;
const int GOALWIDTH = 2;
const int ASSISTWIDTH = 7;

////////////////////////////////////////////////
// Player node structure
////////////////////////////////////////////////

typedef struct PlayerNode *PlayerPtr;

struct PlayerNode
{
   char name[MAXNAMELEN+1];
   char position;
   int goals;
   int assists;
   int goalsAgainst;
};



////////////////////////////////////////////////
// 
////////////////////////////////////////////////

class HockeyList
{
 public:
  HockeyList();
  ~HockeyList();
  int  load(istream &infile);
  void write(ostream &out) const;
  void display(ostream &out) const;
  bool move(int position);
  bool activate(int position, char team);
  bool update(int position, int goals, int assists, int goalsAgainst);
  void lookup(int position, PlayerNode &player, bool &found) const;
  char getTeam(int position) const;
 private:

  struct ListNode
  {
    ListNode *next;
    ListNode *prev;
    PlayerPtr thePlayer;
  };

  typedef ListNode *ListPtr;

  int findTeamNumber(char teamLetter);
  bool search(int pos, ListPtr &item, int &team) const;
  ListPtr createPlayer(const char name[], char position, int goals, int assists, 
                        int goalsAgainst) const;
  void link(ListPtr item, int team);
  void unlink(ListPtr item);
  void displayTeam(int team, int &position, ostream &out) const;

  ListNode head[NUMTEAMS];
  ListNode tail[NUMTEAMS];
};

#endif
