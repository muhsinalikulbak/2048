/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 01:51:34 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/19 14:47:38 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reset_board.h"
#include "print.h"

static void	reset_game_board(int board[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < BOARD_SIZE)
	{
		j = 0;
		while (j < BOARD_SIZE)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

static void	draw_static_map(int start_y, int start_x)
{
	int	i;
	int	j;

	i = 0;
	while (i < DRAW_ROW)
	{
		j = 0;
		while (j < DRAW_COL)
		{
			if (i % 6 == 0 || j % 12 == 0 || (j - 1) % 12 == 0)
				mvaddch(start_y + i, start_x + j, ' ' | COLOR_PAIR(1));
			else
				mvaddch(start_y + i, start_x + j, ' ' | COLOR_PAIR(3));
			j++;
		}
		i++;
	}
}

void	reset_board(t_data *d)
{
	erase();
	bkgd(COLOR_PAIR(3));
	reset_game_board(d->board);
	draw_static_map(d->start_y, d->start_x);
	
	spawn_tile(d);
	draw_board(d->board, d->start_y, d->start_x);

	refresh();
}
