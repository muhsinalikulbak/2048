#include "../inc/draw.h"

static bool	init_colors(void)
{
	if (!has_colors())
		return (false);
	start_color();
	use_default_colors();
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(8, COLOR_GREEN, COLOR_BLACK);
	init_pair(16, COLOR_CYAN, COLOR_BLACK);
	init_pair(32, COLOR_BLUE, COLOR_BLACK);
	init_pair(64, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(128, COLOR_RED, COLOR_BLACK);
	init_pair(1, COLOR_BLACK, COLOR_BLUE);
	init_pair(3, COLOR_BLACK, COLOR_BLACK);
	init_pair(5, 198, -1);
	return (true);
}

// initscr : screen'i başlatır
// curs_set : imleci gizler, 1 = silik, 2 = tam gösterir
// noecho : Basılan tuşların ekrana basılmasını engeller

// nodelay : getch fonksiyonu normalde bloklar (veri bekler), bloklamadan veri alabilmeyi sağlar
// cbreak : Tuşlar enter beklenmeden okunur, normalde enter'a basılması gerekir.
// keypad : Yön ve fonksiyon tuşlarını aktif eder (esc, arrow keys vs)
// set_escdelay : ESC tuşundaki 1 saniyelik bekleme gecikmesini 25 milisaniyeye indirir
static void	init_screen(void)
{
	initscr();
	curs_set(0);
	noecho();
	nodelay(stdscr, TRUE);
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
	d->print_state = STATE_MENU;
	return (0);
}

void	draw_end(void)
{
	endwin();
}
