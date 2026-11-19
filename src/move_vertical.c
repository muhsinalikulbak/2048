#include "move_vertical.h"

// Calculate move up
void  move_up(t_data *d, int *score) // 0,0 1,0 2,0 3,0 --- 0,1 1,1 1,2...
{
    int     last_cell = 0;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        last_cell = 0;
        for (int j = 0; j < BOARD_SIZE; j++)
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
        }
    }
}

// Calculate move down
void  move_down(t_data *d, int *score)
{
    int     last_cell = 0;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        last_cell = BOARD_SIZE - 1;
        for (int j = BOARD_SIZE - 1; j >= 0; j--)
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
        }
    }
}
