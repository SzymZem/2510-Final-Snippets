#include <stdio.h>
#include <string.h>  // for strcpy, strncpy

#define MAX_LEN 100

int main() {
    char original[MAX_LEN];
    char copy1[MAX_LEN];
    char copy2[MAX_LEN];

    // prompt & get string
    printf("Enter a string to copy: ");
    fgets(original, MAX_LEN, stdin);

    // remove trailing newline (if present)
    original[strcspn(original, "\n")] = '\0';

    // copy using strcpy (copies until null terminator)
    strcpy(copy1, original);

    // copy using strncpy
    strncpy(copy2, original, MAX_LEN - 1);
    copy2[MAX_LEN - 1] = '\0';  // ensure string terminator character

    // print results
    printf("\nOriginal: \"%s\"\n", original);
    printf("Copy1 (strcpy): \"%s\"\n", copy1);
    printf("Copy2 (strncpy): \"%s\"\n", copy2);

    return 0;
}
