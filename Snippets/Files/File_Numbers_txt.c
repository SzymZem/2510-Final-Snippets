#include <stdio.h>

int main() {
    int count;

    // step 1: Ask how many numbers to write
    puts("How many integers do you want to write to the file?");
    scanf("%d", &count);

    // step 2: Open file for writing
    FILE *file = fopen("output.txt", "w");
    if(!file) {
        puts("Failed to open file for writing.");
        return 1;
    }

    // step 3: Get numbers from user and write them to file
    printf("\n\nEnter %d integers:\n", count);
    for(int i = 0; i < count; i++) {
        int num;
        printf("\nNumber %d:\n", i + 1);
        scanf("%d", &num);
        fprintf(file, "%d\n", num);  // write each number on a new line
    }

    // step 4: close file
    fclose(file);

    printf("Successfully wrote %d numbers to output.txt\n", count);
    return 0;
}
