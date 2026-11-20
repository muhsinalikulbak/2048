/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 01:51:34 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/20 21:54:57 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reset_board.h"
#include "draw.h"

static void	reset_game_board(int board[4][4])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = 0;
		}
	}
}

static void	draw_static_map(int start_y, int start_x)
{
	for (int i = 0; i < DRAW_ROW; i++)
	{
		for (int j = 0; j < DRAW_COL; j++)
		{
			if (i % 6 == 0 || j % 12 == 0 || (j - 1) % 12 == 0)
				mvaddch(start_y + i, start_x + j, ' ' | COLOR_PAIR(PAIR_WALL));
			else
				mvaddch(start_y + i, start_x + j, ' ' | COLOR_PAIR(PAIR_EMPTY));
		}
	}
}

void	reset_board(t_data *d)
{
	erase();
	bkgd(' ' | COLOR_PAIR(PAIR_EMPTY));
	reset_game_board(d->board);
	draw_static_map(d->start_y, d->start_x);
	
	d->score = 0;
	spawn_tile(d);
	spawn_tile(d);
	draw_left_menu();
	print_2048_fire(d);
	draw_score(d);
	draw_board(d->board, d->start_y, d->start_x);

	refresh();
}
