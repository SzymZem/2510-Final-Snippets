#include <stdio.h>
#include <stdlib.h>   // for atof()
#include <ctype.h>    // for isdigit()
#include <string.h>   // for strcspn()

#define MAX_LEN 100

int is_vali0d_double(const char *str);

int main() {
    char input[MAX_LEN];
    double number;

    // loop until user enters valid double
    while(1) {
        // prompt user for input & get it
        puts("Enter a decimal number:");
        fgets(input, MAX_LEN, stdin);

        // remove newline (if any)
        input[strcspn(input, "\n")] = '\0';

        if(is_valid_double(input)) {
            number = atof(input);  // safe to convert now
            break;
        } else {
            puts("\nInvalid input. Please enter a valid decimal number.");
        }
    }

    printf("You entered the number: %.4f\n", number); // shows 4 decimal places
    return 0;
}


// validates if input string is a valid double (e.g., -12.34, 0.5, 7)
int is_valid_double(const char *str) {
    int seenDigit = 0;
    int seenDot = 0;

    // handle negative (optional)
    if(*str == '-') {
        str++;
    }

    // empty string or just '-'?
    if(*str == '\0') {
        return 0;
    }

    // loop through all characters in passed string
    while(*str) {
        if(*str == '.') {
            if(seenDot)
            {
                // valid doubles only have 1 '.', not multiple
                return 0;
            }
            seenDot = 1;
        } else if(isdigit(*str)) {
            seenDigit = 1;
        } else {
            // invalid character
            return 0;
        }

        // go to next character in string
        str++;
    }

    return seenDigit;
}
