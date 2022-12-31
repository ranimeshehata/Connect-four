#ifndef LOAD_GAME_H_INCLUDED
#define LOAD_GAME_H_INCLUDED

void load_game(char a[row+1][column+1],int undoarr[row][column],int redoarr[row][column],int file_no)     //to load a saved game from a binary file
{
    int check=1,i,j;
    char file_nost[100];
    system("cls");
    printf("Choose a file to load a game:\n1-File 1\n2-File 2\n3-File 3\n");        //choosing which game to load
    if(file_no==0)
    {
    while(check==1)
    {
        gets(file_nost);

        for(i=0;i<strlen(file_nost);i++)
        {
            if(!isdigit(file_nost[i]))
                {  system("cls");
                 printf("Please choose a valid file to load the game:\n1-File 1\n2-File 2\n3-File 3\n");           //if the user enters a character

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
                    printf("Please choose a valid file to load the game:\n1-File 1\n2-File 2\n3-File 3\n");      // if the user enters a number other than 1, 2, 3
                }
            }
    }
    }
    f=file_no;
    if(file_no==1)     // when choosing File 1
    {
        FILE*fp1;
        fp1=fopen("game1.bin","rb");
        if(fp1==NULL)
            {
                printf("There is no game to be loaded!!\n");
               int z;
               printf("Press 1 to return to main menu.\nPress any other button to start a new game.\n");
               scanf("%d",&z);
               if(z==1)
                menuu(1);
               else
                return;
            }
        else{
        row=fgetc(fp1);
        column=fgetc(fp1);
        for(i=0;i<row+1;i++)
        {
            for(j=0;j<column+1;j++)
              {

              a[i][j]=fgetc(fp1);        //reading the saved game from binary file 1
              }
        }
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {

                undoarr[i][j]=getc(fp1);       //reading the saved undo/redo arraies from binary file 1
                redoarr[i][j]=getc(fp1);
            }
        }
        fclose(fp1);
    }}
 else if(file_no==2)      // when choosing File 2
    {
        FILE*fp2;
        fp2=fopen("game2.bin","rb");
        if(fp2==NULL)
            {
                printf("There is no game to be loaded!!\n");
               int z;
               printf("Press 1 to return to main menu.\nPress any other button to start a new game.\n");
               scanf("%d",&z);
               if(z==1)
                menuu(1);
               else
                return;
            }

        else{
        row=fgetc(fp2);
        column=fgetc(fp2);
        for(i=0;i<row+1;i++)
        {
            for(j=0;j<column+1;j++)
               {
                a[i][j]=fgetc(fp2);         //reading the saved  game from binary file 2
               }
        }
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                 undoarr[i][j]=getc(fp2);       //reading the saved undo/redo arraies from binary file 2
              redoarr[i][j]=getc(fp2);
            }
        }
        fclose(fp2);
    }}
     else        // when choosing File 3
    {
        FILE*fp3;
        fp3=fopen("game3.bin","rb");
        if(fp3==NULL)
           {
               printf("There is no game to be loaded!!\n");
               int z;
               printf("Press 1 to return to main menu.\nPress any other button to start a new game.\n");
               scanf("%d",&z);
               if(z==1)
                menuu(1);
               else
                return;
           }
        else {
        row=fgetc(fp3);
        column=fgetc(fp3);
        for(i=0;i<row+1;i++)
        {
            for(j=0;j<column+1;j++)
               {
                 a[i][j]=fgetc(fp3);            //reading the saved game from binary file 3
               }
        }
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                 undoarr[i][j]=getc(fp3);
              redoarr[i][j]=getc(fp3);            //reading the saved undo/redo arraies from binary file 3
            }
        }
        fclose(fp3);
    }
}}

#endif // LOAD_GAME_H_INCLUDED
