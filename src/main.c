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

static void	put_test_tiles(t_data *d)
{
	d->board[0][0] = 2;
	d->board[1][0] = 4;
	d->board[2][0] = 8;
	d->board[3][0] = 16;
	d->board[0][3] = 32;
	d->board[2][1] = 64;
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
		put_test_tiles(&d);
		draw_show(&d, STATE_GAME);
		while (true)
		{
			key = draw_getch(&d);
			while (!is_valid_key(key))
				key = draw_getch(&d);
			// Sol üstte
			// ESC : EXIT
			// R : Restart a game,
			// iki satırlık ek menü düşünmüştüm
			if (key == ESC)
				break ;
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
				// res 2 ise 2048'e ulaşıldığnı belirticek ve
				// bir ekran açılacak, devam etmek istiyorsa SPACE, bitirmek istiyorsa ESC'ye basacak
				// değişiklik varsa: draw_redraw(&d);
			}
		}
	}
	draw_end();
	return (0);
}
