#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int x = *argv[1] - '0';
    int y = *argv[2] - '0';

    printf("Product : %d\n", x * y);


    return 0;
}
