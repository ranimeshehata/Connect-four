#ifndef TOTAL_SCORE_H_INCLUDED
#define TOTAL_SCORE_H_INCLUDED

int total_score(int row,int column,char a[1+row][1+column],int turn,play play1,play play2)
{                                             //function to check for a connect four
    int i,j;
    if (turn==2) //player's 1 score
    {
        play1.score=0;
        for(i=row-1;i>-1;i--)
        {
            for(j=0;j<column;j++)
            {
                if(a[i][j]=='X'&&a[i][j+1]=='X'&&a[i][j+2]=='X'&&a[i][j+3]=='X')     //checking for a horizontal win   (-)
                   play1.score++;
                if(a[i][j]=='X'&&a[i-1][j]=='X'&&a[i-2][j]=='X'&&a[i-3][j]=='X')        //checking for a vertical win   (|)
                    play1.score++;
                if(a[i][j]=='X'&&a[i-1][j+1]=='X'&&a[i-2][j+2]=='X'&&a[i-3][j+3]=='X')         //checking for a diagonally right win   (/)
                    play1.score++;
                if(a[i][j]=='X'&&a[i+1][j+1]=='X'&&a[i+2][j+2]=='X'&&a[i+3][j+3]=='X')              //checking for a diagonally left win   (\)
                    play1.score++;
            }
        }
        return play1.score;
     }
    else if(turn==1)  //player's 2 score
     {
        play2.score=0;
        for(i=row-1;i>-1;i--)
        {
            for(j=0;j<column;j++)
            {
                if(a[i][j]=='O'&&a[i][j+1]=='O'&&a[i][j+2]=='O'&&a[i][j+3]=='O')             //checking for a horizontal win (-)
                    play2.score++;
                if(a[i][j]=='O'&&a[i-1][j]=='O'&&a[i-2][j]=='O'&&a[i-3][j]=='O')              //checking for a vertical win   (|)
                    play2.score++;
               if(a[i][j]=='O'&&a[i-1][j+1]=='O'&&a[i-2][j+2]=='O'&&a[i-3][j+3]=='O')             //checking for a diagonally right win   (/)
                    play2.score++;
                if(a[i][j]=='O'&&a[i+1][j+1]=='O'&&a[i+2][j+2]=='O'&&a[i+3][j+3]=='O')            //checking for a diagonally left win   (\)
                    play2.score++;
            }
        }
        return play2.score;
    }
}

#endif // TOTAL_SCORE_H_INCLUDED
