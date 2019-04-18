/*
  Name:        Jorge Avila
  Email:       javil686@mtroyal.ca
  Course:      COMP 1631-001
  Assignment:  #6
  Due Date:    December 11, 2017
  Instructor:  Paul Pospisil

  Source File: a6.cpp


*/

//=======================================================================

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

const int MAX_SIZE = 100;
const int TITLE_LENGTH = 60;
const int YEAR_LENGTH = 4;
const int RATING_LENGTH = 5;
const int EQUAL = 0;
const char LIST_CHOICE = 'L';
const char SEARCH_CHOICE = 'S';
const char QUIT_CHOICE = 'Q';

typedef char TITLE_STRING[TITLE_LENGTH + 1];
typedef char YEAR_STRING[YEAR_LENGTH + 1];
typedef char RATING_STRING[RATING_LENGTH + 1];

struct Movie
{
  TITLE_STRING  title;
  YEAR_STRING   year;
  int           duration;
  RATING_STRING rating;
};

void readDatabase (Movie movieDB[], int &fillLevel, bool &success);
void showMenuAndPrompt ();
void listAllMovies (const Movie movieDB[], int fillLevel);
void printMovie (Movie);
Movie getSearchData ();
void searchForMovie (const Movie movieDB[], int fillLevel, 
		     Movie searchData);
bool doYearsMatch (const YEAR_STRING year1, const YEAR_STRING year2);

int main ()
{
  Movie movieDB[MAX_SIZE];
  int fillLevel = 0;
  char choice;
  Movie searchData;
  bool readSuccess;
  
  readDatabase (movieDB, fillLevel, readSuccess);
  
  if (readSuccess)
  {
    do {
      showMenuAndPrompt ();
      cin >> choice;
      cout << endl;
      choice = static_cast<char> (toupper(choice));
			
      switch (choice)
      {
      case LIST_CHOICE:
        listAllMovies (movieDB, fillLevel);
        break;
      case SEARCH_CHOICE:
        searchData = getSearchData();
        searchForMovie (movieDB, fillLevel, searchData);
        break;
      case QUIT_CHOICE:
        // avoid erroring on quit choice
        break;
      default:
        cout << "Invalid choice, try again." << endl << endl;
      }
    } while (choice != QUIT_CHOICE);
    
    cout << "Have a nice day!" << endl << endl;
  }
  else
  {
    cout << "Unable to read database file; quitting." << endl << endl;
  }
  
  return 0;
}

//=======================================================================

void readDatabase (Movie movieDB[], int &fillLevel, bool &success)
{
  ifstream     fileIn;
  const char   filename[] = "movieDB.txt";
  TITLE_STRING aTitle; 
  int          length;
  char         newline;
 
  // assume success until a problem occurs
  success = true;
  fileIn.open(filename);
  
  if (fileIn.fail())
  {
    success = false;
  }
  else
  {
    fileIn.getline(aTitle, TITLE_LENGTH);
    while (!fileIn.eof() && fillLevel < MAX_SIZE)
    {
      length = static_cast<int>(strnlen(aTitle, TITLE_LENGTH));
      strncpy (movieDB[fillLevel].title, aTitle, length);
      movieDB[fillLevel].title[length] = '\0';
      fileIn >> movieDB[fillLevel].year;
      fileIn >> movieDB[fillLevel].duration;
      fileIn >> movieDB[fillLevel].rating;
      fillLevel++;
      fileIn.get(newline);
      fileIn.getline(aTitle, TITLE_LENGTH);
    }
    fileIn.close();
  }

  return;
}

//=======================================================================
void showMenuAndPrompt ()
{
  cout << "Welcome to the movie search system." << endl;
  cout << "Your options are:" << endl;
  cout << "    (L)ist all movies." << endl;
  cout << "    (S)earch for a movie." << endl;
  cout << "    (Q)uit" << endl;
  cout << endl;
  cout << "Please enter your selection: ";
}

//=======================================================================
/*
 Name:        listAllMovies

 Purpose:     Prints all movies and their informations from the movie 
              database.

 Details:     Prints movie's title, year, duration and rating
              

 Input:       a constant movie database with type Movie 
                         - stores idividual movie's information 
              an integer - fill level: stores the total number of movies
	                   in the database
 
Output:       all movie's information in the database. 
*/

void listAllMovies (const Movie movieDB[], int fillLevel)
{
    
    for (int i = 0 ; i < fillLevel; i++)
    {
	printMovie(movieDB[i]);
	
    }
}

//======================================================================
/*
 Name:        printMovie

 Purpose:     Prints a single movie's individual information

 Details:     Movie's information: title, year, duration and rating.
             

 Input:       a movie - stores the title, year, duration and rating of 
                        a movie.

 Output:      the movie's informations with a prompt and title each in 
              its own line.
*/

void printMovie (Movie movie)
{
    cout << "Title: " << movie.title << endl;
    cout << "Year: " << movie.year << endl;
    cout << "Duration: " << movie.duration << endl;
    cout << "Rating: " << movie.rating << endl << endl;
    
}

//=======================================================================
Movie getSearchData ()
{
  char yesNo;
  Movie searchData = { "omit", "????", 0, "omit" };
  
  cout << "Do you want to search for a portion of the title? (y/n): ";
  cin >> yesNo;
  if (yesNo == 'y' || yesNo == 'Y')
  {
    cout << "Enter the portion of the title: ";
    cin >> searchData.title;
  }
  
  cout << "Did you want to search by year? (y/n): ";
  cin >> yesNo;
  if (yesNo == 'y' || yesNo == 'Y')
  {
    cout << "Enter the year (you can use ?s for wildcards): ";
    cin >> searchData.year;
  }
  
  cout << "Do you want to search by rating? (y/n): ";
  cin >> yesNo;
  if (yesNo == 'y' || yesNo == 'Y')
  {
    cout << "Enter the rating (case sensitive): ";
    cin >> searchData.rating;		
  }
  
  return searchData;
}

//=======================================================================
/*
 Name:        searchForMovie

 Purpose:     Search for movies that match user given parameters and
              prints all matches.

 Details:     In order for a movie to be printed the following criteria 
              has to be met:
	      
	      - the input title, year and rating parameter must match the
	        movie's database corresponding values in order for the 
		movieto be printed.
		
		the input title and rating values can be complete or 
		partial words, and the search will match them to th 
		movie's corresponding values as long as they start with 
		the exact samecharacters ( the search is case sensitive )

		the year value can be a complete 4 digit year or '?' 
		can be used as wildcards in case the full year is not 
		known.
		    - i.e  2017 and ?01? will be a match 
		           1998 and ??4? will not be a match.
			   
	        if any of the searching parameters(title,year, 
		and/or rating) is/are omited, their values will not be 
		considered as searching parameters and their default 
		values are:
		 - title: "omit".
		 - year: "????"
		 -rating: "omit"
		

 Input:       a constant Movie array - movie database: holds all movie's
                                       info.
              an integer - fill level: holds the current number of movies
	                               in movie database.
	      a Movie struct - search data: stores the input values for 
	      the searching parameters.
					    

Output:       The movie(s) information when  match is found.            
*/

void searchForMovie (const Movie movieDB[], int fillLevel, 
		     Movie searchData)
{
    bool title_match = true,
	 year_match = true,
	 rating_match = true;
    int matches = 0;
    char omit[]= "omit";

    for (int i = 0; i < fillLevel; i++ )
     {
	 // search for title
	 if (strncmp(searchData.title,movieDB[i].title,
		     strlen(searchData.title)) == 0  || 
	     strncmp(searchData.title,omit,strlen(omit)) == 0)
	 {
	     title_match = false;
	 }

	 //search for year
	 if ( doYearsMatch(movieDB[i].year,searchData.year) )
	 {
	     year_match = false;
	 }

	 //search for rating
	 if (strncmp(searchData.rating,movieDB[i].rating,
		     strlen(searchData.rating)) == 0  ||
	     strncmp(searchData.rating,omit,strlen(omit)) == 0)
	 {
	     rating_match = false;
	 }
  
	 if (!title_match && !year_match && !rating_match)
	 {
	     cout << "-------------------------------" << endl;
	     cout << "Movie number: " << i + 1 << endl;
	     printMovie(movieDB[i]);
	     matches++;
	 }
 
	 title_match = true;
	 year_match = true;
	 rating_match = true;
     }
    
    if (matches == 0 )
    {
	cout << endl;
	cout << "***";
	cout << "No Match was found with those parameters. "
	     << "Please try again."
	     << "***" << endl << endl;
    }
	
}

//=======================================================================
/*
 Name:        doYearsMatch

 Purpose:     compares 2 years to determine if they are equal or not

 Details:     checks for same individual characters in year values or for
              the '?' in place of a numer char to determine if years are 
	      equal or not. 
              
 Input:       2 constant YEAR_STRING C-strings 
                - year1 and year 2
 
 Returns:     a bool - match: true if equal, false if not;.
              
*/

bool doYearsMatch (const YEAR_STRING year1, const YEAR_STRING year2)
{
    bool match = true;
    for (int i = 0; i < YEAR_LENGTH && match; i++ )
    {
	if (year1[i] == year2[i] || year2[i] == '?' )
	{
	    match = true;
	}
	else
	{
	    match = false;
	}
    }
	
  return match;
}
