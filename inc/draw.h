/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 01:52:38 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/24 19:20:07 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "game.h"

void	draw_2048_fire(t_data *d);
int     draw_2048_diagonal(int window_row, int window_col);

void	clear_cell_row(int start_y, int start_x, int draw_y, int draw_x);
void	draw_movable(int window_col, char	*str, int row);
void    draw_menu(t_data *d);
void	draw_board(int board[4][4], int start_y, int start_x);
void	draw_left_menu();
void	draw_score(t_data *d);
void    draw_won(t_data *d);
void    draw_game_components(t_data *d);
void    draw_lose(t_data *d);
#endif