#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

void displayBoard(gameState *currentGame);
void takeInput(gameState *currentGame);
int hasGameEnded(gameState *currrentGame);
void endScreen(int state);

#endif