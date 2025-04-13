#include <stdio.h>
#include <stdlib.h>

int **create_matrix(int rows, int cols);
void input_matrix(int **matrix, int rows, int cols, const char *name);
void print_matrix(int **matrix, int rows, int cols, const char *label);
int **multiply_matrices(int **A, int **B, int r1, int c1, int c2);
void free_matrix(int **matrix, int rows);

int main() {
    int r1, c1, r2, c2;

    // get dimensions from user
    printf("Enter dimensions of Matrix A (rows cols):\n");
    scanf("%d %d", &r1, &c1);

    printf("Enter dimensions of Matrix B (rows cols):\n");
    scanf("%d %d", &r2, &c2);

    // make sure we can actually multiply the matricies
    if(c1 != r2) {
        printf("Matrix multiplication not possible: A's columns must match B's rows.\n");
        return 1;
    }

    // create matricies
    int **A = create_matrix(r1, c1);
    int **B = create_matrix(r2, c2);

    // ask user to fill matricies
    input_matrix(A, r1, c1, "A");
    input_matrix(B, r2, c2, "B");

    // multiply matrices
    int **C = multiply_matrices(A, B, r1, c1, c2);

    // display results
    print_matrix(A, r1, c1, "Matrix A");
    print_matrix(B, r2, c2, "Matrix B");
    print_matrix(C, r1, c2, "Matrix A * B (Result)");

    // cleanup
    free_matrix(A, r1);
    free_matrix(B, r2);
    free_matrix(C, r1);

    return 0;
}


// allocate a 2D matrix
int **create_matrix(int rows, int cols) {
    int **mat = malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++) {
        mat[i] = malloc(cols * sizeof(int));
    }
    return mat;
}

// prompt user for each value in a matrix
void input_matrix(int **matrix, int rows, int cols, const char *name) {
    printf("Enter values for %s (%dx%d):\n", name, rows, cols);
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++) {
            printf("%s[%d][%d]:\n", name, i, j);
            scanf("%d", &matrix[i][j]);
        }
}

// print a matrix
void print_matrix(int **matrix, int rows, int cols, const char *label) {
    printf("\n%s:\n", label);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// matrix multiplication: C = A * B
int **multiply_matrices(int **A, int **B, int r1, int c1, int c2) {
    int **C = create_matrix(r1, c2);

    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for(int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }

    return C;
}

// free memory (no memory leaks!)
void free_matrix(int **matrix, int rows) {
    for(int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

