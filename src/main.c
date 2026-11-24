/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:21:07 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/24 19:23:05 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "game.h"
#include "libft.h"
#include "reset_board.h"
#include "draw.h"
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

static void game_loop(t_data *d)
{
	int key;

	key = 0;
	while (key != ESC)
	{
		key = get_key(d, STATE_GAME);
		while (!is_valid_key(key))
			key = get_key(d, STATE_GAME);

		if (key == 'R' || key == 'r')  
			reset_board(d);
		else if (key == ESC)
			return;
		else
		{
			move_board(d, key, &d->score);
			draw_game_components(d);
			refresh();

			if (!d->won && has_win(d->board, d->win_value))
			{   
				d->won = true;
				draw_won(d);
				key = get_key(d, STATE_GAME);
				while (key != ' ' && key != ESC)
				{
					draw_won(d);
					key = get_key(d, STATE_GAME);
				}
				
				
				if (key == ESC)
					break;
				erase();
				draw_static_map(d->start_y, d->start_x);
				draw_game_components(d);
			}

			if (!has_valid_move(d->board))
			{
				draw_lose(d);
				key = get_key(d, STATE_GAME);
				while (key != 'R' && key != 'r' && key != ESC)
				{
					draw_lose(d);
					key = get_key(d, STATE_GAME);
				}
				if (key == 'r' || key == 'R')
					reset_board(d);
				else
					break;
			}
		}	
	}
}

int	main(void)
{
	t_data	d;
	int		key;
	
	if (!init(&d))
		return 1;

	draw_movable(d.window_col, "WELCOME 2048 MADE IT BY Mkulbak", 0);
	draw_menu(&d);
	flushinp();
	while (key != ' ' && key != ESC)
	{
		key = draw_2048_diagonal(d.window_row, d.window_col);
		if (key == ' ' || key == ESC)
			break;
		key = get_key(&d, STATE_MENU);
	}

	while (key != ESC)
	{
		reset_board(&d);
		game_loop(&d);
		draw_menu(&d);
		flushinp();
		key = get_key(&d, STATE_MENU);
		while (key != ' ' && key != ESC)
		{
			key = draw_2048_diagonal(d.window_row, d.window_col);
			if (key == ' ' || key == ESC)
				break;
			key = get_key(&d, STATE_MENU);
		}
	}
	endwin();
	return (0);
}
