#include "tree.h"


void level_check(Node *S,int level)
{
    if (S!=NULL)
    {
        S->level=level;
        level_check(S->left,level+1);
        level_check(S->right,level+1);
    }
}

void delete_node(Node *S,int data)
{
    Node *this=S,*parent,*tmp;
    while( this->data != data)
    {//確認父節點和本節點位置
        parent=this;
        if(this->data < data)
            this=this->right;
        else
            this=this->left;
        if(this == NULL)
        {
            printf("%d is not in tree\n",data);
            return;
        }
    }

    if(this->left == NULL && this->right == NULL)
    {//左右子樹皆為空
        if(parent->left == this)
            parent->left = NULL;
        else
            parent->right = NULL;
        free(this);
    }
    else if(this->left != NULL)
    {//左子樹不為空，找其最右子節點
        parent=this;
        tmp = this->left;
        if(tmp->right == NULL )
        {
            swap(&(tmp->data),&(this->data));
            parent->left=tmp->left;
        }
        else
        {
            while(tmp->right != NULL)
            {
                parent=tmp;
                tmp=tmp->right;
            }
            swap(&(tmp->data),&(this->data));
            parent->right=tmp->left;
        }
        free(tmp);
     }
     else
     {//右子樹不為空，找其最左子節點
            parent=this;
            tmp=this->right;
            if(tmp->left==NULL)
            {
                swap(&(tmp->data),&(this->data));
                parent->right=tmp->right;
            }
            else
            {
                while(tmp->left != NULL)
                {
                    parent=tmp;
                    tmp=tmp->left;
                }
                swap(&(tmp->data),&(this->data));
                parent->left=tmp->right;
            }
            free(tmp);
      }
    level_check(S,1);
}

void swap(int *a,int *b)
{   int tmp;
    tmp = *a;
    *a=*b;
    *b=tmp;
}

bool find(Node* S,int data)
{
    if(S==NULL)
    {
        printf("Not FOUND!!\n");
        return false;
    }
    else
    {
        if(S->data == data)
        {
            printf("%d is in tree\n",data);
            return true;
        }
        else if(data > S->data)
            return find(S->right,data);
        else
            return find(S->left,data);
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
