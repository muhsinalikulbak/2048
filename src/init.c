#include "init.h"
#include "libft.h"

// initscr : screen'i başlatır
// curs_set : imleci gizler, 1 = silik, 2 = tam gösterir
// noecho : Basılan tuşların ekrana basılmasını engeller

// nodelay : getch fonksiyonu normalde bloklar (veri bekler), bloklamadan veri alabilmeyi sağlar
// cbreak : Tuşlar enter beklenmeden okunur, normalde enter'a basılması gerekir.  
// keypad : Yön ve fonksiyon tuşlarını aktif eder (esc, arrow keys vs)
// set_escdelay : ESC tuşundaki 1 saniyelik bekleme gecikmesini 25 milisaniyeye indirir

void	update_size(t_data *d)
{
	getmaxyx(stdscr, d->window_row, d->window_col);
	d->start_y = (d->window_row - DRAW_ROW) / 2;
	d->start_x = (d->window_col - DRAW_COL) / 2;
}

static void	init_screen(void)
{
	initscr();
	curs_set(0); // terminal küçükken burada kod patlıyor neden anlamadım buraya bak
	noecho();
	nodelay(stdscr, TRUE);
	cbreak();
	keypad(stdscr, TRUE);
	set_escdelay(25);
}

static bool	init_colors(void)
{
	if (!has_colors())
		return (false);
	start_color();
	use_default_colors();
	init_pair(2, COLOR_WHITE,  COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(8, COLOR_GREEN,  COLOR_BLACK);
	init_pair(16, COLOR_CYAN,   COLOR_BLACK);
	init_pair(32, COLOR_BLUE,   COLOR_BLACK);
	init_pair(64, COLOR_MAGENTA,COLOR_BLACK);
	init_pair(128, COLOR_RED,    COLOR_BLACK);

	init_pair(1, COLOR_BLACK, COLOR_RED);
	init_pair(3, COLOR_BLACK, COLOR_BLACK);
	init_pair(5, 198, -1);

	return (true);
}

bool    init(t_data *d)
{
	init_screen();
	update_size(d);
	if (!init_colors())
	{
		endwin();
		ft_putendl_fd("Color is unsupported", 2);
		return false;
	}
	if (d->start_x < 0 || d->start_y < 0)
	{
		endwin();
		ft_putendl_fd("Terminal scale is unsupported", 2);
		return false;
	}

	// Burada define win value'yu parse et
	// int olabilirysa değişkene ata
	// edilemiyorsa oto 2048 ata
	d->won = false;
    return true;
}
