#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int signum) {
    printf("Error: Floating-point exception - division by zero\n");
    exit(EXIT_FAILURE);
}

int main() {
    int num1, num2;
    signal(SIGFPE, signal_handler);
    printf("Enter number 1: ");
    scanf("%d", &num1);
    printf("Enter number 2: ");
    scanf("%d", &num2);
    if (num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return EXIT_FAILURE;
    }
    int result = num1 / num2;
    printf("Result: %d\n", result);
    
    return 0;
}
