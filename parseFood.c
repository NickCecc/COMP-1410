#include <stdio.h>
#include <string.h>


void newline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main(void) {
    const int MAX_LINES = 25;   // Maximum number of lines in the input text inFile
    const int MAX_STRING_LENGTH = 100;  // Maximum number of characters in each column of the input text inFile
    const int MAX_LINE_LENGTH = 200;  // Maximum number of characters in each line of the input text inFile

    // Declare 4 string arrays to store the 4 columns from the input text inFile
    char column1[MAX_LINES][MAX_STRING_LENGTH];
    char column2[MAX_LINES][MAX_STRING_LENGTH];
    char column3[MAX_LINES][MAX_STRING_LENGTH];
    char column4[MAX_LINES][MAX_STRING_LENGTH];

    // Read the inFile name from the user
    char fileName[MAX_STRING_LENGTH];
    scanf("%s", fileName);

    // Open the inFile for reading
    FILE *inFile = fopen(fileName, "r");
    if (!inFile) {
        printf("Could not open inFile %s.\n", fileName);
        return 1;
    }

    // Read the inFile line by line
    char line[MAX_LINE_LENGTH];
    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, inFile)) {
        sscanf(line, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]", column1[i], column2[i], column3[i], column4[i]);
        newline(column4[i]);
        i++;
    }
    fclose(inFile);

    // Output the available food items
    for (int j = 0; j < i; j++) {
        if (strcmp(column4[j], "Available") == 0) {
            printf("%s (%s) -- %s\n", column2[j], column1[j], column3[j]);
        }
    }

    return 0;
}
