/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 01:52:38 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/19 17:08:08 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H
# include "game.h"

void	clear_cell_row(int start_y, int start_x, int draw_y, int draw_x);
void	draw_movable(int window_col, char	*str, int row);
int		draw_menu(int start_x);
void	draw_board(int board[4][4], int start_y, int start_x);
void	draw_left_menu();
void	draw_score(t_data *d);

#endif