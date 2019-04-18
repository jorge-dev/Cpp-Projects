/*
  Name:        Jorge Avila
  Email:       javil686@mtroyal.ca
  Course:      COMP 1631-001
  Assignment:  #5 part 1
  Due Date:    November 27, 2017
  Instructor:  Paul Pospisil

  Source File: a5p1.cpp


*/
//=======================================================================
#include <iostream>
#include<cmath>
using namespace std;

void format_print(char text_array[], 
		  int array_length, 
		  int line_length );

void get_next_word(char text_array[], 
		   int array_length, 
		   char next_word[],
		   int& next_word_length,
		   int& word_arr_position, 
		   bool& end_array);

int numeric_word(char word_array[], 
		 int word_array_len);

bool is_delimeter(char delimeter);

const int MAX_ARR_BUFFER = 500;
const int MAX_WORD_LENGTH = 20;

int main()
{
    int array_length = 140, 
	next_word_length = 0, 
	word_arr_position = 0;
	

    double numeric_value= 0,
	   total_sum=0; 
 
    char text_array[MAX_ARR_BUFFER] = "    string 3 this, is an extremely long text that  includes 87.54, a series of delimiters :,.!????,and  just some   more regular   text!    ",

        next_word[MAX_WORD_LENGTH] = {};
    

    bool end_array = false;


    format_print(text_array ,array_length ,35);
    cout << endl;
    while (!end_array)
    {

	get_next_word(text_array, array_length, next_word,
		      next_word_length, word_arr_position, end_array);
 
	
	format_print(next_word ,next_word_length ,next_word_length);
	

	if (!end_array)
	{
	    numeric_value = numeric_word (next_word, next_word_length);
	}

	if (numeric_value != -1)
	{
	    total_sum += numeric_value;
	    } 


    }
    cout << "The total sum is: " << total_sum << endl;
    
    

    return 0;
}
//=======================================================================
/*
Name:        format_print

Purpose:     Takes an array of words and prints a formated line of text  
             according to a custom line length.

Details:     It formats the text inside the array to display a custom 
             line of characters per line until no more words are found.

Input:       A char array - text array which contains the sentence(s) 
             induvidual characters.
	     
	     2 integers - array length: contains the size of the 
	                  text array
                        - line lengh: contains the custom number of chars
                                      to print per line.
*/

void format_print(char text_array[], 
		  int array_length, 
		  int line_length )
{

    int i,
	count = 1;

    for(i = 0; i < array_length; i++)
    {
	
	cout << text_array[i];

	if ( count == line_length  ) 
	{
	    cout << endl;
	    count = 0;
	}
	count++;
    }
   
}

//=======================================================================
/*
Name:        get_next_word

Purpose:     Extracts individual words from text array and stores them in
             a separatearray

Details:     It itarates thrugh the text array and copies the 
             corresponding chars into an array until a delimeter 
	     is found.
	     it also updtaes the array position and word length, 
	     and returns a boolean value indicating the end of the array.

Input:      2 char array - text array: stores the 
                           initial sentence(s).
			 - next word: stores the individual words.
            
	    3 integers - array length: contains the text array length.
	               - next word length: contains the idividual word
		                           array len.
		       - word array position: stores the word array 
		                              last updated position.

	    A bool- end array: marks the end of the array.
            
*/

void get_next_word(char text_array[], // in
		   int array_length,  // in
		   char next_word[],  // in
		   int& next_word_length, // in/out
		   int& word_arr_position,// in/out
		   bool& end_array) // out
{
   
    int i=0;
    bool stop = is_delimeter(text_array[word_arr_position]);
    next_word_length = 0; 
  
  
    while (stop && !end_array) // check for delimeters 
    {
	word_arr_position++;
	stop = is_delimeter(text_array[word_arr_position]);
	
	if (word_arr_position == array_length)
	    {
		end_array = true;
	    }
	    
    }

    while (!stop && !end_array)
    {
	    next_word[i] = text_array[word_arr_position];
	
	
	    if (word_arr_position == array_length)
	    {
		end_array = true;

	    }
	    i++;
	    next_word_length++;
	    word_arr_position++;

	    stop = is_delimeter(text_array[word_arr_position]);

    }
}


//=======================================================================
/*
Name:      numeric_word

Purpose:   Checks and returns the integers,if any,found in word array.

Details:   If a number is found inside the word array, it returns 
           the integer value and addsit to a running total. 
	   if no number is found it returns a -1 value and doesnt add
	   add it to the running total.

	   Equations used:
	   char --> int =static_cast<int>(digit) - static_cast<int>('0')
           complete num = static_cast<int>(pow(10,word length - count))

Input:     a char array - next word: array soring the extracted word 
                          from text array.

	   an integer - next word length: size of next word array.
           
           
*/

int numeric_word(char next_word[], 
		 int next_word_length)
{
    int individual_num = 0,
	complete_num = 0,
	count = 1,
	number= 0,
	i;

    if (next_word[0] < '0' || next_word[0] > '9') // not an integer
    {
	number = -1;
	cout << "This is a word " << endl;
	cout <<"----------------"<< endl<<endl;
    }
    else
    {
	for (i = 0; i < next_word_length; i++)
	{
	    individual_num = static_cast<int>(next_word[i]) 
		- static_cast<int>('0');
	    
	    complete_num = individual_num 
		* static_cast<int>(pow(10,next_word_length - count));
	        
	    number += complete_num ;
	    count++;
	 
	}
	cout << "This is a number "<<endl;
	cout <<"----------------"<< endl<<endl;	
  }

    
    return number;


}

//=======================================================================
/*
Name:        is_delimeter

Purpose:     Checks for delimeter characters 

Details:     If a delimeter is found, a boolean value is returned 
             to mark the end of a word.

Input:       a char - delimeter: contains the character to be checked.
             
             
*/

bool is_delimeter(char delimeter)
{
    char space = ' ',
	point = '.',
	comma = ',',
	colon = ':',
	semicolon = ';',
	exclamation = '!',
	question = '?';

    bool stop = false;
    
    if (delimeter == space || delimeter == point || 
	delimeter == comma || delimeter == colon ||
	delimeter == semicolon || delimeter == exclamation ||
	delimeter == question )
    {
	stop = true;
	
    }

   
    return stop;
}
