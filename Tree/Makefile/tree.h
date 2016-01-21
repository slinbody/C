#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define node_num 9

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
bool find(Node* S,int data);
void delete_node(Node *S,int data);
void swap(int *a,int *b);
void level_check(Node *S,int level);
