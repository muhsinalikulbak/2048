/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:21:07 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/15 02:32:34 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "game_loop.h"
#include "libft.h"
#include "reset_board.h"
#include "print.h"
// initscr : screen'i başlatır
// curs_set : imleci gizler, 1 = silik, 2 = tam gösterir
// noecho : Basılan tuşların ekrana basılmasını engeller

// nodelay : getch fonksiyonu normalde bloklar (veri bekler), bloklamadan veri alabilmeyi sağlar
// cbreak : Tuşlar enter beklenmeden okunur, normalde enter'a basılması gerekir.  
// keypad : Yön ve fonksiyon tuşlarını aktif eder (esc, arrow keys vs)
// set_escdelay : ESC tuşundaki 1 saniyelik bekleme gecikmesini 25 milisaniyeye indirir

static void	update_size(t_data *d)
{
	getmaxyx(stdscr, d->window_row, d->window_col);
	d->start_y = (d->window_row - DRAW_ROW) / 2;
	d->start_x = (d->window_col - DRAW_COL) / 2;
}

static void	init_screen(void)
{
	initscr();
	curs_set(0); // terminal küçükken burada kod patlıyor neden anlamadım buraya bak
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

	init_pair(1, COLOR_BLACK, COLOR_RED);
	init_pair(3, COLOR_BLACK, COLOR_BLACK);
	init_pair(5, 198, -1);

	return (true);
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
	update_size(&d);
	if (!init_colors())
	{
		endwin();
		ft_putendl_fd("Color is unsupported", 2);
		return (1);
	}
	if (d.start_x < 0 || d.start_y < 0)
	{
		endwin();
		ft_putendl_fd("Terminal scale is unsupported", 2);
		return (1);
	}

	key = print_menu(d.window_col);
	if (key == ESC)
	{
		endwin();
		return 0;
	}
	erase();
	reset_board(&d);
	refresh();

	d.board[0][0] = 2;
	d.board[1][0] = 4;
	d.board[2][0] = 8;
	d.board[3][0] = 16;
	d.board[0][3] = 32;
	d.board[2][1] = 64;

	while (key != ESC)
	{
		key = getch();
		while (!is_valid_key(key))
			key = getch();

		// Sol üstte 
		// ESC : EXIT 
		// R : Restart a game,
		// iki satırlık ek menü düşünmüştüm
		if (key == 'R')  
			reset_board(&d);
		else if (key == ESC)
			break;
		else
		{
			// Burada game(key) fonksiyonuna gidilecek
			// int res = game(key);
			// res -1 ise oyun biter,
			// res 0 ise bir şey değişmemiştir
			// res 1 ise değişiklik var
			// res 2 ise 2048'e ulaşıldığnı belirticek ve
			// bir ekran açılacak, devam etmek istiyorsa SPACE, bitirmek istiyorsa ESC'ye basacak

			print_updated_board(d.board, d.start_y, d.start_x);
			refresh();
		}		
	}
	endwin();
	return (0);
}
