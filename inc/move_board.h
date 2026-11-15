/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_board.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 21:29:00 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/15 21:29:00 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_BOARD_H
# define MOVE_BOARD_H

# include "game_loop.h"

int	move_up(t_data *d);
int	move_down(t_data *d);
int	move_left(t_data *d);
int	move_right(t_data *d);
int	has_move(t_data *d);
int	has_win(t_data *d);
void	spawn_tile(t_data *d);
int	move_board(t_data *d, int key);

#endif
