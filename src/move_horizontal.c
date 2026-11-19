#include "move_horizontal.h"

// Calculate move left
void  move_left(t_data *d, int *score)
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
            j++;
        }
        i++;
    }
}

// Calculate move right
void  move_right(t_data *d, int *score)
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
            j--;
        }
        i++;
    }
}
