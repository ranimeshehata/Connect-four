#ifndef XML_H_INCLUDED
#define XML_H_INCLUDED

int row;
int column;
int highno;
int f;
void xml(){
   char a[200],b[200],y;

   char c1[]="<configurations>",c2[]="</configurations>",h1[]="<Height>",h2[]="</Height>",w1[]="<Width>",w2[]="</Width>",hi1[]="<Highscores>",hi2[]="</Highscores>";  //declaring start and end of each tag in the XML file
   char filepath[200];
   int i=0,c,k,j,s=0;
   int in1,in2,in3,in4,in5,in6,x,z;
      FILE*fp;
   fp=fopen("conf.xml","r");  //reading an XML file
   if(fp!=NULL)
   {
       while((y=fgetc(fp))!=EOF)
   {
       if(y!=' '&&y!='\n'&&y!='\t')     //ignoring any spaces or break lines or tabs
       {
           a[s]=y;
           s++;
       }
   }
    fclose(fp);
    x=xml_ind(a,c1);  //checking for indexes
    z=xml_ind(a,c2);
    in1=xml_ind(a,h1);
    in2=xml_ind(a,h2);
    row=checkop(a,in1,in2);
    in3=xml_ind(a,w1);
    in4=xml_ind(a,w2);
    column=checkop(a,in3,in4);
    in5=xml_ind(a,hi1);
    in6=xml_ind(a,hi2);
    highno=checkop(a,in5,in6);}
     if(fp==NULL||row==-1||column==-1||highno==-1||x==-1||z==-1||in2<in1||in4<in3||in6<in5||x>in1||z<in6)
    {    system("cls");
         system("COLOR 05");
        printf("\033[;31m");
        printf("The XML file is corrupted!!!\n");
        for(i=0;i<3;i++)
        {
             for(k=0;k<strlen(a);k++)
               a[i]=NULL;
            printf("will load default in %d\n",3-i);
            printf("Please enter a valid file path!!!:\n");
            gets(filepath);
            fp=fopen(filepath,"r");
            if(1)
            {
                s=0;
                 while((y=fgetc(fp))!=EOF)
                {
                    if(y!=' '&&y!='\n'&&y!='\t')
                     {
                         a[s]=y;
                         s++;
                     }
                }
                fclose(fp);
                in1=xml_ind(a,h1);
                in2=xml_ind(a,h2);
                row=checkop(a,in1,in2);
                in1=xml_ind(a,w1);
                in2=xml_ind(a,w2);
                column=checkop(a,in1,in2);
                in1=xml_ind(a,hi1);
                in2=xml_ind(a,hi2);
                highno=checkop(a,in1,in2);
            }
            if(row!=-1&&row>=4&&column!=-1&&column>=4&&highno!=-1)
                break;
            if(i==2)
            {
                printf("Loading the default parameters");        //setting default values if there's anything wrong in the XML file
                row=7;
                column=9;
                highno=10;
            }
        }
    }

}
int xml_ind(char a[],char check[])
{ int i,j,c,k;
    for(i=0;i<strlen(a);i++)
    {
        c=0,k=i;
        for(j=0;j<strlen(check);j++)
        {
            if(check[j]==a[k])
            {
                c++;
                k++;
            }
            else
                break;
        }
        if(c==strlen(check))
        {
            break;
        }
    }
    if(i==strlen(a))
        return -1;
    else if(check[1]=='/')
        return i;
    else
        return i+strlen(check)-1;
}
int checkop(char a[],int in1,int in2)  //assigning the string between the tags in a substring
{ int check=1,i,k=0;
  char sub[200];
  for(i=in1+1;i<in2;i++)
  {
      sub[k]=a[i];
      k++;
  }
  checkop2(sub,k);
}
int checkop2(char sub[],int k)
{
    int i,var=-1,j,t,a[200];
    for(i=0;i<k;i++)
    {
        if(!isdigit(sub[i]))
            break;
    }
    for(j=0;j<k;j++)
        a[j]=sub[j]-48;

    if(i==k)
    {
        var=0;
        int t=k;
        for(j=0;j<k;j++)
          {
              var=var+a[j]*pow(10,t-1);
              t--;
            }
    }
    return var;
}
#endif // XML_H_INCLUDED
