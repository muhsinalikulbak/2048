/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 16:26:31 by mtaheri           #+#    #+#             */
/*   Updated: 2026/11/15 17:13:40 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/draw.h"
#include "../inc/draw_screens.h"

static void	render(t_data *d, bool animate)
{
	getmaxyx(stdscr, d->window_row, d->window_col);
	d->start_y = (d->window_row - DRAW_ROW) / 2;
	d->start_x = (d->window_col - DRAW_COL) / 2;
	erase();
	if (d->print_state == STATE_MENU)
		draw_menu_screen(d, animate);
	else if (d->print_state == STATE_GAME && draw_fits(d))
		draw_board_screen(d);
	else if (d->print_state == STATE_GAME)
		draw_warning_screen(d);
	refresh();
}

void	draw_show(t_data *d, t_state state)
{
	d->print_state = state;
	render(d, true);
}

void	draw_redraw(t_data *d)
{
	render(d, false);
}

int	draw_getch(t_data *d)
{
	int	key;

	key = getch();
	if (key == KEY_RESIZE)
	{
		clearok(stdscr, TRUE);
		draw_redraw(d);
		return (ERR);
	}
	return (key);
}

bool	draw_fits(t_data *d)
{
	return (d->start_y >= 0 && d->start_x >= 0);
}
