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

static void	reset_draw_board()
{
	int	i;
	int	j;

	i = 0;
	while (i < DRAW_ROW)
	{
		j = 0;
		while (j < DRAW_COL)
		{
			if (i % 6 == 0 || j % 6 == 0)
				mvaddch(START_Y + i, START_X + j, ' ' | COLOR_PAIR(1));
			else
				mvaddch(START_Y + i, START_X + j, ' ' | COLOR_PAIR(3));
			j++;
		}
		i++;
	}
	// mvaddch(START_Y + 3, START_X + 3, '3' | COLOR_PAIR(2));
}

void reset_board(t_data *d)
{
	reset_game_board(d->grid);
	reset_draw_board();
}
