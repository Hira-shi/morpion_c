#ifndef GAME_H
#define GAME_H

#pragma once
#include <stdbool.h>




typedef struct {
    char cases[9];
} board_t;

void print_board(board_t game);
bool is_game_over(board_t game);

void gameplay(board_t game, char C);


#endif // Game TicTacToe