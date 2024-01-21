#include <stdio.h>
#include <string.h>

int main(void) {

    /* TODO: Declare any necessary variables here. */
    FILE *inFile;
    FILE *outFile;
    char fileName[21];
    char fName[26];
    char lName[26];
    char grade;
    int mid1, mid2, final, avg = 0;
    int numStudents = 0;
    float totalMid1 = 0, totalMid2 = 0, totalFinal = 0;
    float totalMid1Avg = 0, totalMid2Avg = 0, totalFinalAvg = 0;



    /* TODO: Read a file name from the user and read the tsv file here. */
    scanf("%20s", fileName);    // Get filename from user

    //inFile section
    inFile = fopen(fileName, "r"); // open file
    if (inFile == NULL) {
        printf("Could not open file %s.\n", fileName);
        return -1; // -1 indicates error
    }

    //outFile section
    outFile = fopen("report.txt", "w");
    if (outFile == NULL) {
        printf("Could not open file report.txt.\n");
        return -1; // -1 indicates error
    }
    // fprintf to print to file

    while (fscanf(inFile, "%25s%25s%d%d%d", lName, fName, &mid1, &mid2, &final) == 5) {
        numStudents++;
        avg = (mid1 + mid2 + final) / 3;

        if (avg >= 90)
            grade = 'A';
        else if (avg >= 80)
            grade = 'B';
        else if (avg >= 70)
            grade = 'C';
        else if (avg >= 60)
            grade = 'D';
        else
            grade = 'F';

        fprintf(outFile, "%s\t%s\t%d\t%d\t%d\t%c\n", lName, fName, mid1, mid2, final, grade);

        totalMid1 += (float) mid1;
        totalMid2 += (float) mid2;
        totalFinal += (float) final;

    }
    totalMid1Avg = totalMid1 / numStudents;
    totalMid2Avg = totalMid2 / numStudents;
    totalFinalAvg = totalFinal / numStudents;
    fprintf(outFile, "\nAverages: midterm1 %.2f, midterm2 %.2f, final %.2f\n", totalMid1Avg, totalMid2Avg,
            totalFinalAvg);


    fclose(inFile);
    fclose(outFile);

    outFile = fopen("report.txt", "r");
    if (outFile == NULL) {
        printf("Could not open file report.txt.\n");
        return -1;
    }

    char line[256];
    while (fgets(line, sizeof(line), outFile)) {
        printf("%s", line);
    }

    fclose(outFile);


    return 0;
}