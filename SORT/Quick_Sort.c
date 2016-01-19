#include <stdio.h>
#include <time.h>
#define a_size 20


void show_data(int data[]);
void quick_sort(int data[],int left,int right);

int main()
{
//    int data[a_size]={92,91,79,61,2,19,39,36,66,1};
    int data[a_size]={0},i;
    srand(time(NULL));

    printf("Original Data: ");

    for(i=0;i<a_size;i++) // initial data
    {
        data[i]=(rand()%100)+1;
    }

    show_data(data);
    quick_sort(data,0,a_size-1);
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

void quick_sort(int data[],int left,int right)
{
    int tmp,pos=left,left_tmp=left,right_tmp=right;
    if(left>=right)
        return ;
    while(left_tmp<right_tmp)
    {
        while(data[left_tmp]<=data[pos])
            left_tmp++;
        while(data[right_tmp]>data[pos])
            right_tmp--;
        if(left_tmp<right_tmp)
        {
            tmp=data[left_tmp];
            data[left_tmp]=data[right_tmp];
            data[right_tmp]=tmp;
        }
    }
    tmp=data[pos];
    data[pos]=data[right_tmp];
    data[right_tmp]=tmp;
    pos=right_tmp;
    printf("Hit any key to continue\n");
    getchar();
    show_data(data);
    quick_sort(data,left,pos-1);
    quick_sort(data,pos+1,right);
}
