/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 01:51:34 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/15 02:44:37 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reset_board.h"

void	reset_cell(int start_y, int start_x, int draw_y, int draw_x)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		mvaddch(start_y + draw_y, start_x + draw_x + i, ' ' | COLOR_PAIR(3));
		i++;
	}
}

static void	reset_game_board(int board[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < GAME_BOARD_SIZE)
	{
		j = 0;
		while (j < GAME_BOARD_SIZE)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

static void	reset_draw_board(int start_y, int start_x)
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
	bkgd(COLOR_PAIR(3));
	refresh();
	reset_game_board(d->board);
	reset_draw_board(d->start_y, d->start_x);
}
