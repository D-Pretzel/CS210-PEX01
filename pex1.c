/** pex1.c
 * =============================================================
 * Name: David Petzold
 * Section:  T 6/7
 * Project:  PEX 1
 * Purpose:  Utilizes the Curses Library to create and edit a program in order to understand
*            the basics of user-defined methods and calls.
 * Documentation Statement:  Referenced the PEX1 assignment sheet & "Curses Reference Guide.pdf"
 * ============================================================= */

// Include the Curses library
#include <ncurses.h>


// Put Your Drawing Functions Here

// Remember that at least one must use parameters

// Put Your Main Function Here
int main(void){

    initscr();

    move(23, 10);
    printw("press a key to continue");
    getch();

    endwin();

    return 0;
}


