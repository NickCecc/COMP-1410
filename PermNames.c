#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int MAX_NAME_SIZE = 50;

// TODO: Write function to create and output all permutations of the list of names.
void PrintAllPermutations(char **permList, int permSize, char **nameList, int nameSize) {
    if (permSize == nameSize) {
        for (int i = 0; i < permSize - 1; ++i) {
            printf("%s, ", permList[i]);
        }
        printf("%s\n", permList[permSize - 1]);
    } else {
        for (int i = 0; i < nameSize; ++i) {
            int found = 0;
            for (int j = 0; j < permSize; ++j) {
                if (strcmp(permList[j], nameList[i]) == 0) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                permList[permSize] = nameList[i];
                PrintAllPermutations(permList, permSize + 1, nameList, nameSize);
            }
        }
    }
}

int main(void) {
    int size;
    int i = 0;
    char name[MAX_NAME_SIZE];
    scanf("%d", &size);
    char *nameList[size];
    char *permList[size];

    for (i = 0; i < size; ++i) {
        nameList[i] = (char *)malloc(MAX_NAME_SIZE);
        scanf("%s", name);
        strcpy(nameList[i], name);
    }

    PrintAllPermutations(permList, 0, nameList, size);

    // Free dynamically allocated memory
    for (i = 0; i < size; ++i) {
        free(nameList[i]);
    }

    return 0;
}