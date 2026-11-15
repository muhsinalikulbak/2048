/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 16:26:55 by mtaheri           #+#    #+#             */
/*   Updated: 2026/11/15 17:10:57 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <ncurses.h>
# include "game_loop.h"

int		draw_init(t_data *d);
void	draw_end(void);
void	draw_show(t_data *d, t_state state);
void	draw_redraw(t_data *d);
int		draw_getch(t_data *d);
bool	draw_fits(t_data *d);

#endif
