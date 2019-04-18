// Function Name:  prettyprint
// Arguments:  an integer representing the field width and an integer
//             representing the number to be outputted
// Action:  the number is outputted to the standard output right-justified
//          in the specified width (leading blanks are printed if necessary)
//
//          e.g. prettyprint (5, 2);   would produce the output
//                        2            where    represents a leading blank
//                    ^^^^                   ^ 
//
//               prettyprint (4, -8);   would produce the output
//                      -8           
//                    ^^            
//
//               prettyprint (4, 2);
//               prettyprint (4, -8);   would produce the output
//                       2  -8
//                    ^^^ ^^

void prettyprint (int, int);

