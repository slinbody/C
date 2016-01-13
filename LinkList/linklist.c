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
Node * reverse_list(Node *s);
void print_list(Node *s);

int main()
{
Node  *s=NULL,*p=NULL,*tmp;
int i;

for(i=20;i<29;i++)
    s=enqueue_tail(s,i);
    //s=enqueue_head(s,i);

for(i=0;i<6;i++)
    //dequeue_tail(s);
    s=dequeue_head(s);

while(s!=NULL)
{
    printf("%d\n",s->data);
    s = s->Ptr;
}

return 0;
} //end of main

Node * reverse_list(Node *s)//反轉list
{
    Node *tmp1=s,*tmp2,*tmp3=NULL;
    if(s=NULL)
        return NULL;
    while(tmp1 != NULL)
    {
        tmp2=tmp1->Ptr;
        tmp1->Ptr=tmp3;
        tmp3=tmp1;
        tmp1=tmp2;
    }
    return tmp3;
}

void print_list(Node *s)//印出內容
{
    printf("This is HEAD!\n");
    while(s!=NULL)
    {
        printf("%d\n",s->data);
        s = s->Ptr;
    }
}

Node * enqueue_tail(Node *s,int data)//從尾端插入
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

Node * enqueue_head(Node *s,int data)//從前端插入
{
    Node *p=NULL;
    p =(Node *)malloc(sizeof(Node));
    p->data = data;
    p->Ptr=s;
    return p;
}

void dequeue_tail(Node *s) //從尾端刪除
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


Node * dequeue_head(Node * s) //從頭刪除
{
    Node *tmp;
    if(s==NULL)
        return NULL;

    tmp=s;
    s=tmp->Ptr;
    free(tmp);
    return s;
}
