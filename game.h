#ifndef GAME_H
#define GAME_H

typedef struct {
    char case1;
    char case2;
    char case3;
    char case4;
    char case5;
    char case6;
    char case7;
    char case8;
    char case9;
} board_t;

void print_board(board_t game);

#endif // Game TicTacToe