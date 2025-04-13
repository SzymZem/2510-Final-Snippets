#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    int count;
    char input[MAX_LEN];

    // prompt # of strings
    printf("How many strings do you want to write? ");
    scanf("%d", &count);
    getchar(); // clear newline from buffer

    FILE *file = fopen("strings.bin", "wb");
    if (!file) {
        puts("Failed to open binary file for writing.");
        return 1;
    }

    // write the number of strings first (metadata)
    fwrite(&count, sizeof(int), 1, file);

    // loop to get user input of string, and write it to file
    for(int i = 0; i < count; i++) {
        printf("String %d: ", i + 1);
        fgets(input, MAX_LEN, stdin);
        input[strcspn(input, "\n")] = '\0'; // trim newline

        fwrite(input, sizeof(char), MAX_LEN, file);
    }

    // close file (prevent memory leak)
    fclose(file);
    printf("Successfully wrote %d strings to strings.bin\n", count);
    return 0;
}
