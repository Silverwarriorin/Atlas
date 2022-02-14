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
    wprintw(win,"This program requires a 30x90 Terminal");
    wmove(win,5,2);
    wprintw(win,"Press Any Key To Continue");
    touchwin(win);
    wrefresh(win);
    getchar();
}

void credits() {
    const char* dev[] = {"______               _                      _   _            ",
                       "|  _  \\             | |                    | | | |           ",
                       "| | | |_____   _____| | ___  _ __   ___  __| | | |__  _   _  ",
                       "| | | / _ \\ \\ / / _ \\ |/ _ \\| '_ \\ / _ \\/ _` | | '_ \\| | | | ",
                       "| |/ /  __/\\ V /  __/ | (_) | |_) |  __/ (_| | | |_) | |_| | ",
                       "|___/_\\___|_\\_/ \\___|_|\\___/| .__/ \\___|\\__,_| |_.__/ \\__, | ",
                       "| | / / ___ \\ \\ / | \\ / / | | | | |                    __/ | ",
                       "| |/ /| |_/ /\\ V / \\ V /| | |_|_| |__  ___            |___/  ",
                       "|    \\|    /  \\ /  /   \\| |/ _` | '_ \\/ __|                  ",
                       "| |\\  \\ |\\ \\  | | / /^\\ \\ | (_| | |_) \\__ \\                  ",
                       "\\_| \\_|_| \\_| \\_/ \\/   \\/_|\\__,_|_.__/|___/                  "};

    const char* atlas[] = {" .----------------. .----------------. .----------------. ",
                           "| .--------------. | .--------------. | .--------------. |",
                           "| |      __      | | |  _________   | | |   _____      | |",
                           "| |     /  \\     | | | |  _   _  |  | | |  |_   _|     | |",
                           "| |    / /\\ \\    | | | |_/ | | \\_|  | | |    | |       | |",
                           "| |   / ____ \\   | | |     | |      | | |    | |   _   | |",
                           "| | _/ /    \\ \\_ | | |    _| |_     | | |   _| |__/ |  | |",
                           "| ||____|  |____|| | |   |_____|    | | |  |________|  | |",
                           "| |              | | |              | | |              | |",
                           "| '--------------' | '--------------' | '--------------' |",
                           " '----------------' '----------------' '----------------' ",
                           " .----------------. .----------------. .----------------. ",
                           "| .--------------. | .--------------. | .--------------. |",
                           "| |      __      | | |    _______   | | |      _       | |",
                           "| |     /  \\     | | |   /  ___  |  | | |     | |      | |",
                           "| |    / /\\ \\    | | |  |  (__ \\_|  | | |     | |      | |",
                           "| |   / ____ \\   | | |   '.___`-.   | | |     | |      | |",
                           "| | _/ /    \\ \\_ | | |  |`\\____) |  | | |     | |      | |",
                           "| ||____|  |____|| | |  |_______.'  | | |     |_|      | |",
                           "| |              | | |              | | |     (_)      | |",
                           "| '--------------' | '--------------' | '--------------' |",
                           " '----------------' '----------------' '----------------' "};
    init_pair(1,COLOR_MAGENTA,COLOR_MAGENTA);
    init_pair(2,COLOR_CYAN,COLOR_BLACK);
    init_pair(3,COLOR_BLACK,COLOR_BLACK);

    WINDOW *win = newwin(30,90,1,1);
    wattron(win, COLOR_PAIR(1));
    box(win, '*', '*');
    touchwin(win);
    wrefresh(win);


    // Sets the text color and prints the "Developed by KRYXlabs
    wattron(win, COLOR_PAIR(2));
    for (int i = 0; i < 11; ++i) {
        wmove(win,5+i,10);
        wprintw(win,dev[i]);
        touchwin(win);
        wrefresh(win);
        msleep(100);
    }

    msleep(3000);

    // Does the same thing but with black test to erase it
    wattron(win, COLOR_PAIR(3));
    for (int i = 0; i < 11; ++i) {
        wmove(win,5+i,10);
        wprintw(win,dev[i]);
        touchwin(win);
        wrefresh(win);
        msleep(100);
    }

    msleep(1000);

    // Draws the ATLAS logo
    wattron(win, COLOR_PAIR(2));
    for (int i = 0; i < 22; ++i) {
        wmove(win,4+i,15);
        wprintw(win,atlas[i]);
        touchwin(win);
        wrefresh(win);
        msleep(100);
    }





    getchar();
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


