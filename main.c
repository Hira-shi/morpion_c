#include <stdio.h>
#include <stdbool.h>
#include "game.h"

board_t new_game(board_t game){
    for(int i = 0; i < 9; i++){
        game.cases[i] = ' ';
    }

    return game;
}


int main(){

    board_t game;

    printf("Welcome to the game");

    bool remake = true;
    new_game(game);
    print_board(game);

    do{
        gameplay(game, 'X');
        print_board(game);
        gameplay(game, 'O');
        print_board(game);

        char answer;
        scanf("Do you want to replay ? (y/n): %c", answer);
        if(answer != 'y'){
            remake = false;
        }else{
            new_game(game);
        }
    }while(remake);

    return 0;
}