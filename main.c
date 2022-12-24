#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "start.h"

/*typedef struct{
   char name;
   int score;
   int moves;

}play;*/


void player1(int row,int column,char a[1+row][1+column],int turn,play play1,play play2,int undoarr[row][column])
  {


      int check=1,i,full=1,col;
      char x_column[1000];

        while(check==1)
    {
        gets(x_column);
        if(x_column[0]=='u'&&strlen(x_column)==1)
        {
            undo(row,column,a,2,play1,play2,undoarr);
            player2(row,column,a,1,play1,play2,undoarr);
        }
        else{

        for(i=0;i<strlen(x_column);i++)
        {
            if(!isdigit(x_column[i]))
                {  system("cls");
                printboard(row,column,a,1,0,play1,play2,undoarr);
                break;
                    }
        }
        if(i==strlen(x_column))
            {
                col=atoi(x_column);
                if(col<=column&&col!=0)
                    check=0;
                else
                {   system("cls");
                    printboard(row,column,a,1,0,play1,play2,undoarr);
                }
            }
    }
    }
      col--;
      for(i=row-1;i>=0;i--)
      {
          if (a[i][col]==' ')
           {
            a[i][col]='X';
            undoarr[i][col]=calc_moves(row,column,a,1,play1,play2)+calc_moves(row,column,a,2,play1,play2);
            //turn++;
            full=0;
            break;
           }

      }
      if(full==1)
      {
          system("cls");
          printboard(row,column,a,1,2,play1,play2,undoarr);
          player1(row,column,a,2,play1,play2,undoarr);
      }
      system("cls");
printboard(row,column,a,turn,1,play1,play2,undoarr);


}


void player2(int row,int column,char a[1+row][1+column],int turn,play play1,play play2,int undoarr[row][column])
{
      int col,check=1,i,full=1;
      char x_column[1000];
       while(check==1)
    {
        gets(x_column);
        if(x_column[0]=='u'&&strlen(x_column)==1)
        {
            undo(row,column,a,1,play1,play2,undoarr);
            player1(row,column,a,2,play1,play2,undoarr);
        }
        else{
        for(i=0;i<strlen(x_column);i++)
        {
            if(!isdigit(x_column[i]))
                {  system("cls");
                printboard(row,column,a,2,0,play1,play2,undoarr);
                break;
                    }
        }
        if(i==strlen(x_column))
            {
                col=atoi(x_column);
                if(col<=column&&col!=0)
                    check=0;
                else
                {   system("cls");
                    printboard(row,column,a,2,0,play1,play2,undoarr);
                }
            }
    }}

      col--;
      for(i=row-1;i>=0;i--)
      {
          if (a[i][col]==' ')
           {
            a[i][col]='O';
            //turn--;
            undoarr[i][col]=calc_moves(row,column,a,2,play1,play2)+calc_moves(row,column,a,1,play1,play2);

            full=0;
            break;
      }
      }
      if(full==1)
      {
          system("cls");
          printboard(row,column,a,2,2,play1,play2,undoarr);
          player2(row,column,a,1,play1,play2,undoarr);
      }
      system("cls");
printboard(row,column,a,turn,1,play1,play2,undoarr);


}
int count_filled(int row,int column,char a[1+row][1+column])
{
   int i,j,count=0;
   for(i=0;i<row;i++)
   {
       for(j=0;j<column;j++)
       {
           if(a[i][j]!=' ')
            count++;
       }
   }
   return count;
}
/*void start_game(int row,int column,char a[1+row][1+column],int turn,play play1,play play2,int undoarr[row][column])
{   int i;
    for(;i<row*column-1;)
    {   i=count_filled(row,column,a);
        if(turn==1)
           {
            turn++;
            //system("COLOR 4");
            player1(row,column,a,turn,play1,play2,undoarr);

           }
        else if(turn==2)
           {
               turn--;
              // system("COLOR 9");
               player2(row,column,a,turn,play1,play2,undoarr);
           }

    }
}*/
int hor_score(int row,int column,char a[1+row][1+column],int turn,play play1,play play2)
{

    int i,j;
    if (turn==2)
    {
        play1.score=0;
        for(i=row-1;i>-1;i--)
        {
            for(j=0;j<column;j++)
            {
                if(a[i][j]=='X'&&a[i][j+1]=='X'&&a[i][j+2]=='X'&&a[i][j+3]=='X')
                   play1.score++;
                if(a[i][j]=='X'&&a[i-1][j]=='X'&&a[i-2][j]=='X'&&a[i-3][j]=='X')
                    play1.score++;
                if(a[i][j]=='X'&&a[i-1][j+1]=='X'&&a[i-2][j+2]=='X'&&a[i-3][j+3]=='X')
                    play1.score++;
                if(a[i][j]=='X'&&a[i+1][j+1]=='X'&&a[i+2][j+2]=='X'&&a[i+3][j+3]=='X')
                    play1.score++;
            }
        }
        return play1.score;
     }
    else if(turn==1)
     {
        play2.score=0;
        for(i=row-1;i>-1;i--)
        {
            for(j=0;j<column;j++)
            {
                if(a[i][j]=='O'&&a[i][j+1]=='O'&&a[i][j+2]=='O'&&a[i][j+3]=='O')
                    play2.score++;
                if(a[i][j]=='O'&&a[i-1][j]=='O'&&a[i-2][j]=='O'&&a[i-3][j]=='O')
                    play2.score++;
               if(a[i][j]=='O'&&a[i-1][j+1]=='O'&&a[i-2][j+2]=='O'&&a[i-3][j+3]=='O')
                    play2.score++;
                if(a[i][j]=='O'&&a[i+1][j+1]=='O'&&a[i+2][j+2]=='O'&&a[i+3][j+3]=='O')
                    play2.score++;
            }
        }
        return play2.score;
    }

}

int calc_moves(int row,int column,char a[1+row][1+column],int turn,play play1,play play2)
{
    int i,j;
    if(turn==2)
    {
        play1.moves=0;
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                if(a[i][j]=='X')
                    play1.moves++;
            }
        }
        return play1.moves;
    }
    if(turn==1)
    {
        play2.moves=0;
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                if(a[i][j]=='O')
                    play2.moves++;
            }
        }
    }
    return play2.moves;
}
void undo(int row,int column,char a[row+1][column+1],int turn,play play1,play play2,int undoarr[row][column]){
    int i,j;
    int last=calc_moves(row,column,a,1,play1,play2)+calc_moves(row,column,a,2,play1,play2);
    if(last==0){
            system("cls");
            printboard(row,column,a,1,1,play1,play2,undoarr);
    printf("The board is already empty!!!\n");
    player1(row,column,a,2,play1,play2,undoarr);

    }
    else{
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            if(undoarr[i][j]==last)
            {
                undoarr[i][j]=0;
                a[i][j]=' ';
            }
        }
    }
    system("cls");
    printboard(row,column,a,turn,1,play1,play2,undoarr);
    }

}






void printboard(int row,int column,char a[1+row][1+column],int turn,int sent,play play1,play play2,int undoarr[row][column])
    {
        int i,j,k;
        for (i=1;i<=column;i++)
        {
           if(i<10){
            printf("\033[;34m");
            printf("   %d  ",i);}
           else{
            printf("\033[;34m");
            printf("  %d  ",i);
        }}
        printf("\n");

        for(i=0;i<column;i++)
        {
            printf("|-----");}
        printf("|\n");
        for (i=0;i<row;i++)
        {
            for(j=0;j<column;j++){
              printf("\033[;34m");
              printf("|  ");

              if(a[i][j]=='X'){
              printf("\033[;31m");
              printf("%c  ",a[i][j]);}
              else
              {
                  printf("\033[;33m");
                  printf("%c  ",a[i][j]);
              }

            }

            printf("\033[;34m");
            printf("|\n");
         for(k=0;k<column;k++)
         {    printf("\033[;34m");
              printf("|-----");}
        printf("\033[;34m");
        printf("|\n");
        }
        //play1.score=total_score(row,column,a,2,play1,play2);
        //play2.score=total_score(row,column,a,1,play1,play2);
        play1.score=hor_score(row,column,a,2,play1,play2);
        play2.score=hor_score(row,column,a,1,play1,play2);
        printf("\033[;31m");
        printf("score X = %d     ",play1.score);
        printf("\033[;33m");
        printf("Score O = %d\n",play2.score);
        play1.moves=calc_moves(row,column,a,2,play1,play2);
        play2.moves=calc_moves(row,column,a,1,play1,play2);
        printf("\033[;31m");
        printf("Moves X = %d     ",play1.moves);
        printf("\033[;33m");
        printf("Moves O = %d\n",play2.moves);

        if (turn==1){
            printf("\033[;31m");
           printf("player's 1 turn\n");}
        else if(turn==2){
           printf("\033[;33m");
           printf("player's 2 turn\n");}
        printf("\033[;34m");
        printf("For undo press u\n");

      if(sent==1){
            printf("Enter a column number.\n");}
      else if(sent==0){
            printf("Enter a valid column number!!\n");}
      else if(sent==2){
            printf("Please choose an empty column!!\n");}

      for(i=0;i<row;i++)
      {
          for(j=0;j<column;j++)
            printf("%d ",undoarr[i][j]);
          printf("\n");

      }
    }

int main()
{
    int row,column,i,j,turn=1,end=1;
    char lol[1];
    play play1,play2;
    clock_t t;               //time
    t = clock();             //time
    play1.score=0;
    play2.score=0;
        do
    {   system("cls");
        printf("please enter rows and column: \n");
      scanf("%d%d",&row,&column);
    }while(row<4&&column<4);
    gets(lol);
        system("cls");
    int undoarr[row][column];

    char a[1+row][1+column];
            for (i=0;i<row;i++)
        {
            for(j=0;j<column;j++){
            a[i][j]=' ';
            undoarr[i][j]=0;
        }}
    printboard(row,column,a,turn,1,play1,play2,undoarr);
    start_game(row,column,a,turn,play1,play2,undoarr);

     t = clock() - t;      //time
    int seconds_passed = (t)/CLOCKS_PER_SEC;// total seconds      time

    printf("Time passed in hours is %d\nin minutes is %d\nin seconds is %d \n", seconds_passed / 3600 % 24, (seconds_passed % 3600)/60, seconds_passed %3600 %60);

   // play1.score=total_score(row,column,a,2,play1,play2);

    return 0;
}
