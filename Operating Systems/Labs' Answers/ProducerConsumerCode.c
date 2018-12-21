/* Includes */
#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */
#include <semaphore.h>  /* Semaphore */
# define MAX 5
sem_t empty;
sem_t full;
int buffer[MAX];
int fill = 0; 
int use  = 0;

void put(int value) {
    buffer[fill] = value;    // line F1
    fill = (fill + 1) % MAX; // line F2
}

int get() {
    int tmp = buffer[use];   // line G1
    use = (use + 1) % MAX;   // line G2
    return tmp;
}
int loops;
void *producer(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
        sem_wait(&empty);           // line P1
        put(i+10);                     // line P2
        sem_post(&full);            // line P3
    }
}

void *consumer(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
        sem_wait(&full);            // line C1
        int tmp = get();            // line C2
        sem_post(&empty);           // line C3
        printf("%d\n", tmp);
    }
}
int main(int argc, char *argv[]) {
    loops = atoi(argv[1]);
    sem_init(&empty, 0, MAX); // MAX buffers are empty to begin with...
    sem_init(&full, 0, 0);    // ... and 0 are full
    pthread_t pid, cid;
    pthread_create(&pid, NULL, producer, NULL); 
    pthread_create(&cid, NULL, consumer, NULL); 
    pthread_join(pid, NULL); 
    pthread_join(cid, NULL); 
    return 0;
}
