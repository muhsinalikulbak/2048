#ifndef INIT_H
# define INIT_H
#include "game.h"
#include <time.h>
#include <draw.h>   
#include "reset_board.h"

bool    init(t_data *d);
void	update_size(t_data *d);
int     get_key(t_data *d, state draw_state);

#endif