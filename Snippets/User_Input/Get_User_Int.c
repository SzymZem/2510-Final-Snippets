#include <stdio.h>
#include <stdlib.h>   // for atoi()
#include <ctype.h>    // for isdigit()
#include <string.h>   // for strcspn()

#define MAX_LEN 100

int isValidInteger(const char *str);

int main() {
    char input[MAX_LEN];
    int number;

    // loop until success
    while(1) {
        // prompt user for input & get it
        puts("Enter a number:");
        fgets(input, MAX_LEN, stdin);

        // remove trailing newline character (if its there)
        input[strcspn(input, "\n")] = '\0';

        if(isValidInteger(input)) {
            number = atoi(input);  // Safe now, since we validated the string
            break;
        } else {
            puts("\nInvalid input. Please enter a valid integer.");
        }
    }

    printf("You entered the number: %d\n", number);
    return 0;
}


// function to check if a string is a valid integer (only digits, optional leading minus)
int isValidInteger(const char *str) {

    // allow negative sign
    if(*str == '-') {
        str++;
    }

    // a string "-" with no number is not a valid int
    if(*str == '\0') {
        return 0;
    }

    // loop through each character
    while(*str) {
        // if the current character is not a digit, then its invalid
        if (!isdigit(*str)) {
            return 0;
        }

        // go to the next character
        str++;
    }

    // if we got here, then there isnt any non-digit characters, so this string is just an integer!
    return 1;
}