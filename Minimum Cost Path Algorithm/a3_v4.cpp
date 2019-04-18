/* 
   Name:        Jorge Avila
   Email:       javil686@mtroyal.ca
   Course:      COMP 1633-001
   Assignment:  #3
   Due Date:    March 7, 2018
   Instructor:  Paul Pospisil

   Source File: a3.cpp

   Purpose: This program takes a 2d array of integers and
            returns its minimum cost path and the 
            coordinates representing such path 

   Details: given a 2d array of max size 100 x 100 the program
            can find the minimum cost path or most efficient
	    path starting from 0 column to the last.
	    
	    to find the minimum cost, the program must go through every
	    path allowed and compare its final cost to determine which 
	    path has the least cost.
	    
	    In any point or position in the array, the three posible or 
	    allowed paths to take are: forward, diagonally up or
	    diagonally down.
	    
	    when the path has been found the program should output the 
	    min cost of the path and the paths coordinates.
	    
	    

   Assumptions, Limitations or Known Bugs:
   No known bugs.
   Program input must be valid numeric data and positive number.
   
*/
#include <iostream>
#include <cstring>
#include <fstream>
#include <limits.h>
using namespace std;
const int MAX_FILE_LEN = 30;
const int MAX_MAT_LEN = 100;

void find_start_pos(const int matrix[][100], int x_pos, int y_pos , 
		    int row, int column,int path_arr[], int &smallest);
int minCost(const int matrix[][MAX_MAT_LEN], int x_pos, int y_pos,
	    int row,int column, int  path_arr[]);
void print_path(const int matrix[100],int column,int i);
int min_3(int small, int medium, int large);
void arr_copy(int arr_dest[100], int arr_src[100],int column,int start);
int go_up( int x_pos, int row_num);
int go_straight( int x_pos, int row_num);
int go_down( int x_pos, int row_num);
void read_file(istream & infile, int matrix[][MAX_MAT_LEN],
	       int row, int column, int rCount, int cCount);


 
int main()
{

    ifstream infile;
    char in_filename[MAX_FILE_LEN + 1];
    int matrix [MAX_MAT_LEN][MAX_MAT_LEN];
    int path_arr [MAX_MAT_LEN] = {0};
    int row,cost;
    int column;
    int x_pos = 0,
	y_pos = 0;
    
    cout << "Enter File Name: ";
    cin >> in_filename;
    infile.open(in_filename);
    if (infile.fail())
    {
	cout <<"Couldn't find file. Please try agian. "<<endl;

    }
    else 
    {
	infile >> row;
	infile >> column;
	
	read_file(infile,matrix,row, column, 0,0);	
	infile.close();
	
	
	find_start_pos(matrix,x_pos,y_pos,row,column,path_arr,cost);
	
	cout << "cost: "<< cost<<endl;
	
	print_path(path_arr,column,0);

    }
    cout << endl;
    return 0;
}


/*=======================================================================
  Name:       find_start_pos

  Purpose:    check the cost for all rows and determine which row has the
              lowest cost 
             
  Details:  there are 2 base cases and one recursion call. the cost will 
            be loaded before the second base case and if the second base
	    case is not met

            Base cases: if x position is greater than the number of rows 
                          in arr then do nothing or stop recursion
                          if cost is smaller then the smallest value 
			  (is cost which is passed by reference) then 
			  the smallest is equal to cost and will call a
			  functoin to copy the contentes from the temp 
			  array into the path array.

            Recursion: while the x position is less than the row number,
	               have a recursive call that will increase the 
		       x position
  
 
  Input:      2 int array: matrix - arr holding a 2d array.
                           path_arr - arr where the min path 
			             will be stored.

	      5 integers: x_pos - starting row
	                  y_pos - starting column (always 0)
			  row - number of rows in 2d array
			  column - number of columns in 2d array
			  smallest - will store cost and is passed by
			             reference
  
 

*/
void find_start_pos(const int matrix[][100], int x_pos, int y_pos , 
		    int row, int column,int path_arr[], int &smallest)
{
    
    int cost = 0;
    int path_start[100]={0};
    int start = 0;
    if (x_pos < row)
    {
	cost = minCost(matrix,x_pos,y_pos,row,column,path_start);
	if (cost < smallest)
	{
	    smallest = cost;
	    arr_copy(path_arr,path_start,column,start);
	}
	else
	{
	    cost = minCost(matrix,x_pos,y_pos,row,column,path_start);
	}	
	find_start_pos(matrix,x_pos+1,y_pos,row,column,path_arr,smallest);
    }

}


/*=======================================================================
  Name:       print_path

  Purpose:    print the miimum path stored in an array
             
  Details:    Base cases: if the end of path is reached, do nothing

              Recusrsion: if the end of array hasn't been reached,
	      print the corresponding coordinate and call print_path
	      function again with the starting point being increased
	      by one.
  
 
  Input:      an int array: matrix - arr holding the min path 
              2 integers: column - number of columns from a 2d matrix
	                           (equal to the number of paths)
	                  start - starting index used to get the elements
			          from array (usually  0)

  Output:     the function prints out a corrdinate (x,y) separated by 
              spaces

*/

void print_path(const int matrix[100],int column, int start)
{
    
    if ( start < column )
    {
	cout <<"("<<  matrix[start]<< "," << start << ") ";
	print_path(matrix,column,start+1);
    }
}

/*=======================================================================
  Name:       min_cost

  Purpose:    given a 2d array, it compares every path through the arr 
              from left to right, and returns the minimum cost and 
	      its path.

  Details:    the function uses 1 base case and 3 recursion calls to 
              find the minimum path.

	      Base case: if the y-position is equal to the last column 
	                 in the array, then the cost equal the current 
			 position and the path coordinate equals the 
			 current x-position.
		     
	      Recursive cases: there are 3 recursive calls, one per path:
	                       path up, path straight, and path down.
			       
			       when the 3 cases are completed and their 
			       corresponding variables are loaded with 
			       the path cost,then the 3 paths are 
			       compared, and the minimin pat and cost 
			       are stored and returned
 
  Input:      2 int array: matrix - arr holding a 2d array.
                           path_arr - arr where the min path 
			             will be stored.

	      4 integers: x_pos - starting row
	                  y_pos - starting column (always 0)
			  row - number of rows in 2d array
			  column - number of columns in 2d array

 Return:      an integer: cost - minimum cost through array

*/
int minCost( const int matrix[][100], int x_pos, int y_pos , 
	     int row, int column,int path_arr[])
{
    
    int cost=0 ,path_up=0, path_down=0,path_straight=0, min_path =0,
	start =0;

    int path_up_arr[100] = {0};
    int path_down_arr[100] = {0};  
    int path_straight_arr[100] = {0} ;
 
    if (y_pos == column -1 ){

	cost = matrix[x_pos][y_pos] ;
	path_arr[y_pos] = x_pos;
    }
    else
    {


	//3 paths
	path_up = minCost(matrix, go_up(x_pos,row), y_pos +1,row,column, 
			  path_up_arr) ;

	path_straight = minCost(matrix, go_straight(x_pos,row), 
				y_pos +1,row,column, path_straight_arr) ;

	path_down = minCost(matrix, go_down(x_pos,row), 
			    y_pos +1, row,column, path_down_arr) ;

	min_path = min_3(path_up,path_straight,path_down);
  
	//find best path
	if (path_up == min_path) 
	{

	    arr_copy(path_arr,path_up_arr,column,start);

	}

	else if (path_straight == min_path) 
	{

	    arr_copy(path_arr,path_straight_arr,column,start);

	}

	else 
	{

	    arr_copy(path_arr,path_down_arr,column,start);
     
	}
   
	path_arr[y_pos] = x_pos;
	cost = matrix[x_pos][y_pos] + min_path;


	
	

    }    
    return cost;
    
}

/*=======================================================================
  Name:       arr_copy

  Purpose:    copy the elements from source array to destination array

  Details:    1 base case and one recursion call.
  
              Base cases: if start(index) is greater than the number of 
	      columns,then do nothing.

	      Recursion call: while start is not greater than number of 
	                      columns,then copy the corresponding 
			      element from src arr to destination array 
			      and make a recursive call with the 
			      starting point increased by one
 
  Input:      2 int arrays: arr_dest - destination array
                            arr_src - source array
	      2 integers: column - number of columns
	                  start - starting index (always 0)

*/
void arr_copy(int arr_dest[100], int arr_src[100],int column,int start)
{
    if (start < column)
    {
	arr_dest[start] = arr_src[start];
	arr_copy(arr_dest,arr_src,column,start+1);
    }
}


/*=======================================================================
  Name:       go_straight

  Purpose:   determine how to move x positin when path in arr is straight

  Input:      2 integers: x_pos - current row position
                          row_num - number of rows
			  

 Return:      an integer with the corresponding x_position

 ************* this funciont is useless, done just 
         to keep my code more uniform************
                          

*/
int go_straight( int x_pos, int row_num)
{
    return x_pos;
}


/*=======================================================================
  Name:       go_up

  Purpose:    determine how to move x position when path in arr is up

  Details:    if the current row position (x_pos) is equal to zero
              then going up will move x position the the last row.
	      otherwise it will move the x position one row up.
             
  
  Input:      2 integers: x_pos - current row position
                          row_num - number of rows

  Return:      an integer with the corresponding x_position
*/
int go_up( int x_pos, int row_num)
{
    
    if ( x_pos == 0)
    {
	x_pos = row_num - 1;
    }
    else {
	x_pos --;
    }

    return x_pos;
}


/*=======================================================================
  Name:       go_down

  Purpose:    determine how to move x position when path in arr is down

  Details:    if the current row position (x_pos) is equal to the last
              row, then going down will move x position the the fisr row.
	      otherwise it will move the x position one row down.
             
  
  Input:      2 integers: x_pos - current row position
                          row_num - number of rows

  Return:      an integer with the corresponding x_position
*/
int go_down( int x_pos, int row_num)
{

    if ( x_pos == row_num -1)
    {
	x_pos = 0;
    }
    else 
    {
	x_pos++;
    }
    return x_pos;
}


/*=======================================================================
  Name:       min_3

  Purpose:    compares 3 numbers and determines which one is the smallest

  Details:    to find the smallest number 2 conditions are tested:
              if first is smaller than second and third, then first 
	      is the smallest.
	      
	      if second is smaller than first and third, then second 
	      is the smallest.
	      
	      otherwise, third is the smallest.

  Input:      3 integers: small = first number.
                          medium = second number
			  large = third number
  
Return:      an integer: min = stores the smallest number
*/
int min_3(int small, int medium, int large)
{
    int min;
    if (small < medium && small < large)
	min = small;

    else if (medium < small && medium < large)
	min = medium;

    else 
	min = large;
    
    return min;


}




/*=======================================================================
  Name:       read_file

  Purpose:    reads a  file and stores its contents into a 2d array 

  Details:    The function uses 3 base cases and 2 recursion calls
              to load the array.
             
	      Base cases:
	      if end of file flag is true then read stops and do nothing 
	      
	      if row(num rows) or column(num columns) equal zero,
	      then the file is empty or invalid matrix,
	      and the (0,0) is  always zero
	      
	      if the row and column are equal to zero,
	      then the (0,0) is equal to the first number read

	      Recursion calls:
	      if current column position(cCount) is less than the number
	      of columns, then load the current row and 
	      have a recursion call that increases the cCount

	      if cCount is greater than the number of columns,
	      then reset cCount to zero and increase the row number
	      to load the next row and have a recursion call that
	      increases the cCount and rCount
	      
  Input:      an istream: infile = stores the current value into a 
                          variable to load a specific (x,y) coordinate
	      an int arr: matrix = 2d arr where values will be stored
	      
	      4 integers: row = number of rows to load
	                  column = number or columns to load
			  rCount = row position
			  cCount = column position

*/
void read_file(istream & infile, int matrix[][MAX_MAT_LEN],
	       int row, int column, int rCount, int cCount)
{
    int temp;
    infile>>temp;
    if (!infile.eof())
    {
	if ( row == 0 || column == 0)
	{
	    matrix[0][0] = 0;
	    infile>>temp;
	}
	else if (row == 1 && column == 1)
	{	 
	    matrix[0][0] = temp;
	    infile>>temp;
	}
	else
	{
	    if (cCount < column)
	    {
		matrix[rCount][cCount] = temp;
	
		read_file(infile,matrix,row, column, rCount, cCount + 1);
	    }//end third if
	    
	    else 
	    {
		cCount =0;
		matrix[rCount +1][cCount] = temp;
		read_file(infile,matrix,row, column, rCount +1, cCount +1  );
	       
	    }//end second else
	

	}//end first else
	
    }//end first if
	
}//end read_file
