#include <stdio.h>
#include <string.h>   // For strlen(), strcspn()

#define MAX_LEN 15
#define MIN_LEN 3     // Set desired minimum length
#define MAX_ALLOWED_LEN 20  // Set upper bound for string length

int isValidString(const char *str, int min, int max);

int main() {
    char input[MAX_LEN];

    // loop until user inputs valid string
    while(1) {
        printf("Enter a valid name (%i-%i characters):\n", MIN_LEN, MAX_LEN);
        fgets(input, MAX_LEN, stdin);

        // remove newline character (if any)
        input[strcspn(input, "\n")] = '\0';

        // valid input = break out of loop.
        // invalid input = reprompt and try again
        if(isValidString(input, MIN_LEN, MAX_ALLOWED_LEN)) {
            break;
        } else {
            puts("\nInvalid input. Please enter a non-empty string of proper length.");
        }
    }

    // print resulting user input
    printf("You entered: \"%s\"\n", input);
    return 0;
}


// checks if input string is within min/max length requirements
int isValidString(const char *str, int min, int max) {
    int len = strlen(str);

    // returns true if the input is within min and max lengths
    return (len >= min && len <= max);
}
