#include <stdio.h>
#include <time.h>
#define a_size 10


void show_data(int data[]);
void split(int data[],int left,int right);

int main()
{
    int data[a_size]={0},i;
    srand(time(NULL));

    printf("Original Data: ");

    for(i=0;i<a_size;i++) // initial data
    {
        data[i]=(rand()%100)+1;
    }

    show_data(data);
    split(data,0,a_size-1);
//    show_data(data);

    return 0;
}

void show_data(int data[])
{
    int i;
    for(i=0;i<a_size;i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
}

void split(int data[],int left,int right)
{
    static int count=0;
    int mid,Ai,Bi,C[right-left+1],Ci,i;

    if (right == left)
    {
//        printf("%d -",data[right]);
        return;
    }
    mid = (left+right)/2;
    split(data,left,mid);
    split(data,mid+1,right);
//=======  merge  =============

    Ai=left;
    Bi=mid+1;
    Ci=0;
    while(Ai<=mid && Bi<=right)
    {
        if(data[Ai]>data[Bi])
        {
            C[Ci]=data[Bi];
            Bi++;
            Ci++;
        }
        else if (data[Ai] <= data[Bi])
        {
            C[Ci]=data[Ai];
            Ai++;
            Ci++;
        }
    }

        if(Ai>mid)
        {
            for(;Bi<=right;Bi++,Ci++)
                C[Ci]=data[Bi];
        }
        if(Bi>right)
        {
            for(;Ai<=mid;Ai++,Ci++)
                C[Ci]=data[Ai];
        }

    printf("This is %d\n",count);
    printf("left : %3d, right: %3d\n",left,right);

    for(i=0;i<Ci;i++,left++)
        data[left]=C[i];
    count++;
    show_data(data);
}
