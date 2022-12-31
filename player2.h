#ifndef PLAYER2_H_INCLUDED
#define PLAYER2_H_INCLUDED

void player2(int row,int column,char a[1+row][1+column],int turn,play play1,play play2,int undoarr[row][column],int redoarr[row][column],int computerturn, int seconds_passed)
{                             //called at player's 2 turn
      int col,check=1,i,full=1,j,k,cred=0;
      char x_column[1000];
      while(check==1)
        {
            gets(x_column);
            if((x_column[0]=='u'||x_column[0]=='U')&&strlen(x_column)==1)                //when player 2 presses undo
            {
                {
                    undo(row,column,a,1,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
                    player1(row,column,a,2,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
                }
            }
            else if((x_column[0]=='r'||x_column[0]=='R')&&strlen(x_column)==1)                     //when player 2 presses redo
                {
                    redo(row,column,a,turn,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
                player1(row,column,a,2,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
            }
           else if((x_column[0]=='s'||x_column[0]=='S')&&strlen(x_column)==1)              //when player 2 presses save
            {
                a[row-1][column]='1';
                save_game(row,column,a,undoarr,redoarr);
                printboard(row,column,a,2,1,play1,play2,undoarr,redoarr,seconds_passed);
            }
             else if((x_column[0]=='m'||x_column[0]=='M')&&strlen(x_column)==1)                      //if player 2 wants to go back to main menu
            {
                menuu(0);
                check=0;
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
                col=atoi(x_column);                             // when player 2 enters a character or anything other than a valid column number
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
            a[i][col]='O';                                   //checking for empty cell to put O
            undoarr[i][col]=calc_moves(row,column,a,2,play1,play2)+calc_moves(row,column,a,1,play1,play2);

            full=0;
            break;
           }
      }
      if(full==1)
      {                                               //when player 2 chooses a full column
          system("cls");
          printboard(row,column,a,2,2,play1,play2,undoarr,redoarr, seconds_passed);
          player2(row,column,a,1,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
      }
      system("cls");
printboard(row,column,a,turn,1,play1,play2,undoarr,redoarr, seconds_passed);
}

#endif // PLAYER2_H_INCLUDED
