#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED

void computer(int row,int column,char a[row+1][column+1],int turn, play play1, play play2,int undoarr[row][column],int redoarr[row][column], int seconds_passed)
{                      //called at vs.computer mode for the computer to play random moves
    int i,j,count=0;
    for(i=row-1;i>-1;i--)
    {
        for(j=0;j<column;j++)
        {
            if(a[i][j]==' ')                   //computer passes through all cells and plays 'O' once he founds an empty cell then breaks
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

#endif // COMPUTER_H_INCLUDED
