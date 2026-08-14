#ifndef TYPE_H
#define TYPE_H

#include <stdio.h>
#include <SDL3/SDL.h>


#define BOARD_SIZE 3

extern int WIDTH;
extern int HEIGHT;


typedef struct{
    int boardSize;
    int currentPlayer;
    int movesPlayed;
    int board[BOARD_SIZE][BOARD_SIZE];
} gameState;

#endif