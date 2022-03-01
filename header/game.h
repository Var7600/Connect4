/**
 *@Author : DOUDOU DIAWARA
 *@verison : 1.0 (Mars 2022)
 *@Github : https://github.com/DD7600
 *
 *this file contains all declarations macros,variables,functions to implements Connect 4 game
 */

#ifndef GAME_H
#define GAME_H

#define LINES 6
#define COLUMNS 7
#define CHAR_SYMBOL_PLY1 'O'
#define CHAR_SYMBOL_PLY2 'X'
#define NEWLINE putchar('\n')
#define SPACE putchar(' ')
#define CHAR_SYMBOL_MULT putchar('*')
#define CHAR_SYMBOL_SUB putchar('-')
#define CHAR_SYMBOL_ADD putchar('+')
#define CHAR_SYMBOL_DIV putchar('|')
#define PLY1 "Player O(SELECT A COLUMN) : "
#define PLY2 "Player X(SELECT A COLUMN) : "
#define TIPS "TIPS: if you wanna quit during a game just press -1"
#define NO_AVAILABLE "Column is full!PLEASE CHOOSE ANOTHER ONE"
#define DRAW "Oops No Winner this time! draw"
#define WINNER(COLOR_PLY,PLY,COLOR_NORMAL) printf("Player %s%c%s has Won %s:)\n%s",COLOR_PLY,PLY,COLOR_NORMAL,COLOR_PLY,COLOR_NORMAL)
#define	QUIT_GAME "Are you sure  you wanna QUIT this party?[y(Y)/n(N)]: "
#define CONFIRM_QUIT "please select y or n to confirm your choice!\n"
#define YES 'y'
#define NO 'n'
//COLOR OUTPUT
#define COLOR_RED  "\x1B[1;31m"
#define COLOR_YELLOW  "\x1B[1;33m"
#define COLOR_NORMAL  "\x1B[0m"
//Extern variable declaration
extern char *purpose;
extern char *option ;
extern char *game_option;
extern int matrix[LINES][COLUMNS];/*game matrix*/

//Extern function declaration

extern void defaultMatrix(void);/*initialisation of the matrix*/

extern void menu(void);/*menu */

extern int choiceMenu(void); /*option*/

extern int gameOption(void) ; /*choose your game option*/

extern void flush(void); /*empty the buffer after each call of scanf*/

extern void position(void);/*position of each column*/

extern void row(void);/*row of grid*/

extern void column(void);/*column of grid*/

extern void show(void);/*display grid at beginning*/

extern int scanner(const char *);/*input players*/

extern int indexLine(const int); /*insertion at line index*/

extern int columnFull(int column); /*check column is full*/

extern int indexColumn(const int); /*insertion at column index*/

extern int indexRow(const int,const int); /*line to insert*/

extern void showGrid(void);/*displays contents of the grid*/

extern int matrixLineWin(int) ; /*check if a player has win horizontaly if, int > 2 means a winner*/

extern int matrixColumnWin(int) ; /*check if a player has win verticaly,int > 2 means a winner*/

extern int matrixDiagonalWin(int) ; /*check diagonals for winner*/

extern int matrixDraw(void) ; /*check if the match ended with a draw*/

extern int status(int) ; /*check the status of the game o*/

extern int play(const char*, const char*); /*loop game*/

#endif

