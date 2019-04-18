//=======================================================================
// Source File: a5p2.cpp
//
// Name:        Jorge Avila
// E-mail:      javil686@mtroyal.ca
// Course:      Comp 1631-001
// Assignment:  5, part 2
// Due Date:    Monday, December 04 at 11:59 p.m.
// Instructor:  Paul Pospisil
//
//=======================================================================
//Purpose:     Loads text from a file and prints a formatted 
//             version of a text with elligible 4 letter words being
//             reversed.
//             
//Details:     In order to read a file, the file has to exist in the
//             current directory.
//
//Input:       -Name of text file to read from.
//             -Desired lenght of charactes to be printed out.
//              Greater than 20 less than 80.
//
//Output:      - Formated lines of text depending on the line length 
//               specified by user.
//             - Second formated text output with same line lenght, but  
//               with possibly reversed some of it 4 letter words
//             - Number of words in the text
//             - Sum of all numeric words in text
//
//Assumption & limitions:
//            It can only process arrays with a size of 500.
//            the number of characters allowed for the file input must be
//            below 20.
//
//Known bugs:
// No no bugs 
//  
//
#include <iostream>
#include<fstream>
using namespace std;

const int BUFFER_SIZE = 500;
const int WORD_SIZE = 20;


void load_text(char array[],int arr_max_size,int& num_char_read,
	       bool& success);

void modify_text(char word_arr[], int word_arr_len, char text_arr[],
		 int text_arr_len, int start_pos_txt_arr);

void swap(char& a, char& b);

bool string_compare(char first_arr[], char second_arr[],int arr_len);


void format_print (const char text [], int text_len, int line_len);
void get_next_word(const char text[], int text_len, int &current, 
                   char word[], int &word_len, bool &eot);
int  numeric_word (const char word[], int word_len);
bool is_delimiter(char ch);


int main()
{
    char text[BUFFER_SIZE];
    char a_word[WORD_SIZE];        // array for current word being processed
  int position;                    // current position in text
  int result;                      // numeric value of a numeric word
  // int text_length = 140;            // amount of text in text array
  int word_length;                 // length of current word
  int print_length = 35;           // length of output line
  bool end_of_text =false;         // used to indicate end of text encountered
  int sum = 0;                     // sum of all numeric words in the text
  int num_char_read = 0;           // Number of characters read in file
  bool success = false;            // used to indicate if load file works
  int num_words = 0;               // number of words in text array
  position = 0;

  load_text(text, BUFFER_SIZE, num_char_read,success);
  
  
  if (success)
  {
      cout << "Enter a line length value (between 20 and 80): ";
      cin >> print_length;
      
      while ( print_length < 20 || print_length > 80)
      {
	  cout << "Wrong line length value." << endl;
	  cout << "Please enter value between 20 and 80;"<< endl;
	  cout << "Enter a line length value (between 20 and 80): ";
	  cin >> print_length;
      }// end while
      cout << endl;
      cout << "------------File before modification------------"<< endl;
      format_print (text, num_char_read, print_length);
      cout << endl;

      get_next_word (text, num_char_read, position, a_word, 
		     word_length, end_of_text);
      
      while (!end_of_text && num_char_read > 0 )
      {
	  num_words++;
	  result = numeric_word(a_word, word_length);
	  if (result != -1)
	  {
	      sum = sum + result;
	  } // end if      
	  if( word_length == 4)
	  {
	      modify_text (a_word, word_length, text, num_char_read, position - 4);
	  
	  } // end if 
	  get_next_word (text, num_char_read, position, a_word, 
		 word_length, end_of_text);
	 
      
      } // end while 
      
  
      cout << "------------File after modification------------"<< endl;
      format_print (text, num_char_read, print_length);
      cout << endl;
      cout << "Number of words " << num_words <<endl;
      cout << "Numeric word sum is: " << sum << endl;
  }//end if

  else
  {
     cout << "Sorry the file can't be open."
	     << endl;
  }

  return 0;
}


//=======================================================================
// Name:        load_text
//
// Purpose:     checks for valid text file to be loaded and if file is 
//              not found it returns an error message.
//
// Details:     the file wanted to be loaded, needs to be a a file 
//              located      
//              in current directory.
//
// Input:       a char array -  text array: the text in the file will be 
//                              loaded to this array.
//              2 integers  -  array max size:  holds the max size of 
//                             array
//                          -  number of characters read.
//              a bool - success: indicates whether the file was opened 
//                       or not
//

void load_text(char text[], //in/out
	       int arr_max_size, //in
	       int& num_char_read, // in/out
	       bool& success) //in/out
{
    const int MAXLEN = 50;
    int i;
    char file_name[MAXLEN+1]= "";
    char ch;
    ifstream input;

    cout << "Please enter the file name(less than 50 char) ";
    cin >> file_name;

    input.open(file_name);

    if (input.fail())
    {
	success = false;
    }//end if

    else 
    {
	success = true;
	input.get(ch);
	for (i = 0; i < arr_max_size && !input.eof(); i++)
	{
	    
	    text[i] = ch;
	    num_char_read++;
	    input.get(ch);
	}//end for 
	//cout << " Success\n";
	input.close();
    }//end else
}



//=======================================================================
// Name:        modify_text
//
// Purpose:    Checks and compares text array word with words inside 
//             a file and if they match, the word is reversed 
//
// Details:    the file read to comapare the text words is exclude.txt.
//             the words iniside this file ara:
//             2200, hope, this, only, okay, Fair, That, oops, When, idea
//
// Input:     2 char arrays - word array: holds individual words from 
//                          -  text array      
//                          - text array: holds text to be used          
//            3 integers - word array length
//                       - text array length  
//                       - starting position in text array
//
void modify_text(char word_arr[], int word_arr_len,char text_arr[],
		 int text_arr_len, int start_pos_txt_arr)

{
   
    const int EXCLUDE_LEN = 4;
    ifstream input;
    char exclude_word[EXCLUDE_LEN];
    input.open("exclude.txt");

    if (input.fail())
    {
	cout << "input fail"<<endl;
    }

    else{
	input >> exclude_word;
	while(!input.eof())
	{
	
	    if (string_compare(word_arr,exclude_word, word_arr_len))
	    {
		swap (text_arr [start_pos_txt_arr], 
		      text_arr[start_pos_txt_arr + 3]);
		swap (text_arr [start_pos_txt_arr + 1], 
		      text_arr[start_pos_txt_arr + 2]);
	    }
	    input >> exclude_word;
	}
    }
    input.close();
    
}

//=======================================================================
// Name:        swap
//
// Purpose:     reverses the order od two given characters
//
// Input:      2 characters - a: first character
//                          - b: second character
//             
//
void swap(char& a, char& b)
{
    char temp ;
    
    temp = a;
    a = b;
    b = temp; 
       
    

}

//=======================================================================
// Name:        string_compare
//
// Purpose:     compares two arraya character by character to determine
//              if they have equal values.
//
// Details:     for two arrays to be equal all  their corresponding 
//              indices must be the same
//
// Input:       2 char arrays - first array: holds the parameter word to 
//                              be checked
//                            - second array: holds the word the 
//                              parameter word needs                
//                              be compared to.
//              an integer    - array length: indicated the length of the
//                              arrays
//                              which must be the same for both.
//
bool string_compare(char first_arr[], char second_arr[],
    int arr_len)

{
    bool are_identical = true;
    bool match = true;
    int i;
    

	for (i =0; i < arr_len && match; i++)
	{

	    if (first_arr[i]== second_arr[i])
	    {
		match = true;
	    }//end if 
	    else
	    {
		match = false;
	    }//end else
	    
	}//end for 
	
	if (!match)
	{
	    are_identical = false;
	}
	    

    




    
    return are_identical;
}

//=======================================================================
/*
Name:        format_print

Purpose:     Takes an array of words and prints a formated line of text  
             according to a user defined line length.

Details:     It formats the text inside the array to display a custom 
             line of characters per line until no more words are found 
	     and checks for words on the end og =f each line and if a
	     word exceeds the line lenght, it prints the whole word to 
	     the next line.

Input:       A char array - text array which contains the sentence(s) 
             induvidual characters.
	     
	     2 integers - array length: contains the size of the 
	                  text array
                        - line lengh: contains the custom number of chars
                                      to print per line.
*/

void format_print (const char text [], int text_len, int line_len)
{
     bool eot;                      
        
   int index,                     
        char_count,                
        current, 
       word_len = 0,              
        remaining_len;             
   
 
    char word[WORD_SIZE];          

    char_count = 0;
    for (index = 0; index < text_len; index++)
    {
	current = index;
	word_len = 0;

	if (is_delimiter(text[index]) == false){
	    get_next_word(text, text_len, current, word, word_len, eot);
	    remaining_len = line_len - char_count;
	}

	if ((index != 0 && char_count == line_len) ||
	    word_len > remaining_len){
	    cout << endl;
	    char_count = 0;
	}

	else {
	    char_count++;
	}

	cout << text[index];
    }
    cout << endl;
    return;
}



//=======================================================================

// Name:     get_next_word
//
// Purpose:  this function copies the next word, if it exists, from a 
//           text array to a word array.
//
// Details:  The text array is processed character by character.
//           Starting from the current position all leading delimiters 
//           are ignored by updating the current positon.
//           If the text length has been reached the boolean flag is set 
//           to true, the word length is set to zero and the word array
//           is unchanged.
//           Otherwise there is a next word so the boolean flag is set
//           to false, the word is copied to the word array until 
//           either a delimiter is encountered or the text length 
//           reached. The word
//           length is set to the number of word characters copied.
//           Regardless of whether or not a next word is found the 
//           current position index into the text array will be updated 
//           to the last
//           character processed. This is either the first character 
//           after this word or the text length.
//
// Input:    an array of character - the text array
//           an integer - the actual length of characters in the text 
//           array
//           an integer - the current position in the text array from 
//           which to start processing
//
// Output:   an integer - the current position in the text array after
//                        processing
//           an array of characters - the word array in which to store 
//                                    the next word
//           an integer - the number of characters in the next word
//           a boolean - a flag indicating whether or not the end of the
//                       text has been encountered

void get_next_word(const char text[], int text_len, int &current, 
                   char word[], int &word_len, bool &eot)
{
    word_len = 0;
    eot = false;

    while (current < text_len && is_delimiter(text[current]))
        current++;

    if (current < text_len)
    {
        while (current < text_len && !(is_delimiter(text[current])))
        {
            word[word_len] = text[current];
            word_len++;
            current++;
        }
    }
    else
    {
        eot = true;
    }
    return;
}

//=======================================================================
// Name:     numeric_word
//
// Purpose:  this function converts a word consisting of digit characters
//           into the corresponding numeric value
//           
// Details:  The first character of the word is checked, since words are
//           either exclusively composed of alphabetic characters or 
//           numeric characters. Thus, the first character of the 
//           word determines whether or not the word is a numeric word
//
//           If the first character is a digit the word is converted to a
//           numeric value. 

//           Since the length of the word is known the word is processed 
//           least to most significant digits, which is from largest to 
//           smallest indices. Each digit character is converted to
//           a numeric digit by subtracting the character '0' from it. 
//           This works because in the ASCII encoding scheme digits are 
//           assigned
//           consecutive numeric values.
//
//           Each digit is multiplied by the appropriate power of 10 and
//           added to a running sum. The appropriate power of 10 starts 
//           at 1 for the least significant digit and is then multiplied 
//           by 10 for each successive digit.
//
// Input:    an array of character - the word array
//           an integer - the number of characters in the word array
//
// Returns:  an integer - the corresponding numeric value for a digit
//                        character word or -1 for an alphabetic word

int  numeric_word (const char word[], int word_len)
{
    int i,                // loop counter variable
        value,            // corresponding numeric value of word
        power_of_ten;     // digit multiplier

    value = -1;
    if (word[0] >= '0' && word[0] <= '9')
    {
        value = 0;
        power_of_ten = 1;
        for (i = word_len - 1; i >= 0; i--)
        {
            value = value + (word[i] - '0') * power_of_ten;
            power_of_ten = power_of_ten * 10;
        }
    }
    return value;
}


//=======================================================================
// Name:     is_delimiter
//
// Purpose:  this function determines whether or not a character is a 
//           delimiter
//
//           A delimiter is one of the following possible characters:
//               ' ','.', ',', ':', ';', '!', '?'
//           If the character matches any of these the function returns 
//           true;
//           otherwise it returns false.
//
// Input:    a character - the character to be checked
//
// Returns:  a boolean - true if the character is a delimiter; false 
//           otherwise

bool is_delimiter(char ch)
{
  bool a_delimiter;
  const int NUM_OF_DELIMITERS = 7;
  const char delimiters[NUM_OF_DELIMITERS] = { ' ', '.', ',', ':', ';', 
					       '!', '?'};
  int index;

  a_delimiter = false;
  for (index = 0; index < NUM_OF_DELIMITERS && !a_delimiter; index++)
  {
    if (ch == delimiters[index])
      a_delimiter = true;
  }

  return a_delimiter;
}
 
