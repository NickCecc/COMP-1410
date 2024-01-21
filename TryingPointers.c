#include <stdio.h>

/*
void convInch2Feet(int totinches, int* feet, int* remInch){
    *feet = totinches/12;
    *remInch = totinches % 12;
    // pointers allow me to "return" 2 values instead of 1
}



int main(){
    int totInches = 90;
    int feet, inches;
    // & sign corresponds to the feet and remInch parameters
    convInch2Feet(totInches, &feet, &inches);
    printf("%d %d", feet, inches);
}
 */
/*
int main(){
    int num1 = 5;
    int *num2;

    printf("num1: %d\n", num1);
    num2 = &num1;
    printf("num2: %d\n", *num2);
    *num2 = 10;
    printf("num1: %d\n", num1);
    printf("num2: %d\n", *num2);

}
 */
#include <stdio.h>
#include <string.h>

int main () {
    const char str[] = "http://www.tutorialspoint.com";
    const char ch = '.';
    char *ret;

    ret = strchr(str, ch);

    printf("String after |%c| is - |%s|\n", ch, ret);

    return(0);
}