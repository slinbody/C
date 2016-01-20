#include <stdio.h>
#include <time.h>
#define a_size 20
#define ANSI_COLOR_GREEN   "\x1b[32m"              //How to printf with color
#define ANSI_COLOR_RESET   "\x1b[0m"               //http://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c

void show_data(int data[]);
void split(int data[],int left,int right);
void show_data_change(int data[],int left,int right);

int main()
{
//    int data[a_size]={87,1,88};

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
        printf("%2d ",data[i]);
    }
    printf("\n");
}

void show_data_change(int data[],int left,int right)
{
    int i;
    for(i=0;i<a_size;i++)
    {
        if(left == i)
            printf(ANSI_COLOR_GREEN);
        printf("%2d ",data[i]);
        if(right == i)
            printf(ANSI_COLOR_RESET);
    }
    printf("\n");
}

void split(int data[],int left,int right)
{
    static int count=0;
    int mid,Ai,Bi,C[right-left+1],Ci,i,tmp;

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
    tmp=left;
    for(i=0;i<Ci;i++,tmp++)
        data[tmp]=C[i];
    count++;
    show_data_change(data,left,right);

}
