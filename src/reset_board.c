/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 01:51:34 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/17 19:20:55 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reset_board.h"
#include "print.h"

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
	erase();
	bkgd(COLOR_PAIR(3));
	reset_game_board(d->board);
	reset_draw_board(d->start_y, d->start_x);

	// burada mock olarak verildi,
	// Burada iki adet random sayı eklenecek
	d->board[0][0] = 2;
	d->board[1][0] = 2;
	d->board[2][0] = 2;
	d->board[3][0] = 2;

	d->board[0][2] = 2;
	d->board[1][2] = 2;
	d->board[2][2] = 4;
	d->board[3][2] = 2;


	d->board[0][1] = 2;
	d->board[3][1] = 4;
	print_updated_board(d->board, d->start_y, d->start_x);

	refresh();
}
