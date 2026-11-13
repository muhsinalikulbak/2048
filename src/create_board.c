/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 00:08:33 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/13 01:57:47 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_board.h"
#include "libft.h"

static bool	 create_game_rows(int **board, int board_size)
{
	int	i;

	i = 0;
	while (i < board_size)
	{
		board[i] = (int*)ft_calloc(board_size, sizeof(int));
		if (!board[i])
		{
			while (--i >= 0)
			{
				if (board[i])
					free(board[i]);
			}
			free(board);
			board = NULL;
			return (false);
		}
		i++;
	}
	return (true);
}

bool	create_board(t_data *d)
{
	d->game_board = (int **)ft_calloc(GAME_BOARD_SIZE + 1, sizeof(int *));
	if (!d->game_board)
		return (false);
	d->game_board[GAME_BOARD_SIZE] = NULL;
	if (!create_game_rows(d->game_board, GAME_BOARD_SIZE))
		return (false);
	return (true);
}
