#include "move_vertical.h"

// Calculate move up
void  move_up(t_data *d, int *score) // 0,0 1,0 2,0 3,0 --- 0,1 1,1 1,2...
{
    int     i;
    int     j;
    int     last_cell;

    last_cell = 0;
    i = 0;
    j = 0;
    while (i < BOARD_SIZE)
    {
        last_cell = 0;
        j = 0;
        while (j < BOARD_SIZE)
        {
            if (d->board[j][i] > 0 && j != last_cell)
            {
                if (d->board[last_cell][i] == d->board[j][i])
                {
                    d->board[last_cell][i] += d->board[j][i];
                    *score += d->board[last_cell][i];
                    d->board[j][i] = 0;
                    last_cell++;
                }
                else if (d->board[last_cell][i] == 0)
                {
                    d->board[last_cell][i] = d->board[j][i];
                    d->board[j][i] = 0;
                }
                else
                {
                    last_cell++;
                    if (j != last_cell)
                    {
                        d->board[last_cell][i] = d->board[j][i];
                        d->board[j][i] = 0;
                    }
                }
            }
            j++;
        }
        i++;
    }
}

// Calculate move down
void  move_down(t_data *d, int *score)
{
    int     i;
    int     j;
    int     last_cell;

    last_cell = 0;
    i = 0;
    j = 0;
    while (i < BOARD_SIZE)
    {
        last_cell = BOARD_SIZE - 1;
        j = BOARD_SIZE - 1;
        while (j >= 0)
        {
            if (d->board[j][i] > 0 && j != last_cell)
            {
                if (d->board[last_cell][i] == d->board[j][i])
                {
                    d->board[last_cell][i] += d->board[j][i];
                    *score += d->board[last_cell][i];
                    d->board[j][i] = 0;
                    last_cell--;

                }
                else if (d->board[last_cell][i] == 0)
                {
                    d->board[last_cell][i] = d->board[j][i];
                    d->board[j][i] = 0;
                }
                else
                {
                    last_cell--;
                    if (j != last_cell)
                    {
                        d->board[last_cell][i] = d->board[j][i];
                        d->board[j][i] = 0;
                    }
                }
            }
            j--;
        }
        i++;
    }
}
