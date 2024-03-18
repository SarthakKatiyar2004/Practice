//Implementing queue and its basic functions using 2 stacks

#include<stdio.h>

struct Stack{
    int top;
    int capacity;
    int *pArray;
};

struct Stack *pCreateStack(unsigned capacity){
    struct Stack *pStack = (struct Stack*)malloc(sizeof (struct Stack));
    pStack -> top = -1;
    pStack -> capacity = capacity;
    pStack -> pArray = (int *)malloc(pStack -> capacity *(sizeof(int)));
}

int main(){
    int size;
    printf("Enter the size of the queue: ");
    scanf("%lu", &size);

    struct Stack *pStk1 = pCreateStack(size);
    struct Stack *pStk2 = pCreateStack(size);

    return 0;
}
