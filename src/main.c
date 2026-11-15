/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:21:07 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/15 17:13:48 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_loop.h"
#include "../libft/libft.h"
#include "../inc/reset_board.h"
#include "../inc/draw.h"

static int	wait_menu(t_data *d)
{
	int	key;

	draw_show(d, STATE_MENU);
	key = draw_getch(d);
	while (key != ' ' && key != ESC)
		key = draw_getch(d);
	return (key);
}

static bool	is_valid_key(int key)
{
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
		return (true);
	if (key == ESC || key == 'R')
		return (true);
	return (false);
}

int	main(void)
{
	t_data	d;
	int		key;

	if (draw_init(&d) == 1)
	{
		ft_putendl_fd("Color is unsupported", 2);
		return (1);
	}
	key = 0;
	while (key != ESC)
	{
		key = wait_menu(&d);
		if (key == ESC)
			break ;
		reset_board(&d);
		draw_show(&d, STATE_GAME);
		while (true)
		{
			key = draw_getch(&d);
			while (!is_valid_key(key))
				key = draw_getch(&d);
			if (key == ESC)
			{
				// İki board'u free et
				break ;
			}
			else if (!draw_fits(&d))
				continue ;
			else if (key == 'R')
			{
				reset_board(&d);
				draw_redraw(&d);
			}
			else
			{
				// Burada game(key) fonksiyonuna gidilecek
				// int res = game(key);
				// res -1 ise oyun biter,
				// res 0 ise bir şey değişmemiştir
				// res 1 ise değişiklik var
				// res 2 ise değişiklik var ve 2048'e ulaşıldı
				// değişiklik varsa: draw_redraw(&d);
			}
		}
	}
	draw_end();
	return (0);
}
