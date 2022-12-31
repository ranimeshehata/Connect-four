#ifndef REDO_H_INCLUDED
#define REDO_H_INCLUDED

void redo(int row,int column,char a[row+1][column+1],int turn,play play1,play play2,int undoarr[row][column],int redoarr[row][column],int computerturn, int seconds_passed){
    int i,j,cred=0;                 //to redo an undid move
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
                if(movex==moveo){  //when moves are equal then it's player's 1 turn and an 'X' is redone
                    a[i][j]='X';
                    }
                else if(movex>moveo)
                    a[i][j]='O';
                redoarr[i][j]=0;
            }
            if(computerturn==0&&redoarr[i][j]==last+2)
            {
                undoarr[i][j]=last+2;
                    a[i][j]='O';                //when moves of player 2 are greater than those of player1 then it's player's 2 turn and an 'O' is redone
                redoarr[i][j]=0;
            }
        }
    }
    system("cls");
    printboard(row,column,a,turn,1,play1,play2,undoarr,redoarr, seconds_passed);
    }
}

#endif // REDO_H_INCLUDED
