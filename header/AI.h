
/**
 *@Author : DOUDOU DIAWARA
 *@verison :  1.0 (Mars 2022)
 *@Github : https://github.com/DD7600
 *
 *this file contains all declarations macros,variables,functions to implements a AI to play Connect4
 */

#ifndef AI_H_INCLUDED
#define AI_H_INCLUDED
#include <time.h>
#define COLOR_AI  "\x1B[1;34m"
#define CHAR_SYMBOL_AI 'X'
#define PLY_AI "AI  X(SELECT A COLUMN) : "
#define IA_WIN(COLOR_AI,COLOR_NORMAL) printf("%sAI HAS WON ;) hmm, I guess AI system are just smarter%s",COLOR_AI,COLOR_NORMAL)
#define BEAT_AI "!!!!!The person who beat the machine\n"
#define NO_TIME "Error!Could not read system time\n"

//FUNCTION DECLARATION
extern int preventLineWin(void);/*prevent player player to win horizontaly*/

extern int preventColumnWin(void); /*prevent player to win verticaly*/

int randomPlay(void);/*play random position to play*/

extern int gamePlayAI(void);/*AI next move for Line and Column*/

extern int playAI(const char *,const char *); /*gaming loop*/

#endif // IA_H_INCLUDED
