#include <stdio.h>

void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void print_array(int arr[], int size);


int main() {
    int data[] = {12, 5, 7, 1, 18, 3, 9, 0};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original array:\n");
    print_array(data, size);

    quick_sort(data, 0, size - 1);

    printf("\nFinal sorted array:\n");
    print_array(data, size);

    return 0;
}


// quick Sort algorithm
void quick_sort(int arr[], int low, int high) {

    // you can only sort if the array has more than 1 element
    if(low < high) {
        // partition the array
        int pivotIndex = partition(arr, low, high);

        // show array after each partition
        printf("\nAfter partitioning with pivot index %d:\n", pivotIndex);
        print_array(arr, high + 1);

        // recursively sort subarrays
        quick_sort(arr, low, pivotIndex - 1);
        quick_sort(arr, pivotIndex + 1, high);
    }

}


// partition step: places pivot in correct position and returns its index
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // choose last element as pivot
    int i = low - 1;       // index of smaller element

    // loop from low, to high - 1
    for(int j = low; j < high; j++) {

        // if arr[j] is smaller than the pivot, it should be to the left of it
        if(arr[j] < pivot) {
            i++;

            // swap arr[i] and arr[j] (to put the smaller element in place)
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // swap pivot into correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // after the loop, i + 1 is the index the pivot was placed
    return i + 1;
}


// print the current array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

