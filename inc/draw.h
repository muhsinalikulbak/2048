/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 16:26:55 by mtaheri           #+#    #+#             */
/*   Updated: 2026/11/15 21:06:03 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <ncurses.h>
# include "game_loop.h"

int		draw_init(t_data *d);
void	draw_show(t_data *d, t_state state);
void	draw_redraw(t_data *d);
int		draw_getch(t_data *d);
bool	draw_fits(t_data *d);

#endif
