#include <stdio.h>

int main() {
    // open file
    FILE *file = fopen("output.txt", "r");
    if(!file) {
        printf("Failed to open output.txt for reading.\n");
        return 1;
    }

    int number;
    int index = 0;

    printf("Numbers read from output.txt:\n");

    // read each line as an integer until EOF
    while(fscanf(file, "%d", &number) == 1) {
        printf("%d\n", number);
        index++;
    }

    // close file (prevent memory leaks)
    fclose(file);
    return 0;
}
