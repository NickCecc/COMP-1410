/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char hi[20];
void CreateAcronym(char userPhrase[], char userAcronym[]) {

    char a[1];
    char per[1] = ".";
    int flag= 0;

    for (int i = 0; i < strlen(userPhrase); i++) {
        if (isupper(userPhrase[i]) != 0 && flag != 1) {
            a[0] = userPhrase[i];
            //printf("%s", a);
            strncat(userAcronym, a, 5);
            strncat(userAcronym, per, 5);

            flag = 1;



            continue;
        } else if (isspace(userPhrase[i]) != 0) {
            flag = 0;
            continue;
        }

    }
    //strcpy(hi, userAcronym);
    printf("%s", userAcronym);

}


int main() {

    char str[30];
    char str2[30];

    scanf("%[^\n]s", str);
    CreateAcronym(str, str2);
    printf("%s\n", hi);


    return 0;
}
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int acronymIndex = 0;
int flag = 0;
void CreateAcronym(char userPhrase[], char userAcronym[]){


    for (int i = 0; i < strlen(userPhrase); i++) {
        if (isupper(userPhrase[i])!=0  && flag == 0) {
            userAcronym[acronymIndex++] = toupper(userPhrase[i]);
            userAcronym[acronymIndex++] = '.';
            flag = 1;
        }
        if (isspace(userPhrase[i]) != 0)
        {
            flag = 0;
            continue;
        }

    }

}

int main() {
    char acronym[100];
    char input[100];
    //printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    CreateAcronym(input, acronym);
    acronym[acronymIndex] = '\0';
    printf("%s", acronym);
    return 0;
}




