#ifndef PRINTBOARD_H_INCLUDED
#define PRINTBOARD_H_INCLUDED

typedef struct
{
  char name[50];
   int score;
   int moves;
}play;          //structure that holds player's information

void printboard(int row,int column,char a[1+row][1+column],int turn,int sent,play play1,play play2,int undoarr[row][column],int redoarr[row][column], int seconds_passed)
    {          //printing the board
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
            printf("|-----");}              //printing the grid!!
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
        play1.score=total_score(row,column,a,2,play1,play2);
        play2.score=total_score(row,column,a,1,play1,play2);
        printf("\033[;31m");
        printf("Score X = %d     ",play1.score);       //printing player's 1 score
        printf("\033[;33m");
        printf("Score O = %d\n",play2.score);       //printing player's 2 score
        play1.moves=calc_moves(row,column,a,2,play1,play2);
        play2.moves=calc_moves(row,column,a,1,play1,play2);
        printf("\033[;31m");
        printf("Moves X = %d     ",play1.moves);            //printing player's 1 moves
        printf("\033[;33m");
        printf("Moves O = %d\n",play2.moves);               //printing player's 2 moves
        if(play1.moves+play2.moves==row*column)
        {
            printf("\033[;31m");
            printf("GAME OVER!!!\n");
            return;
        }
        else{
        if (turn==1){
            printf("\033[;31m");
           printf("Player's 1 turn\n");            //printing turn to player 1
           }
        else if(turn==2){
           printf("\033[;33m");
           printf("Player's 2 turn\n");}       //printing turn to player 2
        printf("\033[;34m");
        printf("To undo press u\n");        //printing in game menu
        printf("To redo press r\n");
        printf("To save press s\n");
        printf("For menu press m\n");
      if(sent==1){
            printf("Enter a column number.\n");}         //asking the player to choose a column everytime
      else if(sent==0){
            printf("Enter a valid column number!!\n");}        //if the player enters a character or a number out of scope
      else if(sent==2){
            printf("Please choose an empty column!!\n");}        //if the player chooses a full column
   } }

#endif // PRINTBOARD_H_INCLUDED
