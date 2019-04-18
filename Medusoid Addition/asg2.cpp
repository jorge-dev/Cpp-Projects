// Name:        Jorge Avila
// Email:       javil686@mtroyal.ca
// Course:      COMP 1631-001
// Assignment:  #2
// Due Date:    October 12, 2017
// Instructor:  Paul Pospisil
//
// Source File: asg2.cpp
//
// Purpose: This program adds two 6 digit numbers using the medusoid number 
//          system (which changes its base number according to their age and
//          tentacle number) that will produce a 6 digit sum.    
//     
//
// Details: Formulas used in the program:
//          base = (age*2) + 1
//          carry = realReuslt + prevoiousCarry / (age +1) 
//          medusoidResult = realResult - ( carry * base ) + preiviousCarry
//          
//          Input: all input is provided by the user and must be integers
//                 a number from 1-12 and 
//                 two 6-digit numbers separated by blanks/spaces   
//                 
//          Output: first and second set of numbers arranged in 2 rows and
//                  separated by spaces, a plus sign to the left of the second 
//                  row, a line to separate the addition from the result, 
//                  a medusoid result below the separating line with the same 
//                  spacing and format as the first and second row, 
//                  the addition of the first and second row in decimal form 
//                  and its result and the the medusoid result expressed in 
//                  decimal form.
//
// Assumptions, Limitations or Known Bugs:
//
//          Program input must be all integers 
//          The 6-digit values must be separated by blanks and not contain 
//          more than 6 digits
//          The 6-digit values must not exceed the allowed range of digits 
//          determined by its base.



#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int first1,first2,first3,first4,first5,first6; // First set of digits
    int second1,second2,second3,second4,second5,second6; //Second set of digits
    int carry1,carry2,carry3,carry4,carry5,carry6;
    int realRes1,realRes2,realRes3,realRes4,realRes5,realRes6; //Result base 10
    int medusRes1,medusRes2,medusRes3,medusRes4,medusRes5,medusRes6;//Result
//      in medusoid base
    int base,age;
    int firstToDecimal,secondToDecimal,medusToDecimal,decimalRes;
    int power0,power1,power2,power3,power4,power5;

//-----------------------------------------------------------------------------
//                           Take user input 
    cout <<endl<< "Welcome to Planet RLLGRLYH(5). Ready to calculate..." 
	 << endl << endl;
    
    cout << "Enter age(1-12): ";
    cin >> age;
    
    cout <<"Enter six digits of first number(each separated by blank): ";
    
    cin >> first1 >> first2 >> first3 >> first4 >> first5 >> first6;
    
    cout << "Enter six digits of second number(each separated by blank): ";
    
    cin >> second1 >> second2 >> second3 >> second4 >> second5 >> second6;

//-----------------------------------------------------------------------------
//                              CALCULATIONS
    
    base = (2 * age) + 1;
    power0 = static_cast<int>(pow(base,0));
    power1 = static_cast<int>(pow(base,1)); 
    power2 = static_cast<int>(pow(base,2)); 
    power3 = static_cast<int>(pow(base,3)); 
    power4 = static_cast<int>(pow(base,4)); 
    power5 = static_cast<int>(pow(base,5));

    
    realRes1 = first1 + second1;
    realRes2 = first2 + second2;
    realRes3 = first3 + second3;
    realRes4 = first4 + second4;
    realRes5 = first5 + second5;
    realRes6 = first6 + second6;

    
    carry6 = realRes6 / (age + 1);
    carry5 = (realRes5 + carry6) / (age + 1);
    carry4 = (realRes4 + carry5) / (age + 1);
    carry3 = (realRes3 + carry4) / (age + 1);
    carry2 = (realRes2 + carry3) / (age + 1);
    carry1 = (realRes1 + carry2) / (age + 1);
    

    medusRes6 = realRes6 - (base * carry6);
    medusRes5 = realRes5 - (base * carry5) + carry6;
    medusRes4 = realRes4 - (base * carry4) + carry5;
    medusRes3 = realRes3 - (base * carry3) + carry4;
    medusRes2 = realRes2 - (base * carry2) + carry3;
    medusRes1 = realRes1 - (base * carry1) + carry2;
    
//----------------------------------------------------------------------------
//  Conversion from medusoid to decimal form and the result from that 
//  conversion

    firstToDecimal =(first1 * power5) + (first2 * power4) + (first3 * power3)+
	(first4 * power2) + (first5 * power1) + (first6 * power0);

    secondToDecimal =(second1 * power5)+ (second2 * power4)+ (second3 * power3)
	+ (second4 * power2) + (second5 * power1) + (second6 * power0);
    
    medusToDecimal =(medusRes1 * power5) + (medusRes2 * power4) + 
	(medusRes3 * power3) + (medusRes4 * power2) + (medusRes5 * power1)
	+ (medusRes6 * power0);

    decimalRes = firstToDecimal + secondToDecimal;

//-----------------------------------------------------------------------------
//                           Output Formatting

    cout <<"\n\nFor a " << age << " year old, "
	 << first1 << "\t" << first2 << "\t" << first3 << "\t" << first4
	 <<"\t"<< first5 <<"\t" << first6 << endl;
    
    cout <<"                + " << second1 << "\t" << second2 <<"\t" 
	 << second3 << "\t" << second4 << "\t" << second5 << "\t" << second6
	 << endl;

    cout <<"                 =============================================" 
	 << endl;
    
    cout <<"                 " << medusRes1 << "\t" << medusRes2 <<"\t" 
	 << medusRes3  << "\t" << medusRes4 << "\t" << medusRes5 << "\t"
	 << medusRes6 << endl;

    cout << "\n\nIn the decimal system this equation is " << firstToDecimal 
	 << " + " << secondToDecimal << " = " << medusToDecimal << endl;

    cout << "The addition result in decimal is " << decimalRes <<endl<<endl;
    

  return 0;
}
