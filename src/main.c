/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:21:07 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/19 01:06:46 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "game.h"
#include "libft.h"
#include "reset_board.h"
#include "print.h"
#include "move_board.h"
#include "game_status.h"
#include "init.h"

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
			draw_board(d.board, d.start_y, d.start_x);
			refresh();

			if (!d.won && has_win(d.board, d.win_value))
			{   
				d.won = true;
				// Burada you win ekranı 
				// Ve devam etmek için SPACE
				// Oyunu sonlandırmak için ESC tuşu koyulacak

				// Devam ediyorsa win yazısını silmek için
				erase();
				draw_board(d.board, d.start_y, d.start_x);
			}

			if (!has_valid_move(d.board))
			{
				// Oyun bittiyse eğer Kaybettiniz yazsın ve
				// Menu için ESC, Restart için R basma ekranı gelsin
				mvaddstr(LINES / 2, (COLS - ft_strlen("FINISH")) / 2, "FINISH");
				// break;
			}
		}		
	}
	endwin();
	return (0);
}
