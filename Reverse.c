//Write a C program to take n integers as input and print them out in reverse order

#include<stdio.h>

int main(){
    int num;
    int* pNum = &num;
    int i;

    printf("Enter the number of elements to be input: ");
    scanf("%d",&num);

    int arr[*pNum];

    for (i = 0; i < num; i++){
        printf("Enter element no. %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    i--;
    printf("\nThe input in reversed order is: ");
    for ( ; i>=0; --i){
        printf("%d ",arr[i]);
    }
    return 0;
}
