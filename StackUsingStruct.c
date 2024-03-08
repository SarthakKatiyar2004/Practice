//Implementing stack using struct

#include<stdio.h>

//Structure for Stack
struct Stack{
    int top;
    unsigned capacity;
    int *pArray;
};


//Function that creates a stack structure according to user-defined size
struct Stack *pCreateStack(unsigned capacity){
    struct Stack *pStack = (struct Stack*)malloc(sizeof(struct Stack)); //creating a structure pointer 'pStack' that's malloced to occupy the memory of the structure Stack.
    pStack -> top = -1; // assigning -1 as the value of top of the pointer pointing at Stack
    pStack -> capacity = capacity; //assigning the user-defined capacity as the value of capacity of the pointer pointing at Stack
    pStack -> pArray = (int *)malloc(pStack -> capacity*sizeof(int)); //mallocing the size of the pointer pointing at array of the pointer pointing at stack to capacity * size of int
}

//Basic operations of a stack

void push();
void pop();
void peek();
void display();

int main()
