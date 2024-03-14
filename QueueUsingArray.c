//Implementing Queue using array

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int array[MAX];
int front = -1;
int rear = -1;
int size;

void enqueue(){
    if (rear == size-1){
        printf("\nQueue Overflow!");
    }
    else{
        if (front == -1){
            front = 0;
        }

        printf("Enter the element to be enqueued: ");
        scanf("%d", &array[++rear]);
    }
}

void dequeue(){
    if (front == -1 || front > rear){
        printf("\nQueue Underflow!");
    }
    else{
        printf("The element dequeued is: %d", array[front++]);
    }
}

void display(){
    if (front == -1){
        printf("\nQueue Underflow!");
    }
    else{
        for (int i = front; i <= rear; i++){
            printf("%d ", array[i]);
        }
    }
}

void atfront(){
    if (front == -1 || front > rear){
        printf("\nQueue Underflow!");
    }
    else{
        printf("The element at the front is: %d", array[front]);
    }
}

void atrear(){
    if (front == -1 || front > rear){
        printf("\nQueue Underflow!");
    }
    else{
        printf("The element at the rear is: %d", array[rear]);
    }
}

int main(){

    printf("Enter the size: ");
    scanf("%d",&size);

    while (1){
        int choice;
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. See at first");
        printf("\n5. See at last");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: atfront(); break;
            case 5: atrear(); break;
            case 6: exit(0); break;
            default: printf("\nEnter a valid choice!");
        }
    }
    
    return 0;
}
