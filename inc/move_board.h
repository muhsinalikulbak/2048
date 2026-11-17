#ifndef MOVE_BOARD_H
# define MOVE_BOARD_H

#include "game_loop.h"

void    move_board(t_data *d, int key, int *score);
bool    has_move(int board[4][4]);
bool    has_win(int board[4][4], int target);

#endif