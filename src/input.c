#include "input.h"

int     get_key(t_data *d, state draw_state)
{
	int key = getch();

	if (key != KEY_RESIZE)
		return key;
	if (key == KEY_RESIZE)
	{
		timeout(30);
		key = getch();
	}
	timeout(-1);
	redraw(d, draw_state);
	if (key == ERR)
		key = getch();
	return key;
}
