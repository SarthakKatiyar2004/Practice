#include<stdio.h>

int main(){
    
    int array[8];
    int new_array[4];
    for (int i = 0; i < 8; i++){
        printf("Enter element no.%d of the array: ", i+1);
        scanf("%d", &array[i]);
    }
    
    for (int w = 0, y = 0; w < 8; w += 2, y++){
        new_array[y] = array[w]*10+array[w+1];
    }
    
    printf("The given array is: ");
    for (int j = 0; j < 8; j++){
        printf("%d ", array[j]);
    }
    printf("\nThe resultatnt array is: ");
    for (int k = 0; k < 4; k++){
        printf("%d ", new_array[k]);
    }
    
    return 0;
}
