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
	int	x;
	char	*score_str;
	char	score_buf[32];
	char	*score_label;

	attron(COLOR_PAIR(PAIR_TEXT) | A_BOLD);
	mvaddnstr(0, 0, "ESC: Exit", d->window_col);
	mvaddnstr(1, 0, "R: Restart", d->window_col);
	score_str = ft_itoa(d->score);
	if (score_str)
	{
		score_label = "Score: ";
		ft_strlcpy(score_buf, score_label, sizeof(score_buf));
		ft_strlcat(score_buf, score_str, sizeof(score_buf));
		free(score_str);
		x = (d->window_col - (int)ft_strlen(score_buf)) / 2;
		if (x < 0)
			x = 0;
		mvaddnstr(0, x, score_buf, d->window_col - x);
	}
	attroff(COLOR_PAIR(PAIR_TEXT) | A_BOLD);
	i = 0;
	while (i < DRAW_ROW)
	{
		j = 0;
		while (j < DRAW_COL)
		{
			if (i % CELL_H == 0 || j % CELL_W == 0 || (j - 1) % CELL_W == 0)
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

void	draw_win_overlay(t_data *d)
{
	int	center_y;
	int	center_x;
	char	*msg1;
	char	*msg2;

	center_y = d->window_row / 2;
	center_x = d->window_col / 2;
	msg1 = "YOU WIN!";
	msg2 = "SPACE: continue  ESC: quit";
	attron(COLOR_PAIR(PAIR_TEXT) | A_BOLD);
	mvaddstr(center_y - 1, center_x - ft_strlen(msg1) / 2, msg1);
	mvaddstr(center_y + 1, center_x - ft_strlen(msg2) / 2, msg2);
	attroff(COLOR_PAIR(PAIR_TEXT) | A_BOLD);
}

void	draw_over_overlay(t_data *d)
{
	int	center_y;
	int	center_x;
	char	*msg1;
	char	*msg2;

	center_y = d->window_row / 2;
	center_x = d->window_col / 2;
	msg1 = "GAME OVER";
	msg2 = "R: restart  ESC: quit";
	attron(COLOR_PAIR(PAIR_TEXT) | A_BOLD);
	mvaddstr(center_y - 1, center_x - ft_strlen(msg1) / 2, msg1);
	mvaddstr(center_y + 1, center_x - ft_strlen(msg2) / 2, msg2);
	attroff(COLOR_PAIR(PAIR_TEXT) | A_BOLD);
}
