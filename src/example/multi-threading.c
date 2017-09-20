#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <espace/error.h>                   // reference to ESPACE API's
#include <example/error.h>                  // reference to defined ERROR

void * t1_entry(void *arg)
{
    espace_raise(LIBA_E001);                // raise ERROR to see 
    printf("thread-1: %s\n", espace->id);   // Will ERROR_STATE affect to 
                                            // thread-2

    sleep(3);                               // wait for thread-1 checking
    return NULL;
}

void * t2_entry(void *arg)
{
    sleep(1) ;                              // wait for thread-1 raises ERROR
    printf("thread-2: %s\n", espace->id);   // check affecting from thread-1
                                            // it must not be affected
    return NULL;
}

void exit_err(const char *msg)
{
    fprintf(stderr, "ERROR: %s with %s\n", strerror(errno), msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    pthread_t t1;
    pthread_t t2;

    if (pthread_create(&t1, NULL, t1_entry, NULL))
        exit_err("pthread_create:t1_entry");
    if (pthread_create(&t2, NULL, t2_entry, NULL))
        exit_err("pthread_create:t2_entry");

    if (pthread_join(t1, NULL))
        exit_err("pthread_join:t1_entry");
    if (pthread_join(t2, NULL))
        exit_err("pthread_join:t2_entry");
}

