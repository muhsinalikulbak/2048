#include "../inc/draw_screens.h"
#include "../libft/libft.h"

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

static void	draw_digit(int y, int x, int digit, int attr)
{
	const char	*font[10][3] = {
	{"┏━┓", "┃┃┃", "┗━┛"}, {"╺┓ ", " ┃ ", "╺┻╸"},
	{"┏━┓", "┏━┛", "┗━╸"}, {"┏━┓", "╺━┫", "┗━┛"},
	{"╻ ╻", "┗━┫", "  ╹"}, {"┏━╸", "┗━┓", "┗━┛"},
	{"┏━┓", "┣━┓", "┗━┛"}, {"┏━┓", "  ┃", "  ╹"},
	{"┏━┓", "┣━┫", "┗━┛"}, {"┏━┓", "┗━┫", "┗━┛"}};
	int			row;

	attron(attr);
	row = 0;
	while (row < 3)
	{
		mvaddstr(y + row, x, font[digit][row]);
		row++;
	}
	attroff(attr);
}

static void	draw_tile(t_data *d, int i, int j)
{
	char	buf[20];
	int		len;
	int		x;
	int		k;

	if (d->board[i][j] == 0)
		return ;
	num_to_str(buf, d->board[i][j]);
	len = ft_strlen(buf);
	x = d->start_x + j * CELL_W + 2 + (CELL_IN_W - len * 3) / 2;
	k = 0;
	while (buf[k])
	{
		draw_digit(d->start_y + i * CELL_H + 2, x + k * 3, buf[k] - '0', COLOR_PAIR(tile_pair(d->board[i][j])) | A_BOLD);
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
