#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * Ptr;
};

typedef struct node Node;

Node * enqueue_tail(Node *s,int data);
Node * enqueue_head(Node *s,int data);
void dequeue_tail(Node *s);
Node * dequeue_head(Node *s);

int main()
{
Node  *s=NULL,*p=NULL,*tmp;
int i;

for(i=20;i<29;i++)
    s=enqueue_tail(s,i);
    //s=enqueue_head(s,i);

for(i=0;i<2;i++)
    dequeue_tail(s);

while(s!=NULL)
{
    printf("%d\n",s->data);
    s = s->Ptr;
}

return 0;
} //end of main

Node * enqueue_tail(Node *s,int data)
{
    Node *p=NULL,*tmp;
    p =(Node *)malloc(sizeof(Node));
    p->data = data;
    p->Ptr=NULL;

    if(s==NULL)
        return p;
    else
    {
        tmp = s;
        while(tmp->Ptr!=NULL)
            tmp=tmp->Ptr;
        tmp->Ptr=p;
        return s;
    }
}

Node * enqueue_head(Node *s,int data)
{
    Node *p=NULL;
    p =(Node *)malloc(sizeof(Node));
    p->data = data;
    p->Ptr=s;
    return p;
}

void dequeue_tail(Node *s)
{
    Node *tmp;
    if(s==NULL)
        return;

    tmp=s->Ptr;
    while(tmp->Ptr!=NULL)
    {
        s=tmp;
        tmp=tmp->Ptr;
    }
    s->Ptr=NULL;
    free(tmp);
}
