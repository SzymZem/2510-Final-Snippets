#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("output.bin", "rb");
    if (!file) {
        printf("Could not open output.bin for reading.\n");
        return 1;
    }

    // step 1: Find how many integers are stored
    fseek(file, 0, SEEK_END); // go to end
    long fileSize = ftell(file); // get position = size in bytes
    rewind(file); // go back to start

    int count = fileSize / sizeof(int);  // total number of integers
    int *numbers = malloc(fileSize);
    if(!numbers) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    // step 2: Read all numbers
    size_t read = fread(numbers, sizeof(int), count, file);
    if(read != count) {
        printf("Warning: expected %d integers, but only read %zu.\n", count, read);
    }

    // step 3: Print the results
    printf("Read %d integers from output.bin:\n", count);
    for(int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // step 4: Cleanup
    fclose(file);
    free(numbers);

    return 0;
}
