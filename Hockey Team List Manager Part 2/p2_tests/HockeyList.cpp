#include "HockeyList.h"
#include <iostream>
#include <cstring>

/*
  INTERNAL IMPLEMENTATION:
       findTeamNumber is implemente inside update.
       
       search is implemented inside move,activate,update,lookup,
                                    and getTeam
				    
       createPlayer is implemented inside load
       
       link is implemented inside  update,activate and move
				  
       unlink is implemented inside ~HockeyList, update,activate 
                                  and move

				  
       displayTeam is implemented inside display

  PRIVATE METHOD SPECIFICATION:
  
       findTeamNumber: takes a teams first letter caharacter and 
                       converts it to the correct array index for 
		       that team (returns the team index number).

       search: searches a specific player in the list and if found
               it updates and returns the player's team and a 
               PlayerNode with the rest of the information.
	       (returns true if the player is found, false if not)

       createPlayer: creates new player node by dinamiacally allocating
                     the necessary memory needed to create players 
		     during run time.
		     (returns a ListPtr loaded with players information)

       link: correctly links and connects a new node into the link list
             by redirecting the pointers to avoid a memory leak

       unlinks: detaches a node from the link list by correctly redirecting
                necessary pointers to extract the neede node from the 
                current list.

       displayTeam: given a specified team, it traverses the specified team's
                    list and prints all the players and its information one
		    by one using the following format:
		    "number, player name, goals, assists, goals against"
		  
     


 */



//=======================Public=============================

HockeyList::HockeyList()
{
    for (int i = 0; i < 4; i++)
    {
	head[i].next = &tail[i];
	tail[i].prev = &head[i]; 
    }
  // stub
}

HockeyList::~HockeyList()
{

    ListPtr temp;
    for (int i = 0; i < NUMTEAMS;i++)
    {
	temp = head[i].next;
	while (temp != &tail[i])
	{
	    //head[i].next = temp -> next;
	    unlink(temp);
	    delete temp -> thePlayer;
	    delete temp;
	    temp = head[i].next;
	}
	//head[i].next == &tail[i];
	
    }
    
  // stub
}

int HockeyList::load(istream &infile)
{
    char name [MAXNAMELEN+1];
    char position;
    int goals;
    int assists;
    int goalsAgainst;
    char team;
    int numPlayers = 0;
    int teamNumber;
    ListPtr listPlayer;

    infile >> team;
    
    while (!infile.eof())
    {
	teamNumber = findTeamNumber(team);
	
	infile >> position;
	infile >> goals;
	infile >> assists;
	infile >> goalsAgainst;
	infile.ignore();
	infile.getline(name,MAXNAMELEN + 1);
     
	listPlayer = createPlayer(name, position, goals, assists, 
					   goalsAgainst);

	link(listPlayer, teamNumber);

	infile >> team;
	
	numPlayers++;

    }

    
    
  // stub
    return numPlayers;
}

void HockeyList::write(ostream &out)const
{
    ListPtr current;

    for (int i = 0; i < NUMTEAMS; i++)
    {
	    current = head[i].next;
	while (current != &tail[i])
	{
	    out << TEAMCHARS[i]<< ' ';
	    out << current -> thePlayer -> position<< ' ';
	    out << current -> thePlayer -> goals<< ' ';
	    out << current -> thePlayer -> assists<< ' ';
	    out << current -> thePlayer -> goalsAgainst<< ' ';
	    out << current -> thePlayer -> name;
	    out << endl;
	    current = current ->next;
	    
	}
    }
    
    
    
  // stub
}

void HockeyList::display(ostream &out) const
{
    int position =1;
    int numEmpty = 0;
//    cout << "--------------------------------------------"
//	 << "-----------------------------------"<<endl<<endl;
   
    
    
    for (int i = 0; i < NUMTEAMS; i++)
    {
	 if (head[i].next == &tail[i])
	 {
	     numEmpty++;
	 }
	 else 
	 {
	     displayTeam(i, position, out);
	     
	 }

    }
    
    if (numEmpty == NUMTEAMS)
    {
	out << endl;
	out << "Empty list. There's nothing to display"<<endl;
	out << endl;
	
    }
 
    //   cout << "--------------------------------------------"
//	 << "-----------------------------------"<<endl;
// stub
}

bool HockeyList:: move(int position)
{
    bool found = false;
    bool success = false;
    int team =0 ;
    ListPtr item;
 

    success =search(position,item,team);
    
    if (success && INJURYLISTPOSITION != team)
    {
	found = true;
	unlink(item);
	link(item ,INJURYLISTPOSITION);
    }
       
    
  // stub
    return found;
}

bool HockeyList::activate(int position, char team)
{
    bool found = false;
    bool success;
    int teamNumber =0;
    int teamTemp;
    ListPtr item;
 
    teamTemp = findTeamNumber(team);
 
    success =search(position,item,teamNumber);
    
    
    if (success && teamNumber == INJURYLISTPOSITION )
    {

	found = true;
	unlink(item);
	link(item ,teamTemp);
    }
        
    

  // stub
    return found;
}

bool HockeyList::update(int position, int goals, int assists, int goalsAgainst)
{
    bool found;
    bool success = false;
    ListPtr item;
    int team;
    found = search(position,item,team);
    
    if (found && team != INJURYLISTPOSITION )
    {
	
	success = true;
	unlink(item);
	item -> thePlayer -> goals += goals;
	item -> thePlayer -> assists += assists;
	
	if (item -> thePlayer -> position == GOAL)
	    item -> thePlayer -> goalsAgainst += goalsAgainst;
	
	link(item, team);
    }
    
  // stub
    return success;
}

void HockeyList::lookup(int position, PlayerNode &player, bool &found) const
{
    ListPtr item;
    int team = 0;

    found = search(position,item,team);
    if (found)
    {
	strncpy(player.name,item -> thePlayer -> name,MAXNAMELEN+1);
	player.assists = item -> thePlayer -> assists;
	player.goals = item -> thePlayer -> goals;
	player.goalsAgainst = item -> thePlayer -> goalsAgainst;
	player.position = item -> thePlayer -> position;
    }
  // stub
}

char HockeyList::getTeam(int position) const
{
    bool found;
    int teamNum =0;
    char team;
    ListPtr item;
    found =search(position,item,teamNum);
    if (found)
    {
	team = TEAMCHARS[teamNum];
    }
    return team;
}


//==============================Private===============================================

int HockeyList::findTeamNumber(char teamLetter)
{
    bool match= false;
    int teamNum=0;

    for (int i = 0; i < NUMTEAMS && !match ; i++)
    {
	if (teamLetter == TEAMCHARS[i])
	{
	    teamNum = i;
	    match=true;
	}	  
	
	else 
	    teamNum++;
    }
    
  // stub
    return teamNum;
}

bool HockeyList::search(int pos, ListPtr &item, int &team) const
{
    team = 0; 
    bool found = false;

    item = head[team].next;
    int number =0;
    while (!found && team < NUMTEAMS)
    {
	while(!found && item != &tail[team])
	{
	    number++;
	    if (number == pos)
	    {
		found = true;
	    }
	    else 
	    {

		item = item -> next;
	    }
			
	
	}
	if(!found)
	{
	    team++;
	    item = head[team].next;
	}
    }
    return found;
}
#if 1

HockeyList::ListPtr HockeyList::createPlayer(const char name[], char position, 
			  int goals, int assists,
			  int goalsAgainst) const
{
    ListPtr list = new ListNode;
    PlayerPtr player = new PlayerNode;
    strncpy(player->name,name,MAXNAMELEN+1);
    player->position = position;
    player->goals = goals;
    player->assists = assists;
    player->goalsAgainst = goalsAgainst;
    list->thePlayer = player;
  // stub
    return  list;
}
#endif
void HockeyList::link(ListPtr item, int team)
{
    item->prev = tail[team].prev;
    item->next = &tail[team];
    tail[team].prev -> next = item;
    tail[team].prev = item;
 // stub
  
}

void HockeyList::unlink(ListPtr item)
{
    item -> next-> prev = item -> prev;
    item -> prev -> next = item -> next;
    //item  = NULL;
  // stub
  
}

void HockeyList::displayTeam(int team, int &position, ostream &out)const
{
    ListPtr current;
    current = head[team].next;


	
	out << TEAMS[team]<<endl;
	
	while (current != &tail[team])
	{
	    
	    out <<left << position  << ":\t "<<left << setw(24) <<current ->thePlayer -> name 
		 <<  setw(4) <<current -> thePlayer -> goals << setw(4)  << "goals   " << setw(4) 
		 <<  setw(4)<< current -> thePlayer ->assists << setw(4)<<  "assists   " ;
	    
	    if (current -> thePlayer -> position == GOAL)
	    {
		out << setw(4)<<current ->thePlayer -> goalsAgainst<<setw(4) << "goals against";
	    }//end if
	    out << endl;
	    position++;
	    current = current ->next;
	}//end while
	out <<endl;
	

}	
    
 

