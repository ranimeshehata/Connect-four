#ifndef START_GAME_H_INCLUDED
#define START_GAME_H_INCLUDED

void start_game(int row,int column,char a[1+row][1+column],int turn,play play1,play play2,int undoarr[row][column],int redoarr[row][column],int computerturn, clock_t start, clock_t finish, int seconds_passed)
{                         //where palyers' functions are called
    int i,x,y,z;
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
           {                         //player 1 plays at turn=1
            turn++;
            player1(row,column,a,turn,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
            finish = clock() ;      // time function
            seconds_passed += (finish - start)/CLOCKS_PER_SEC;
            printf("Time passed : %d hours : %d minutes : %d seconds\n", seconds_passed / 3600 % 24, (seconds_passed % 3600)/60, seconds_passed %3600 %60);  //printing time in seconds, minutes, hours
            }
        else if(turn==2&&computerturn==1)         //player 2 plays at turn=2 and computer's turn=1
           {
               turn--;
               player2(row,column,a,turn,play1,play2,undoarr,redoarr,computerturn, seconds_passed);
               finish = clock() ;      //time function
              seconds_passed += (finish - start)/CLOCKS_PER_SEC;
     printf("Time passed : %d hours : %d minutes : %d seconds\n", seconds_passed / 3600 % 24, (seconds_passed % 3600)/60, seconds_passed %3600 %60);
           }
        else if(computerturn==0)
        {                        //computer plays at turn=0
            turn--;
            computer(row,column,a,turn,play1,play2,undoarr,redoarr, seconds_passed);
          finish = clock() ;      //time function
    seconds_passed += (finish - start)/CLOCKS_PER_SEC;
    printf("Time passed : %d hours : %d minutes : %d seconds\n", seconds_passed / 3600 % 24, (seconds_passed % 3600)/60, seconds_passed %3600 %60);
        }
    }
    x=total_score(row,column,a,2,play1,play2);        //calculating player's 1 score
    y=total_score(row,column,a,1,play1,play2);        //calculating player's 2 score
    if(i==row*column-1)
    {
       if(x>y)                             //checking for a winner!!
       {
           printf("Player 1 wins!!\nPlease enter your name:\n");
           gets(play1.name);
           write_scores(x,play1);                 // asking for the winner's name and writing his score in the leaderboard
       }
       else if(x<y)
       {
           printf("Player 2 wins!!\nPlease enter your name:\n");
           gets(play2.name);
           write_scores(y,play2);
       }
       else
       {
            printf("\033[1;35m");                    //there's no winner!!
         printf("It's a tie!!\n");
       }
       printf("Leaderboard:\n");
       read_scores();                        //displaying the leaderboard on screen
       printf("Press 1 if you want to return to main menu?\n");                 //asking the player if he wants to return to menu when game ends
       scanf("%d",&z);
       if(z==1)
           menuu(1);
    }
}


#endif // START_GAME_H_INCLUDED
