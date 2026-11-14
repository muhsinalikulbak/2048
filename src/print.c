#include "print.h"
#include "libft.h"
#include "reset_board.h"

// str parse without call malloc
static void	str_parse(char buffer[20], int num)
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

void    print_updated_board(int board[4][4], int start_y, int start_x)
{
	int		i;
	int		j;
	int		k;
	int		draw_y;
	int		draw_x;
	char	buffer[20];

	i = 0;
	j = 0;
	k = 0;
	draw_y = 0;
	draw_x = 0;
	while (i < 4)
	{
		j = 0;
		draw_y = i * 6 + 3;
		while (j < 4)
		{
			draw_x = j * 12 + 2;
			reset_cell(start_y, start_x, draw_y, draw_x);
			str_parse(buffer, board[i][j]);
			k = 0;
			while (buffer[k])
			{
				mvaddch(start_y + draw_y, start_x + draw_x + k, buffer[k] | COLOR_PAIR(board[i][j]) | A_BOLD);
				k++;
			}
			j++;
		}
		i++;
	}
	
}


void	print_movable(int window_col, char	*str, int row)
{
	int	i;
	int len;
	int	speed;

	speed = 100;
	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		mvaddch(row, (window_col - len) / 2 + i, str[i]);
		mvaddch(row, (window_col - len) / 2 + len - i - 1, str[len - 1 - i]);
		refresh();
		i++;
		napms(speed);
	}
}

int	print_menu(int start_x)
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
	print_movable(start_x, "Welcome 2048 Made it by Mtaheri & Mkulbak", i++);
	mvprintw(i++, (start_x - ft_strlen(start)) / 2, "%s", start);
	mvprintw(i++, (start_x - ft_strlen(quit)) / 2, "%s", quit);
	attroff(COLOR_PAIR(5));
	attroff(A_BOLD);
	refresh();

	while (key != ' ' && key != ESC)
		key = getch();
	return key;
}
