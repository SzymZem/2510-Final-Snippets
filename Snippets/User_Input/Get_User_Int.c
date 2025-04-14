#include <stdbool.h> // For exit status
#include <stdio.h>
#include <stdlib.h> // For strtol()
#include <string.h> // For strlen() and strchr()

#define MAX_LEN 15

/* ------------------ Copying Get_User_String.c ------------------*/

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

/*-------- End copying, Get_User_Int actually begins here --------*/

/**
 * Like scanf("%d"), but better.
 *
 * @return success status
 */
bool scand(int* num)
{
    // Use our scans to reuse the buffer overflow check, then convert it to int.
    char input[MAX_LEN];
    if (!scansNonEmpty(input))
        return false;

    // strtol can detect input errors, unlike atoi.
    char* endptr;
    *num = strtol(input, &endptr, 10);
    if (*endptr == '\0')
    {
        return true;
    }
    puts("Input must be a number.");
    return false;
}

/**
 * Like scand, but requires positive input.
 * Replace the line `if (*num > 0)` with whatever other condition you want.
 * @return success status
 */
bool scandPositive(int* num)
{
    if (!scand(num))
        return false;
    if (*num > 0)
        return true;
    puts("Number must be non-negative.");
    return false;
}

int main()
{
    int number;
    while (1)
    {
        printf("Enter a number: ");
        if (scand(&number))
            break; // success
    }
    printf("You entered the number: %d\n", number);

    int positiveNumber;
    while (1)
    {
        printf("Enter a positive number: ");
        if (scandPositive(&positiveNumber))
            break; // success
    }
    printf("You entered the number: %d\n", positiveNumber);
}
