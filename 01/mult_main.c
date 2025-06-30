#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    char* x = argv[1];
    char* y = argv[2];

    execl("./a.out", "./a.out", x, y, NULL);

    return 0;
}