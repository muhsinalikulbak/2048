/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 01:52:38 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/15 01:55:04 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H
# include "game_loop.h"

void	print_movable(int window_col, char	*str, int row);
int		print_menu(int start_x);
void	print_updated_board(int board[4][4], int start_y, int start_x);

#endif