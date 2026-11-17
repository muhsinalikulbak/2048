#include "move_board.h"
#include "print.h"

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
static bool  move_up(t_data *d, int *score)
{
    int     i;
    int     j;
    int     last_cell;
    bool    changed;

    changed = false;
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
                    changed = true;
                    last_cell++;
                }
                else if (d->board[last_cell][i] == 0)
                {
                    d->board[last_cell][i] = d->board[j][i];
                    d->board[j][i] = 0;
                    changed = true;
                }
                else
                {
                    last_cell++;
                    if (j != last_cell)
                    {
                        d->board[last_cell][i] = d->board[j][i];
                        d->board[j][i] = 0;
                        changed = true;
                    }
                }
            }
            j++;
        }
        i++;
    }
    return changed;
}

// Calculate move down
static bool  move_down(t_data *d, int *score)
{
    int     i;
    int     j;
    int     last_cell;
    bool    changed;

    changed = false;
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
                    changed = true;
                    last_cell--;

                }
                else if (d->board[last_cell][i] == 0)
                {
                    d->board[last_cell][i] = d->board[j][i];
                    d->board[j][i] = 0;
                    changed = true;
                }
                else
                {
                    last_cell--;
                    if (j != last_cell)
                    {
                        d->board[last_cell][i] = d->board[j][i];
                        d->board[j][i] = 0;
                        changed = true;
                    }
                }
            }
            j--;
        }
        i++;
    }
    return changed;
}

// Calculate move left
static bool  move_left(t_data *d, int *score)
{
    int     i;
    int     j;
    int     last_cell;
    bool    changed;

    changed = false;
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
                    changed = true;
                    last_cell++;
                }
                else if (d->board[i][last_cell] == 0)
                {
                    d->board[i][last_cell] = d->board[i][j];
                    d->board[i][j] = 0;
                    changed = true;
                }
                else
                {
                    last_cell++;
                    if (j != last_cell)
                    {
                        d->board[i][last_cell] = d->board[i][j];
                        d->board[i][j] = 0;
                        changed = true;
                    }
                }
            }
            j++;
        }
        i++;
    }
    return changed;
}

// Calculate move right
static bool  move_right(t_data *d, int *score)
{
    int     i;
    int     j;
    int     last_cell;
    bool    changed;

    changed = false;
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
                    changed = true;
                    last_cell--;
                }
                else if (d->board[i][last_cell] == 0)
                {
                    d->board[i][last_cell] = d->board[i][j];
                    d->board[i][j] = 0;
                    changed = true;
                }
                else
                {
                    last_cell--;
                    if (j != last_cell)
                    {
                        d->board[i][last_cell] = d->board[i][j];
                        d->board[i][j] = 0;
                        changed = true;
                    }
                }
            }
            j--;
        }
        i++;
    }
    return changed;
}

void move_board(t_data *d, int key, int *score)
{
    bool    changed;

    if (key == KEY_UP)
        changed = move_up(d, score);
    else if (key == KEY_DOWN)
        changed = move_down(d, score);
    else if (key == KEY_LEFT)
        changed = move_left(d, score);
    else if (key == KEY_RIGHT)
        changed = move_right(d, score);

    // Sadece board hareket ettiyse VE boş blok var ise 
    // Rastgele sayı üretilir 
    if (has_move(d->board) && changed)
    {
        // Hareket edilmiş ve oyun devam ediyor olabilir
        // Ama boş hücre olmayabilir o yüzden
        // Önce boş hücre kontrolü yap
        // Varsa rastgele sayıyı üret
        // Yoksa üretmeden çık
    }
}
