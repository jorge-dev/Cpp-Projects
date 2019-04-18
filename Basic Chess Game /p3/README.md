Complete the two-player chess program. When the program begins it will set up a standard chess board (white at the bottom). It will then allow the human users to take turns moving (white first).
The Pieces
Here is a summary of the standard chess pieces:

 
Description
King
K or k
Can move one square in any direction (horizontal, vertical, diagonal; forward or backward).
 
Queen
Q or q
Can move multiple squares in any direction.
 
Bishop
B or b
Can move multiple squares diagonally.

Knight
N or n
Can move two squares horizontally and then one vertically, or can move one square horizontally and then two vertically. Special note: this is the only piece that can jump over other pieces when moving to a new square.
 
Rook
R or r
Can move multiple squares horizontally, or can move multiple squares vertically

Pawn
P or p
Can move one square forward vertically if not capturing, or can move one square forward diagonally if capturing. Special note: can move two squares forward on its very first move if not capturing.

The symbol for a white piece will be uppercase. Lowercase will be used for black.

The Board
At the start of a game, the board is set up as shown below. Black moves down, and white moves up.
______________________________
r   n   b   q   k   b   n   r |  
p   p   p   p   p   p   p   p | 
*   *   *   *   *   *   *   * |
*   *   *   *   *   *   *   * |
*   *   *   *   *   *   *   * |
*   *   *   *   *   *   *   * |
P   P   P   P   P   P   P   P |  
R   N   B   Q   K   B   N   R |
______________________________|

Game Over
The game ends if one player captures his opponent’s king or if a player enters the sentinel board coordinates (–1, –1). Be sure to confirm the request to quit.

What You Don’t Have to Handle
In a real game of chess, if a king can be captured by an opposing piece on that player’s next turn, the king is said to be in check and players inform one another to “check” their king. A player cannot make a move which places her king in check. When in check, a player must make a move to get out of check. If that is impossible, then s/he has lost. This is called “checkmate”.
Your program does not have to handle check detection. In this simplified game, players will not be informed that their king is in check. Furthermore, a player may make any move s/he wishes at his/her turn, even putting the king in check or leaving the king in check. As such, the game will play two extra moves.
Your program is not to handle the special chess moves called capturing en passant and castling.
