#include "reset_board.h"

static void	reset_game_board(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < GAME_BOARD_SIZE)
	{
		j = 0;
		while (j < GAME_BOARD_SIZE)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

static void	reset_draw_board(int start_y, int start_x)
{
	int	i;
	int	j;

	i = 0;
	while (i < DRAW_ROW)
	{
		j = 0;
		while (j < DRAW_COL)
		{
			if (i % 6 == 0 || j % 12 == 0 || (j-1) % 12 == 0)
				mvaddch(start_y + i, start_x + j, ' ' | COLOR_PAIR(1));
			else
				mvaddch(start_y + i, start_x + j, ' ' | COLOR_PAIR(3));
			j++;
		}
		i++;
	}
}

void reset_board(t_data *d)
{
	reset_game_board(d->grid);
	reset_draw_board(d->start_y, d->start_x);
}
