#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include "type.h"

int game(int gameMode, int isFirstPlayer, int isGUI);
void getBotInput(gameState *currentGame, int isFirstPlayer);
int minmax(gameState *currentGame, int isFirstPlayer);

#endif