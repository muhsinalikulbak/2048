#include "../inc/game_loop.h"
#include "../inc/reset_board.h"
#include "../inc/draw.h"
#include "../inc/move_board.h"
#include <time.h>

static int	wait_menu(t_data *d)
{
	int	key;

	draw_show(d, STATE_MENU);
	flushinp();
	key = draw_getch(d);
	while (key != ' ' && key != ESC)
		key = draw_getch(d);
	return (key);
}

static bool	is_valid_key(int key)
{
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
		return (true);
	if (key == ESC || key == 'R' || key == 'r')
		return (true);
	return (false);
}

static void	start_game(t_data *d)
{
	reset_board(d);
	spawn_tile(d);
	spawn_tile(d);
	draw_show(d, STATE_GAME);
}

static bool	wait_over(t_data *d)
{
	int	key;

	draw_show(d, STATE_OVER);
	while (true)
	{
		key = draw_getch(d);
		if (key == ESC)
			return (true);
		else if (key == 'R' || key == 'r' || key == ' ')
		{
			start_game(d);
			return (false);
		}
	}
}

static bool	wait_win(t_data *d)
{
	int	key;

	draw_show(d, STATE_WIN);
	while (true)
	{
		key = draw_getch(d);
		if (key == ' ')
		{
			if (!has_move(d))
				return (wait_over(d));
			draw_show(d, STATE_GAME);
			return (false);
		}
		else if (key == ESC)
			return (true);
	}
}

static bool	handle_result(t_data *d, int res)
{
	if (res == 0)
		return (false);
	else if (res == 1)
		draw_redraw(d);
	else if (res == 2)
		return (wait_win(d));
	else if (res == -1)
		return (wait_over(d));
	return (false);
}

// Sol üstte
// ESC : EXIT
// R : Restart a game,
// iki satırlık ek menü düşünmüştüm
static void	play(t_data *d)
{
	int	key;

	while (true)
	{
		key = draw_getch(d);
		while (!is_valid_key(key))
			key = draw_getch(d);
		if (key == ESC)
			break ;
		else if (!draw_fits(d))
			continue ;
		else if (key == 'R' || key == 'r')
			start_game(d);
		else if (handle_result(d, move_board(d, key)))
			return ;
	}
}

void	game_loop(t_data *d)
{
	srand(time(NULL));
	if (wait_menu(d) == ESC)
		return ;
	start_game(d);
	play(d);
}
