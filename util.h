#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

void displayBoard(gameState *currentGame);
void getMove(gameState *currentGame, int gameMode, int isFirstPlayer);
int hasGameEnded(gameState *currrentGame);
void endScreen(int state);
void setNextPlayer(gameState *currentGame);

#endif