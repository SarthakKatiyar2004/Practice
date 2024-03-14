//C Program to implement Queue using array

#include <stdio.h>

#define MAX 1000

int rear = -1;
int front = -1;
int size;
int array[MAX];

/*Function declaration*/
void enqueue(){
    if (front == size-1){
        printf("\nQueue is full!");
    }
    else{
        front
    }
}
void dequeue();
void display();
void first();
void last();

int main(){
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    pQueue = (int *)malloc(size*sizeof(int));

    while (1){
        int choice;
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. First");
        printf("\n5. Last");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: first(); break;
            case 5: last(); break;
        }
    }

    return 0;
}
