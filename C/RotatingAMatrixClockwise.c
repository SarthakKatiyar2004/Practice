//C program to create a 2-d array, store the values in form of a matrix then printing the stored data rotated 90 deg clockwise

#include <stdio.h>

int main() {
    int rows = 0, cols = 0;
    
    printf("Enter the no. of rows: ");
    scanf("%d", &rows);
    printf("Enter the no. of cols: ");
    scanf("%d", &cols);
    
    int Matrix[rows][cols];
    
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("Enter the element in Matrix[%d][%d]: ", i+1, j+1);
            scanf("%d", &Matrix[i][j]);
        }
    }
    
    
    printf("The original matrix is: \n");
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            printf("%d ", Matrix[r][c]);
        }
        printf("\n");
    }
    
    //rotating the matrix
    printf("The rotated matrix is: \n");
    for (int r = 0; r < cols; r++){
        for (int c = rows-1; c >= 0; c--){
            printf("%d ", Matrix[c][r]);
        }
        printf("\n");
    }
    
    return 0;
}
