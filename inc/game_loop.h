/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:13:04 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/15 19:33:57 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_LOOP_H
# define GAME_LOOP_H

# include <ncurses.h>
# include <stdlib.h>
# include <stdbool.h>

# define ESC 27
# define GAME_BOARD_SIZE 4
# define CELL_H 6
# define CELL_W 17
# define CELL_IN_W 15
# define DRAW_ROW 25
# define DRAW_COL 70

/// Bu terminal resize yapılırken nereyi çizdiğini
// Kaybetmemesi için 
typedef enum e_state
{
	STATE_MENU,
	STATE_GAME,
	STATE_QUIT
}	t_state;

typedef struct s_data
{
	t_state	print_state;
	int		score;
	int		window_row;
	int		window_col;
	int		start_y;
	int		start_x;
	int		board[4][4];
}	t_data;

void	game_loop(t_data *d);

#endif
