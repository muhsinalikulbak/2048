/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:13:04 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/14 01:40:42 by muhsin           ###   ########.fr       */
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
	int		rows;
	int		cols;
	int		start_y;
	int		start_x;
	int		grid[4][4];
}	t_data;
#endif
