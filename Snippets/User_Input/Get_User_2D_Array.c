#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **matrix, int rows, int cols);

int main() {
    int rows, cols;

    // get matrix size from user
    puts("Enter number of rows: ");
    scanf("%d", &rows);

    puts("Enter number of columns: ");
    scanf("%d", &cols);

    // dynamically allocate memory for 2D array
    int **matrix = malloc(rows * sizeof(int *));
    if(!matrix) {
        printf("Memory allocation failed for rows.\n");
        return 1;
    }

    for(int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        if(!matrix[i]) {
            printf("Memory allocation failed for row %d.\n", i);
            return 1;
        }
    }

    // fill in the matrix with user input
    printf("\nEnter the elements row by row:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("\nElement [%d][%d]:\n", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // print the matrix
    print_matrix(matrix, rows, cols);

    // free the memory
    for(int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}


// print a 2D array
void print_matrix(int **matrix, int rows, int cols) {
    printf("\nYou entered this matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}
