#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node {
    struct node * left;
    int data;
    int level;
    struct node * right;
};

typedef struct node Node;

Node * insert_tree(Node *s,int data, int level);
void printf_in_order(Node *s);
void printf_tree(Node *s);
void find_Node(Node* S,int data);

int main()
{
Node *S = NULL;

int array_init[10];
int i,j,tmp;

srand(time(NULL));
printf("Original Data: ");
for(i=0;i<10;i++)
{
    array_init[i]=(rand()%100)+1;
    printf("%d ",array_init[i]);
}
printf("\n");

for(i=0;i<10;i++)
    S=insert_tree(S,array_init[i],0);

//printf("%d \n",S->data);

printf_in_order(S);
printf("\n");
return 0;
}//           end of main

void find(Node* S,int data)
{
    if(S==NULL)
        printf("Not FOUND!!\n");
    else
    {
        if(S->data == data)
            printf("%d is in tree\n",data);
        else if(data > S->data)
            find(S->right,data);
        else
            find(S->left,data);
    }
}

Node * insert_tree(Node *s,int data,int level)
{
    if(s == NULL)
    {
        s=(Node *)malloc(sizeof(Node));
        s->data=data;
        s->level=level+1;
        s->right=NULL;
        s->left=NULL;
        return s;
    }
    else if(data>s->data)
        s->right=insert_tree(s->right,data,level+1);
    else
        s->left=insert_tree(s->left,data,level+1);

}

void printf_in_order(Node *s)
{
    if(s==NULL)
        return;
    printf_in_order(s->left);
    printf("%d(%d) ",s->data,s->level);
    printf_in_order(s->right);

}
