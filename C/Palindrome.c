#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LENGTH 1000

char *pString = NULL;
char temp[MAX_LENGTH];

typedef struct Stack {
    int capacity;
    int top;
    char *pArray;
} Stack;

Stack *pCreateStack (int size){
    Stack *pStack = (Stack*)malloc(sizeof(Stack));
    pStack -> capacity = size;
    pStack -> top = -1;
    pStack -> pArray = (char*)malloc(size * sizeof(char));
}

void push (char startingCharacters, Stack *pStack){
    *(pStack -> pArray + ++(pStack -> top)) = startingCharacters;
}

void pop (Stack *pStack){
    (pStack -> top)--;
}

int matchCharacters(char endingCharacters, Stack *pStack){
    return (*(pStack -> pArray + (pStack -> top)) == endingCharacters);
}

int main(){
    printf("Enter the string: ");
    
    fgets(temp, MAX_LENGTH, stdin);
    
    pString = (char*)malloc(strlen(temp));
    
    if (pString == NULL){
        printf("Allocation failed!");
        return 1;
    }
    
    strcpy(pString, temp);
    for (int i = 0; i < strlen(pString) - 1; i++){
        *(pString + i) = tolower(*(pString+i));
    }
    
    Stack *pStack = pCreateStack(strlen(pString));
    
    int i = 0;
    while (i < strlen(pString)/2){
        push(*(pString+i), pStack);
        i++;
    }
    
    if (strlen(pString) % 2 == 0){
        pop(pStack);
    }

    while (i < strlen(pString)){
        if (matchCharacters(*(pString + i), pStack)){
            pop(pStack);
        }
        i++;
    }
    
    (pStack -> top == -1) ? printf("Palindrome!") : printf("Not Palindrome!");
    
    return 0;
}
