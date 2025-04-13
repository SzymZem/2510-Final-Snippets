#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 100   // size for each line of input

int main() {
    char buffer[CHUNK_SIZE];
    char *message = malloc(1);  // start with empty string
    if (!message) {
        fprintf(stderr, "Initial malloc failed.\n");
        return 1;
    }
    message[0] = '\0';  // null-terminate empty string

    while (1) {
        printf("Enter text (type QUIT to stop):\n");
        fgets(buffer, CHUNK_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';  // remove newline

        // check for sentinel word to exit loop
        if(strcmp(buffer, "QUIT") == 0) {
            break;
        }

        // calculate new size for message
        size_t oldLen = strlen(message);
        size_t addLen = strlen(buffer);
        char *temp = realloc(message, oldLen + addLen + 2); // +1 for space/newline +1 for null

        if(!temp) {
            fprintf(stderr, "Memory allocation failed.\n");
            free(message);
            return 1;
        }

        message = temp;


        // append new input
        strcat(message, buffer);

        printf("Message so far: \n%s\n", message);
    }

    // output final result
    printf("\nFinal message:\n%s\n", message);

    // clean up
    free(message);
    return 0;
}
