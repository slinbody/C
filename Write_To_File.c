#include<stdio.h>
#include <stdlib.h>
#define Max_Buffer 80
int main()
{
FILE * fp;
char words[Max_Buffer];
int i;
fp=fopen("/tmp/c/score.txt","w");

while(1)
{
scanf("%s",words);
fprintf(fp,"%s\n",words);
fflush(fp);//immediatelyy write to file
}

fclose(fp);
return 0;
}
