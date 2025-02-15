#include "game.h"
#include <stdio.h>



void print_board(board_t game){
    printf("%c | %c | %c \n ----------- \n %c | %c | %c \n ----------- \n %c | %c | %c", game.cases[0], game.cases[1], game.cases[2], game.cases[3], game.cases[4], game.cases[5], game.cases[6], game.cases[7], game.cases[8]);
}

bool check_win(const board_t game) {
    // Check rows
    if ((game.cases[0] == game.cases[1] && game.cases[1] == game.cases[2] && game.cases[0] != ' ') ||
        (game.cases[3] == game.cases[4] && game.cases[4] == game.cases[5] && game.cases[3] != ' ') ||
        (game.cases[6] == game.cases[7] && game.cases[7] == game.cases[8] && game.cases[6] != ' ')) {
        return true;
    }
    // Check columns
    if ((game.cases[0] == game.cases[3] && game.cases[3] == game.cases[6] && game.cases[0] != ' ') ||
        (game.cases[1] == game.cases[4] && game.cases[4] == game.cases[7] && game.cases[1] != ' ') ||
        (game.cases[2] == game.cases[5] && game.cases[5] == game.cases[8] && game.cases[2] != ' ')) {
        return true;
    }
    // Check diagonals
    if ((game.cases[0] == game.cases[4] && game.cases[4] == game.cases[8] && game.cases[0] != ' ') ||
        (game.cases[2] == game.cases[4] && game.cases[4] == game.cases[6] && game.cases[2] != ' ')) {
        return true;
    }
    return false;
}

bool is_board_full(board_t game){
    for(int i = 0; i < 9; i++){
        if(game.cases[i] == ' '){
            return false;
        }
    }
    return true;
}

bool is_case_empty(board_t game, int n){
    return game.cases[n] == ' ';
}

bool is_game_over(board_t game){
    if(is_board_full(game) || check_win(game)){
        return true;
    }else{
        return false;
    }
}


void gameplay(board_t *game, char C){
    while (true) {
        int choice;
        scanf("%d", &choice);
        if (is_case_empty(*game, choice)) {
            game->cases[choice] = C;
            break;
        } else {
            printf("Case already used, one more time\n");
        }
    }
}