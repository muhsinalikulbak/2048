#include "spawn_tile.h"

static int count_empty_cells(int board[4][4])
{
    int count = 0;
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            if (board[i][j] == 0)
                count++;
    return count;
}

void spawn_tile(t_data *d)
{
    int empty_count = count_empty_cells(d->board);
    if (empty_count == 0)
        return;
        
    int rnd_num = rand() % empty_count + 1;
    int count = 0;

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (d->board[i][j] == 0)
            {
                count++;
                if (count == rnd_num)
                {
                    d->board[i][j] = 2;
                    return;
                }
            }
        }
    }
}
