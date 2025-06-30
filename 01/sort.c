#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global_array[8] = {1, 6, 2, 4, 5, 8, 9, 0};

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main() {
    pid_t pid = fork();
if (pid < 0) {
        perror("fork failed");
        exit(1);

    } else if (pid == 0) {
        // Child process
        bubble_sort(global_array, 8);
        printf("Child sorted array:\n");
        for (int i = 0; i < 8; i++) {
            printf("%d ", global_array[i]);
        }

        printf("\n");
        exit(0);

    } else {
        // Parent process
        printf("Parent array after child process:\n");
        for (int i = 0; i < 8; i++) {
            printf("%d ", global_array[i]);
        }
        printf("\n");
    }
return 0;
}
