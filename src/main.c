/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:21:07 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/13 01:58:07 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "game_loop.h"
#include "libft.h"
#include "create_board.h"
#include "reset_board.h"

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

	init_pair(1, COLOR_BLACK, COLOR_BLUE);
	init_pair(3, COLOR_BLACK, COLOR_BLACK);
	init_pair(5, 198, -1);

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

static int	print_menu()
{
	int		i;
	int		key;
	char	*quit;
	char	*start;

	i = 0;
	key = 0;
	start = "1: Start";
	quit = "2: Quit";

	erase();
	attron(COLOR_PAIR(5));
	print_movable("Welcome 2048", i++);
	mvprintw(i++, (COLS - ft_strlen(start)) / 2, "%s", start);
	mvprintw(i++, (COLS - ft_strlen(quit)) / 2, "%s", quit);
	attroff(COLOR_PAIR(5));

	refresh();

	while (key != '1' && key != '2')
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
	if (!init_colors())
	{
		endwin();
		ft_putendl_fd("Color is unsupported", 2);
		return (1);
	}
	if (START_X < 0 || START_Y < 0)
	{
		ft_putendl_fd("Terminal scale is unsupported", 2);
		endwin();
		return (1);
	}
	while (true)
	{
		key = print_menu();
		if (key == '2')
			break;
		erase();
		if (!create_board(&d))
		{
			ft_putendl_fd("Calloc error", 2);
			return (1);
		}
		reset_board(&d);
		// İki adet random sayı üret
		// Sayıları buffer'a koy (çiz)
		// Sol üst köşeye -->
		// R = Restart a game
		// ESC = menu

		while (true)
		{
			refresh();
			// Oyun devam edilebilir mi kontrol et ona göre çık
			key = getch();
			while (!is_valid_key(key))
				key = getch();

			if (key == 'R')
				reset_board(&d);
			else if (key == ESC)
			{
				// İki board'u free et
				break;
			}
			
			// Ok yönlerine göre ilgili fonksiyona git ve game_board'u değiştir
		}
	}
	endwin();
	return (0);
}
