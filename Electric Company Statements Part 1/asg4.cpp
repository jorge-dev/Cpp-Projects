// Name:        Jorge Avila
// Email:       javil686@mtroyal.ca
// Course:      COMP 1631-001
// Assignment:  #4 Part1
// Due Date:    November 7, 2017
// Instructor:  Paul Pospisil
//
// Source File: asg4.cpp
//
//
//-----------------------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;


void read_and_process (int account_num, 
		       double& total_electric_use, 
		       double& total_electric_contribute, 
		       bool& transaction_no_error,
		       bool& account_is_valid);
		       
bool valid_account (int account_num);

void update_account (double starting_balance, 
		     double total_electric_use, 
		     double total_electric_contribute, 
		     bool& discount_is_elligible,
		     double& total_electric_cost,
		     double& total_contribute_credit,
		     double& discount,
		     double& total_gst,
		     double& new_balance);

void print_statement(int account_num, 
		     double total_electric_use,
		     double total_electric_contribute, 
		     double starting_balance, 
		     double total_electric_cost,
		     double total_contribute_credit, 
		     bool discount_is_elligible,
		     double discount,
		     double total_gst, 
		     double new_balance);

const double GST = 0.05;

int main()
{
    
//----Variable declaration 
    int account_num;

    double total_electric_use, 
	   total_electric_contribute, 
	   total_contribute_credit, 
	   total_electric_cost,
	   starting_balance, 
	   total_gst, 
	   discount, 
	   new_balance;
  
    char discount_eligibility;
    
    bool transaction_no_error, 
	 discount_is_elligible,
	 account_is_valid;

//------------------------Main Program-----------------------------------
    
    cout << "\nThis is your current monthly statement: " << endl << endl;
    
//-----Header record input
    cin >> account_num >> starting_balance >> discount_eligibility; 
    
//----discount eligibility  
    if (discount_eligibility == 'Y' || discount_eligibility == 'y')
    {
	discount_is_elligible = true;
    }

    else if (discount_eligibility == 'N' || discount_eligibility == 'n')
    {
	discount_is_elligible = false; 
    }

    else 
    {
	discount_is_elligible = false;
    }

//-----Function calling and output 
    read_and_process(account_num,                
		     total_electric_use,         
		     total_electric_contribute,                         
		     transaction_no_error,       
		     account_is_valid);      
    
    if (transaction_no_error && account_is_valid )
    {
	 update_account (starting_balance, 
			 total_electric_use, 
			 total_electric_contribute, 
			 discount_is_elligible,
			 total_electric_cost,
			 total_contribute_credit,
			 discount,
			 total_gst,
			 new_balance);

	 print_statement(account_num, 
			 total_electric_use,
			 total_electric_contribute, 
			 starting_balance, 
			 total_electric_cost,
			 total_contribute_credit, 
			 discount_is_elligible,
			 discount,
			 total_gst, 
			 new_balance);
    }

    else 
    {
	cout << "*** Account " << account_num 
	     << " not processed due to errors ***"<<endl<<endl; 
    }
   

  return 0;
}



//=======================================================================
// Name:        read_and_process
//
// Purpose:     Print any error message if any, read the monthly 
//              transaction record and determine if the account is valid 
//              and/or if there's any transaction errors.
//
// Details:     It reads and returns the 3 values in the monthly 
//              transaction record and calls the validate_account 
//              function,which takes the account number as argument, to 
//              validate the account. 
//              
//              If the accout number is invalid and/or if there is a 
//              transaction error, then it returns an appropiate error 
//              message and the corresponding boolean values.Otherwise, 
//              it returns two positive boolean values.
//              
//
// Input:       an integer - account number. 
//              2 doubles - total electric usage 
//                          & total electric contribution.
//              2 booleans - stores the transaction error and valid 
//                           account values:
//                           TRUE: no transaction error, accout is valid
//                           FALSE: transaction error, account is invalid
//          
void read_and_process (int account_num,                   //in 
		       double& total_electric_use,        //out 
		       double& total_electric_contribute, //out 
		       bool& transaction_no_error,        //out 
		       bool& account_is_valid)            //out
{
    int transaction_error ; // takes 1 or 0 integer
    
//----Monthly Transaction Record input
    cin >> total_electric_use >> total_electric_contribute 
	>> transaction_error;


//----Account validation & transaction error verification
    if (valid_account(account_num) == false && transaction_error == 0)
    {
	cout << "Invalid account number found" << endl;
	account_is_valid = false;
	transaction_no_error = true;    
    }
    
    else if (valid_account(account_num)== false && transaction_error== 1)
    {
	cout << "Invalid account number found" << endl;
	cout << "Bad monthly transaction record" << endl;
	account_is_valid = false;
	transaction_no_error = false;
    }

    else if (valid_account(account_num) && transaction_error == 1)
    { 
	cout << "Bad monthly transaction record" << endl;
	account_is_valid = true;
	transaction_no_error = false;
    }
    
    else
    {
	account_is_valid = true;
	transaction_no_error = true;
    }
}
		       


//=======================================================================
// Name:        valid_account
//
// Purpose:     Check whether the account number is valid or invalid.
//
// Details:     It takes an account number and determines if its valid 
//              or not by checking the if the following criteria is met:
//         
//              - A valid account mst be composed of 9 digits, not more
//                or less.
//
//              -Every valid account has a check digit which is located
//               in the number's ones position (position 0 from right to
//               left).For an account to be valid, the check digit must  
//               be the same as the comparison digit which is calculated
//               using the following steps:
//
//               - A: Add the account's odd position digits and multiply
//                    the resutl by 2.
//
//               - B: Add the account's even position digits but ignoring
//                    the 0th position (check number).
//
//               - C: Add the results of A and B.
//              
//               - D: Extract the units digits of the result in step C.
//                    If the extracted digit equals 0 then it is the 
//                    comparison digit. Otherwise, subtract 10 from the
//                    extracted digit to get the comparison digit.
//
// Input:        an integer - the account number.
//
//
// Return:       a bool -  stores the result of the account's validaton.
//                         - TRUE: account is valid.
//                         - FALSE: account invalid.
//
bool valid_account (int account_num) // in 
{
    bool accout_is_valid;

    int check_digit,
	digit_position_0,
	digit_position_1,
	digit_position_2,
	digit_position_3,
	digit_position_4,
	digit_position_5,
	digit_position_6,
	digit_position_7,
	digit_position_8,
	odd_posiiton_result,
	even_position_result,
	result_odd_plus_even,
	unit_digit_of_odd_even_sum;

//----Account number single digit extraction 
    digit_position_0 = account_num % 10;
    digit_position_1 = (account_num / 10) % 10;
    digit_position_2 = (account_num / 100) % 10;
    digit_position_3 = (account_num / 1000) % 10;
    digit_position_4 = (account_num / 10000) % 10;
    digit_position_5 = (account_num / 100000) % 10;
    digit_position_6 = (account_num / 1000000) % 10;
    digit_position_7 = (account_num / 10000000) % 10;
    digit_position_8 = (account_num / 100000000) % 10;

//---Odd digit addition - Step A  
    odd_posiiton_result = 2 * (digit_position_1 + digit_position_3  
			  + digit_position_5 + digit_position_7);

//---Even dgit addition - Step B 
    even_position_result = digit_position_2 + digit_position_4 
	                   + digit_position_6 + digit_position_8;

//---Even and odd addition - Step C
    result_odd_plus_even = odd_posiiton_result + even_position_result;

//---Unit digit extraction form the previus addition - Step D part 1 
    unit_digit_of_odd_even_sum = result_odd_plus_even % 10;


//---Determining the check digit to validate the account Step D part 2
    if (unit_digit_of_odd_even_sum == 0)
    { 
	check_digit = 0;
	
    }
    else 
    {
	check_digit = 10 - unit_digit_of_odd_even_sum;
    }

//----Acount validation 
    if (account_num < 100000000 || account_num > 999999999)
    {
	accout_is_valid = false;
    }

    else if (check_digit != digit_position_0)
    {
	accout_is_valid = false; 
    }
    else 
    {
	accout_is_valid = true;
    }

    return accout_is_valid;
}



//=======================================================================
// Name:        update_account
//
// Purpose:     Calculate and return the account's billing information
//
// Details:     It calculates the total electricity cost, total 
//              contributed electricity credit, any applicable discount, 
//              GST and ending balance.  
//             
//              It uses the monthly starting balance, total electricity 
//              used and total electricity contributed to calculate the 
//              previous values. 
//               
//
//
// Input:       8 doubles - starting balance, total elctric use, total   
//                          electric contribution, total electric cost  
//                          total contribution credit, discount, GST 
//                          and new balance.
//
//              a boolean -  discount ellligibility.
//                           FALSE - discount not availabe.
//                           TRUE - discount available. 
//
//
//
void update_account (double starting_balance,          //in 
		     double total_electric_use,        //in
		     double total_electric_contribute, //in 
		     bool& discount_is_elligible,      //out
		     double& total_electric_cost,      //out
		     double& total_contribute_credit,  //out
		     double& discount,                 //out
		     double& total_gst,                //out
		     double& new_balance)              //out
{

    total_electric_cost = 0.11 * total_electric_use;
    
    total_contribute_credit = 0.055 * total_electric_contribute;

//----Discount value calculation
    if (discount_is_elligible)
    {
	discount = total_electric_cost * 0.10;
    }
    else 
    {
	discount = 0;
    }
    
    total_gst = (total_electric_cost - discount) * GST;
    
    new_balance = (starting_balance + total_electric_cost)
	- (total_contribute_credit + discount) + total_gst;    
}



//=======================================================================
// Name:        print_statement
//
// Purpose:     Print the statement information with a formatted output  
//
// Details:     It takes a monthly statements 9 values as input and 
//              prints them out putting the value names to the right and 
//              its numberic value to the right formatted to 2 decimal 
//              places. It also takes a boolean value to determine
//              whether or not a discount will be displayed or not
//
//
// Input:       9 doubles - account number, total electrical usage,
//                          total electric contributed, starting 
//                          balance, toto electricity cost, total
//                          conributed electricit credit, discount,
//                          GST and ending balance.
//
//              a boolean - holding the result for discount elligibility.
//                          TRUE: discount will be dispayed.
//                          FALSE: discount will not be displayed.
//
//
void print_statement(int account_num,                   
		     double total_electric_use,
		     double total_electric_contribute, 
		     double starting_balance, 
		     double total_electric_cost,
		     double total_contribute_credit, 
		     bool discount_is_elligible,
		     double discount,
		     double total_gst, 
		     double new_balance)

{

//----Determine whether discount will be displayed or not
  
    if (discount_is_elligible == false)
    {
	cout << "Account Number:" << setw(22) << account_num << endl;
	cout << fixed;
	cout << setprecision(2);
	cout << "Electricity Used:" <<  setw(20) <<total_electric_use 
	     << " kWh"<<endl;
	cout << "Electricity Contributed:" <<  setw(13) 
	     << total_electric_contribute
	     << " kWh"<< endl << endl;
	cout << "Starting Balance:" <<  setw(20) << starting_balance
	     << endl;
	cout << "Electricity Cost:" <<  setw(20) << total_electric_cost
	     << endl;
	cout << "Electricity Credit:" <<  setw(18) 
	     << total_contribute_credit << endl;
	cout << "GST:" <<  setw(33) <<  total_gst << endl;
	cout << "Ending Balance:"<<  setw(14) << "$"<<  setw(8) 
	     << new_balance<< endl << endl;				
    }

    else 
    {
	cout << "Account Number:" << setw(22) << account_num << endl;
	cout << fixed;
	cout << setprecision(2);
	cout << "Electricity Used:" <<  setw(20) <<total_electric_use 
	     << " kWh"<<endl;
	cout << "Electricity Contributed:" <<  setw(13) 
	     << total_electric_contribute << " kWh"<< endl << endl;
	cout << "Starting Balance:" <<  setw(20) << starting_balance
	     << endl;
	cout << "Electricity Cost:" <<  setw(20) << total_electric_cost
	     << endl;
	cout << "Electricity Credit:" <<  setw(18) 
	     << total_contribute_credit << endl;
	cout << "Discount:" << setw(28) << discount << endl;
	cout << "GST:" <<  setw(33) <<  total_gst << endl;
	cout << "Ending Balance:"<<  setw(14) << "$"<<  setw(8) 
	     << new_balance<< endl << endl;

    }
    


}


