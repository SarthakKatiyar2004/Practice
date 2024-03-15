//Making a linear queue containing just the characters

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int front = -1;
int rear = -1;
int size;
char *pString;

void enqueue(){
  if (rear >= size -1){
    printf("\nQueue overflow!");
  }
  else{
    if (front == -1){
      front = 0;
    }
    char element;
    printf("\nEnter the charcter to be enqueued: ");
    scanf("%c", &element);
    *(pString + ++rear) =  element;
  }
}

void dequeue(){
  if (front == -1 || front > rear){
    printf("\nQueue underflow!");
  }
  else{
    printf("\nThe element dequeued is: ", *(pString + front++));
  }
}

void display(){
  if (front == -1 || front > rear){
    printf("\nQueue underflow!");
  }
  else{
    for (int i = front; i <= rear; i++){
      printf("%c ", *(pString + i));
    }
  }
}

void atfront(){
  if (front == -1 || front > rear){
    printf("\nQueue Underflow!");
  }
  else{
    printf("\nThe element at the front of the queue is %c", *(pString + front));
  }
}

void atrear(){
  if (front == -1 || front > rear){
    printf("\nQueue Underflow!");
  }
  else{
    printf("\nThe element at the back of the queue is %c", *(pString + rear));
  }
}

int main(){

  printf("Enter the size of the queue: ");
  scanf("%u", &size);

  pString = (char *)malloc(size*sizeof(char));

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
