/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:21:07 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/12 11:34:55 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h> 
#include <stdio.h>

enum COLORS
{
	PAIR_DEFAULT = 1,
};

// screen'i başlatır
// imleci gizler, 1 = silik, 2 = tam gösterir
// Basılan tuşların ekrana basılmasını engeller

// getch fonksiyonu normalde bloklar (veri bekler),
// bloklamadan veri alabilmeyi sağlar

// Tuşlar enter beklenmeden okunur, normalde enter'a basılması gerekir.

static void	init_screen(void)
{
	initscr();
	curs_set(0);
	noecho();
	nodelay(stdscr, TRUE);
	cbreak();
}

static void	init_colors(void)
{
	if (has_colors())
	{
		start_color();
		use_default_colors();
		init_pair(PAIR_DEFAULT, COLOR_WHITE, COLOR_BLACK);
	}
}

static bool	create_rows(char **board, int board_size)
{
	int	i;

	i = 0;
	while (board[i])
	{
		board[i] = calloc(sizeof(char), board_size + 1);
		if (!board[i])
		{
			i--;
			while (i >= 0)
			{
				if (board[i])
					free(board[i]);
				i--;
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

int	main(void)
{
	int		board_size;
	char	**board;

	board_size = 10;
	board = calloc(board_size + 1, sizeof(char *));
	if (!board)
		return (1);
	board[board_size] = NULL;
	init_screen();
	init_colors();



	bool blue = false;
	for (int i = 0; i < board_size; i++)
	{
		blue = !blue;
		for (int j = 0; j < board_size; j++)
		{
			if (blue)
			{
				if (j % 2 == 0)
					mvaddch(i, j, '2' | COLOR_PAIR(1));
				else
					mvaddch(i, j, '2' | COLOR_PAIR(2));
			}
			else
			{
				if (j % 2 == 0)
					mvaddch(i, j, '2' | COLOR_PAIR(2));
				else
					mvaddch(i, j, '2' | COLOR_PAIR(1));
			}
		}
		napms(1000);
		refresh();
	}
	endwin();
	return 0;
}
