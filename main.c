#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "xml.h"
#include "save_game.h"
#include "load_game.h"
#include "printboard.h"
#include "player1.h"
#include "player2.h"
#include "computer.h"
#include "total_score.h"
#include "highscores_functions.h"
#include "start_game.h"
#include "undo.h"
#include"redo.h"
#include "menu.h"
#include "calc_moves.h"

scores pscores[100];
int row;
int column;
int highno;
int f;

int count_filled(int row,int column,char a[1+row][1+column])          //counts number of empty cells
{
   int i,j,count=0;
   for(i=0;i<row;i++)
   {
       for(j=0;j<column;j++)
       {
           if(a[i][j]!=' ')
            count++;            //increments count by 1 everytime it finds an empty cell
       }
   }
   return count;
}

int main()
{
    menuu(0);   //calling menu function
    return 0;
}
