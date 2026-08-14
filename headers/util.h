#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include "type.h"

void displayBoard(gameState *currentGame);
int hasGameEnded(gameState *currrentGame);
int isThisBotTurn(gameState *currentGame, int isFirstPlayer, int gameMode);
void endScreen(SDL_Renderer *renderer, int state, int isGUI);
void setNextPlayer(gameState *currentGame);
void takeUserInput(gameState *currentGame);

#endif