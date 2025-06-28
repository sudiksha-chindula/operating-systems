#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>

#define SEM_NAME "/mysemaphore"

sem_t *semaphore;

void* thread_fun(void* arg) {
    int thread_id = *(int*)arg;
    printf("Thread %d: Waiting for semaphore\n", thread_id);
    sem_wait(semaphore);
    printf("Thread %d: Entering critical section\n", thread_id);
    sleep(1); 
    printf("Thread %d: Leaving critical section\n", thread_id);
    sem_post(semaphore);

    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;
    semaphore = sem_open(SEM_NAME, O_CREAT, 0644, 1);
    if (semaphore == SEM_FAILED) {
        perror("sem_open failed");
        return 1;
    }
    pthread_create(&thread1, NULL, thread_fun, &id1);
    pthread_create(&thread2, NULL, thread_fun, &id2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    sem_close(semaphore);
    sem_unlink(SEM_NAME);

    return 0;
}
