//The primary objectives of the program are to:
//1. Take a string containing different types of parentheses as input
//2. Verify that the parentheses are properly matched in the string


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 1000

char *pString = NULL; //creating a string pointer and initializing it to NULL
char temp[MAX_LENGTH];

struct Stack{
    int top;
    int capacity;
    char *pArray;
};

struct Stack *pCreatestack(unsigned capacity){
    struct Stack *pStack = (struct Stack*)malloc(sizeof(struct Stack));
    pStack -> top = -1;
    pStack -> capacity = capacity;
    pStack -> pArray = (char *)malloc(pStack -> capacity * sizeof(char));
}

int isPair(char char1, char char2){
    if (char1 == '(' && char2 == ')'){
        return 1;
    }
    if (char1 == '{' && char2 == '}'){
        return 1;
    }
    if (char1 == '[' && char2 == ']'){
        return 1;
    }
    else{
        return 0;
    }
    
}

void push(struct Stack *pStack, char char1){
    if (pStack -> top == pStack -> capacity - 1){
        printf("Stack Overflow!");
    }
    else{
        scanf("%c", pStack -> pArray + ++(pStack -> top));
    }
}

void pop(struct Stack *pStack, char char2){
    if (pStack -> top == -1){
        printf("Stack Underflow!");
    }
    else{
        if(isPair(*(pStack -> pArray + pStack -> top), char2)){
            (pStack -> top)--;
        }
    }
}


int main(){

    printf("Enter the expression sting: ");
    fgets(temp, MAX_LENGTH, stdin); //temp is allocated a memory of MAX_LENGTH in stdin stream

    //now let us say temp has 6 characters + NULL then we only need to work with 6 characters the remaining 994 are garbage
    //for that we can dynamically allocate a space of 7 characters to *pString

    pString = (char *)malloc(strlen(temp));

    if(pString == NULL){
            printf("Memory allocation failed!\n");
            return 1;
    }

    strcpy(pString, temp);

    struct Stack* stack = pCreatestack(strlen(pString));

    while (*pString){
        
        if(*pString == '(' || *pString == '{' || *pString == '['){
            push(stack, *pString);
        }
        else{
            pop(stack, *pString);
        }

        pString++;
        
    }

    printf("%s",pString);

    return 0;
}
