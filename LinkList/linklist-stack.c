#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * Ptr;
};

typedef struct node Node;

void enqueue(Node *s,int data);

int main()
{
Node  *s=NULL,*p=NULL,*tmp;
int i;

//s initial
s =(Node *)malloc(sizeof(Node));
s->data = 10;
s->Ptr=NULL;


for(i=1;i<8;i++)
    enqueue(s,i);

while(s!=NULL)
{
    printf("%d\n",s->data);
    s = s->Ptr;
}

return 0;
}
void enqueue(Node *s,int data)
{
    Node *p=NULL;
    while(s->Ptr != NULL)
        s = s->Ptr;
    p =(Node *)malloc(sizeof(Node));
    p->data = data;
    p->Ptr=NULL;
    s->Ptr=p;
}
