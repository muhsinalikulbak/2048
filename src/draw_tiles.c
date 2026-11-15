#include "../inc/draw_screens.h"

static void	num_to_str(char buffer[20], int num)
{
	int	len;
	int	cpy;

	cpy = num;
	len = 0;
	while (cpy > 0)
	{
		cpy /= 10;
		len++;
	}
	buffer[len--] = '\0';
	while (num > 0)
	{
		buffer[len--] = (char)(num % 10 + '0');
		num /= 10;
	}
}

static int	tile_pair(int value)
{
	int	n;

	n = 0;
	while (value > 2)
	{
		value /= 2;
		n++;
	}
	return (TILE_PAIR + n % TILE_COLORS);
}

static void	draw_tile(t_data *d, int i, int j)
{
	char	buffer[20];
	int		k;
	int		y;
	int		x;

	if (d->board[i][j] == 0)
		return ;
	num_to_str(buffer, d->board[i][j]);
	y = d->start_y + i * 6 + 3;
	x = d->start_x + j * 12 + 2;
	k = 0;
	while (buffer[k])
	{
		mvaddch(y, x + k, buffer[k] | COLOR_PAIR(tile_pair(d->board[i][j]))
			| A_BOLD);
		k++;
	}
}

void	draw_tiles(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < GAME_BOARD_SIZE)
	{
		j = 0;
		while (j < GAME_BOARD_SIZE)
		{
			draw_tile(d, i, j);
			j++;
		}
		i++;
	}
}
