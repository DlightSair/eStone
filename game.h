#ifndef GAME_H
#define GAME_H

#include <stdio.h>

int game(int gameMode, int isFirstPlayer);
void getBotInput(gameState *currentGame, int isFirstPlayer);
int minmax(gameState *currentGame, int isFirstPlayer);

#endif