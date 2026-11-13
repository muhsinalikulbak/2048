/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:13:04 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/13 20:15:12 by mkulbak          ###   ########.fr       */
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
# define START_Y (LINES - DRAWING_BOARD_SIZE) / 2
# define START_X (COLS - DRAWING_BOARD_SIZE) / 2

typedef struct s_data
{
	int		board_size;
	int		**game_board;
}	t_data;
#endif
