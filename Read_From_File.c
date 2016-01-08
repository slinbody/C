#include<stdio.h>

int main()
{

FILE *fp;
char words[80];
char c;
int line=1,score1,score2;

fp=fopen("/root/c/score.txt","r+");
if(fp == NULL)
    printf("File open failed!!");


while(scanf(" %d",&line) > 0)

{
fseek(fp,19*line,SEEK_SET);
fgets(words,19,fp);
fprintf(stdout,"%s\n",words);
line++;
}

fclose(fp);
return 0;
}
