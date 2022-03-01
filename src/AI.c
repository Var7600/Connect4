/**
 *@Author : DOUDOU DIAWARA
 *@verison :  1.0 (Mars 2022)
 *@Github : https://github.com/DD7600
 *
 *this file contains all implementations of @file: AI.h
 */

#include <stdio.h>
#include <stdlib.h>

#include "AI.h"
#include "game.h"

/** \brief this function scans the matrix to see if a player can win with their next move and
 *try to prevent him from winning , returns the position to be played to prevent a player to win
 *
 * @return : int column to prevent player to win otherwise return -1
 */

int  preventLineWin(void)
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

				if(symbol_ply1 == 2)
				{
					return j+2;
				}


			} else if (matrix[i][j] == CHAR_SYMBOL_AI && matrix[i][j+1] == CHAR_SYMBOL_AI )
			{
				symbol_ply2++;

				if(symbol_ply2 == 2)
				{
					return j+2;
				}
			}

		}

		/*reset counting for each lines*/
		symbol_ply1 = 0 ;
		symbol_ply2 = 0 ;
	}


	return -1;
}
/**\brief this function scans the matrix to see if the player can win with their next move and
 *try to prevent him from winning , returns the position to be played to prevent player to win vertically
 *
 *@return : int column to prevent player to win otherwise -1
 *
 */
int preventColumnWin(void)
{
	/*count player symbol at each columns*/
	int symbol_ply1 = 0 ;
	int symbol_ply2 = 0 ;

	for(int i = 0 ; i < COLUMNS ; i++)
	{
		for(int j = 0 ; j < COLUMNS - 1 ; j++) /*COLUMNS - 1 cause [i][j+1] otherwise j+1 not in range index*/
		{
			if(matrix[j][i] == CHAR_SYMBOL_PLY1 && matrix[j+1][i] == CHAR_SYMBOL_PLY1  )
			{
                	symbol_ply1++;
                	if(symbol_ply1 == 2)
					{
						return i;
					}

			}else if (matrix[j][i] == CHAR_SYMBOL_AI && matrix[j+1][i] == CHAR_SYMBOL_AI )
				{
					symbol_ply2++;

					if(symbol_ply2 == 2)
					{
						return i;
					}


				}

		}
			/*reset counting for each lines*/
			symbol_ply1 = 0 ;
			symbol_ply2 = 0 ;
		}

return -1;
}

/** \brief this function  generate a random position to insert using the system time
 *
 * @return: int postion, column to insert
 *
 */

int randomPlay(void)
{
	int ret = 0;
	time_t cur_time ;
	do
	{
		/*to get the current system time*/
		time(&cur_time);

	} while(cur_time == -1);

	ret = cur_time % COLUMNS;

	if(ret == 7 ) /*position 7 means in the matrix 6*/
	{
		return ret -1 ;
	}

return ret;
}
/** \brief this function allows the AI to choose the right move to play by checking the different options(Line,Column) given to him
 *
 * \return returns int column to insert
 *
 */

int gamePlayAI(void)
{
	int ret = -1;

	if ((ret = preventColumnWin()) != -1 )
	{
		if((columnFull(ret)) != -1 ) /*if the column to play is not already full*/
		{
			return ret;

		}
	}

	if ((ret = preventLineWin()) != -1 )
	{
		if((columnFull(ret)) != -1 ) /*if the column to play is not already full*/
		{
			return ret;

		}
	}


return -1 ;
}

/********************
GAME LOOP
********************/
int playAI(const char *user1,const char *user2)
{
	int column = 0 ;
	int line = 0;

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
			if((status(2)) == 0)
			{
				break;
			}
			NEWLINE;
			line = -1;

		/*AI*/
			while(line == -1)
			{
				column =  gamePlayAI() ;
				line = indexRow(column,1);

				if(column != -1  && line != -1)
				{
					printf("%s %d\n",user2,column+1); /*AI selection column*/
					matrix[line][column] = CHAR_SYMBOL_AI;

				} else {

					column = randomPlay();
					line = indexRow(column,1);

						if(line != -1)
						{
							printf("%s %d\n",user2,column+1); /*player column choice (+1 view of player index start at 1)*/
							matrix[line][column] = CHAR_SYMBOL_AI;
						}

					}


			}


			NEWLINE;

			showGrid();
			//CHECK STATUS OF THE GAME
			if((status(2)) == 0)
			{
				break;
			}

	}
return 0;
}




