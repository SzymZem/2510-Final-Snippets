#include <stdio.h>

void merge(int array[], int left, int mid, int right);
void merge_sort(int array[], int left, int right);
void print_array(int arr[], int size);


int main() {
    int data[] = {12, 5, 7, 1, 18, 3, 9, 0};
    int size = sizeof(data) / sizeof(data[0]);

    puts("Before sorting:");
    print_array(data, size);

    merge_sort(data, 0, size - 1);

    puts("\nAfter sorting:");
    print_array(data, size);

    return 0;
}



// merge two sorted halves into a full sorted array
void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // size of left half
    int n2 = right - mid;     // size of right half

    // temporary arrays
    int leftArr[n1];
    int rightArr[n2];

    // copy data to temp arrays
    for(int i = 0; i < n1; i++) {
        leftArr[i] = array[left + i];
    }
    for(int j = 0; j < n2; j++) {
        rightArr[j] = array[mid + 1 + j];
    }

    // merge the temp arrays back into original
    int i = 0;
    int j = 0;
    int k = left;
    while(i < n1 && j < n2) {
        if(leftArr[i] <= rightArr[j]) {
            array[k++] = leftArr[i++];
        } else {
            array[k++] = rightArr[j++];
        }
    }

    // copy remaining elements (if any)
    while(i < n1) {
        array[k++] = leftArr[i++];
    }
    while(j < n2) {
        array[k++] = rightArr[j++];
    }
}

// recursive merge sort
void merge_sort(int array[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        // sort each half
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);

        // merge them
        merge(array, left, mid, right);
    }
}

// helper to print array
void print_array(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
