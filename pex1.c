/** pex1.c
 * =============================================================
 * Name: David Petzold
 * Section:  T 6/7
 * Project:  PEX 1
 * Purpose:  Utilizes the Curses Library to create and edit a program in order to understand
*            the basics of user-defined methods and calls.
 * Documentation Statement:  Referenced the PEX1 assignment sheet & "Curses Reference Guide.pdf"
 * ============================================================= */

//! Note to self: (0, 0) is the top left - window size is 23 (R) x 79 (C)

// Include the Curses library
#include <ncurses.h>

// Color Piar Definition
#define BLACK_WHITE 1
#define RED_BLUE 2
#define WHITE_BLUE 3


//Prototypes:
/**
 * @brief Draw a straight vertical or horizontal line in a curses instace
 * @param beginRow coordinate of line's begining row
 * @param beginCol coordinate of line's beginning column
 * @param length how long the line will be
 * @param isHorizontal determines horizontal or vertical line
 * @return void
 * @pre beginRow !> 23 && beginCol !> 79
 * @post will draw a line - all parameters will remain unchnged
 */
void drawLine(int beginRow, int beginCol, int length, int isHorizontal); //Draws line of length "length" starting from beginRow, beginCol

/**
 * @brief sign the curses window
 * @return void
 * @pre no condition
 * @post will sign curses window starting at (20, 5)
 */
void signWork();    //Signs work with "Created with Curses by David Petzold"

/**
 * @brief draws initials on curses window
 * @return void
 * @pre none
 * @post none
 */
void initials();    //Draws my initials

// Put Your Main Function Here
int main(void){

    int artDecision;
    int startX, startY, length, horizontality; //If the line is horizontal == 1...if it is vertical == 0

    //Let user decide what type of 'art' they would like to see...
    printf("What type of \"art\" would you like to see today? Press 1 to draw a singular line or press 2 to see my first initial: ");
    scanf("%i", &artDecision);

    if (artDecision == 1){

        //Get user input for the ONE line they are allocated...
        printf("\nYou may draw only ONE line because \"art\" is subjective and the programmer is lazy...\n\n");
        printf("Please enter a starting x-coordinate, starting y-coordinate, and length (in order, space-separated, without commas): ");
        scanf("%i %i %i", &startX, &startY, &length);
        printf("Now enter whether the line is horizontal or not (a \'1\' is horizontal and a \'0\' is vertical): ");
        scanf("%i", &horizontality);

        //Start Curses
        initscr();

        //Start some color stuff for Curses
        start_color();
        init_pair(BLACK_WHITE, COLOR_BLACK, COLOR_WHITE);
        init_pair(RED_BLUE, COLOR_RED, COLOR_BLUE);
        wbkgd(stdscr, COLOR_PAIR(BLACK_WHITE));

        //Draw the user's line and sign the work
        drawLine(startX, startY, length, horizontality);
        signWork();

    } else if (artDecision == 2) {

        //Start Curses
        initscr();

        //Start some color stuff for Curses
        start_color();
        init_pair(BLACK_WHITE, COLOR_BLACK, COLOR_WHITE);
        init_pair(WHITE_BLUE, COLOR_WHITE, COLOR_BLUE);
        wbkgd(stdscr, COLOR_PAIR(BLACK_WHITE));

        //Draw my first initial and sign the work
        initials();
        signWork();

    }

    //Wait for keystroke then end
    move(23, 5);
    printw("Press a key to continue: ");
    getch();

    endwin();   //! Required by curses to close

    return 0;
}

//Method definitions:
void drawLine(int beginRow, int beginCol, int length, int isHorizontal){

    attron(COLOR_PAIR(RED_BLUE));

    move(beginRow, beginCol);
    if (isHorizontal == 1) {

        for (int i = 1; i < length + 1; i++) {
            printw(" ");
            move(beginRow, beginCol + i);
        }

    } else {

        for (int i = 1; i < length + 1; i++) {
            printw(" ");
            move(beginRow + i, beginCol);
        }
    }

    attroff(COLOR_PAIR(RED_BLUE));
}

void signWork(){
    move(20, 5);
    printw("Creaded with Curses by David Petzold.\n");
}

void initials(){

    attron(WHITE_BLUE);
    move(5, 5);
    printw(" ");

    for (int i = 0; i < 10; i++) {
        move(5 + i, 5);
        printw(" ");
    }

    move(15, 5);
    printw(" ");

    for (int i = 0; i < 5; i++) {
        move(15, 5 + i);
        printw(" ");
    }

    move(15, 10);
    printw(" ");

    for (int i = 0; i < 10; i++) {
        move(15 - i, 10);
        printw(" ");
    }

    move(5, 10);
    printw(" ");

    for (int i = 0; i < 5; i++) {
        move(5, 10 - i);
        printw(" ");
    }
    attroff(WHITE_BLUE);
}