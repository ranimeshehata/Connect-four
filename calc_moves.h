#ifndef CALC_MOVES_H_INCLUDED
#define CALC_MOVES_H_INCLUDED

int calc_moves(int row,int column,char a[1+row][1+column],int turn,play play1,play play2)  //function to calculate no of moves for each player
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
        return play1.moves;      //player's 1 moves
    }
    if(turn==1)
    {
        play2.moves=0;
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                if(a[i][j]=='O')         //player's 2 moves
                    play2.moves++;
            }
        }
    }
    return play2.moves;
}

#endif // CALC_MOVES_H_INCLUDED
