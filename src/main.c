/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:21:07 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/17 19:55:00 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "game_loop.h"
#include "libft.h"
#include "reset_board.h"
#include "print.h"
#include "move_board.h"
#include "init.h"

// initscr : screen'i başlatır
// curs_set : imleci gizler, 1 = silik, 2 = tam gösterir
// noecho : Basılan tuşların ekrana basılmasını engeller

// nodelay : getch fonksiyonu normalde bloklar (veri bekler), bloklamadan veri alabilmeyi sağlar
// cbreak : Tuşlar enter beklenmeden okunur, normalde enter'a basılması gerekir.  
// keypad : Yön ve fonksiyon tuşlarını aktif eder (esc, arrow keys vs)
// set_escdelay : ESC tuşundaki 1 saniyelik bekleme gecikmesini 25 milisaniyeye indirir

static bool is_valid_key(int key)
{
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
		return (true);
	
	if (key == ESC || key == 'R' || key == 'r')
		return (true);
	return (false);
}


int	main(void)
{
	t_data	d;
	int		key;
	
	if (!init(&d))
		return 1;

	key = print_menu(d.window_col);
	if (key == ESC)
	{
		endwin();
		return 0;
	}
	reset_board(&d); // reset board zaten random 2 sayı koyacak

	while (key != ESC)
	{
		key = getch();
		while (!is_valid_key(key))
			key = getch();

		if (key == 'R' || key == 'r')  
			reset_board(&d);
		else if (key == ESC)
			break;
		else
		{
			move_board(&d, key, &d.score);
			if (!d.won && has_win(d.board, d.win_value))
			{   
				d.won = true;
				// Burada you win ekranı 
				// Ve devam etmek için SPACE
				// Oyunu sonlandırmak için ESC tuşu koyulacak
			}

			if (!has_move(d.board))
			{
				// Oyun bittiyse eğer Kaybettiniz yazsın ve
				// Menu için ESC, Restart için R basma ekranı gelsin
			}
			print_updated_board(d.board, d.start_y, d.start_x);
			refresh();
		}		
	}
	endwin();
	return (0);
}
