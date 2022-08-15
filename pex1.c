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
void drawLine(int beginRow, int beginCol, int length, int isHorizontal); //Draws line of length "length" starting from beginRow, beginCol
void signWork();    //Signs work with "Created with Curses by David Petzold"
void initials();    //Draws my initials

// Put Your Main Function Here
int main(void){

    int artDecision;
    int startX, startY, length, horizontality; //If the line is horizontal == 1...if it is vertical == 0



    //Let user decide what type of 'art' they would like to see...
    printf("What type of \"art\" would you like to see today? Press 1 to draw a singular line or press 2 to see my initials: ");
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

    } else if (artDecision == 2){

        //Start Curses
        initscr();

        //Start some color stuff for Curses
        start_color();
        init_pair(BLACK_WHITE, COLOR_BLACK, COLOR_WHITE);
        init_pair(WHITE_BLUE, COLOR_WHITE, COLOR_BLUE);
        wbkgd(stdscr, COLOR_PAIR(BLACK_WHITE));

        //Draw the user's line and sign the work
        drawLine(startX, startY, length, horizontality);
        signWork();

    }

    //Start curses


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