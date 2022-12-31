#ifndef UNDO_H_INCLUDED
#define UNDO_H_INCLUDED

void undo(int row,int column,char a[row+1][column+1],int turn,play play1,play play2,int undoarr[row][column],int redoarr[row][column],int computerturn, int seconds_passed){
    int i,j;            //to undo a played move
    int last=calc_moves(row,column,a,1,play1,play2)+calc_moves(row,column,a,2,play1,play2);
    if(last==0){
            system("cls");
            printboard(row,column,a,1,1,play1,play2,undoarr,redoarr, seconds_passed);
            printf("\033[0;31m");
    printf("The board is already empty!!!\n");        //when pressing undo at empty board
    player1(row,column,a,2,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
    if(computerturn==0)
        computer(row,column,a,2,play1,play2,undoarr,redoarr, seconds_passed);
    }
    else{
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            if(undoarr[i][j]==last)  //checking for the largest no in the undoarray, saving it in the redoarray and then deleting it from the board and the undo array
            {   redoarr[i][j]=undoarr[i][j];
                undoarr[i][j]=0;
                a[i][j]=' ';
            }
            if(undoarr[i][j]==last-1&&computerturn==0){  //undo when playing with computer
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

#endif // UNDO_H_INCLUDED
