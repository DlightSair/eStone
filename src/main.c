#include <stdio.h>
#include <string.h>
#include "type.h"
#include "util.h"
#include "game.h"

int WIDTH = 640;
int HEIGHT = 480;



int main(int argsc, char *argsv[])
{
    int gameMode = 1;
    int isFirstPlayer = 0;
    int isGUI = 1;

    for(int i=1; i<argsc; i++){
        if( strcmp(argsv[i], "-2p") == 0 ){
            gameMode = 0;
        }

        if( strcmp(argsv[i], "-b1") == 0 ){
            gameMode = 1;
            isFirstPlayer = 1;
        }
        
        if( strcmp(argsv[i], "-b2") == 0 ){
            gameMode = 1;
            isFirstPlayer = 0;
        }
        
        if( strcmp(argsv[i], "-t") == 0 ){
            isGUI = 0;
        }
        
    }

    return game(gameMode, isFirstPlayer, isGUI);
}