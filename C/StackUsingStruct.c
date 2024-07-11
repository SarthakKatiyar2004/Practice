//Implementing stack using struct

#include<stdio.h>
#include<stdlib.h>

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

void push(struct Stack *pStack){
    if (pStack -> top == pStack -> capacity - 1){
        printf("\nStack overflow!");
    } else{
        printf("\nEnter the element to be pushed: ");
        scanf("%d", (pStack -> pArray + ++(pStack -> top)));
    }
}

void pop(struct Stack *pStack){
    if (pStack -> top == -1){
        printf("\nStack Underflow!");
    } else{
        printf("\nThe popped element is: %d", *(pStack->pArray + (pStack -> top)--));
    }
}
void peek(struct Stack *pStack){
    if (pStack -> top == -1){
        printf("\nThere's no element in the stack!");
    } else{
        printf("\nThe element at the top is: %d",*(pStack -> pArray + pStack -> top));
    }
}
void display(struct Stack *pStack){
    printf("\nThe Stack is: ");
    for (int i = 0; i <= pStack -> top; i++){
        printf("%d ",*(pStack -> pArray + i));
    }
}

//Main loop

int main(){
    unsigned size;
    printf("Enter the size of the stack: ");
    scanf("%u",&size);

    struct Stack* stack = pCreateStack(size);

    while (1){
        int choice;
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

    switch(choice){
        case 1:
            push(stack);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            peek(stack);
            break;
        case 4:
            display(stack);
            break;
        case 5:
            free(stack);
            exit(0);
            break;
        default:
            printf("Enter a valid choice!");
        }
    }

    return 0;
}
