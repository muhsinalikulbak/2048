#ifndef DRAW_SCREENS_H
# define DRAW_SCREENS_H

# include "game_loop.h"

# define PAIR_BORDER 1
# define PAIR_EMPTY 3
# define PAIR_TEXT 5
# define TILE_PAIR 10
# define TILE_COLORS 7

void	draw_menu_screen(t_data *d, bool animate);
void	draw_board_screen(t_data *d);
void	draw_warning_screen(t_data *d);
void	draw_tiles(t_data *d);

#endif
