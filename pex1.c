/** pex1.c
 * =============================================================
 * Name: David Petzold
 * Section:  T 6/7
 * Project:  PEX 1
 * Purpose:  Utilizes the Curses Library to create and edit a program in order to understand
*            the basics of user-defined methods and calls.
 * Documentation Statement:  Referenced the PEX1 assignment sheet & "Curses Reference Guide.pdf"
 * ============================================================= */

//! Note to self: (0, 0) is the top left

// Include the Curses library
#include <ncurses.h>


//Prototypes:
void drawLine(int beginRow, int beginCol, int length, bool isHorizontal); //Draws line of length "length" starting from beginRow, beginCol
void signWork();    //Signs work with "Created with Curses by David Petzold"


// Put Your Main Function Here
int main(void){

    initscr();  //! Required by curses to initialize

    //Some bullshit here...

    //Wait for keystroke then end
    move(23, 10);
    printw("Press a key to continue: ");
    getch();

    endwin();   //! Required by curses to close

    return 0;
}

//Method definitions: