//Implementing Stack using array

#include<stdio.h>
#include<stdlib.h>
#define max 100

int top = -1;
int stack[max];
int size;

void push();
void pop();
void disp();

int main(){

  printf("Enter the size of the stack: ");
  scanf("%d",&size);

  while (1){
    int choice;
    printf("\n1. Push");
    printf("\n2. Pop");
    printf("\n3. Display");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice){
      case 1:
        push();
        break;
      case 2:
        pop();
        break;
      case 3:
        disp();
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("Enter a valid choice!");
    }
  }  
  return 0;
}

void push(){
  if (not (top < size)){
    printf("Stack Overflow!");
  } else{
    printf("Enter the element to be pushed: ");
    scanf("%d", &stack[++top]);
  }
}

void pop(){
  if (top == -1){
    printf("Stack Underflow!");
  } else{
    printf("The poped element is: %d", stack[top--]);
  }
}

void disp(){
  if (top == -1){
    printf("Stack is empty!");
  } else{
    printf("The Stack is: ");
    for (int i = 0; i <= top; i++){
      printf("%d ",stack[i]);
    }
  }
}
