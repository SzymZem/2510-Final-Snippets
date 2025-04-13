#include <stdio.h>
#include <string.h>

#define MAX_LEN 256
#define WORD_LEN 50

void replace_word(const char *original, const char *oldWord, const char *newWord, char *resultBuffer);

int main() {
    char input[MAX_LEN];
    char wordToReplace[WORD_LEN];
    char replacement[WORD_LEN];
    char result[MAX_LEN * 2] = ""; // double size in case replacements grow the string

    // get original input
    printf("Enter the original message:\n");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = '\0';

    // get target word to replace
    printf("Enter the word to replace:\n");
    fgets(wordToReplace, WORD_LEN, stdin);
    wordToReplace[strcspn(wordToReplace, "\n")] = '\0';

    // get replacement word
    printf("Enter the replacement word:\n");
    fgets(replacement, WORD_LEN, stdin);
    replacement[strcspn(replacement, "\n")] = '\0';

    // perform replacement
    replace_word(input, wordToReplace, replacement, result);

    // display result
    printf("\nUpdated message:\n%s\n", result);
    return 0;
}


// helper to replace all occurrences of oldWord with newWord in original, writing result into resultBuffer
void replace_word(const char *original, const char *oldWord, const char *newWord, char *resultBuffer) {
    const char *pos = original;
    int oldLen = strlen(oldWord);
    int newLen = strlen(newWord);


    // loop until we cannot find an occurance of oldWord
    while((pos = strstr(pos, oldWord)) != NULL) {
        // copy part before the match
        int bytesBefore = pos - original;
        strncat(resultBuffer, original, bytesBefore);

        // append new word
        strcat(resultBuffer, newWord);

        // advance original pointer past the matched old word
        original = pos + oldLen;
        pos = original;
    }

    // copy remaining part of original (after last match)
    strcat(resultBuffer, original);
}
