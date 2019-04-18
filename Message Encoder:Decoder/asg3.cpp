// Name:        Jorge Avila 
// Email:       javil686@mtroyal.ca
// Course:      COMP 1631-001
// Assignment:  #3
// Due Date:    October 31, 2017
// Instructor:  Paul Pospisil
//
// Source File: asg3.cpp
//
// Purpose: This program decodes coded messages composed of 2 words and 
//          displays the decoded result. 
//
// Details: The program takes 2 coded words which each is encoded using 
//          a combination of 7 characters.
//          The seven characters must be separated by a blank space in
//          order to be stored individually.
//          The 1st,3rd,5th, and 7th entrie in each word are coded 
//          characters of the message represented by any displayable 
//          character. The 2nd,4th, and 6th entrie in each word are 
//          integers ranging from 0 to 9. 
//             
//          Input: Two coded words formatted as follows:
//             - each character in a word separated by a blank 
//             - the 1st,3rd,5th, and 7th entrie can be a char or int
//             - the 2nd,4th, and 6th entrie must be integers
//             - words must be composed of 7 entries
//
//          Output: First and second decoded word each in its own line  
//                 
//
// Assumptions, Limitations or Known Bugs:
//
//          If the following input is entered, the program will not 
//          produce any real or useful result:
//
//          - More or less than 7 entries              
//          - No integers in the 2nd,4th, and/or 6th entrie
//          - No input at all
//          - Entries not separated by blank spaces 
//
//-----------------------------------------------------------------------

#include <iostream>
#include<cmath>
using namespace std;

void display_decoded_word(char char1, char char3, char char5, char char7,
			  int digit2 ,int digit4, int digit6);
			   
int compute_key (int digit2, int digit4, int digit6);

char decode_letter (char a_char, int a_key);

int char_to_offset (char char_value);

char offset_to_char (int offset_val);

const char BASE_CHARACTER = ' '; // range's starting character

int main()
{
    char word1_first_char, word1_third_char, 
	word1_fifth_char, word1_seventh_char,
	word2_first_char, word2_third_char, 
	word2_fifth_char, word2_seventh_char ;

    int word1_second_digit, word1_fourth_digit, word1_sixth_digit,
	word2_second_digit, word2_fourth_digit, word2_sixth_digit;

//-----------------------------------------------------------------------
    cout << "Welcome to the Decoder. " << endl << endl;

    cout << "Enter the first word from coded message "
	   "(each char separated by blank): ";
    cin >> word1_first_char >> word1_second_digit >> word1_third_char
	>> word1_fourth_digit >> word1_fifth_char >> word1_sixth_digit
	>> word1_seventh_char;
    
     cout << "Enter the second word from coded message"
	  << " (each char separated by blank): ";
     cin >> word2_first_char >> word2_second_digit >> word2_third_char
	 >> word2_fourth_digit >> word2_fifth_char >> word2_sixth_digit
	 >> word2_seventh_char;
   

     cout << endl << "The first word is: ";
   
     // function call
     display_decoded_word(word1_first_char, word1_third_char, 
			  word1_fifth_char, word1_seventh_char, 
			  word1_second_digit, word1_fourth_digit, 
			  word1_sixth_digit);

     cout << endl << endl << "The second word is: ";

     //functoin call
     display_decoded_word(word2_first_char, word2_third_char, 
			  word2_fifth_char, word2_seventh_char, 
			  word2_second_digit, word2_fourth_digit, 
			  word2_sixth_digit);
     cout << endl << endl;
	
  return 0;
}

//----------------------------FUNCTIONS----------------------------------


//-----------------------------------------------------------------------
// Name: display_decoded_word
//
// Purpose: print the decoded word to the screen
//
// Details: Takes the 7 characters in a word and decodes the 4 coded 
//          characters by calling two other functions: compute_key -
//          to calculatea decoding key and decode_letter - to decode the
//          encoded chaacters. It then prints each decoded charater to 
//          the screen.
//      
//           
// Input: 4 characters - the 1st, 3rd, 5th, and 7th char of a word 
//                       (the coded characters)
//        3 integers - the 2nd, 4th, and 6th char of a word
//                     ( the integers used to calculate a decoding key)
//          
void display_decoded_word(char char1, char char3, char char5, char char7,
			   int digit2 ,int digit4, int digit6)
{
    char first_decoded_letter, second_decoded_letter, 
	third_decoded_letter, fourth_decoded_letter;
    int master_decoding_key;
    
    // function calls
    master_decoding_key = compute_key(digit2,digit4,digit6);
    
    first_decoded_letter = decode_letter(char1,master_decoding_key);
    second_decoded_letter = decode_letter(char3,master_decoding_key + 1);
    third_decoded_letter = decode_letter(char5,master_decoding_key + 2);
    fourth_decoded_letter = decode_letter(char7,master_decoding_key + 3);

    cout << first_decoded_letter << second_decoded_letter
	 << third_decoded_letter << fourth_decoded_letter << " ";  
    
    return;
}



//-----------------------------------------------------------------------
// Name: compute_key
//
// Purpose: generate a key value used to decode the message
//
// Details: Takes 3 digit integers and multiplies the digit by a hundred,
//          second by 10, the third by one and adds the three resulting 
//          numbers.It then cubes the resulting value and extracts the
//          4th and 5th digit to the right. 
//          The key value is obtained by reversing the two numbers 
//          previously extracted. For example, if the number extracted
//          was 57, the resulting key value would be 75.
//          
//          Formulas used:
//              -extract first digit from cube result: 
//                 (cube result / 100,000) % 10
//
//               -extract second digit from cube result: 
//                 (cube result / 10,000) % 10
//           
// Input: 3 integers  - the 2nd, 4th, and 6th char of a word (which have
//                      to be digit integers)
//                      
// Return : an integer - the key value       
//          
int compute_key (int digit2, int digit4, int digit6)
{
    int key_value, ones_digit, tens_digit, hundreds_digit, cube_result,
	three_digit_result, first_dig_extracted, second_dig_extracted;

    // joins three digits into single three-digit int
    hundreds_digit = digit2 * 100;
    tens_digit = digit4 *10;
    ones_digit = digit6;
    three_digit_result = hundreds_digit + tens_digit + ones_digit;
    
    cube_result = static_cast<int>(pow(three_digit_result,3));
    
    // digit extraction
    first_dig_extracted = (cube_result / 100000) % 10;
    second_dig_extracted = (cube_result / 10000) % 10;
    
    key_value = (second_dig_extracted *10) + first_dig_extracted;

    return key_value;
}



//-----------------------------------------------------------------------
// Name: decode_letter
//
// Purpose: decode a character and return its result  
//
// Details: To decode a given character, it uses two other functions: 
//          char_to_offset to converta character into its ASCII code
//          (which its an int) and offset_to_char to convert that code
//          into its corresponding character and a key value to decode .
//          the encoded character.
//      
//           
// Input: a character - the encoded character.
//        an integer  - the key value
//        
// Returns - a character - the decoded character       
//          
char decode_letter (char a_char , int decoding_key)
{
    int offset,remainder;
    char decoded_letter_to_display;
   
    offset = char_to_offset(a_char) + decoding_key;
    remainder = offset % 95;
    decoded_letter_to_display = offset_to_char(remainder);
    
    return decoded_letter_to_display;
}



//-----------------------------------------------------------------------
// Name: char_to_offset
//
// Purpose: converts a character into its offset value
//
// Details: takes a coded character and the starting character in a  
//          a range (in this case the character space " " represented as
//          a constant), converts this two characters into integers and 
//          subtracts its result to get the encoded character's offset
//          value.
//          
//      
//           
// Input: a character - the coded character
//        
// Returns: an integer - the offset value
//                    
//          
int char_to_offset (char coded_char)
{
    int offset_res;// converts the space char(BASE) and coded char to
    //                integers in order to get its offset value

    offset_res = static_cast<int>(coded_char) - 
	static_cast<int>(BASE_CHARACTER);
    
    return offset_res;
}



//-----------------------------------------------------------------------
// Name: offset_to_char
//
// Purpose: converts an offset value into its 
//          corresponding character.
//
// Details: The starting character in a range, being the space character
//          " " used as a constant for this function, is converted into 
//          its corresponding int value and added to a given offset 
//          to get an ASCII code value. The ASCII value is then converted
//          to its correspondig character.
//
//
// Input: an integer - the offset value
//
// Returns: a character - decoded character  
//          
char offset_to_char (int offset_value)
{
    char decoded_char_result;
    int offset_to_ascii;
    
    offset_to_ascii = offset_value + static_cast<int>(BASE_CHARACTER);
    decoded_char_result = static_cast<char>(offset_to_ascii);
    
    return decoded_char_result;
}


