#include <stdio.h>

int Fibonacci(int n) {

    if (n == 1){
        return 1;
    }
    if (n == 0){
        return 0;
    }
    if (n < 0){
        return -1;
    }
    else{
        return Fibonacci(n-1) + Fibonacci(n-2);

    }



}

int main() {
    int startNum;

    scanf("%d", &startNum);
    printf("Fibonacci(%d) is %d\n", startNum, Fibonacci(startNum));

    return 0;
}