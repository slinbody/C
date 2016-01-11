#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

int main()
{
struct stack *s;
s->top=-1;
int i;

for(i=0;i<11;i++)
{
    push(s,i);
}

for(i=0;i<=10;i++)
{
    pop(s);
}

return 0;
}


void print_stack(struct stack *s)
{
    while(s->top > 0)
    {
        printf("%d\n",s->array[s->top]);
        s->top--;
    }
}

void current_num(struct stack *s)
{
    printf("# of stack: %d\n",s->top);

}

void pop(struct stack *s)
{
    if(s->top < 0)
    {
       printf("Stack is empty!!\n");
    }
    else
    {
        printf("pop: %d\n",s->array[s->top]);
        s->top--;
    }
}

void push(struct stack *s,int data)
{
    if(s->top == Max -1)
    {
        printf("Stack is FULL\n");
    }
    else
    {
        s->top++;
        s->array[s->top]=data;
        printf("push: %d\n",data);
    }
}
