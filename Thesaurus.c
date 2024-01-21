#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int NUM_CHARACTERS = 26;   // Maximum number of letters
    int MAX_SYNONYMS = 10;     // Maximum number of synonyms per starting letter
    int MAX_WORD_SIZE = 30;    // Maximum length of the input word
    int n, i;
    char* synonyms[NUM_CHARACTERS][MAX_SYNONYMS];   // Declare 2D array of string pointers for all synonyms

    // Initialize the first column of the 2D array
    for (n = 0; n < NUM_CHARACTERS; n++) {
        synonyms[n][0] = NULL;
    }

    char word[MAX_WORD_SIZE];
    char inputFile[MAX_WORD_SIZE + 4]; // Add 4 for ".txt" and null terminator
    char targetLetter;
    char synonym[MAX_WORD_SIZE];
    FILE* file;

    // Read input from the user
    scanf("%s %c", word, &targetLetter);

    // Construct input file name and open the file
    snprintf(inputFile, sizeof(inputFile), "%s.txt", word);
    file = fopen(inputFile, "r");

    if (file == NULL) {
        printf("Error: could not open file %s\n", inputFile);
        return 1;
    }

    // Read synonyms from the file and store them in the 2D array
    while (fscanf(file, "%s", synonym) != EOF) {
        if (synonym[0] != '*') {
            int index = synonym[0] - 'a';

            for (i = 0; i < MAX_SYNONYMS; i++) {
                if (synonyms[index][i] == NULL) {
                    synonyms[index][i] = malloc(strlen(synonym) + 1);
                    strcpy(synonyms[index][i], synonym);
                    synonyms[index][i + 1] = NULL;
                    break;
                }
            }
        }
    }

    fclose(file);

    // Output synonyms that begin with the input letter
    int found = 0;
    int targetIndex = targetLetter - 'a';
    for (i = 0; i < MAX_SYNONYMS && synonyms[targetIndex][i] != NULL; i++) {
        printf("%s\n", synonyms[targetIndex][i]);
        found = 1;
    }

    if (!found) {
        printf("No synonyms for %s begin with %c.\n", word, targetLetter);
    }

    // Free allocated memory
    for (n = 0; n < NUM_CHARACTERS; n++) {
        for (i = 0; i < MAX_SYNONYMS && synonyms[n][i] != NULL; i++) {
            free(synonyms[n][i]);
        }
    }

    return 0;
}
