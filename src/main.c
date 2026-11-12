/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:21:07 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/12 19:02:30 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "game_loop.h"
#include "libft.h"

// initscr : screen'i başlatır
// curs_set : imleci gizler, 1 = silik, 2 = tam gösterir
// noecho : Basılan tuşların ekrana basılmasını engeller

// nodelay : getch fonksiyonu normalde bloklar (veri bekler), bloklamadan veri alabilmeyi sağlar
// cbreak : Tuşlar enter beklenmeden okunur, normalde enter'a basılması gerekir.  
// keypad : Yön ve fonksiyon tuşlarını aktif eder (esc, arrow keys vs)
// set_escdelay : ESC tuşundaki 1 saniyelik bekleme gecikmesini 25 milisaniyeye indirir

static void	init_screen(void)
{
	initscr();
	curs_set(0);
	noecho();
	nodelay(stdscr, TRUE);
	cbreak();
	keypad(stdscr, TRUE);
	set_escdelay(25);
}

static bool	init_colors(void)
{
	if (!has_colors())
		return (false);
	start_color();
	use_default_colors();
	init_pair(2, COLOR_WHITE,  COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(8, COLOR_GREEN,  COLOR_BLACK);
	init_pair(16, COLOR_CYAN,   COLOR_BLACK);
	init_pair(32, COLOR_BLUE,   COLOR_BLACK);
	init_pair(64, COLOR_MAGENTA,COLOR_BLACK);
	init_pair(128, COLOR_RED,    COLOR_BLACK);
	return (true);
}

static bool	create_rows(char **board, int board_size)
{
	int	i;

	i = 0;
	while (board[i])
	{
		board[i] = ft_calloc(board_size + 1, sizeof(char));
		if (!board[i])
		{
			i--;
			while (i >= 0)
			{
				if (board[i])
					free(board[i]);
				i--;
			}
			free(board);
			board = NULL;
			return (false);
		}
		board[i][board_size] = '\0';
		i++;
	}
	return (true);
}

static void	print_movable(char	*str, int row)
{
	int	i;
	int len;
	int	speed;

	speed = 100;
	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		mvaddch(row, (COLS - len) / 2 + i, str[i]);
		mvaddch(row, (COLS - len) / 2 + len - i - 1, str[len - 1 - i]);
		refresh();
		i++;
		napms(speed);
	}
}

static int	menu()
{
	int		i;
	int		key;
	// char	*game_name;
	char	*quit;
	char	*start_five;
	char	*start_four;

	i = 0;
	key = 0;
	// game_name = "-2048-";
	start_four = "1: Start with 4x4";
	start_five = "2: Start with 5x5";
	quit = "3: Quit          ";

	erase();
	bkgd(COLOR_PAIR(1));
	print_movable("Welcome 2048", i++);
	
	// mvprintw(i++, (COLS - ft_strlen(game_name)) / 2, "%s", game_name);
	mvprintw(i++, (COLS - ft_strlen(start_four)) / 2, "%s", start_four);
	mvprintw(i++, (COLS - ft_strlen(start_five)) / 2, "%s", start_five);
	mvprintw(i++, (COLS - ft_strlen(quit)) / 2, "%s", quit);
	refresh();

	while (key != '1' && key != '2' && key != '3')
		key = getch();
	return key;
}

static bool is_valid_key(int key)
{
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
		return (true);
	
	if (key == ESC || key == 'R')
		return (true);
	return (false);
}

int	main(void)
{
	t_data	d;
	int		key;

	init_screen();
	d.support_color = init_colors();
	d.board_size = 5;
	d.drawing_board = ft_calloc(sizeof(char *), d.board_size + 1);
	if (!d.drawing_board)
		return (1);
	d.drawing_board[d.board_size] = NULL;
	create_rows(d.drawing_board, d.board_size);
	

	while (true)
	{
		key = menu();
		if (key == '1')
		{
			// game_board ve draw_board'ı oluştur.
			// game_board'a random iki yere 2 koy.

			while (true)
			{
				erase();
				// çizimi yap

				refresh();
				key = getch();
				while (!is_valid_key(key))
					key = getch();
				
				if (key == 'R')
				{
					// game_board'u sıfırla
				}
				else if (key == ESC)
				{
					// İki board'u free et
					break;
				}
				
				// Ok yönlerine göre ilgili fonksiyona git ve game_board'u değiştir
			}
			
		}
		else if (key == '2')
		{
			// while (true)
			// {
			// 	/* code */
			// }
			
		}
		else
			break;
	}
	
	endwin();
	return (0);
}
