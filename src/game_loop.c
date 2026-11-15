#include "../inc/game_loop.h"
#include "../inc/reset_board.h"
#include "../inc/draw.h"
#include "../inc/move_board.h"
#include <time.h>

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

// Sol üstte
// ESC : EXIT
// R : Restart a game,
// iki satırlık ek menü düşünmüştüm
static void	play(t_data *d)
{
	int	key;
	int	res;

	while (true)
	{
		key = draw_getch(d);
		while (!is_valid_key(key))
			key = draw_getch(d);
		if (key == ESC)
			break ;
		else if (!draw_fits(d))
			continue ;
		else if (key == 'R')
		{
			reset_board(d);
			spawn_tile(d);
			spawn_tile(d);
			draw_redraw(d);
		}
		else
		{
			res = move_board(d, key);
			if (res != 0)
				draw_redraw(d);
			if (res == -1)
				break ;
			if (res == 2)
			{
				// Win screen logic here
			}
		}
	}
}

void	game_loop(t_data *d)
{
	srand(time(NULL));
	while (wait_menu(d) != ESC)
	{
		reset_board(d);
		spawn_tile(d);
		spawn_tile(d);
		draw_show(d, STATE_GAME);
		play(d);
	}
}
