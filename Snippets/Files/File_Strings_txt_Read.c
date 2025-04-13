#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char line[MAX_LEN];

    // open file
    FILE *file = fopen("strings.txt", "r");
    if(!file) {
        puts("Failed to open file for reading.");
        return 1;
    }

    printf("Reading strings from file:\n\n");

    // read lines from file until EOF
    while(fgets(line, MAX_LEN, file)) {
        // remove trailing newline (if present)
        line[strcspn(line, "\n")] = '\0';

        // print the line
        printf("%s\n", line);
    }

    // close file (prevent memory leaks)
    fclose(file);
    puts("\nDone reading from file.");

    return 0;
}
