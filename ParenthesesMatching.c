//The primary objectives of the program are to:
//1. Take a string containing different types of parentheses as input
//2. Verify that the parentheses are properly matched in the string


#include<stdio.h>

int top = -1;
int stack[100];
char string[100];

int main(){

    printf("Enter a string containing parentheses: ");
    scanf("%s",string);

    int i = 0;
    while (string[i]){
        if (string[i] == "("
        || string[i] == "{"
        || string[i] == "["){
            push(string[i]);
            }
    }

    return 0;
}
