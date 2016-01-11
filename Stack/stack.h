#define Max 10

struct stack {
    int top;
    int array[Max];
};

void print_stack(struct stack *s);
void current_num(struct stack *s);
void pop(struct stack *s);
void push(struct stack *s,int data);
