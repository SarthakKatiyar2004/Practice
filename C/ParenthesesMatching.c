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

struct Stack *pCreatestack(long unsigned capacity){
    struct Stack *pStack = (struct Stack*)malloc(sizeof(struct Stack));
    pStack -> top = -1;
    pStack -> capacity = capacity;
    pStack -> pArray = (char *)malloc(pStack -> capacity * sizeof(char));
}

void push(char opening_bracket, struct Stack *pStack){
    *(pStack -> pArray + ++(pStack -> top)) = opening_bracket;
}

int match_pair(char closing_bracket, struct Stack *pStack){
    if (*(pStack -> pArray + pStack -> top) == '(' && closing_bracket == ')'
      ||*(pStack -> pArray + pStack -> top) == '{' && closing_bracket == '}'
      ||*(pStack -> pArray + pStack -> top) == '[' && closing_bracket == ']'){
        return 1;
    }
    else{
        return 0;
    }
}

void pop(char closing_bracket, struct Stack *pStack){
    (pStack -> top)--;
}


int main(){

    printf("Enter the expression string: ");
    fgets(temp, MAX_LENGTH, stdin); //temp is allocated a memory of MAX_LENGTH in stdin stream

    //now let us say temp has 6 characters + NULL then we only need to work with 6 characters the remaining 994 are garbage
    //for that we can dynamically allocate a space of 7 characters to *pString

    pString = (char *)malloc(strlen(temp));
    
    if (pString == NULL){
        printf("Memory allocation failed!");
        return 1;
    }
    
    strcpy(pString, temp);
    
    struct Stack *pStack = pCreatestack(strlen(pString));
    
    while (*pString){
        if (*pString == '(' || *pString == '{' || *pString == '['){
            push(*pString, pStack);
        }
        
        if (*pString == ')' || *pString == '}' || *pString == ']'){
            if (pStack -> top == -1){
                printf("The parentheses aren't balanced.");
                exit(0);
            }
            if (match_pair(*pString, pStack)){
                pop(*pString, pStack);
            }
        }
        if (*pString == '\0'){
            (pStack -> top)--;
        }
        
        pString++;
    }
    
    if (pStack -> top == -1){
        printf("The parentheses are balanced");
    }
    else{
        printf("The parentheses aren't balanced");
    }
    
    return 0;
}
