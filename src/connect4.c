/**
 *@Author : DOUDOU DIAWARA
 *@verison : 1.0 (Mars 2022)
 *@Github : https://github.com/DD7600
 *
 *this file start game Connect4
 */

#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "AI.h"

#define BYE "END!"
#define START "GAME BEGINS"


int main(void)
{

	int choice = 0 ;

	do
	{
		defaultMatrix(); /*initialize matrix*/
		NEWLINE;
		choice = choiceMenu();

		switch(choice)
		{
			case 0:
			puts(BYE);//QUIT
			break;

			case 1: //1P vs 2P
			NEWLINE;
			puts(START); /*welcome message*/
			NEWLINE;
			puts(TIPS);
			show(); /*grid at start*/
			NEWLINE;
			play(PLY1,PLY2);/*game*/
			break;

			case 2://1P vs IA
			NEWLINE;
			puts(START); /*welcome message*/
			NEWLINE;
			puts(TIPS);
			show(); /*grid at start*/
			NEWLINE;
			playAI(PLY1,PLY_AI);
			break;

		}

	} while(choice != 0);

return 0;
}
