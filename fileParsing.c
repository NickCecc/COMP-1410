#include <stdio.h>
#include <string.h>

int main(void) {

    /* Type your code here. */
    FILE *inFile = NULL;
    char firstName[101];
    char modName[101];
    char inFileName[101];
    scanf("%100s", inFileName);
    inFile = fopen(inFileName, "r");
    if (inFile == NULL) {
        printf("Could not open file ParkPhotos.txt.\n");
        return -1; // -1 indicates error
    }

    while (fscanf(inFile, "%100s", firstName) == 1) {
        if (strstr(firstName, "_photo.jpg") != NULL) {
            strncpy(modName, firstName, strlen(firstName) - strlen("_photo.jpg"));
            modName[strlen(firstName) - strlen("_photo.jpg")] = '\0';
            strcat(modName, "_info.txt");
            printf("%s\n", modName);
        } else if (strstr(firstName, "_info.txt") != NULL) {
            printf("%s\n", firstName);
        }
    }


    fclose(inFile);

    return 0;
}

