#ifndef TYPE_H
#define TYPE_H

#include <stdio.h>

#define BOARD_SIZE 3

typedef struct{
    int boardSize;
    int currentPlayer;
    int movesPlayed;
    int board[BOARD_SIZE][BOARD_SIZE];
} gameState;

#endif