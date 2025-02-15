#include <stdio.h>

#include "game.h"

void new_game(board_t *game){
    for(int i = 0; i < 9; i++){
        game->cases[i] = ' ';
    }
}


int main(){

    board_t game;

    printf("Welcome to the game");

    bool remake = true;
    new_game(&game);
    print_board(game);

    do{
        do{
            gameplay(&game, 'X');
            print_board(game);
            gameplay(&game, 'O');
            print_board(game);
        }while(!is_game_over(game));

        char answer;
        printf("Do you want to replay ? (y/n): ");
        scanf(" %c", answer);
        if(answer != 'y'){
            remake = false;
        }else{
            new_game(&game);
        }
    }while(remake);

    return 0;
}