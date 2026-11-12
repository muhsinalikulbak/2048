/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:13:04 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/12 18:50:43 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_LOOP_H
# define GAME_LOOP_H

# include <ncurses.h>
# include <stdlib.h>
# include <stdbool.h>

#define ESC 27

typedef struct s_data
{
	int		board_size;
	bool	support_color;
	char	**drawing_board;
	int		**game_board;
}	t_data;
#endif
