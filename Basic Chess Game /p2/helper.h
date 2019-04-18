#ifndef HELPER_H
#define HELPER_H


//class Pawn;
#include "Board.h"
#include <iostream>
using namespace std;
typedef char prompt[100];

int readFromX ();
int readToX ();
int readFromY ();
int readToY();
bool exitGame();
bool confirmQuit(int x,int y);
bool isKingDead (const Board& t);
void initChess (Board& test,PiecePtr blackPiece, PiecePtr whitePiece);


prompt fromXPrompt = "Enter x coordinate to move from: ";
prompt fromYPrompt = "Enter y coordinate to move from: ";
prompt toXPrompt = "Enter x coordinate to move to: ";
prompt toYPrompt = "Enter y coordinate to move to: ";
prompt quitPrompt = "Are you sure you want to quit (y/n)): ";

#endif
