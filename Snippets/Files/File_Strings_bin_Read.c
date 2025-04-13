#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    int count;
    char buffer[MAX_LEN];

    // open file
    FILE *file = fopen("strings.bin", "rb");
    if(!file) {
        puts("Failed to open binary file for reading.");
        return 1;
    }

    // read the number of strings first
    fread(&count, sizeof(int), 1, file);
    printf("Reading %d strings from file:\n\n", count);

    for(int i = 0; i < count; i++) {
        fread(buffer, sizeof(char), MAX_LEN, file);
        printf("%s\n", buffer);
    }

    // close file (prevent memory leaks)
    fclose(file);
    puts("\nDone reading from strings.bin.");
    return 0;
}
