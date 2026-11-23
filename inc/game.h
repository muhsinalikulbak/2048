/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:13:04 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/23 01:43:14 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <ncurses.h>
# include <stdlib.h>
# include <stdbool.h>

# define ESC 27
# define BOARD_SIZE 4
# define DRAW_ROW 25
# define DRAW_COL 50

/// Bu terminal resize yapılırken nereyi çizdiğini
// Kaybetmemesi için 
typedef enum e_state
{
	STATE_MENU,
	STATE_GAME,
	STATE_QUIT
}	state;

enum e_const
{
	WIN_VALUE = 2048
};

enum e_pair
{
	PAIR_EMPTY = 3,
	PAIR_2 = 2,
	PAIR_4 = 4,
	PAIR_8 = 8,
	PAIR_16 = 16,
	PAIR_32 = 32,
	PAIR_64 = 64,
	PAIR_128 = 128,
	PAIR_WALL = 1,
	PAIR_MENU = 129,
	PAIR_TITLE = 5
};

typedef struct s_data
{
	state	print_state;
	int		win_value;
	bool	won;
	int		score;
	int		window_row;
	int		window_col;
	int		start_y;
	int		start_x;
	int		board[4][4];
}	t_data;
#endif
