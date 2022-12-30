#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
typedef struct{
  char name[50];
   int score;
   int moves;
}play;

typedef struct{
   char name[50];
   int score;
}scores;
scores pscores[100];
int row;
int column;
int highno;
int f;
void player1(int row,int column,char a[1+row][1+column],int turn,play play1,play play2,int undoarr[row][column],int redoarr[row][column],int computerturn, int seconds_passed)
  {
      int check=1,i,full=1,col,j,k;
      char x_column[1000];
      int cred=0;
      while(check==1)
        {
            gets(x_column);
            if((x_column[0]=='u'||x_column[0]=='U')&&strlen(x_column)==1)
            {
                undo(row,column,a,2,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
                if(computerturn==1)
                    {
                     player2(row,column,a,1,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
                     system("cls");
                    }
                else if(computerturn==0)
                    system("cls");
                    printboard(row,column,a,1,1,play1,play2,undoarr,redoarr, seconds_passed);
           }
           else if((x_column[0]=='r'||x_column[0]=='R')&&strlen(x_column)==1)
           {
               redo(row,column,a,turn,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
               if(computerturn==1)
                player2(row,column,a,1,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
            }
           else if((x_column[0]=='s'||x_column[0]=='S')&&strlen(x_column)==1)
            {
                a[row-1][column]=' ';
                save_game(row,column,a,undoarr,redoarr);
                printboard(row,column,a,1,1,play1,play2,undoarr,redoarr,seconds_passed);
            }
           else
                {
                    for(i=0;i<strlen(x_column);i++)
                    {
                        if(!isdigit(x_column[i]))
                        {
                            system("cls");
                            printboard(row,column,a,1,0,play1,play2,undoarr,redoarr, seconds_passed);
                            break;
                        }
                    }
                    if(i==strlen(x_column))
                        {
                            col=atoi(x_column);
                            if(col<=column&&col!=0)
                            check=0;
                            else
                                {
                                    system("cls");
                                    printboard(row,column,a,1,0,play1,play2,undoarr,redoarr, seconds_passed);
                                }
                        }
                }
        }
        col--;
        for(i=0;i<row;i++)
            {
                for(j=0;j<column;j++)
                redoarr[i][j]=0;
            }
        for(i=row-1;i>=0;i--)
            {
                if (a[i][col]==' ')
                    {
                        a[i][col]='X';
                        undoarr[i][col]=calc_moves(row,column,a,1,play1,play2)+calc_moves(row,column,a,2,play1,play2);
                        full=0;
                        break;
                    }
            }
            if(full==1)
                {
                    system("cls");
                    printboard(row,column,a,1,2,play1,play2,undoarr,redoarr, seconds_passed);
                    player1(row,column,a,2,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
                }
            system("cls");
            printboard(row,column,a,turn,1,play1,play2,undoarr,redoarr, seconds_passed);
    }

void player2(int row,int column,char a[1+row][1+column],int turn,play play1,play play2,int undoarr[row][column],int redoarr[row][column],int computerturn, int seconds_passed)
{
      int col,check=1,i,full=1,j,k,cred=0;
      char x_column[1000];
       while(check==1)
    {
        gets(x_column);
        if((x_column[0]=='u'||x_column[0]=='U')&&strlen(x_column)==1)
        {
            undo(row,column,a,1,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
            player1(row,column,a,2,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
        }
         else if((x_column[0]=='r'||x_column[0]=='R')&&strlen(x_column)==1){

                redo(row,column,a,turn,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
                player1(row,column,a,2,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
            }
           else if((x_column[0]=='s'||x_column[0]=='S')&&strlen(x_column)==1)
            {
                a[row-1][column]='1';
                save_game(row,column,a,undoarr,redoarr);
                printboard(row,column,a,2,1,play1,play2,undoarr,redoarr,seconds_passed);
            }
        else{
        for(i=0;i<strlen(x_column);i++)
        {
            if(!isdigit(x_column[i]))
                {  system("cls");
                printboard(row,column,a,2,0,play1,play2,undoarr,redoarr, seconds_passed);
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
                    printboard(row,column,a,2,0,play1,play2,undoarr,redoarr, seconds_passed);
                }
            }
    }
    }
      col--;
      for(i=0;i<row;i++)
      {
          for(j=0;j<column;j++)
            redoarr[i][j]=0;
      }
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
          printboard(row,column,a,2,2,play1,play2,undoarr,redoarr, seconds_passed);
          player2(row,column,a,1,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
      }
      system("cls");
printboard(row,column,a,turn,1,play1,play2,undoarr,redoarr, seconds_passed);
}

void computer(int row,int column,char a[row+1][column+1],int turn, play play1, play play2,int undoarr[row][column],int redoarr[row][column], int seconds_passed)
{
    int i,j,count=0;
    for(i=row-1;i>-1;i--)
    {
        for(j=0;j<column;j++)
        {
            if(a[i][j]==' ')
            {
                a[i][j]='O';
                count++;
                undoarr[i][j]=calc_moves(row,column,a,1,play1,play2)+calc_moves(row,column,a,2,play1,play2);
                break;
            }
        }
        if(count!=0)
            break;
    }
    system("cls");
    printboard(row,column,a,1,1,play1,play2,undoarr,redoarr, seconds_passed);
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
void start_game(int row,int column,char a[1+row][1+column],int turn,play play1,play play2,int undoarr[row][column],int redoarr[row][column],int computerturn, clock_t start, clock_t finish, int seconds_passed)
{   int i,x,y;
    if(a[row-1][column]=='1')
        turn=2;
    if(a[row][column]=='0')
        computerturn=0;
         system("cls");
                system("COLOR 05");
    printboard(row,column,a,turn,1,play1,play2,undoarr,redoarr,seconds_passed);
    for(;i<row*column-1;)
    {   start = clock();
        i=count_filled(row,column,a);
        if(turn==1)
           {
            turn++;
            player1(row,column,a,turn,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
            finish = clock() ;      //time
            seconds_passed += (finish - start)/CLOCKS_PER_SEC;
            printf("Time passed : %d hours : %d minutes : %d seconds\n", seconds_passed / 3600 % 24, (seconds_passed % 3600)/60, seconds_passed %3600 %60);           }

        else if(turn==2&&computerturn==1)
           {
               turn--;
               player2(row,column,a,turn,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
               finish = clock() ;      //time
   seconds_passed += (finish - start)/CLOCKS_PER_SEC;
     printf("Time passed : %d hours : %d minutes : %d seconds\n", seconds_passed / 3600 % 24, (seconds_passed % 3600)/60, seconds_passed %3600 %60);
           }
        else if(computerturn==0)
        {
            turn--;
            computer(row,column,a,turn,play1,play2,undoarr,redoarr, seconds_passed);
          finish = clock() ;      //time
    seconds_passed += (finish - start)/CLOCKS_PER_SEC;
    printf("Time passed : %d hours : %d minutes : %d seconds\n", seconds_passed / 3600 % 24, (seconds_passed % 3600)/60, seconds_passed %3600 %60);
        }
    }
    x=hor_score(row,column,a,2,play1,play2);
    y=hor_score(row,column,a,1,play1,play2);
    if(i==row*column-1)
    {
       if(x>y)
       {
           printf("Player 1 wins!!\nPlease enter your name:\n");
           gets(play1.name);
           write_scores(x,play1);
       }
       else if(x<y)
       {
           printf("Player 2 wins!!\nPlease enter your name:\n");
           gets(play2.name);
           write_scores(y,play2);
       }
    }






}
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
void undo(int row,int column,char a[row+1][column+1],int turn,play play1,play play2,int undoarr[row][column],int redoarr[row][column],int computerturn, int seconds_passed){
    int i,j;
    int last=calc_moves(row,column,a,1,play1,play2)+calc_moves(row,column,a,2,play1,play2);
    if(last==0){
            system("cls");
            printboard(row,column,a,1,1,play1,play2,undoarr,redoarr, seconds_passed);
            printf("\033[0;31m");
    printf("The board is already empty!!!\n");
    player1(row,column,a,2,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
    if(computerturn==0)
        computer(row,column,a,2,play1,play2,undoarr,redoarr, seconds_passed);
    }
    else{
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            if(undoarr[i][j]==last)
            {   redoarr[i][j]=undoarr[i][j];
                undoarr[i][j]=0;
                a[i][j]=' ';
            }
            if(undoarr[i][j]==last-1&&computerturn==0){
               redoarr[i][j]=undoarr[i][j];
               undoarr[i][j]=0;
                a[i][j]=' ';
            }
        }
    }
    system("cls");
    printboard(row,column,a,turn,1,play1,play2,undoarr,redoarr, seconds_passed);
    }
}
void redo(int row,int column,char a[row+1][column+1],int turn,play play1,play play2,int undoarr[row][column],int redoarr[row][column],int computerturn, int seconds_passed){
    int i,j,cred=0;
    int last=calc_moves(row,column,a,1,play1,play2)+calc_moves(row,column,a,2,play1,play2);
    int movex=calc_moves(row,column,a,2,play1,play2);
    int moveo=calc_moves(row,column,a,1,play1,play2);
     for(i=0;i<row;i++)
            {
                for(j=0;j<column;j++)
                {
                    if(redoarr[i][j]!=0)
                        cred++;
                }
            }
    if(cred==0)
            {
                system("cls");
                printboard(row,column,a,turn-1,1,play1,play2,undoarr,redoarr, seconds_passed);
                printf("\033[;31m");
                printf("There is nothing to be redone!!!\n");
                if(movex==moveo)
                    player1(row,column,a,2,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
                else if(movex>moveo){
                        system("cls");
                    printboard(row,column,a,2,1,play1,play2,undoarr,redoarr, seconds_passed);
                    printf("\033[;31m");
                    printf("There is nothing to be redone!!!\n");
                    player2(row,column,a,1,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
            }
            }
  else{  for(i=0;i<row;i++)
       {
        for(j=0;j<column;j++)
        {
            if(redoarr[i][j]==last+1)
            {   undoarr[i][j]=last+1;
                if(movex==moveo){
                    a[i][j]='X';
                    }
                else if(movex>moveo)
                    a[i][j]='O';
                redoarr[i][j]=0;
            }
            if(computerturn==0&&redoarr[i][j]==last+2)
            {
                undoarr[i][j]=last+2;
                    a[i][j]='O';
                redoarr[i][j]=0;
            }
        }
    }
    system("cls");
    printboard(row,column,a,turn,1,play1,play2,undoarr,redoarr, seconds_passed);
    }
}
void printboard(int row,int column,char a[1+row][1+column],int turn,int sent,play play1,play play2,int undoarr[row][column],int redoarr[row][column], int seconds_passed)
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
        play1.score=hor_score(row,column,a,2,play1,play2);
        play2.score=hor_score(row,column,a,1,play1,play2);
        printf("\033[;31m");
        printf("Score X = %d     ",play1.score);
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
           printf("Player's 1 turn\n");}
        else if(turn==2){
           printf("\033[;33m");
           printf("Player's 2 turn\n");}
        printf("\033[;34m");
        printf("To undo press u\n");
        printf("To redo press r\n");
        printf("To save press s\n");
      if(sent==1){
            printf("Enter a column number.\n");}
      else if(sent==0){
            printf("Enter a valid column number!!\n");}
      else if(sent==2){
            printf("Please choose an empty column!!\n");}



    }

void save_game(int row , int column , char a[row+1][column+1],int undoarr[row][column],int redoarr[row][column])
{   int check=1,file_no,i,j;
    char file_nost[100];
    system("cls");
    printf("Choose a file to save the game:\n1-File 1\n2-File 2\n3-File 3\n");
    while(check==1)
    {
        gets(file_nost);

        for(i=0;i<strlen(file_nost);i++)
        {
            if(!isdigit(file_nost[i]))
                {  system("cls");
                 printf("Please choose a valid file to save the game:\n1-File 1\n2-File 2\n3-File 3\n");

                break;
                    }
        }
            if(i==strlen(file_nost))
            {
                file_no=atoi(file_nost);
                if(file_no<=3&&file_no!=0)
                    check=0;
                else
                {
                      system("cls");
                    printf("Please choose a valid file to save the game:\n1-File 1\n2-File 2\n3-File 3\n");
                }
            }
    }
    if(file_no==1)
    {
        FILE*fp1;
        fp1=fopen("game1.bin","wb");
        fputc(row,fp1);
        fputc(column,fp1);
        for(i=0;i<row+1;i++)
        {
            for(j=0;j<column+1;j++)
              {

              fputc(a[i][j],fp1);

              }
        }
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                fprintf(fp1,"%c%c",undoarr[i][j],redoarr[i][j]);
            }
        }
        fclose(fp1);
    }
 else if(file_no==2)
    {
        FILE*fp2;
        fp2=fopen("game2.bin","wb");
        fputc(row,fp2);
        fputc(column,fp2);
        for(i=0;i<row+1;i++)
        {
            for(j=0;j<column+1;j++)
               {
                   fputc(a[i][j],fp2);
               }
        }
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                fprintf(fp2,"%c%c",undoarr[i][j],redoarr[i][j]);
            }
        }
        fclose(fp2);
    }
     else
    {
        FILE*fp3;
        fp3=fopen("game3.bin","wb");
        fputc(row,fp3);
        fputc(column,fp3);
        for(i=0;i<row+1;i++)
        {
            for(j=0;j<column+1;j++)
               {
                   fputc(a[i][j],fp3);
               }
        }
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                fprintf(fp3,"%c%c",undoarr[i][j],redoarr[i][j]);
            }
        }
        fclose(fp3);
    }
system("cls");
}

void load_game(/int row,int column,/char a[row+1][column+1],int undoarr[row][column],int redoarr[row][column],int file_no)
{
    int check=1,i,j;
    char file_nost[100];
    system("cls");
    printf("Choose a file to load a game:\n1-File 1\n2-File 2\n3-File 3\n");
    if(file_no==0)
    {
    while(check==1)
    {
        gets(file_nost);

        for(i=0;i<strlen(file_nost);i++)
        {
            if(!isdigit(file_nost[i]))
                {  system("cls");
                 printf("Please choose a valid file to load the game:\n1-File 1\n2-File 2\n3-File 3\n");

                break;
                    }
        }
            if(i==strlen(file_nost))
            {
                file_no=atoi(file_nost);
                if(file_no<=3&&file_no!=0)
                    check=0;
                else
                {
                      system("cls");
                    printf("Please choose a valid file to load the game:\n1-File 1\n2-File 2\n3-File 3\n");
                }
            }
    }}
    f=file_no;
    if(file_no==1)
    {
        FILE*fp1;
        fp1=fopen("game1.bin","rb");
        row=fgetc(fp1);
        column=fgetc(fp1);
        for(i=0;i<row+1;i++)
        {
            for(j=0;j<column+1;j++)
              {

              a[i][j]=fgetc(fp1);
              }
        }
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {

                undoarr[i][j]=getc(fp1);
                redoarr[i][j]=getc(fp1);
            }
        }
        fclose(fp1);
    }
 else if(file_no==2)
    {
        FILE*fp2;
        fp2=fopen("game2.bin","rb");
        row=fgetc(fp2);
        column=fgetc(fp2);
        for(i=0;i<row+1;i++)
        {
            for(j=0;j<column+1;j++)
               {
                a[i][j]=fgetc(fp2);
               }
        }
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                 undoarr[i][j]=getc(fp2);
              redoarr[i][j]=getc(fp2);
            }
        }
        fclose(fp2);
    }
     else
    {
        FILE*fp3;
        fp3=fopen("game3.bin","rb");
        row=fgetc(fp3);
        column=fgetc(fp3);
        for(i=0;i<row+1;i++)
        {
            for(j=0;j<column+1;j++)
               {
                 a[i][j]=fgetc(fp3);
               }
        }
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                 undoarr[i][j]=getc(fp3);
              redoarr[i][j]=getc(fp3);
            }
        }
        fclose(fp3);
    }
//system("cls");


}

int xml_ind(char a[],char check[])
{ int i,j,c,k;
    for(i=0;i<strlen(a);i++)
    {
        c=0,k=i;
        for(j=0;j<strlen(check);j++)
        {
            if(check[j]==a[k])
            {
                c++;
                k++;
            }
            else
                break;
        }
        if(c==strlen(check))
        {
            break;
        }

    }
    if(check[1]=='/')
        return i;
    else
        return i+strlen(check)-1;
}
int checkop(char a[],int in1,int in2)
{ int check=1,i,k=0;
  char sub[200];
  for(i=in1+1;i<in2;i++)
  {
      sub[k]=a[i];
      k++;
  }
  checkop2(sub,k);
}
int checkop2(char sub[],int k)
{
    int i,var=-1,j,t,a[200];
    for(i=0;i<k;i++)
    {
        if(!isdigit(sub[i]))
            break;
    }
    for(j=0;j<k;j++)
        a[j]=sub[j]-48;

    if(i==k)
    {
        var=0;
        int t=k;
        for(j=0;j<k;j++)
          {
              var=var+a[j]*pow(10,t-1);
              t--;

    }}
    return var;
}

void xml(){
   char a[200],b[200],y;
   char c1[]="<configurations>",c2[]="</configurations>",h1[]="<Height>",h2[]="</Height>",w1[]="<Width>",w2[]="</Width>",hi1[]="<Highscores>",hi2[]="</Highscores>";
   char filepath[200];

   int i=0,c,k,j,s=0;
   int in1,in2;
      FILE*fp;
   fp=fopen("conf.xml","r");
   if(fp!=NULL)
   {
       while((y=fgetc(fp))!=EOF)
   {
       if(y!=' '&&y!='\n'&&y!='\t')
       {
           a[s]=y;
           s++;
       }
   }
   fclose(fp);
    in1=xml_ind(a,h1);
    in2=xml_ind(a,h2);
    row=checkop(a,in1,in2);
    in1=xml_ind(a,w1);
    in2=xml_ind(a,w2);
   column=checkop(a,in1,in2);
    in1=xml_ind(a,hi1);
    in2=xml_ind(a,hi2);
    highno=checkop(a,in1,in2);}
     if(fp==NULL||row==-1||column==-1||highno==-1)
    {    system("cls");
         system("COLOR 05");
        printf("\033[;31m");
        printf("The XML file is corrupted!!!\n");
        for(i=0;i<3;i++)
        {
             for(k=0;k<strlen(a);k++)
               a[i]=NULL;
            printf("will load default in %d\n",3-i);
            printf("Please enter a valid file path!!!:\n");
            gets(filepath);
            fp=fopen(filepath,"r");
            if(1)
            {
                s=0;
                 while((y=fgetc(fp))!=EOF)
                {
                    if(y!=' '&&y!='\n'&&y!='\t')
                     {
                         a[s]=y;
                         s++;
                     }
                }
                fclose(fp);
                in1=xml_ind(a,h1);
                in2=xml_ind(a,h2);
                row=checkop(a,in1,in2);
                in1=xml_ind(a,w1);
                in2=xml_ind(a,w2);
                column=checkop(a,in1,in2);
                in1=xml_ind(a,hi1);
                in2=xml_ind(a,hi2);
                highno=checkop(a,in1,in2);
            }

            if(row!=-1&&row>=4&&column!=-1&&column>=4&&highno!=-1)
                break;
            if(i==2)
            {
                printf("Loading the default parameters");
                row=7;
                column=9;
                highno=10;
            }
        }
    }

}
void write_scores(int winscore, play play1)
{   int i,j,k,temp=0;
    FILE*fp;
    fp=fopen("highscores.bin","rb");
    fread(pscores,sizeof(scores),100,fp);
    fclose(fp);
    for(i=0;i<100;i++)
    {
        if(pscores[i].score==0)
            break;
    }
    strcpy(pscores[i].name,play1.name);
    pscores[i].score=winscore;
    arrange(i);
    fp=fopen("highscores.bin","wb");
    fwrite(pscores,sizeof(scores),100,fp);
    fclose(fp);



}
void arrange(int len)
{ int i,j,temp;
  char wait[50];
  for (i=0;i<len;i++)
  {
      for(j=i+1;j<len;j++)
      {
          if(pscores[i].score<pscores[j].score)
          {
              temp=pscores[i].score;
              pscores[i].score=pscores[j].score;
              pscores[j].score=temp;
              strcpy(wait,pscores[i].name);
              strcpy(pscores[i].name,pscores[j].name);
              strcpy(pscores[j].name,wait);
          }
      }
  }

}

void read_scores()
{   int i;
    FILE*fp;
    fp=fopen("highscores.bin","rb");
    if(fp!=NULL)
    {
        fread(pscores,sizeof(scores),100,fp);
    }
    else
       {printf("The file is empty!!!");
        return;
    }fclose(fp);
    for(i=0;i<100;i++)
    {
        if(pscores[i].score==0)
            break;
    }
    arrange(i);
    fp=fopen("highscors.bin","rb");
        fwrite(&pscores,sizeof(scores),100,fp);
    fclose(fp);

    print_scores();
}

void print_scores()
{
    int i;
    for(i=0;i<highno;i++)
    {
         printf("  %d- %s %d\n",i+1,pscores[i].name,pscores[i].score);
         if(pscores[i+1].score==0)
            break;


    }
}


int main()
{
    int i,j,turn=1,end=1,computerturn=1,menucheck=1,modecheck=1,menu,mode,x,y;
    char lol[1],menust[1000],modest[1000];
    play play1,play2;
    clock_t start;
    clock_t finish;
    int seconds_passed=0;
    play1.score=0;
    play2.score=0;
    xml();
    x=row;
    y=column;
    system("COLOR F5");

    int undoarr[row][column],redoarr[row][column];
    char a[row+1][column+1];
        for (i=0;i<row+1;i++)
        {
            for(j=0;j<column+1;j++)
                {
            a[i][j]=' ';
            undoarr[i][j]=0;
            redoarr[i][j]=0;
            }
        }
system("cls");
    printf("\033[1;35m");
    printf(" \n\n\n\n\t\t\t\t\t\t< MAIN MENU >\n\t\t\t\t\t\t1-New game\n\t\t\t\t\t\t2-Load game\n\t\t\t\t\t\t3-Top players\n\t\t\t\t\t\t4-Quit\n");
    printf("Please choose an option.\n");
   while(menucheck==1)
        {
            gets(menust);
                for(i=0;i<strlen(menust);i++)
        {
            if(!isdigit(menust[i]))
                { system("cls");
                  printf(" \n\n\n\n\t\t\t\t\t\tMAIN MENU\n\t\t\t\t\t\t1-New game\n\t\t\t\t\t\t2-Load game\n\t\t\t\t\t\t3-Top players\n\t\t\t\t\t\t4-Quit\n");
                  printf("Please choose a valid option!!!\n");
                break;
                    }
        }
        if(i==strlen(menust))
            {
                menu=atoi(menust);
                if(menu<=4&&menu!=0)
                    menucheck=0;
                else
                {   system("cls");
                    printf(" \n\n\n\n\t\t\t\t\t\tMAIN MENU\n\t\t\t\t\t\t1-New game\n\t\t\t\t\t\t2-Load game\n\t\t\t\t\t\t3-Top players\n\t\t\t\t\t\t4-Quit\n");
                    printf("Please choose a valid option!!!\n");
                }
            }
        }
    if(menu==1)
    {

        while(modecheck==1){
        printf("1- Vs human\n2- Vs computer\n");
        gets(modest);
         for(i=0;i<strlen(modest);i++)
        {
            if(!isdigit(modest[i]))
                { system("cls");
                  printf(" \n\n\n\n\t\t\t\t\t\tMAIN MENU\n\t\t\t\t\t\t1- New game\n\t\t\t\t\t\t2- Load game\n\t\t\t\t\t\t3- Top players\n\t\t\t\t\t\t4- Quit\n");
                  printf("Please choose a valid option!!!\n");
                break;
                    }
        }
        if(i==strlen(modest))
            {
                mode=atoi(modest);
                if(mode<=2&&mode!=0)
                    modecheck=0;
                else
                {   system("cls");
                    printf(" \n\n\n\n\t\t\t\t\t\t< MAIN MENU >\n\t\t\t\t\t\t1- New game\n\t\t\t\t\t\t2- Load game\n\t\t\t\t\t\t3- Top players\n\t\t\t\t\t\t4- Quit\n");
                    printf("Please choose a valid option!!!\n");
                }
            }
         }
         if(mode==1){
                system("cls");
                system("COLOR 05");
            printboard(row,column,a,turn,1,play1,play2,undoarr,redoarr, seconds_passed);
            start_game(row,column,a,turn,play1,play2,undoarr,redoarr,computerturn, start, finish, seconds_passed);
         }
         else
         {
             system("cls");
             system("COLOR 05");
             computerturn=0;
             a[row][column]='0';
             printboard(row,column,a,turn,1,play1,play2,undoarr,redoarr, seconds_passed);
            start_game(row,column,a,turn,play1,play2,undoarr,redoarr,computerturn, start, finish, seconds_passed);
         }
    }
    if(menu==2)
    {
        load_game(/row,column,/a,undoarr,redoarr,0);
        if(x!=row||y!=column)
        {
            int undoarr1[row][column],redoarr1[row][column];
            char b[row+1][column+1];
            load_game(b,undoarr1,redoarr1,f);
            start_game(row,column,b,turn,play1,play2,undoarr1,redoarr1,computerturn,start,finish,seconds_passed);

        }
       else
        start_game(row,column,a,turn,play1,play2,undoarr,redoarr,computerturn,start,finish,seconds_passed);
    }
    if(menu==3)
    {  system("cls");
       printf("\n\n\t\t\t\t\tLeadboard:\n");
       read_scores();
    }
    //seconds_passed = (finish - start)/CLOCKS_PER_SEC;
    //printf("Time passed : %d hours : %d minutes : %d seconds\n", seconds_passed / 3600 % 24, (seconds_passed % 3600)/60, seconds_passed %3600 %60);
    return 0;

}
