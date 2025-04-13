#include <stdio.h>

#define MATRIX_SIZE 4 // Define size of square matrix

void rotate_90_clockwise(int original[MATRIX_SIZE][MATRIX_SIZE], int rotated[MATRIX_SIZE][MATRIX_SIZE]);
void print_matrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]);

int main() {
    int matrix[MATRIX_SIZE][MATRIX_SIZE] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13,14, 15, 16}
    };

    int rotated[MATRIX_SIZE][MATRIX_SIZE];

    printf("Original matrix:\n");
    print_matrix(matrix);

    rotate_90_clockwise(matrix, rotated);

    printf("Rotated matrix (90 degrees clockwise):\n");
    print_matrix(rotated);

    return 0;
}



// rotates matrix 90 degrees clockwise (creates a new rotated matrix)
void rotate_90_clockwise(int original[MATRIX_SIZE][MATRIX_SIZE], int rotated[MATRIX_SIZE][MATRIX_SIZE]) {
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {

            // this is where the matrix rotation actually happens
            rotated[j][MATRIX_SIZE - 1 - i] = original[i][j];
        }
    }
}

// prints a 2D array
void print_matrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

