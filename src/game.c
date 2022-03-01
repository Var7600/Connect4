/**
 *@Author : DOUDOU DIAWARA
 *@verison : 1.0 (Mars 2022)
 *@Github : https://github.com/DD7600
 *
 *this file contains all implementations of @file: game.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "game.h"
#include "AI.h"

#define OUTPUT_COLUMN 122
#define FULL 49
#define INVALIDE_OPTION "TRY AGAIN! INVALID OPTION\n"
#define ERR_CONVERSION "Error! please enter a digit\n"
#define ERR_COLUMN "Error!please enter a column between 1 AND 7\n"
#define INVALIDE_RANGE "Error!please select OPTION 1 or 2\n"


char *purpose;
char *option;
char *game_option ;
int matrix[LINES][COLUMNS];


/*
this function initialize the matrix before the game start
*/
void defaultMatrix(void)
{
	for (int i = 0; i < LINES ; i++)
	{
		for (int j = 0 ; j < COLUMNS ; j++ )
		{
			matrix[i][j] = 0;
		}

	}

}


/* this function PRINT THE GAME GOAL AND OPTION*/
void menu(void)
{
	  puts("PS:if the following output is not align correctly just Maximize your Window and restart");

 const char* purpose = "* CONNECT 4 VERSION:1.0\t\t\t\t\t\t\t\t\t\t\t\t\t  *\n* this game is like TIC TOC but POW4 uses a grid of 6x7 6 rows and 7 column each player has 21 X or O symbols to win      *\n\
* A player must align 4 consecutive symbols to win either vertically horizontally or obliquely the grid is vertical which *\n* means that the symbol\t\t\t\t\t\t\t\t\t\t\t\t\t  *\n\
* fall to the bottom of the column chosen by the player\t\t\t\t\t\t\t\t\t  *\n*";

/*message column output*/
 for (int i = 0; i < OUTPUT_COLUMN ;i++ )
	{
		CHAR_SYMBOL_MULT;
    }

	CHAR_SYMBOL_MULT;
    NEWLINE;
	printf("%s",purpose);

    for (int i = 0; i < OUTPUT_COLUMN ;i++ )
	{
       	CHAR_SYMBOL_MULT;
    }

    NEWLINE;
}

/** this function let's player choose game play option
 *1.1P vs 2P : 1player vs 2player
 *2.1P vs IA : 1 player vs IA
 * @return : 1 or 2
 *
 */

int gameOption(void)
{
	int option = 0;

	char *game_option = "===============================\n\
1.1P vs 2P\n\
2.1P vs IA\n\
===============================\n\
option: ";
	do
	{
		printf("%s",game_option);

		if((scanf("%d",&option)) != 1)
		{
			fprintf(stderr,INVALIDE_OPTION);
			fprintf(stderr,ERR_CONVERSION);
			flush(); /*empty buffer*/
		}
		else if(option != 1 && option != 2)
		{
			fprintf(stderr,INVALIDE_RANGE);
			flush(); /*empty buffer*/
		}

	}while(option != 2 && option != 1);

return option;
}
/*
MENU CHOICE
*/
int choiceMenu(void)
{
	int choice = -1 ;
	int ret = 0 ;

	menu(); //menu function

//OPTION MENU
option = "1.Press 1 to start\n\
0.Press 0 to quit\n\
choice: ";

	do
	{
		printf("%s",option);
		ret = scanf("%d",&choice);

		if(ret == 1 && (choice != 0 &&  choice != 1))
		{
			fprintf(stderr,INVALIDE_OPTION);
			flush(); /*empty buffer*/
			ret = 0;
		} else if(ret != 1)
		{
			fprintf(stderr,ERR_CONVERSION);
			flush(); /*empty buffer*/
		}

		//GAME OPTION
		if(choice == 1)
		{
			return gameOption();

		}

	}while((choice != 1 && choice != 0) && ret != 1);

return choice;

}

/*this function show the
POSITON NUMBERS  OF EACH COLUMNS*/
void position(void)
{
	SPACE;
	SPACE;

	for(int x = 1 ; x <= COLUMNS ; x++)
	{
		printf("%d",x);
		SPACE;
		SPACE;
		SPACE;
	}
}

//this function DISPLAY LINES +---+---+---+---+---+---+---+
void row(void)
{
		NEWLINE;

		for(int i = 0 ; i < COLUMNS ; i++)
		{
			CHAR_SYMBOL_ADD;

			for(int j = 0 ; j < 3 ; j++)
			{
			 CHAR_SYMBOL_SUB;
			}
		}
	CHAR_SYMBOL_ADD;
	NEWLINE;
}

//DISPLAYS COLUMNS |  |  |  |  |  |  |  |
void column(void)
{
	for(int i = 0 ; i < LINES ; i++)
	{
	CHAR_SYMBOL_DIV;
    SPACE;
    SPACE;
    SPACE;
	}
	CHAR_SYMBOL_DIV;
}

//DISPLAY GRID AT BEGINNING
void show(void)
{
	position();

	for(int i = 1 ; i <= LINES ; i++)
	{
		row();
		column();
		SPACE;
		SPACE;
		SPACE;
		CHAR_SYMBOL_DIV;
	}

	row();
	position();
	NEWLINE;
}

/*this function clear the buffer before each call of scanf function
*/
void flush(void)
{
	scanf("%*[^\n]");/*read everything on the buffer expect '\n' character*/
	getchar();/*read '\n' character*/
}

/** \brief this function take input from players and check if it is a valid column to insert between 1 and 7
*-q means quit during game
*
* @param : const char *ptr, player1 or player2
*
* @return : return the column chosen , or if -1 return YES or NO
*
*/
int scanner(const char *ptr)
{
	int column = 0 ;
	int ret = 0;
	char quit = 0 ;
	int q = 0;

	do
	{
		printf("%s",ptr);

		if((ret = scanf("%d",&column)) != 1)
		{
			fprintf(stderr,ERR_CONVERSION);
			flush();/*empty buffer*/
		}

		if( ret == 1 )
		{

			/*quit during a game*/
			if(column == -1)
			{
				flush(); //empty buffer

				printf(QUIT_GAME);
				do
				{
					/*to confirm choice*/
					q = scanf("%c",&quit) ;

					if( q != 1 )
					{

						fprintf(stderr,CONFIRM_QUIT);
						flush(); //empty buffer
					}

					if(tolower(quit) == YES)
					{
						return tolower(quit);

					}
					if ( tolower(quit) != NO)
					{

						printf(QUIT_GAME);
					}

				} while(tolower(quit) != YES && tolower(quit) != NO);
			}

				/*not in range column*/
			if(column <= 0 || column >= 8)
			{
				fprintf(stderr,ERR_COLUMN);
				ret = 0;
				flush();/*empty buffer*/
			}
		}


	}while(ret != 1);

return column;

}

/** \brief this function return the current row to insert
 *the second parameter allows to know if we play with the AI or not
 * 1 means we play with the AI no error message otherwise 0 with error message for player
 *
 * @param : int column , column choosen by a player
 * @param : int with_AI, if we play with AI == 2 or not
 * @return : a valid row index or -1 if column is full
 */

int indexRow(int column,int with_AI)
{
	for(int i = LINES - 1 ; i >= 0 ; i-- )
	{
		if(matrix[i][column] != CHAR_SYMBOL_PLY1 && matrix[i][column] != CHAR_SYMBOL_PLY2 )
		{
			return i; //return index row to insert
		}

	}
	if(with_AI == 2)
	{
		puts(NO_AVAILABLE);

	}

return -1;
}

/**
*check if the column in parametre is full .
*return column if not full else return -1
*
* @param : int column , column to check if is empty
* @return : return column otherwise -1
*
*/
int columnFull(int column)
{

	int counter = 0;

	for(int j = 0 ; j < COLUMNS ; j++)
	{
		if (matrix[j][column] == CHAR_SYMBOL_PLY1 || matrix[j][column] == CHAR_SYMBOL_PLY2 )
		{
			counter++;
		}

	}

		if(counter == LINES  ) /*if counter == COLUMNS column is full*/
		{
				return -1;

		} else {

			return column;

		}
}
/** \brief INDEX COLUMN VIEW STARTING AT 0(postion - 1)
 *
 * @param : int column , column chosen by the player
 * @return : int column start at 0
 *
 */

int indexColumn(int pos)
{
	return pos - 1;
}


 //DISPLAYS CONTENTS OF THE GRID
 void showGrid(void)
{
	position();/*position of each columns*/

	for(int i = 0 ; i < LINES ; i++)
	{
		row();

		CHAR_SYMBOL_DIV;

			for( int j = 0 ; j < COLUMNS ; j++)
			{
				 /*Display only palyers select columns*/
				if(matrix[i][j] == CHAR_SYMBOL_PLY1)
				{

					SPACE;
					printf("%s%c%s ",COLOR_RED,matrix[i][j],COLOR_NORMAL);
					CHAR_SYMBOL_DIV;

				} else if(matrix[i][j] == CHAR_SYMBOL_PLY2)
				{
					SPACE;
					printf("%s%c%s ",COLOR_YELLOW,matrix[i][j],COLOR_NORMAL);
					CHAR_SYMBOL_DIV;


				}

				else {

					SPACE;

					SPACE;

					SPACE;

					CHAR_SYMBOL_DIV;

				}

			}

	}
	row();
	position();
	NEWLINE;

}

/**
*his methode check if a player has won by alignement of 4  symbol consecutives
*it's done by checking Horizontaly
*so idea is we only count when there is two contigus symbol
*if we reach 3 or more symbol counting by two then we have a winner ohtherwise we don't
*
* @return : 0 if a winner else -1 non winner
*
 */
int matrixLineWin(int withAI)
{
	/*count players2 symbol at each rows*/
	int symbol_ply1 = 0 ;
	int symbol_ply2 = 0 ;

	for(int i = 0 ; i < LINES ; i++)
	{
		for(int j = 0 ; j < COLUMNS - 1; j++) /*COLUMNS - 1 cause [i][j+1] otherwise j+1 not in range index*/
		{
			if(matrix[i][j] == CHAR_SYMBOL_PLY1 && matrix[i][j+1] == CHAR_SYMBOL_PLY1 ) /*count symbol players by two*/
			{
				symbol_ply1++;

			} else if (matrix[i][j] == CHAR_SYMBOL_PLY2 && matrix[i][j+1] == CHAR_SYMBOL_PLY2 )
			{
				symbol_ply2++;
			}
		}
		/*if we hit 3 or more by counting by two then we have a winner*/
		if(symbol_ply1 > 2)
		{
			WINNER(COLOR_RED,CHAR_SYMBOL_PLY1,COLOR_NORMAL);
			return 0 ;

		} else if(symbol_ply2 > 2)

		{
			if(withAI != 2)
			{
				NEWLINE;
				WINNER(COLOR_YELLOW,CHAR_SYMBOL_PLY2,COLOR_NORMAL);
				return 0 ;

			} else {

				NEWLINE;
				IA_WIN(COLOR_AI,COLOR_NORMAL);
				return 0 ;
			}
		}
/*reset counting for each lines*/
	symbol_ply1 = 0 ;
	symbol_ply2 = 0 ;

	}

	return -1;

}
/**
*his methode check if a player has won by align of 4 symbol consecutives
*it's done by checking vertically
*so idea is we only count when there is two consecutives symbol
*if we reach 3 symbol or more counting by two then we have a winner
*
* @return : return 0 if a winner else -1 not winner
 */
int matrixColumnWin(int with_AI)
{
	/*count player1 symbol at each columns*/
	int symbol_ply1 = 0 ;
	int symbol_ply2 = 0 ;

	for(int i = 0 ; i < COLUMNS ; i++)
	{
		for(int j = 0 ; j < COLUMNS - 1 ; j++) /*COLUMNS - 1 cause [i][j+1] otherwise j+1 not in range index*/
		{
			if(matrix[j][i] == CHAR_SYMBOL_PLY1 && matrix[j+1][i] == CHAR_SYMBOL_PLY1 )
			{
				symbol_ply1++;

			} else if (matrix[j][i] == CHAR_SYMBOL_PLY2 && matrix[j+1][i] == CHAR_SYMBOL_PLY2 )
			{
				symbol_ply2++;

			}
		}

		if(symbol_ply1 > 2)
		{
			NEWLINE;
			WINNER(COLOR_RED,CHAR_SYMBOL_PLY1,COLOR_NORMAL);
			return 0 ;

		} else if(symbol_ply2 > 2)

		{
			if(with_AI != 2)
			{
				NEWLINE;
				WINNER(COLOR_YELLOW,CHAR_SYMBOL_PLY2,COLOR_NORMAL);
				return 0 ;

			} else {

				NEWLINE;
				IA_WIN(COLOR_AI,COLOR_NORMAL);
				return 0 ;
			}
		}

		symbol_ply1 = 0 ;
		symbol_ply2 = 0 ;
	}

	return -1;

}

/**
*this function check if a player has won by alignement of four consecutives symbol on the diagonal
*idea count the diagonal on position ,
*and apply same principles by counting by two who ever hit 3 Win
*
* @param :  return 0 if a winner else -1 not winner
 */
int matrixDiagonalWin(int with_AI)
{
	int symbol_ply1 = 0 ;
	int symbol_ply2 = 0 ;

	/*run the matrix diagonal from 00,11,22.. to 56*/
	for(int i = 0,j = 0 ; i < LINES ; i++,j++)
	{
			if(matrix[j][i] == CHAR_SYMBOL_PLY1 && matrix[j+1][i+1] == CHAR_SYMBOL_PLY1 )
			{
				symbol_ply1++;

			} else if (matrix[j][i] == CHAR_SYMBOL_PLY2 && matrix[j+1][i+1] == CHAR_SYMBOL_PLY2 )
			{
				symbol_ply2++;

			}
	}
		if(symbol_ply1 > 2)
		{
			NEWLINE;
			WINNER(COLOR_RED,CHAR_SYMBOL_PLY1,COLOR_NORMAL);
			return 0;

		} else if(symbol_ply2 > 2)

		{
			if(with_AI != 2)
			{
				NEWLINE;
				WINNER(COLOR_YELLOW,CHAR_SYMBOL_PLY2,COLOR_NORMAL);
				return 0 ;

			} else {

				NEWLINE;
				IA_WIN(COLOR_AI,COLOR_NORMAL);
				return 0 ;
			}

		}
		symbol_ply1 = 0 ;
		symbol_ply2 = 0 ;

		/*run the diagonal  50,41,32,23,14,05 */
		for(int i = LINES - 1,j = 0 ; i >= 0  ; i--,j++)
		{
			if(matrix[i][j] == CHAR_SYMBOL_PLY1 && matrix[i-1][j+1] == CHAR_SYMBOL_PLY1 )
			{
				symbol_ply1++;

			} else if (matrix[i][j] == CHAR_SYMBOL_PLY2 && matrix[i-1][j+1] == CHAR_SYMBOL_PLY2 )
			{
				symbol_ply2++;

			}
		}
		if(symbol_ply1 > 2)
		{
				NEWLINE;
				WINNER(COLOR_RED,CHAR_SYMBOL_PLY1,COLOR_NORMAL);
			return 0 ;

		} else if(symbol_ply2 > 2)

		{
			if(with_AI != 2)
			{
				NEWLINE;
				WINNER(COLOR_YELLOW,CHAR_SYMBOL_PLY2,COLOR_NORMAL);
				return 0 ;

			} else {

				NEWLINE;
				IA_WIN(COLOR_AI,COLOR_NORMAL);
				return 0 ;
			}

		}

		symbol_ply1 = 0 ;
		symbol_ply2 = 0 ;

		/*run the diagonal from 10,21,32,43,54*/
		for(int i = 1,j = 0 ; i < LINES  ; i++,j++)
		{
			if(matrix[i][j] == CHAR_SYMBOL_PLY1 && matrix[i++][j++] == CHAR_SYMBOL_PLY1 )
			{
				symbol_ply1++;

			} else if (matrix[i][j] == CHAR_SYMBOL_PLY2 && matrix[i++][j++] == CHAR_SYMBOL_PLY2 )
			{
				symbol_ply2++;

			}
		}
		if(symbol_ply1 > 2)
		{
				NEWLINE;
				WINNER(COLOR_RED,CHAR_SYMBOL_PLY1,COLOR_NORMAL);
			return 0 ;

		} else if(symbol_ply2 > 2)

		{
			if(with_AI != 2)
			{
				NEWLINE;
				WINNER(COLOR_YELLOW,CHAR_SYMBOL_PLY2,COLOR_NORMAL);
				return 0 ;

			} else {

				NEWLINE;
				IA_WIN(COLOR_AI,COLOR_NORMAL);
				return 0 ;
			}
		}

	symbol_ply1 = 0 ;
	symbol_ply2 = 0 ;

    /*run the diagonal from 20,31,42,53*/
    for(int i = 2,j = 0 ; i < LINES   ; i++,j++)
	{

			if(matrix[i][j] == CHAR_SYMBOL_PLY1 && matrix[i+1][j+1] == CHAR_SYMBOL_PLY1 )
			{
				symbol_ply1++;

			} else if (matrix[i][j] == CHAR_SYMBOL_PLY2 && matrix[i+1][j+1] == CHAR_SYMBOL_PLY2 )
			{
				symbol_ply2++;

			}

		if(symbol_ply1 > 2)
		{
			NEWLINE;
			WINNER(COLOR_RED,CHAR_SYMBOL_PLY1,COLOR_NORMAL);

			return 0 ;

		} else if(symbol_ply2 > 2)

		{	if(with_AI != 2)
			{
				NEWLINE;
				WINNER(COLOR_YELLOW,CHAR_SYMBOL_PLY2,COLOR_NORMAL);
				return 0 ;

			} else {

				NEWLINE;
				IA_WIN(COLOR_AI,COLOR_NORMAL);
				return 0 ;
			}
		}
    }


	symbol_ply1 = 0 ;
	symbol_ply2 = 0 ;

	 /*run the diagonal 01,12,23,45,56*/
    for(int i = 0,j = 1 ; i < LINES   ; i++,j++)
	{

			if(matrix[i][j] == CHAR_SYMBOL_PLY1 && matrix[i+1][j+1] == CHAR_SYMBOL_PLY1 )
			{
				symbol_ply1++;

			} else if (matrix[i][j] == CHAR_SYMBOL_PLY2 && matrix[i+1][j+1] == CHAR_SYMBOL_PLY2 )
			{
				symbol_ply2++;

			}
	}

	if(symbol_ply1 > 2)
	{
		NEWLINE;
		WINNER(COLOR_RED,CHAR_SYMBOL_PLY1,COLOR_NORMAL);
		return 0 ;

	} else if(symbol_ply2 > 2)

	{
			if(with_AI != 2)
			{
				NEWLINE;
				WINNER(COLOR_YELLOW,CHAR_SYMBOL_PLY2,COLOR_NORMAL);
				return 0 ;

			} else {

				NEWLINE;
				IA_WIN(COLOR_AI,COLOR_NORMAL);
				return 0 ;
			}
	}

	symbol_ply1 = 0 ;
	symbol_ply2 = 0 ;

	  /*run the diagonal 02,13,24,35,46*/
    for(int i = 0,j = 2 ; j < LINES   ; i++,j++)
	{

			if(matrix[i][j] == CHAR_SYMBOL_PLY1 && matrix[i+1][j+1] == CHAR_SYMBOL_PLY1 )
			{
				symbol_ply1++;

			} else if (matrix[i][j] == CHAR_SYMBOL_PLY2 && matrix[i+1][j+1] == CHAR_SYMBOL_PLY2 )
			{
				symbol_ply2++;

            }
    }

		if(symbol_ply1 > 2)
		{
			NEWLINE;
			WINNER(COLOR_RED,CHAR_SYMBOL_PLY1,COLOR_NORMAL);
            return 0 ;

		} else if(symbol_ply2 > 2)

		{
			if(with_AI != 2)
			{
				NEWLINE;
				WINNER(COLOR_YELLOW,CHAR_SYMBOL_PLY2,COLOR_NORMAL);
				return 0 ;

			} else {

				NEWLINE;
				IA_WIN(COLOR_AI,COLOR_NORMAL);
				return 0 ;
			}
		}
	symbol_ply1 = 0 ;
	symbol_ply2 = 0 ;

	/*run the diagonal from 03,14,25,36*/
    for(int i = 0,j = 3 ; j < LINES   ; i++,j++)
	{

			if(matrix[i][j] == CHAR_SYMBOL_PLY1 && matrix[i+1][j+1] == CHAR_SYMBOL_PLY1 )/*parcours la diagonale*/
			{
				symbol_ply1++;

			} else if (matrix[i][j] == CHAR_SYMBOL_PLY2 && matrix[i+1][j+1] == CHAR_SYMBOL_PLY2 )
			{
				symbol_ply2++;

            }
    }

		if(symbol_ply1 > 2)
		{
			NEWLINE;
			WINNER(COLOR_RED,CHAR_SYMBOL_PLY1,COLOR_NORMAL);
			return 0 ;

		} else if(symbol_ply2 > 2)

		{
			if(with_AI != 2)
			{
				NEWLINE;
				WINNER(COLOR_YELLOW,CHAR_SYMBOL_PLY2,COLOR_NORMAL);
				return 0 ;

			} else {

				NEWLINE;
				IA_WIN(COLOR_AI,COLOR_NORMAL);
				return 0 ;
			}
		}
	symbol_ply1 = 0 ;
	symbol_ply2 = 0 ;

		/*run the diagonal from 51,42,33,24,15,05*/
		for(int i = LINES - 1,j = 1 ; i >= 0  ; i--,j++)
		{
			if(matrix[i][j] == CHAR_SYMBOL_PLY1 && matrix[i-1][j+1] == CHAR_SYMBOL_PLY1 )
			{
				symbol_ply1++;

			} else if (matrix[i][j] == CHAR_SYMBOL_PLY2 && matrix[i-1][j+1] == CHAR_SYMBOL_PLY2 )
			{
				symbol_ply2++;

			}
		}
		if(symbol_ply1 > 2)
		{
				NEWLINE;
				WINNER(COLOR_RED,CHAR_SYMBOL_PLY1,COLOR_NORMAL);
			return 0 ;

		} else if(symbol_ply2 > 2)

		{
			if(with_AI != 2)
			{
				NEWLINE;
				WINNER(COLOR_YELLOW,CHAR_SYMBOL_PLY2,COLOR_NORMAL);
				return 0 ;

			} else {

				NEWLINE;
				IA_WIN(COLOR_AI,COLOR_NORMAL);
				return 0 ;
			}
		}

	symbol_ply1 = 0 ;
	symbol_ply2 = 0 ;

/*run the diagonal from 52,43,34,25,16*/
		for(int i = LINES - 1,j = 2 ; j < LINES  ; i--,j++)
		{
			if(matrix[i][j] == CHAR_SYMBOL_PLY1 && matrix[i-1][j+1] == CHAR_SYMBOL_PLY1 )
			{
				symbol_ply1++;

			} else if (matrix[i][j] == CHAR_SYMBOL_PLY2 && matrix[i-1][j+1] == CHAR_SYMBOL_PLY2 )
			{
				symbol_ply2++;

			}
		}
		if(symbol_ply1 > 2)
		{
				NEWLINE;
				WINNER(COLOR_RED,CHAR_SYMBOL_PLY1,COLOR_NORMAL);
			return 0 ;

		} else if(symbol_ply2 > 2)

		{
			if(with_AI != 2)
			{
				NEWLINE;
				WINNER(COLOR_YELLOW,CHAR_SYMBOL_PLY2,COLOR_NORMAL);
				return 0 ;

			} else {

				NEWLINE;
				IA_WIN(COLOR_AI,COLOR_NORMAL);
				return 0 ;
			}
		}

	symbol_ply1 = 0 ;
	symbol_ply2 = 0 ;

		/*run the diagonal from 53,44,35,26*/
		for(int i = LINES - 1,j = 3 ; j < LINES  ; i--,j++)
		{
			if(matrix[i][j] == CHAR_SYMBOL_PLY1 && matrix[i-1][j+1] == CHAR_SYMBOL_PLY1 )
			{
				symbol_ply1++;

			} else if (matrix[i][j] == CHAR_SYMBOL_PLY2 && matrix[i-1][j+1] == CHAR_SYMBOL_PLY2 )
			{
				symbol_ply2++;

			}
		}
		if(symbol_ply1 > 2)
		{
				NEWLINE;
				WINNER(COLOR_RED,CHAR_SYMBOL_PLY1,COLOR_NORMAL);
			return 0 ;

		} else if(symbol_ply2 > 2)

		{
			if(with_AI != 2)
			{
				NEWLINE;
				WINNER(COLOR_YELLOW,CHAR_SYMBOL_PLY2,COLOR_NORMAL);
				return 0 ;

			} else {

				NEWLINE;
				IA_WIN(COLOR_AI,COLOR_NORMAL);
				return 0 ;
			}
		}

return -1;
}
/** \brief
*this fonction check if a draw occur
*idea if the matrix is full and there is not winner then that's is a draw
*
* @return : 0 if draw else -1
*
 */
int  matrixDraw(void) {

	int nbr = 0 ;

	for (int i = 0; i < LINES ; i++)
	{
			for (int j = 0 ; j < COLUMNS ; j++ )
			{

				if(matrix[i][j] == CHAR_SYMBOL_PLY1 || matrix[i][j] == CHAR_SYMBOL_PLY2 )
				{
					nbr++;

				}
			}

	}

	if(nbr == FULL) /*if full*/
	{
		puts(DRAW);
		return 0;

	} else
	{
		return -1;
	}

}
/** \brief this method check status of the game to see if we have a winner or a draw
 *
 *@param : int with_AI , indicate if we play with the AI or not
 * @return : 0 if the game is over else -1
 *
 */
int status(int with_AI)
{
	//CHECK STATUS OF THE GAME
	if( matrixLineWin(with_AI) == 0 || matrixColumnWin(with_AI) == 0 || matrixDiagonalWin(with_AI) == 0 || matrixDraw() == 0 )
	{
		return 0;
	}
return -1;
}
/********************
GAME LOOP
********************/
int play (const char *user1,const char *user2)
{

	int line = 0;
	int column = 0 ;

	while(1) //LOOP GAMES
	{
		line = -1;
		//PLAYER 1
		while( line == -1)
		{
			NEWLINE;
			column = scanner(user1); /*input players columns*/

			/*quit during game*/
			if(column == YES)
			{
				return 0;
			}

			column = indexColumn(column); /*index column */
			line = indexRow(column,0); /*index row*/

		}

			matrix[line][column] = CHAR_SYMBOL_PLY1;

			NEWLINE;

			showGrid();

			//CHECK STATUS OF THE GAME
			if((status(0)) == 0)
			{
				break;
			}

			line = -1;

			while (line == -1)
			{
				//PLAYER 2
				NEWLINE;
				column = scanner(user2);
				/*quit during game*/
				if(column == YES)
				{
					return 0;
				}
				column = indexColumn(column); /*index column */

				line = indexRow(column,0);

			}

			matrix[line][column]= CHAR_SYMBOL_PLY2;

			NEWLINE;

			showGrid();
			//CHECK STATUS OF THE GAME
			if((status(0)) == 0)
			{
				break;
			}


	}
return 0;
}




