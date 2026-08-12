#include <stdio.h>
#include <string.h>
#include "type.h"
#include "util.h"
#include "game.h"

int main(int argsc, char *argsv[])
{
    int gameMode = 0;
    int isFirstPlayer = 0;

    for(int i=1; i<argsc; i++){
        if( strcmp(argsv[i], "-b") == 0 ){
            gameMode = 1;
        }else if( strcmp(argsv[i], "-b1") == 0 ){
            gameMode = 1;
            isFirstPlayer = 1;
        }else if( strcmp(argsv[i], "-b2") == 0 ){
            gameMode = 1;
            isFirstPlayer = 0;
        }
    }

    return game(gameMode, isFirstPlayer);
}