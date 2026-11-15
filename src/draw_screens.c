#include "../inc/draw_screens.h"
#include "../libft/libft.h"

static void	print_centered(t_data *d, int row, char *str)
{
	int	x;

	if (row < 0 || row >= d->window_row)
		return ;
	x = (d->window_col - (int)ft_strlen(str)) / 2;
	if (x < 0)
		x = 0;
	mvaddnstr(row, x, str, d->window_col - x);
}

static void	print_movable(t_data *d, char *str, int row)
{
	int	i;
	int	len;
	int	x;

	len = ft_strlen(str);
	x = (d->window_col - len) / 2;
	if (x < 0 || row >= d->window_row)
		return (print_centered(d, row, str));
	i = 0;
	while (i < (len + 1) / 2)
	{
		mvaddch(row, x + i, str[i]);
		mvaddch(row, x + len - i - 1, str[len - 1 - i]);
		refresh();
		i++;
		napms(100);
	}
}

void	draw_menu_screen(t_data *d, bool animate)
{
	char	*title;

	title = "Welcome 2048 Made it by Mtaheri & Mkulbak";
	attron(COLOR_PAIR(PAIR_TEXT) | A_BOLD);
	if (animate)
		print_movable(d, title, 0);
	else
		print_centered(d, 0, title);
	print_centered(d, 1, "SPACE: Start");
	print_centered(d, 2, "ESC: Quit");
	attroff(COLOR_PAIR(PAIR_TEXT) | A_BOLD);
}

void	draw_board_screen(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < DRAW_ROW)
	{
		j = 0;
		while (j < DRAW_COL)
		{
			if (i % 6 == 0 || j % 12 == 0 || (j - 1) % 12 == 0)
				mvaddch(d->start_y + i, d->start_x + j, ' ' | COLOR_PAIR(PAIR_BORDER));
			else
				mvaddch(d->start_y + i, d->start_x + j, ' ' | COLOR_PAIR(PAIR_EMPTY));
			j++;
		}
		i++;
	}
	draw_tiles(d);
}

void	draw_warning_screen(t_data *d)
{
	int	y;

	y = d->window_row / 2 - 1;
	if (y < 0)
		y = 0;
	attron(COLOR_PAIR(PAIR_TEXT));
	print_centered(d, y, "Terminal too small");
	print_centered(d, y + 1, "Make the window bigger");
	attroff(COLOR_PAIR(PAIR_TEXT));
}
