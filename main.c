#include <ncurses.h>

int main(void)
{
    int y = 0;
    int x = 0;

    initscr();              // curses modunu başlat
    curs_set(0);
    nodelay(stdscr, TRUE);

    for (size_t i = 0; i <= 50; i++)
    {
        clear();
        char ch = 'o';
        mvaddch(y,x+i, ch);
        refresh();
        napms(100);     
        int key = getch();

        if (key == 'q')
            break;
    }
    
    endwin();               // terminali eski haline döndür
    return 0;
}