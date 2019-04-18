/*
  Name:        Jorge Avila
  E-mail:      javil686@mtroyal.ca
  Course:      COMP 1631-001
  Assignment:  4, Part 2
  Due Date:    Tuesday, November 21, 2017 at 11:59 p.m.
  Instructor:  Paul Pospisl

  Source File: a4p2.cpp

//=======================================================================

Purpose:
    This program prepares a monthly electricity bill for a customer
    or series of customers.

Details:
    Customers are charged 11 cents per kWh for the amount of electricity 
    they use, but are credited 5.5 cents per kWh for the amount of 
    electricity they contribute. Eligible customers get a 10% discount on
    electricity used.

Input:
    The customer's data comes in two lines minumum (there can be several 
    transaction records). The first line is a header 
    record that consists of three items:

        customer account number, month starting balance and discount 
	elibility

    The discount eligibility is either a 'y'/'Y' for yes or an 'n'/'N' 
    for no.

    The second line is a transaction record, which has three 
    items:

        account number, type of transaction(usage or contribution), 
	and transaction amount

    Both the usage and contribution are values in kWhs. 
    Transaction records are cheacked for any of three errors:
        -Account number not matching the header account
	-Invalid transaction code (only 'U' or 'C' are valid)
	-Transaction amount less than 0
    

Output:
    The account number is validated and if either an invalid account is 
    detected or the account has transaction errors appropriate error 
    messages are generated and a bill is not produced.

    If the account is fine then a bill is printed that is nicely formated
    and includes:
        the account number
        used electricity
        contributed electricity
        the starting balance
        the ending balance
        the cost of the used electricity
        the credit for contributed electricity
        any discount on used electricity
        GST
*/
//=======================================================================

#include <iostream>
#include <iomanip>
using namespace std;

bool valid_account (int account);
void read_and_process (int account, 
		       int& error_count, 
		       bool& valid, 
		       double& usage, 
		       double& contribution, 
		       int& line_number);

void read_and_total (int account_number,
		     int& error_count, 
		     bool& valid, 
		     double& contribution,
		     double& usage, 
		     int& line_number);

void read_and_ignore (int& line__number);

void update_account (double usage, 
		     double& cost_usage, 
		     double& credit, 
                     double contribution, 
		     bool discount_eligible, 
		     double& discount,
                     double& gst, 
		     double start_balance, 
		     double& end_balance);

void print_statement (int account, 
		      double start_balance, 
		      double usage, 
                      double contribution, 
		      double cost_usage, 
		      double credit, 
                      bool discount_eligible, 
		      double discount, 
		      double gst, 
                      double end_balance);

const double GST_RATE = 0.05;          // rate of GST

int main ( )
{
    int account_number,
	line_number,
	error_count,
	number_of_accounts;

    bool valid,
	discount_eligible;
	
  
    double usage, 
	contribution,
	start_balance,
	end_balance,
	cost_usage,
	credit,
	discount,
	gst;

    char   discount_char;


  
    line_number = 0;
    error_count =0;
    number_of_accounts = 0;


    cin >> account_number >> start_balance >> discount_char;

    while (!cin.eof())	 
    {
	line_number++;
	 discount_eligible = (discount_char == 'y' || 
			      discount_char == 'Y');
    
	 read_and_process(account_number, error_count, valid,usage,
			  contribution,line_number);

	 if (valid)
	 {
	 update_account (usage, cost_usage, credit, contribution, 
			 discount_eligible, discount, gst, 
			 start_balance, end_balance);
	 print_statement (account_number, start_balance, usage, 
			  contribution, cost_usage, credit, 
			  discount_eligible, discount, 
			  gst, end_balance );
	 }
	 else
	 {
	 cout << "*** Account " << account_number 
	 << " - statement not printed due to errors ***" << endl;
	 }

	 number_of_accounts++;

	cin >> account_number >> start_balance >> discount_char;
   
    } // end of loop

    cout << "Processed " << line_number << " total lines.  " 
	 << "Processed "<< number_of_accounts << " accounts. " 
	 <<"There were "<< error_count << " errors." << endl;
    return 0;
}


//=======================================================================
/*

 Name:        read_and_process

 Purpose:     Check for account header validity and process the 
              transaction(s) records.

 Details:     Makes a call to two other functions to process the 
              transaction records or to ignore them in case an invalid
	      account is found
              

 Input:       3 integers - account number, error count, line number.
              a bool - validity of account.
	                -True: valid
                        -False: no valid
	      2 doubles - usage and contribution

*/
void read_and_process (int account, int& error_count, bool& valid, 
		       double& usage, double& contribution, 
		       int& line_number)
{
    
    valid = valid_account(account);
    if (!valid)
    {
	cout <<"Error in line #"<< line_number 
	     << " - Invalid account number found " <<account << endl;
	read_and_ignore(line_number);
	error_count++;
    }
    
   
    else 
    {
	read_and_total (account,error_count, valid, contribution, 
			usage,line_number);
	
    }

   
}

//=======================================================================
bool valid_account (int account)
{
    const int MAX_9_DIGITS = 999999999;
    const int MIN_9_DIGITS = 100000000;    
    int digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8;
    int check_digit;                  // from the original account number
    int compare_digit;                // from the calculated number
    int compare_number;
    int compare_units_digit;
    bool result = true;               // assume the account is valid

    if (account < MIN_9_DIGITS)
    { 
	result = false;
    }
    else
    {
	if (account > MAX_9_DIGITS)
	{
	    result = false;
	}
	else
	{
	    check_digit = account % 10;

	    digit1 = (account % 100 ) /10;
	    account = account / 100;
	    digit2 = account % 10;
	    account = account / 10;
	    digit3 = account % 10;
	    account = account / 10;
	    digit4 = account % 10;
	    account = account / 10;
	    digit5 = account % 10;
	    account = account / 10;
	    digit6 = account % 10;
	    account = account / 10;
	    digit7 = account % 10;
	    digit8 = account / 10;

	    compare_number = 2 * (digit1 + digit3 + digit5 + digit7)
		+ digit2 + digit4 + digit6 + digit8;
      
	    compare_units_digit = compare_number % 10;
	    if (compare_units_digit == 0)
		compare_digit = compare_units_digit;
	    else
		compare_digit = 10 - compare_units_digit;
      
	    if (check_digit != compare_digit)
		result = false;
	}
    }

    return result;
}

//=======================================================================

/*

 Name:        read_and_total

 Purpose:     read transaction records and sum the total usage and 
              contributions if no errors are found.

 Details:     The usage and contribution values are updated only if there
              are no errror in the transacations. If one or more errors 
	      are found, the two values will not be added to a total and
	      a corresponding error message will be printed instead.

 Input:       3 integers - transaction account number, error count and
                           line number
              a bool - account validity
                      True: no errors
                      False: errors
	      2 doubles - usage and contrubutions
*/

void read_and_total (int account_number, int& error_count, 
		     bool& valid, double& contribution,
		     double& usage, int& line_number)
{
    int trans_account_num;
    bool end_trans_record;
    char transaction_code;
    double transaction_value;
    usage = 0; 
    contribution =0;

    valid = true;
    end_trans_record = (trans_account_num == -1 && 
			transaction_code == 'X' && 
			transaction_value == -1);

    cin >> trans_account_num >> transaction_code >> transaction_value;
    
    
     
	while (!end_trans_record)
	{
	    line_number++;
	    
	    cout << fixed;
	    cout << setprecision(2);

     
	    
	    if (trans_account_num != account_number)
	    {
		cout << "Error in line #"<< line_number 
		     << " - non-matching account number " 
		     << trans_account_num << endl;
		valid  = false;
		error_count ++;
		
	    }

	    if (transaction_code != 'U' && transaction_code != 'C') 
	    {
		cout << "Error in line #"<< line_number 
		     << " - invalid transaction code \'"
		     << transaction_code << "\'"<<endl;
		valid  = false;
		error_count ++;
	    }


	 
	    if (transaction_value < 0)
	    {
		cout << "Error in line #"<< line_number
		     << " - invalid transaction amount " 
		     << transaction_value << endl;
		valid  = false;
		error_count ++;
	    }

	

	    if (valid)
	    { 	 

		if (transaction_code == 'U')
		{
		    usage += transaction_value;
		}

		if (transaction_code == 'C')
		{
		    contribution  += transaction_value;
	     
		} 
	 
	 
	    } 
	 
	 
	    cin >> trans_account_num 
		>> transaction_code 
		>> transaction_value;

	    end_trans_record = (trans_account_num == -1 && 
				transaction_code == 'X' && 
				transaction_value == -1);
	   
	}//end of loop
    
	line_number++;

}


//=======================================================================

/*

 Name:        read_and_ignore

 Purpose:     read an account's transaction records until the end of 
              the transactions is found.  

 Details:     Uses the values -1 X -1 to determine when the acount's
              transaction record end has been found. The three values 
	      must be present in order to determine an end.
              

 Input:       an integer - line number 
              
              

*/ 

void read_and_ignore (int& line_number)

{

    int trans_account_num;
    bool end_trans_record;
    char transaction_code;
    double transaction_value;

    end_trans_record = (trans_account_num == -1 && 
			transaction_code == 'X' && 
			transaction_value == -1);

    cin >> trans_account_num >> transaction_code >> transaction_value;

    while (!end_trans_record)
    {
	line_number++;
	cin >> trans_account_num 
	    >> transaction_code 
	    >> transaction_value;

	end_trans_record = (trans_account_num == -1 && 
			    transaction_code == 'X' && 
			    transaction_value == -1);

	

    }// end of loop
    line_number++; 
}


//=======================================================================
void update_account (double usage, 
		     double& cost_usage, 
		     double& credit, 
                     double contribution, 
		     bool discount_eligible, 
                     double& discount, 
		     double& gst, 
		     double start_balance, 
                     double& end_balance)
{
    const double USAGE_RATE = 0.11;
    const double CONTRIBUTION_RATE = 0.055;
    const double DISCOUNT_RATE = 0.1;

    cost_usage = usage * USAGE_RATE;
    credit = contribution * CONTRIBUTION_RATE;

    if (discount_eligible)
	discount = cost_usage * DISCOUNT_RATE;
    else
	discount = 0;

    gst = (cost_usage - discount) * GST_RATE;

    end_balance = start_balance + gst + cost_usage - credit - discount;

    return;
}

//=======================================================================
void print_statement (int account, 
		      double start_balance, 
		      double usage, 
                      double contribution, 
		      double cost_usage, 
		      double credit, 
                      bool discount_eligible, 
		      double discount, 
		      double gst, 
                      double end_balance )
{
    const int TITLE_WIDTH = 27;
    const int VALUE_WIDTH = 9;

    cout << fixed;
    cout << setprecision(2);

    cout << endl;

    cout << left << setw(TITLE_WIDTH) << "Account Number:" 
	 << account << endl;

    cout << left << setw(TITLE_WIDTH) << "Electricity Used:" << right
	 << setw(VALUE_WIDTH) << usage << " kWh" << endl;

    cout << left << setw(TITLE_WIDTH) << "Electricity Contributed: " 
	 << right << setw(VALUE_WIDTH) << contribution << " kWh" << endl;

    cout << endl;

    cout << left << setw(TITLE_WIDTH) << "Starting Balance: " << right 
	 << setw(VALUE_WIDTH) << start_balance << endl;

    cout << left << setw(TITLE_WIDTH) << "Electricity Cost:" << right 
	 << setw(VALUE_WIDTH) << cost_usage << endl;

    cout << left << setw(TITLE_WIDTH) << "Electricity Credit:" << right 
	 << setw(VALUE_WIDTH) << credit << endl;

    if (discount_eligible)
    {
	cout << left << setw(TITLE_WIDTH) << "Discount:" << right 
	     << setw(VALUE_WIDTH) << discount << endl;
    }

    cout << left << setw(TITLE_WIDTH) << "GST:" << right 
	 << setw(VALUE_WIDTH)<< gst << endl;

    cout << left << setw(TITLE_WIDTH) << "Ending Balance:" << '$' 
	 << right << setw(VALUE_WIDTH - 1) << end_balance << endl;

    cout << endl;

    return;
}


