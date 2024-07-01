#include <stdio.h>

void swap(int *pArr, int i, int j){
    int temp = pArr[i];
    pArr[i] = pArr[j];
    pArr[j] = temp;
}

void bubbleSort(int *pArr, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1; j++){
            if (pArr[j] > pArr[j+1]){
                swap(pArr, j, j+1);
            }
        }
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = { 13, 12, 10, 17, 24, 7, 3, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, N);
    printf("Sorted array: ");
    printArray(arr, N);
    return 0;
}
