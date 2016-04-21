#include <stdio.h>
#include <stdlib.h>
// 父行程創造10個子行程
// 子行程依序印出訊息
int main()
{
    int pid,i;
    printf("%s %d: parant: %d\n", __FUNCTION__, __LINE__, getpid());


    for(i=1;i<10;i++)
    {
        pid = fork();
        if (pid == 0)   //child
        {
//          printf("%s %d: child pid: %d, pid: %d\n", __FUNCTION__, __LINE__, getpid(), pid);
            sleep(i);
            printf("I am %d child, address: %p\n",i,&i);
            exit(0);
        }
        else
        {
            printf("%s %d: parant pid: %d, child pid: %d\n", __FUNCTION__, __LINE__, getpid(), pid);
//          waitpid(0,NULL,0);
        }
    }
}
