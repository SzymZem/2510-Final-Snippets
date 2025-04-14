#include <stdbool.h> // For exit status
#include <stdio.h>
#include <string.h> // For strlen() and strchr()

#define MAX_LEN 15


/**
 * Like scanf("%s"), but better.
 *
 * @return success status (whether input was valid)
 */
bool scans(char* str)
{
    fgets(str, MAX_LEN, stdin);

    // Find the pointer to the newline character
    char* EOL = strchr(str, '\n');
    if (EOL)
    {
        *EOL = '\0';
        return true;
    }

    // If not found, it means user entered more characters than allowed
    // Then clear the input stream.
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // If you don't do this,
        // the next call to fgets() will read the rest of the line
        // instead of waiting for new input.
    }

    // And print error message
    printf("Maximum %d characters allowed.\n", MAX_LEN);
    return false;
}

/**
 * Like scans(), but also checks for empty string.
 * Replace the line `if (strlen(str) > 0)` to whatever other condition you like
 * (e.g. string must have minimum 3 characters, etc.)
 *
 * @return success status (whether input was valid)
 */
bool scansNonEmpty(char* str)
{
    if (!scans(str))
        return false;

    if (strlen(str) > 0)
        return true;

    printf("Empty string not allowed.\n");
    return false;
}

int main()
{
    char input[MAX_LEN];
    while (1)
    {
        printf("Enter a string: ");
        if (scans(input))
        {
            break;
        }
    }
    printf("You entered: \"%s\"\n", input);


    char nonEmptyInput[MAX_LEN];
    while (1)
    {
        printf("Enter a non-empty string: ");
        if (scansNonEmpty(nonEmptyInput))
        {
            break;
        }
    }
    printf("You entered: \"%s\"\n", nonEmptyInput);

    return 0;
}
