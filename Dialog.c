//
// Created by Gabriel Womelsdorf on 2/12/22.
//

#include <ncurses.h>
#include <locale.h>
#include <time.h>
#include <errno.h>

int msleep(long msec)
{
    struct timespec ts;
    int res;

    if (msec < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}



void startupdia() {
    init_pair(1,COLOR_MAGENTA,COLOR_MAGENTA);
    init_pair(2,COLOR_MAGENTA,COLOR_BLACK);

    WINDOW *win = newwin(10,43,1,1);
    wattron(win, COLOR_PAIR(1));
    box(win, '*', '*');

    //wmove(win,width/2,(height-strlen("This program requires a 70x100 Terminal"))/2);
    wmove(win,4,2);
    wattron(win, COLOR_PAIR(2));
    wprintw(win,"This program requires a 70x225 Terminal");
    wmove(win,5,2);
    wprintw(win,"Press Any Key To Continue");
    touchwin(win);
    wrefresh(win);
    getchar();
}

void credits() {
    const char* atlas[21] = {"          _____                _____                    _____            _____                    _____          ","         /\\    \\              /\\    \\                  /\\    \\          /\\    \\                  /\\    \\         ","        /::\\    \\            /::\\    \\                /::\\____\\        /::\\    \\                /::\\    \\        ","       /::::\\    \\           \\:::\\    \\              /:::/    /       /::::\\    \\              /::::\\    \\       ","      /::::::\\    \\           \\:::\\    \\            /:::/    /       /::::::\\    \\            /::::::\\    \\      ","     /:::/\\:::\\    \\           \\:::\\    \\          /:::/    /       /:::/\\:::\\    \\          /:::/\\:::\\    \\     ","    /:::/__\\:::\\    \\           \\:::\\    \\        /:::/    /       /:::/__\\:::\\    \\        /:::/__\\:::\\    \\    ","   /::::\\   \\:::\\    \\          /::::\\    \\      /:::/    /       /::::\\   \\:::\\    \\       \\:::\\   \\:::\\    \\   ","  /::::::\\   \\:::\\    \\        /::::::\\    \\    /:::/    /       /::::::\\   \\:::\\    \\    ___\\:::\\   \\:::\\    \\  "," /:::/\\:::\\   \\:::\\    \\      /:::/\\:::\\    \\  /:::/    /       /:::/\\:::\\   \\:::\\    \\  /\\   \\:::\\   \\:::\\    \\ ","/:::/  \\:::\\   \\:::\\____\\    /:::/  \\:::\\____\\/:::/____/       /:::/  \\:::\\   \\:::\\____\\/::\\   \\:::\\   \\:::\\____\\","\\::/    \\:::\\  /:::/    /   /:::/    \\::/    /\\:::\\    \\       \\::/    \\:::\\  /:::/    /\\:::\\   \\:::\\   \\::/    /"," \\/____/ \\:::\\/:::/    /   /:::/    / \\/____/  \\:::\\    \\       \\/____/ \\:::\\/:::/    /  \\:::\\   \\:::\\   \\/____/ ","          \\::::::/    /   /:::/    /            \\:::\\    \\               \\::::::/    /    \\:::\\   \\:::\\    \\     ","           \\::::/    /   /:::/    /              \\:::\\    \\               \\::::/    /      \\:::\\   \\:::\\____\\    ","           /:::/    /    \\::/    /                \\:::\\    \\              /:::/    /        \\:::\\  /:::/    /    ","          /:::/    /      \\/____/                  \\:::\\    \\            /:::/    /          \\:::\\/:::/    /     ","         /:::/    /                                 \\:::\\    \\          /:::/    /            \\::::::/    /      ","        /:::/    /                                   \\:::\\____\\        /:::/    /              \\::::/    /       ","        \\::/    /                                     \\::/    /        \\::/    /                \\::/    /        ","         \\/____/                                       \\/____/          \\/____/                  \\/____/         "};

    init_pair(1,COLOR_MAGENTA,COLOR_MAGENTA);
    init_pair(2,COLOR_MAGENTA,COLOR_BLACK);

    WINDOW *win = newwin(70,225,1,1);
    wattron(win, COLOR_PAIR(1));
    box(win, '*', '*');
    touchwin(win);
    wrefresh(win);

    wattron(win, COLOR_PAIR(2));
    wmove(win,5,5);
    wprintw(win," ,-----.                        ,--.            ,--.    ,--.               ,--. ,--.,------.,--.   ,--.,--.   ,--.,--.        ,--.           ");
    wmove(win,6,5);
    wprintw(win,"'  .--./,--.--. ,---.  ,--,--.,-'  '-. ,---.  ,-|  |    |  |-.,--. ,--.    |  .'   /|  .--. '\\  `.'  /  \\  `.'  / |  | ,--,--.|  |-.  ,---.  ");
    wmove(win,7,5);
    wprintw(win,"|  |    |  .--'| .-. :' ,-.  |'-.  .-'| .-. :' .-. |    | .-. '\\  '  /     |  .   ' |  '--'.' '.    /    .'    \\  |  |' ,-.  || .-. '(  .-'  ");
    wmove(win,8,5);
    wprintw(win,"'  '--'\\|  |   \\   --.\\ '-'  |  |  |  \\   --.\\ `-' |    | `-' | \\   '      |  |\\   \\|  |\\  \\    |  |    /  .'.  \\ |  |\\ '-'  || `-' |.-'  `) ");
    wmove(win,9,5);
    wprintw(win," `-----'`--'    `----' `--`--'  `--'   `----' `---'      `---'.-'  /       `--' '--'`--' '--'   `--'   '--'   '--'`--' `--`--' `---' `----'  ");
    wmove(win,10,5);
    wprintw(win,"                                                              `---'                                                                          ");
    touchwin(win);
    wrefresh(win);

    msleep(2500);


    for (int i = 0; i < 21; ++i) {
        wmove(win,30+i,20);
        wprintw(win,atlas[i]);
        touchwin(win);
        wrefresh(win);
        msleep(500);
    }





    getch();
    endwin();

}
void startup() {
    // Initialize the screen
    initscr();
    start_color();
    keypad(stdscr, TRUE);
    noecho();
    startupdia();
    credits();
    refresh();
    getch();
    endwin();


}



int main() {


    setlocale(LC_ALL, "");
    startup();
    return 0;
}


