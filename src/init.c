#include "init.h"
#include "libft.h"

// initscr : screen'i başlatır
// curs_set : imleci gizler, 1 = silik, 2 = tam gösterir
// noecho : Basılan tuşların ekrana basılmasını engeller

// nodelay : getch fonksiyonu normalde bloklar (veri bekler), bloklamadan veri alabilmeyi sağlar
// Ama bu oyunda gerekli değil çünkü 2048 zaten olay tabanlı bir oyun.
// Yani bloklanması sorun teşkil etmez. Çünkü oyun kullanıcıdan intput aldıkça ilerler.
// Yani oyunun kendisi zaten bloklanarak ilerliyor.

// cbreak : Tuşlar enter beklenmeden okunur, normalde enter'a basılması gerekir.  
// keypad : Yön ve fonksiyon tuşlarını aktif eder (esc, arrow keys vs)
// set_escdelay : ESC tuşundaki 1 saniyelik bekleme gecikmesini 25 milisaniyeye indirir

void	update_size(t_data *d)
{
	d->window_col = 0;
	d->window_row = 0;

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
	int	black;

	if (!has_colors())
		return (false);
	start_color();
	use_default_colors();
	black = COLOR_BLACK;
	if (COLORS >= 256)
		black = 16;

	init_pair(PAIR_2, COLOR_WHITE, black);
	init_pair(PAIR_4, COLOR_YELLOW, black);
	init_pair(PAIR_8, COLOR_GREEN, black);
	init_pair(PAIR_16, COLOR_CYAN, black);
	init_pair(PAIR_32, COLOR_BLUE, black);
	init_pair(PAIR_64, COLOR_MAGENTA, black);
	init_pair(PAIR_128, COLOR_RED, black);

	init_pair(PAIR_WALL, COLOR_BLACK, COLOR_RED);
	init_pair(PAIR_EMPTY, black, black);
	init_pair(PAIR_MENU, COLOR_CYAN, black);
	init_pair(PAIR_TITLE, 198, black);

	return (true);
}

bool    init(t_data *d)
{
	init_screen();
	update_size(d);
    srand(time(NULL));
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

	
	// win value kontrolü yapılacak
	d->win_value = WIN_VALUE;
	d->score = 0;
	d->won = false;
    return true;
}


int     get_key(t_data *d, state draw_state)
{
	int key = getch();

	if (key == KEY_RESIZE)
	{
		timeout(20);
		key = getch();
		update_size(d);
		if (draw_state == STATE_MENU)
			draw_menu(d);
		else if (draw_state == STATE_GAME)
		{
			erase();
			draw_static_map(d->start_y, d->start_x);
			draw_board(d->board, d->start_y, d->start_x);
			draw_left_menu();
			draw_score(d);
			draw_2048_fire(d);
		}
	}
	return key;
}
