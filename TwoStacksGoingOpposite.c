//The objectives of the program:
//1. Create a stack that contains 2 stacks, of user-defined sizes, within it
//2. One of the stack is to push elements starting from the left going right
//while the other stack is to push elements in the opposite direction

#include<stdio.h>
#include<stdlib.h>

int size, size1, size2;
int top1 = -1, top2;
int *pStack;

void push1(){
  if (top1 == size1-1){
    printf("\nStack 1 Overflow!");
  } else{
    int element;
    printf("\nEnter the element to be pushed: ");
    scanf("%d",&element);
    *(pStack + ++top1) = element;
  }
}

void pop1(){
  if (top1 == -1){
    printf("\nStack 1 Underflow!");
  } else{
    int element = *(pStack + top1--);
    printf("\nThe element popped from stack 1 is: %d",&element);
  }
}

void peek1(){
  if (top1 == -1){
    printf("\nStack 1 is empty!");
  } else{
    int element = *(pStack + top1);
    printf("\nThe topmost element of stack 1 is: %d",&element);
  }
}

void disp1(){
  printf("\nStack 1 is: ");
  for (int i = 0; i < size-size2; i++){
    printf("%d ",*(pStack+i));
  }
}

void push2(){
  if (top2 == size-size1){
    printf("\nStack 2 Overflow!");
  } else{
    int element;
    printf("\nEnter the element to be pushed: ");
    scanf("%d",&element);
    *(pStack + --top2) = element;
  }
}

void pop2(){
  if (top2 == size){
    printf("\nStack 2 Underflow!");
  } else{
    int element = *(pStack + top2++);
    printf("\nThe element popped from stack 2 is: %d",&element);
  }
}

void peek2(){
  if (top2 == size){
    printf("\nStack 2 is empty!");
  } else{
    int element = *(pStack + top2);
    printf("\nThe topmost element of stack 2 is: %d",&element);
  }
}

void disp2(){
  printf("\nStack 2 is: ");
  for (int i = size-1; i >= size-size2; i--){
    printf("%d ",*(pStack+i));
  }
}

void disp(){
  printf("\nThe complete Stack is: ");
  for (int i = 0; i < size; i++){
    printf("%d ",*(pStack+i));
  }
}

int main(){

  printf("Enter the size of stack 1: ");
  scanf("%d",&size1);

  printf("Enter the size of stack 2: ");
  scanf("%d", &size2);

  size = size1+size2;

  pStack = (int *)malloc(size*sizeof(int));
  
  top2 = size;

  while(1){
    int choice;
    printf("\n1. Push in Stack 1\n2. Push in Stack 2");
    printf("\n3. Pop from Stack 1\n4. Pop from Stack 2");
    printf("\n5. Peek at the top of Stack 1\n6. Peek at the top of Stack 2");
    printf("\n7. Display Stack 1\n8. Display Stack 2");
    printf("\n9. Display entire Stack");
    printf("\n10. Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice){
      case 1: push1(); break;
      case 2: push2(); break;
      case 3: pop1(); break;
      case 4: pop2(); break;
      case 5: peek1(); break;
      case 6: peek2(); break;
      case 7: disp1(); break;
      case 8: disp2(); break;
      case 9: disp(); break;
      case 10: exit(0); free(pStack); break;
      default: printf("Enter a valid choice!");
    }
    
  }
  return 0;
}
