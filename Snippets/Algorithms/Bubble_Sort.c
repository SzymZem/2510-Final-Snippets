#include <stdio.h>
#include <stdbool.h>

void print_array(int arr[], int size);
    void bubble_sort(int arr[], int size);


int main() {
    int data[] = {12, 5, 7, 1, 18, 3, 9, 0};
    int size = sizeof(data) / sizeof(data[0]);

    puts("Original array:");
    print_array(data, size);

    bubble_sort(data, size);

    puts("\nFinal sorted array:");
    print_array(data, size);

    return 0;
}


// function to print the array at each step
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%4d", arr[i]);
    }

    // spacing
    puts("");
}

// bubble Sort with progress visualization
void bubble_sort(int arr[], int size) {
    bool swapped;

    puts("Starting Bubble Sort...");

    for(int pass = 0; pass < size - 1; pass++) {
        swapped = false;

        printf("\nPass %d:\n", pass + 1);

        for(int i = 0; i < size - 1 - pass; i++) {
            // print action before swapping
            printf(" Comparing %d and %d:\t", arr[i], arr[i + 1]);
            if (arr[i] > arr[i + 1]) {
                // swap elements
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }

            // print current state after each comparison
            print_array(arr, size);
        }

        if(!swapped) {
            puts("No swaps done — array is sorted.");
            break;
        }
    }
}

