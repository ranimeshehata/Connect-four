#ifndef HIGHSCORES_FUNCTIONS_H_INCLUDED
#define HIGHSCORES_FUNCTIONS_H_INCLUDED

typedef struct{
   char name[50];
   int score;
}scores;            //structure to record the player's score

scores pscores[100];

void write_scores(int winscore, play play1)
{   int i,j,k=0,temp=0;
    FILE*fp;
    fp=fopen("highscores.bin","rb");        //function to write highscores in a binary file
    fread(pscores,sizeof(scores),100,fp);
    fclose(fp);
    for(i=0;i<100;i++)
    {
        if(pscores[i].score==0)
            break;
    }
    strcpy(pscores[i].name,play1.name);
    pscores[i].score=winscore;
    arrange(i);   //arranging the scores
    fp=fopen("highscores.bin","wb");
    fwrite(pscores,sizeof(scores),100,fp);
    fclose(fp);
}

void arrange(int len)        //for sorting the scores descendingly
{ int i,j,temp;
  char wait[50];
  for(i=0;i<len;i++)
  {
      if(!(strcasecmp(pscores[len].name,pscores[i].name)))
      {
          if(pscores[len].score>pscores[i].score)
          {
              pscores[i].score=pscores[len].score;
              pscores[len].score=0;
          }
          else if(pscores[len].score<pscores[i].score)
            {pscores[len].score=0;
            strcpy(pscores[len].name,"");}
      }
  }
  for (i=0;i<=len;i++)
  {
      for(j=i+1;j<=len;j++)
      {
          if(pscores[i].score<pscores[j].score)
          {
              temp=pscores[i].score;          //swapping the scores and names
              pscores[i].score=pscores[j].score;
              pscores[j].score=temp;
              strcpy(wait,pscores[i].name);
              strcpy(pscores[i].name,pscores[j].name);
              strcpy(pscores[j].name,wait);
          }
      }
  }
}

void read_scores()
{   int i;
    FILE*fp;
    fp=fopen("highscores.bin","rb");           //to read highscores from a binary file
    if(fp!=NULL)
    {
        fread(pscores,sizeof(scores),100,fp);
    }
    else
       {printf("The leaderboard is empty!!!\n");       //if no score is in file
        return;
    }fclose(fp);
    for(i=0;i<100;i++)
    {
        if(pscores[i].score==0)
            break;
    }
    arrange(i);
    fp=fopen("highscors.bin","rb");
        fwrite(&pscores,sizeof(scores),100,fp);
    fclose(fp);
    print_scores();
}

void print_scores()
{
    int i;
    for(i=0;i<highno;i++)
    {
         printf("  %d- %s %d\n",i+1,pscores[i].name,pscores[i].score);      //displaying highscores on screen
         if(pscores[i+1].score==0)
            break;
    }
}


#endif // HIGHSCORES_FUNCTIONS_H_INCLUDED
