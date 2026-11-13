/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:13:04 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/14 01:22:59 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_LOOP_H
# define GAME_LOOP_H

# include <ncurses.h>
# include <stdlib.h>
# include <stdbool.h>

# define ESC 27
# define GAME_BOARD_SIZE 4
# define DRAW_ROW 25
# define DRAW_COL 50
# define START_Y (LINES - DRAW_ROW) / 2
# define START_X (COLS - DRAW_COL) / 2


/// Bu terminal resize yapılırken nereyi çizdiğini
// Kaybetmemesi için 
typedef enum e_state
{
	STATE_MENU,
	STATE_GAME
}	t_state;

typedef struct s_data
{
	t_state	print_state;
	int		score;
	int		rows;
	int		cols;
	int		grid[4][4];
}	t_data;
#endif
