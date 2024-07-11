//Implementing circular queue using struct
#include<stdio.h>
#include<stdlib.h>

struct CircularQueue{
    int capacity;
    int size;
    int front;
    int rear;
    int *pArray;
};

struct CircularQueue *pCreateCircularQueue(unsigned capacity){
    struct CircularQueue *pCQueue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    pCQueue -> capacity = capacity;
    pCQueue -> size = 0;
    pCQueue -> front = -1;
    pCQueue -> rear = -1;
    pCQueue -> pArray = (int *)malloc(capacity * sizeof(int));
}
void enqueue(struct CircularQueue *pCQ){
    if (pCQ -> size >= pCQ -> capacity){
        printf("\nQueue Overflow!!!");
    }
    else{
        if (pCQ -> front == -1){
            pCQ -> front = 0;
        }
        printf("\nEnter the element to be enqueued: ");
        scanf("%d", (pCQ -> pArray + (++(pCQ -> rear) % pCQ -> capacity)));
        (pCQ -> size)++;
    }
}
void dequeue(struct CircularQueue *pCQ){
    if (pCQ -> size == 0){
        printf("\nQueue Underflow!!!");
    }
    else{
        if (pCQ -> front == -1){
            pCQ -> front = 0;
        }
        printf("\nThe element dequeued is: %d", *(pCQ -> pArray + ((pCQ -> front)++ % pCQ -> capacity)));
        (pCQ -> size)--;
    }
}
void lookatfront(struct CircularQueue *pCQ){
    if (pCQ -> size == 0){
        printf("\nThe queue is empty!");
    }
    else{
        printf("\nThe element at the front is: %d", *(pCQ -> pArray + (pCQ -> front) % pCQ -> capacity));
    }
}
void lookatrear(struct CircularQueue *pCQ){
    if (pCQ -> size == 0){
        printf("\nThe queue is empty!");
    }
    else{
        printf("\nThe element at the rear is: %d", *(pCQ -> pArray + (pCQ -> rear) % pCQ -> capacity));
    }
}

void display(struct CircularQueue *pCQ){
    if (pCQ -> size == 0){
        printf("\nThe queue is empty!");
    }
    else{
        for (int i = pCQ -> front; i <= pCQ -> rear; i++){
            printf("%d ", *(pCQ -> pArray + i));
        }
    }
}

int main(){
    unsigned capacity;
    printf("Enter the size of the circular: ");
    scanf("%u", &capacity);

    struct CircularQueue *pCQ = pCreateCircularQueue(capacity);
    
    int choice;
    while (1){
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Look at the front");
        printf("\n4. Look at the rear");
        printf("\n5. Display the queue");
        printf("\n6. Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: enqueue(pCQ); break;
            case 2: dequeue(pCQ); break;
            case 3: lookatfront(pCQ); break;
            case 4: lookatrear(pCQ); break;
            case 5: display(pCQ); break;
            case 6: free(pCQ); exit(0); break;
            default: printf("Enter a valid choice!\n");
        }
    }
    
    return 0;
}
