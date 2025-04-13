#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    int count;
    char input[MAX_LEN];

    // step 1: Ask user how many strings to enter
    puts("How many lines do you want to write to the file? ");
    scanf("%d", &count);
    getchar(); // consume newline left in buffer after scanf

    // step 2: Open the file for writing
    FILE *file = fopen("strings.txt", "w");
    if(!file) {
        puts("Failed to open file for writing.\n");
        return 1;
    }

    // step 3: Get strings from user and write them to file
    printf("Enter %d lines of text:\n", count);
    for(int i = 0; i < count; i++) {
        printf("\nLine %d:\n", i + 1);
        fgets(input, MAX_LEN, stdin);

        // remove trailing newline from input, if any
        input[strcspn(input, "\n")] = '\0';

        fprintf(file, "%s\n", input);
    }

    // step 4: Close the file
    fclose(file);
    printf("Successfully wrote %d lines to strings.txt\n", count);

    return 0;
}
