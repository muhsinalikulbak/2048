#include "draw.h"
#include "libft.h"
#include "reset_board.h"
#include "init.h"

void	print_2048_fire(t_data *d)
{
	static const char	*lines[] = {
		"    )    )      )  (      ",
		" ( /( ( /(   ( /(  )\\ (   ",
		" )(_)))\\())  )\\())((_))\\  ",
		"((_) ((_)\\  ((_)\\   _((_) ",
		"|_  )/  (_)| | (_) ( _ )  ",
		" / /| () | |_  _|  / _ \\  ",
		"/___|\\__/    |_|   \\___/ "
	};

	int	start_y = d->start_y - 10;
	int start_x = (d->window_col - 25) / 2;
	
	
	attron(COLOR_PAIR(PAIR_TITLE));
	attron(A_BOLD);
	for (int i = 0; i < 7; i++)
	{
		mvaddstr(start_y + i, start_x, lines[i]);
	}
	attroff(A_BOLD);
	attroff(COLOR_PAIR(PAIR_TITLE));
	refresh();
}

void	print_2048_diagonal(int window_row, int window_col)
{
	static const char	*lines[] = {
		"                                          ,---.-,",
		"                                   ,--,  '   ,'  '.",
		"      ,----,     ,----..         ,--.'| /   /      \\",
		"    .'   .' \\   /   /   \\     ,--,  | :.   ;  ,/.  :",
		"  ,----,'    | /   .     : ,---.'|  : ''   |  | :  ;",
		"  |    :  .  ;.   /   ;.  \\;   : |  | ;'   |  ./   :",
		"  ;    |.'  /.   ;   /  ` ;|   | : _' ||   :       ,",
		"  `----'/  ; ;   |  ; \\ ; |:   : |.'  | \\   \\     /",
		"    /  ;  /  |   :  | ; | '|   ' '  ; :  ;   ,   '\\",
		"   ;  /  /-, .   |  ' ' ' :\\   \\  .'. | /   /      \\",
		"  /  /  /.`| '   ;  \\; /  | `---`:  | '.   ;  ,/.  :",
		"./__;      :  \\   \\  ',  /       '  ; |'   |  | :  ;",
		"|   :    .'    ;   :    /        |  : ;'   |  ./   :",
		";   | .'        \\   \\ .'         '  ,/ |   :      /",
		"`---'            `---`           '--'   \\   \\   .'",
		"                                         `---`-'"
	};

	int	start_y = (window_row - 16) / 2;
	int	start_x = (window_col - 52) / 2;

	attron(COLOR_PAIR(PAIR_4));
	attron(A_BOLD);
	for (int i = 0; i < 16; i++)
	{
		mvaddstr(start_y + i, start_x, lines[i]);
		refresh();
	}
	attroff(A_BOLD);
	attroff(COLOR_PAIR(PAIR_4));

	for (int i = 0; i < 16; i++)
	{
		attron(COLOR_PAIR(PAIR_TITLE));
		attron(A_BOLD);
		mvaddstr(start_y + i, start_x, lines[i]);
		attroff(A_BOLD);
		attroff(COLOR_PAIR(PAIR_TITLE));
		refresh();
		napms(60);

		attron(COLOR_PAIR(PAIR_4));
		attron(A_BOLD);
		mvaddstr(start_y + i, start_x, lines[i]);
		attroff(A_BOLD);
		attroff(COLOR_PAIR(PAIR_4));
		refresh();

	}
	refresh();
}

void	clear_cell_row(int start_y, int start_x, int draw_y, int draw_x)
{
	for (int i = 0; i < 10; i++)
	{
			mvaddch(start_y + draw_y, start_x + draw_x + i, ' ' | COLOR_PAIR(PAIR_EMPTY));
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
	int len = ft_strlen(str_num) + ft_strlen(str);

	attron(COLOR_PAIR(PAIR_MENU));
	attron(A_BOLD);

	mvaddstr(0, (d->window_col - len) / 2, str);
	mvaddstr(0, (d->window_col - len) / 2 + ft_strlen(str), str_num);

	attroff(COLOR_PAIR(PAIR_MENU));
	attroff(A_BOLD);
}

void	draw_left_menu()
{
	attron(COLOR_PAIR(PAIR_MENU));
	attron(A_BOLD);
	
	mvaddstr(0, 0, "Menu: ESC");
	mvaddstr(1, 0, "Restart: R");

	attroff(COLOR_PAIR(PAIR_MENU));
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

			pair = board[i][j] > 128 ? PAIR_128 : board[i][j];
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
		mvaddch(row, (window_col - len) / 2 + i, str[i] | COLOR_PAIR(PAIR_TITLE) | A_BOLD);
		mvaddch(row, (window_col - len) / 2 + len - i - 1, str[len - 1 - i] | COLOR_PAIR(PAIR_TITLE) | A_BOLD);
		refresh();
		napms(speed);
	}
	if (len % 2 == 1)
		mvaddch(row, (window_col - len) / 2 + len/2, str[len/2] | COLOR_PAIR(PAIR_TITLE) | A_BOLD);
	refresh();
}

void	draw_menu(t_data *d)
{
	int		i;
	char	*quit;
	char	*start;
	char	*start_name;

	i = 0;
	start = "SPACE: Start";
	quit = "ESC: Quit";
	start_name = "WELCOME 2048 MADE IT BY Mkulbak";

	bkgd(' ' | COLOR_PAIR(PAIR_EMPTY));
	erase();
	refresh();

	attron(COLOR_PAIR(PAIR_TITLE));
	attron(A_BOLD);

	mvaddstr(i++, (d->window_col - ft_strlen(start_name)) / 2, start_name);
	mvaddstr(i++, (d->window_col - ft_strlen(start)) / 2, start);
	mvaddstr(i++, (d->window_col - ft_strlen(quit)) / 2, quit);
	attroff(COLOR_PAIR(PAIR_TITLE));
	attroff(A_BOLD);
	refresh();
}
