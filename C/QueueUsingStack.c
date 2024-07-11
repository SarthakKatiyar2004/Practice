#include<stdio.h>
#include<stdlib.h>

typedef struct Stack {
    int size;
    int top;
    int *pArray;
} Stack;

Stack *pCreateStack(int capacity){
    Stack *pStack = (Stack *)malloc(sizeof(Stack));
    pStack -> size = capacity;
    pStack -> top = -1;
    pStack -> pArray = (int*)malloc(capacity * sizeof(int));
}

void display(Stack *pPrimary){
    if (pPrimary -> top == -1){
        printf("\nQueue Underflow!");
    }
    else{
        for (int i = 0; i <= pPrimary -> top; i++){
            printf("%d ", *(pPrimary -> pArray + i));
        }
    }
}

void enqueue(Stack *pPrimary){
    if (pPrimary -> top == (pPrimary -> size - 1)){
        printf("\nQueue Overflow!");
    }
    else{
        int num;
        printf("\nEnter the number to be Enqueued: ");
        scanf("%d", &num);
        *(pPrimary -> pArray + ++(pPrimary -> top)) = num;
    }
}

void dequeue(Stack *pPrimary, Stack *pSecondary){
    if (pPrimary -> top == -1){
        printf("\nQueue Underflow!");
    }
    else{
        while (pPrimary -> top != -1){
            *(pSecondary -> pArray + ++pSecondary -> top) = *(pPrimary -> pArray + pPrimary -> top--);
        }
        
        printf("The Dequeued Element is: %d ", *(pSecondary -> pArray + (pSecondary -> top)--));
        
        while (pSecondary -> top != -1){
            *(pPrimary -> pArray + ++pPrimary -> top) = *(pSecondary -> pArray+ pSecondary -> top--);
        }
    }
}

int main(){
    
    int capacity;
    printf("Enter the size of the Queue: ");
    scanf("%d", &capacity);
    
    Stack *pPrimaryStack = pCreateStack(capacity);
    Stack *pSecondaryStack = pCreateStack(capacity);
    
    while (1){
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice){
            case 1:
                enqueue(pPrimaryStack);
                break;
            case 2:
                dequeue(pPrimaryStack, pSecondaryStack);
                break;
            case 3:
                display(pPrimaryStack);
                break;
            case 4:
                free(pPrimaryStack);
                free(pSecondaryStack);
                exit(0);
                break;
        }
    }
    
    return 0;
}
