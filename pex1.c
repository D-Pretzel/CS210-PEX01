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
//? Maybe make a color method that does...something...idk yet

// Put Your Main Function Here
int main(void){

    int startX, startY, length;
    bool horizontality; //If the line is horizontal == 1...if it is vertical == 0

    //Get user input for the ONE line they are allocated...
    printf("You may draw only ONE line because the programmer is lazy...\n");
    scanf("Please enter a starting x-coordinate, starting y-coordingate, and length (in order): %i %i %i", &startX, &startY, &length);
    scanf("Now enter whether the line is horizontal or not (a \'1\' is horizontal and a \'0\' is vertical): %i", &horizontality);

    //Start curses
    initscr();  //! Required by curses to initialize

    /* SOME BULLSHIT HERE */

    //Wait for keystroke then end
    move(23, 10);
    printw("Press a key to continue: ");
    getch();

    endwin();   //! Required by curses to close

    return 0;
}

//Method definitions: