#ifndef SAVE_GAME_H_INCLUDED
#define SAVE_GAME_H_INCLUDED

void save_game(int row , int column , char a[row+1][column+1],int undoarr[row][column],int redoarr[row][column])      //to save a game in binary file
{   int check=1,file_no,i,j;
    char file_nost[100];
    system("cls");
    printf("Choose a file to save the game:\n1-File 1\n2-File 2\n3-File 3\n");        //choosing where to save a game, it saves up to 3 games
    while(check==1)
    {
        gets(file_nost);
        for(i=0;i<strlen(file_nost);i++)          //if the user enters a character
        {
            if(!isdigit(file_nost[i]))
                {  system("cls");
                 printf("Please choose a valid file to save the game:\n1-File 1\n2-File 2\n3-File 3\n");
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
                    printf("Please choose a valid file to save the game:\n1-File 1\n2-File 2\n3-File 3\n");        // if the user enters a number other than 1, 2, 3
                }
            }
    }
    if(file_no==1)      // when choosing File 1
    {
        FILE*fp1;
        fp1=fopen("game1.bin","wb");
        fputc(row,fp1);
        fputc(column,fp1);
        for(i=0;i<row+1;i++)
        {
            for(j=0;j<column+1;j++)
              {
              fputc(a[i][j],fp1);   //saving the game board in binary file 1
              }
        }
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                fprintf(fp1,"%c%c",undoarr[i][j],redoarr[i][j]);         //saving the undo/redo arraies in binary file 1
            }
        }
        fclose(fp1);
    }
 else if(file_no==2)     // when choosing File 2
    {
        FILE*fp2;
        fp2=fopen("game2.bin","wb");
        fputc(row,fp2);
        fputc(column,fp2);
        for(i=0;i<row+1;i++)
        {
            for(j=0;j<column+1;j++)
               {
                   fputc(a[i][j],fp2);       //saving the game board in binary file 2
               }
        }
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                fprintf(fp2,"%c%c",undoarr[i][j],redoarr[i][j]);        //saving the undo/redo arraies in binary file 2
            }
        }
        fclose(fp2);
    }
     else            // when choosing File 3
    {
        FILE*fp3;
        fp3=fopen("game3.bin","wb");
        fputc(row,fp3);
        fputc(column,fp3);
        for(i=0;i<row+1;i++)
        {
            for(j=0;j<column+1;j++)
               {
                   fputc(a[i][j],fp3);     //saving the game board in binary file 3
               }
        }
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                fprintf(fp3,"%c%c",undoarr[i][j],redoarr[i][j]);           //saving the undo/redo arraies in binary file 3
            }
        }
        fclose(fp3);
    }
system("cls");
}


#endif // SAVE_GAME_H_INCLUDED
