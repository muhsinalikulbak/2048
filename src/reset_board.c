#include "../inc/reset_board.h"

void	reset_board(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < GAME_BOARD_SIZE)
	{
		j = 0;
		while (j < GAME_BOARD_SIZE)
		{
			d->grid[i][j] = 0;
			j++;
		}
		i++;
	}
}
