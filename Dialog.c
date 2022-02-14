//
// Created by Gabriel Womelsdorf on 2/12/22.
//

#include <ncurses.h>
#include <locale.h>
#include <time.h>

typedef struct _win_border_struct {
    chtype 	ls, rs, ts, bs,
            tl, tr, bl, br;
}WIN_BORDER;

typedef struct _WIN_struct {

    int startx, starty;
    int height, width;
    WIN_BORDER border;
}WIN;

void init_win_params(WIN *p_win);
void print_win_params(WIN *p_win);
void create_box(WIN *win, bool flag);


void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
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

    waitFor(2);







    waitFor(5);
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


