/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_boards.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 00:08:33 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/13 01:00:46 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_boards.h"
#include "libft.h"

static bool	create_draw_rows(char **board, int board_size)
{
	int	i;

	i = 0;
	while (board[i])
	{
		board[i] = (char *)ft_calloc(board_size + 1, sizeof(char));
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
		board[i][board_size] = '\0';
		i++;
	}
	return (true);
}

static bool	create_game_rows(int **board, int board_size)
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

static void	free_all(void *ptr, int height)
{
	void	**arr;
	int		i;

	if (!ptr)
		return ;
	arr = (void **)ptr;
	i = 0;
	while (i < height)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
}

bool	create_boards(t_data *d)
{
	d->drawing_board = calloc(DRAWING_BOARD_SIZE + 1, sizeof(char *));
	if (!d->drawing_board)
		return (false);
	d->game_board = calloc(GAME_BOARD_SIZE + 1, sizeof(int *));
	if (!d->game_board)
	{
		if (d->drawing_board)
			free(d->drawing_board);
		return (false);
	}
	d->drawing_board[DRAWING_BOARD_SIZE] = NULL;
	d->game_board[GAME_BOARD_SIZE] = NULL;
	if (!create_game_rows(d->game_board, GAME_BOARD_SIZE))
	{
		free(d->drawing_board);
		return (false);
	}
	if (!create_draw_rows(d->drawing_board, DRAWING_BOARD_SIZE))
	{
		free_all(d->game_board, GAME_BOARD_SIZE);
		return (false);
	}
	return (true);
}
