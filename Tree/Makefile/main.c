#include"tree.h"

int main()
{
Node *S = NULL;

int array_init[node_num]={20,15,14,18,13,16,12,11,10};
int i;
/*
srand(time(NULL));
printf("Original Data: ");
for(i=0;i<node_num;i++)
{
    array_init[i]=(rand()%100)+1;
    printf("%d ",array_init[i]);
}
printf("\n");
*/
for(i=0;i<node_num;i++)
    S=insert_tree(S,array_init[i],0);

//printf("%d \n",S->data);

printf_in_order(S);
printf("\n");

delete_node(S,15);

printf_in_order(S);
printf("\n");

return 0;
}//           end of main
