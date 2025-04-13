#include <stdio.h>
#include <stdlib.h>

int main() {
    int count;

    // step 1: Ask how many numbers
    puts("How many integers do you want to write to the binary file? ");
    scanf("%d", &count);

    int *numbers = malloc(count * sizeof(int));
    if(!numbers) {
        puts("Memory allocation failed.");
        return 1;
    }

    // step 2: Get numbers from user
    printf("Enter %d integers:\n", count);
    for(int i = 0; i < count; i++) {
        printf("\nNumber %d:\n", i + 1);
        scanf("%d", &numbers[i]);
    }

    // step 3: Open file for binary writing
    FILE *file = fopen("output.bin", "wb");
    if(!file) {
        printf("Failed to open binary file for writing.\n");
        free(numbers);
        return 1;
    }

    // step 4: Write the numbers to file
    size_t written = fwrite(numbers, sizeof(int), count, file);
    if(written != count) {
        printf("Warning: Only wrote %zu out of %d values.\n", written, count);
    } else {
        printf("Successfully wrote %d integers to output.bin\n", count);
    }

    // step 5: Clean up
    fclose(file);
    free(numbers);

    return 0;
}
