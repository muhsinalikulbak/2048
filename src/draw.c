#include "draw.h"
#include "libft.h"
#include "reset_board.h"

void	clear_cell_row(int start_y, int start_x, int draw_y, int draw_x)
{
	for (int i = 0; i < 10; i++)
	{
		mvaddch(start_y + draw_y, start_x + draw_x + i, ' ' | COLOR_PAIR(3));
	}
}

// str parse without call malloc
static void	int_to_str(char buffer[], int num)
{
	if (num == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return;
	}

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

void	draw_score(t_data *d)
{
	char *str = "Score : ";
	char str_num[20];
	
	int_to_str(str_num, d->score);
	char *join = ft_strjoin(str, str_num);
	int len = ft_strlen(join);

	attron(COLOR_PAIR(129));
	attron(A_BOLD);

	mvaddstr(0, (d->window_col - len) / 2, join);

	attroff(COLOR_PAIR(129));
	attroff(A_BOLD);
	free(join);
}

void	draw_left_menu()
{
	attron(COLOR_PAIR(129));
	attron(A_BOLD);
	
	mvaddstr(0, 0, "Menu: ESC");
	mvaddstr(1, 0, "Restart: R");

	attroff(COLOR_PAIR(129));
	attroff(A_BOLD);
}

void    draw_board(int board[4][4], int start_y, int start_x)
{
	int		mid;
	int		pair;
	int		draw_y;
	int		draw_x;
	char	buffer[20];

	draw_y = 0;
	draw_x = 0;
	for (int i = 0; i < 4; i++)
	{
		draw_y = i * 6 + 3;
		for (int j = 0; j < 4; j++)
		{
			draw_x = j * 12 + 2;
			
			clear_cell_row(start_y, start_x, draw_y, draw_x);
			if (board[i][j] == 0)
				continue;

			pair = board[i][j] > 128 ? 128 : board[i][j];
			int_to_str(buffer, board[i][j]);
			mid = (10 - ft_strlen(buffer)) / 2;

			attron(COLOR_PAIR(pair));
			attroff(A_BOLD);

			mvaddstr(start_y + draw_y, start_x + draw_x + mid, buffer);
			
			attroff(COLOR_PAIR(pair));
			attroff(A_BOLD);
		}
	}
	
}


void	draw_movable(int window_col, char	*str, int row)
{
	int len;
	int	speed;

	speed = 100;
	len = ft_strlen(str);
	for (int i = 0; i < len / 2; i++)
	{
		mvaddch(row, (window_col - len) / 2 + i, str[i]);
		mvaddch(row, (window_col - len) / 2 + len - i - 1, str[len - 1 - i]);
		refresh();
		napms(speed);
	}
}

int	draw_menu(int start_x)
{
	int		i;
	int		key;
	char	*quit;
	char	*start;

	i = 0;
	key = 0;
	start = "SPACE: Start";
	quit = "ESC: Quit";

	erase();
	attron(COLOR_PAIR(5));
	attron(A_BOLD);

	draw_movable(start_x, "WELCOME 2048 MADE IT BY Mkulbak", i++);
	mvaddstr(i++, (start_x - ft_strlen(start)) / 2, start);
	mvaddstr(i++, (start_x - ft_strlen(quit)) / 2, quit);

	attroff(COLOR_PAIR(5));
	attroff(A_BOLD);
	refresh();

	while (key != ' ' && key != ESC)
		key = getch();
	return key;
}
