#include <curses.h>

#define DX 3

int main(int argc, char **argv) {

    if (argc != 2) {
	printf("Enter a file name\n");
	return 1;	
    }

    WINDOW *win;
    int c = 0;

    initscr();
    noecho();
    cbreak();
    printw(argv[1]);
    refresh();

    FILE *f;
    char arr[COLS-3*DX];
    f = fopen(argv[1], "r");

    win = newwin(LINES-2*DX, COLS-2*DX, DX, DX);
    keypad(win, TRUE);
    scrollok (win, TRUE);
    box(win, 0, 0); 
    // wmove(win, 1, 0); 
    while((c = wgetch(win)) != 27) {
        if (c == ' ') {
            werase(win);
	    int count = 0;
            while (fgets(arr, COLS-3*DX, f) != NULL && count++ < LINES-3*DX)
                wprintw(win, "%s\n", arr);
        }
        // wprintw(win, "  Key: %d, Name: %s\n", c, keyname(c));
        box(win, 0, 0); 
        wrefresh(win);
    }
    fclose(f);
    endwin();
    return 0;
}
