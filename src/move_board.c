#include "move_board.h"
#include "move_vertical.h"
#include "move_horizontal.h"
#include "spawn_tile.h"

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
