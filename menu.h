#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menuu(int geto)     //MAIN MENU FUNCTION
{
     int i,j,turn=1,end=1,computerturn=1,menucheck=1,modecheck=1,menu,mode,x,y;
     char lol[1],menust[1000],modest[1000];
     clock_t start;
     int seconds_passed=0;
     clock_t finish;
     play play1,play2;
     play1.score=0;
     play2.score=0;
     xml();               //calling that function to read the XML file and checking for configurations
     int undoarr[row][column],redoarr[row][column];
     char a[row+1][column+1];
     x=row;
     y=column;
     for (i=0;i<row+1;i++)
        {
            for(j=0;j<column+1;j++)
            {
                a[i][j]=' ';             //initiallizing the board array to white spaces
                undoarr[i][j]=0;          //initiallizing undo/redo arraies to zero
                redoarr[i][j]=0;
            }
        }
    system("COLOR F5");
    system("cls");
    printf("\033[1;35m");
    printf(" \n\n\n\n\t\t\t\t\t\t< MAIN MENU >\n\t\t\t\t\t\t1-New game\n\t\t\t\t\t\t2-Load game\n\t\t\t\t\t\t3-Top players\n\t\t\t\t\t\t4-Quit\n");  //PRINTING MAIN MENU
    printf("Please choose an option.\n");
   while(menucheck==1)
        {   if (geto!=0)
               gets(lol);
             geto=0;                  //reading the chosen option from the user
            gets(menust);
                for(i=0;i<strlen(menust);i++)
        {
            if(!isdigit(menust[i]))      //when user enters an invalid character
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
                    menucheck=0;   //if user enters a valid choice
                else
                {   system("cls");
                    printf(" \n\n\n\n\t\t\t\t\t\tMAIN MENU\n\t\t\t\t\t\t1-New game\n\t\t\t\t\t\t2-Load game\n\t\t\t\t\t\t3-Top players\n\t\t\t\t\t\t4-Quit\n");
                    printf("Please choose a valid option!!!\n");
                }
            }
        }
    if(menu==1)         //CHOOSING NEW GAME!!
    {
        while(modecheck==1){
        printf("1- Vs human\n2- Vs computer\n");        //asking for game mode
        gets(modest);
         for(i=0;i<strlen(modest);i++)
        {
            if(!isdigit(modest[i]))       //when user enters an invalid character
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
                    modecheck=0;         //if user enters a valid choice
                else
                {   system("cls");
                    printf(" \n\n\n\n\t\t\t\t\t\t< MAIN MENU >\n\t\t\t\t\t\t1- New game\n\t\t\t\t\t\t2- Load game\n\t\t\t\t\t\t3- Top players\n\t\t\t\t\t\t4- Quit\n");
                    printf("Please choose a valid option!!!\n");
                }
            }
         }
         if(mode==1){       // VS. HUMAN MODE
                system("cls");
                system("COLOR 05");
            printboard(row,column,a,turn,1,play1,play2,undoarr,redoarr, seconds_passed);
            start_game(row,column,a,turn,play1,play2,undoarr,redoarr,computerturn, start, finish, seconds_passed);
         }
         else
         {             //VS. COMPUTER MODE
             system("cls");
             system("COLOR 05");
             computerturn=0;
             a[row][column]='0';
             printboard(row,column,a,turn,1,play1,play2,undoarr,redoarr, seconds_passed);
            start_game(row,column,a,turn,play1,play2,undoarr,redoarr,computerturn, start, finish, seconds_passed);
         }
    }
    if(menu==2)    //CHOOSING LOAD GAME!!
    {
        load_game(a,undoarr,redoarr,0);
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
    if(menu==3)        //CHOOSING TOP PLAYERS!!
    {  system("cls");
       printf("\n\n\t\t\t\t\tLeadboard:\n");
       read_scores();    //printing the leaderboard
       int meee;
       printf("Press 1 to return to main menu\n");
       scanf("%d",&meee);
       if(meee==1)
        menuu(1);
    }
    else if(menu==4)        //quitting the game
        return;
}

#endif // MENU_H_INCLUDED
