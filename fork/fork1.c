#include <stdio.h>
//fork() return child pid to parent pid
//                      0 to child pid
//codes above fork() are not excute!!
int main()
{
        int n;
        printf("hello my pid is :%d\n", getpid());

        n = fork();
        printf("hi my pid is: %d, the fork() return: %d\n", getpid(), n);
}
