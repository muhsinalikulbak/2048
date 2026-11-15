/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 01:51:34 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/15 17:57:58 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/reset_board.h"

void	reset_board(t_data *d)
{
	int	i;
	int	j;

	d->score = 0;
	d->won = false;
	i = 0;
	while (i < GAME_BOARD_SIZE)
	{
		j = 0;
		while (j < GAME_BOARD_SIZE)
		{
			d->board[i][j] = 0;
			j++;
		}
		i++;
	}
}
