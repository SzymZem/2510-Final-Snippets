#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define DELIM " "

int main() {
    char input[MAX_LEN];

    // prompt & get user input
    printf("Enter a sentence: ");
    fgets(input, MAX_LEN, stdin);

    // remove newline character (if any)
    input[strcspn(input, "\n")] = '\0';

    // use strtok to split input string into tokens
    printf("\nTokens:\n");
    for(char *tok = strtok(input, DELIM); tok != NULL; tok = strtok(NULL, DELIM)) {
        printf("- \"%s\"\n", tok);
    }

    return 0;
}
