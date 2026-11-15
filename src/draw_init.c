#include <locale.h>
#include "../inc/draw.h"
#include "../inc/draw_screens.h"

static bool	init_colors(void)
{
	if (!has_colors())
		return (false);
	start_color();
	use_default_colors();
	init_pair(TILE_PAIR + 0, COLOR_WHITE, COLOR_BLACK);
	init_pair(TILE_PAIR + 1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(TILE_PAIR + 2, COLOR_GREEN, COLOR_BLACK);
	init_pair(TILE_PAIR + 3, COLOR_CYAN, COLOR_BLACK);
	init_pair(TILE_PAIR + 4, COLOR_BLUE, COLOR_BLACK);
	init_pair(TILE_PAIR + 5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(TILE_PAIR + 6, COLOR_RED, COLOR_BLACK);
	init_pair(PAIR_BORDER, COLOR_BLACK, COLOR_RED);
	init_pair(PAIR_EMPTY, COLOR_BLACK, COLOR_BLACK);
	init_pair(PAIR_TEXT, 198, -1);
	return (true);
}

// initscr : screen'i başlatır
// curs_set : imleci gizler, 1 = silik, 2 = tam gösterir
// noecho : Basılan tuşların ekrana basılmasını engeller

// cbreak : Tuşlar enter beklenmeden okunur, normalde enter'a basılması gerekir.
// keypad : Yön ve fonksiyon tuşlarını aktif eder (esc, arrow keys vs)
// set_escdelay : ESC tuşundaki 1 saniyelik bekleme gecikmesini 25 milisaniyeye indirir
static void	init_screen(void)
{
	setlocale(LC_ALL, "");
	initscr();
	curs_set(0);
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	set_escdelay(25);
}

int	draw_init(t_data *d)
{
	init_screen();
	if (!init_colors())
	{
		endwin();
		return (1);
	}
	bkgd(COLOR_PAIR(PAIR_EMPTY));
	d->print_state = STATE_MENU;
	return (0);
}

