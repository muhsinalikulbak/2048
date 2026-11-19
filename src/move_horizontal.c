#include "move_horizontal.h"

// Calculate move left
void  move_left(t_data *d, int *score)
{
    int     last_cell = 0;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        last_cell = 0;
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (d->board[i][j] > 0 && j != last_cell)
            {
                if (d->board[i][last_cell] == d->board[i][j])
                {
                    d->board[i][last_cell] += d->board[i][j];
                    *score += d->board[i][last_cell];
                    d->board[i][j] = 0;
                    last_cell++;
                }
                else if (d->board[i][last_cell] == 0)
                {
                    d->board[i][last_cell] = d->board[i][j];
                    d->board[i][j] = 0;
                }
                else
                {
                    last_cell++;
                    if (j != last_cell)
                    {
                        d->board[i][last_cell] = d->board[i][j];
                        d->board[i][j] = 0;
                    }
                }
            }
        }
    }
}

// Calculate move right
void  move_right(t_data *d, int *score)
{
    int     last_cell = 0;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        last_cell = BOARD_SIZE - 1;
        for (int j = BOARD_SIZE - 1; j >= 0; j--)
        {
            if (d->board[i][j] > 0 && j != last_cell)
            {
                if (d->board[i][last_cell] == d->board[i][j])
                {
                    d->board[i][last_cell] += d->board[i][j];
                    *score += d->board[i][last_cell];
                    d->board[i][j] = 0;
                    last_cell--;
                }
                else if (d->board[i][last_cell] == 0)
                {
                    d->board[i][last_cell] = d->board[i][j];
                    d->board[i][j] = 0;
                }
                else
                {
                    last_cell--;
                    if (j != last_cell)
                    {
                        d->board[i][last_cell] = d->board[i][j];
                        d->board[i][j] = 0;
                    }
                }
            }
        }
    }
}
