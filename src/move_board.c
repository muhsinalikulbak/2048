#include "move_board.h"
#include "print.h"
#include "spawn_tile.h"

bool has_win(int board[4][4], int target)
{
    for (size_t i = 0; i < BOARD_SIZE; i++)
    {
        for (size_t j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == target)
                return true;
        }
    }
    return false;
}

// Check for lose status 
bool has_move(int board[4][4])
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < BOARD_SIZE)
    {
        j = 0;
        while (j < BOARD_SIZE)
        {
            if (board[i][j] == 0)
                return true;
            if (j + 1 < BOARD_SIZE)
            {
                if (board[i][j+1] == 0 || board[i][j] == board[i][j+1])
                    return true;
            }
            if (i + 1 < BOARD_SIZE)
            {
                if (board[i+1][j] == 0 || board[i][j] == board[i+1][j])
                    return true;
            }
            j++;
        }
        i++;
    }
    return false;
}

// Calculate move up
static void  move_up(t_data *d, int *score) // 0,0 1,0 2,0 3,0 --- 0,1 1,1 1,2...
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
static void  move_down(t_data *d, int *score)
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

// Calculate move left
static void  move_left(t_data *d, int *score)
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
static void  move_right(t_data *d, int *score)
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

static bool can_spawn_tile(int updated[4][4], int prev[4][4])
{
    bool is_empty_tile = false;
    bool changed = false;

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (updated[i][j] != prev[i][j])
                changed = true;
            if (updated[i][j] == 0)
                is_empty_tile = true;
        }
    }
    return changed && is_empty_tile;
}

static void copy_board(int src[4][4], int dest[4][4])
{
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            dest[i][j] = src[i][j];
}

void move_board(t_data *d, int key, int *score)
{
    int prev[4][4];
    copy_board(d->board, prev);

    if (key == KEY_UP)
        move_up(d, score);
    else if (key == KEY_DOWN)
        move_down(d, score);
    else if (key == KEY_LEFT)
        move_left(d, score);
    else if (key == KEY_RIGHT)
        move_right(d, score);

    // Sadece board hareket ettiyse VE boş blok var ise 
    // Rastgele sayı üretilir
    if (can_spawn_tile(d->board, prev))
        spawn_tile(d);
}
