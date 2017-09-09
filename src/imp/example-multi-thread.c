/*
DESCRIPTION

    Show multi-thread error handling. ERROR_STORAGE is local thread
    and it doen't affect to ERROR_STORAGE of other threads.

AUTHORS

    Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include <espace/error.h>

// START: DECLARE_YOUR_ERROR_SPACE
// Should put this block into header file

// define ERROR_NOs imediately, no need to declare
#define LIBA_E001 1
#define LIBA_E002 2
#define LIBA_E003 3

// declare ERROR_STORAGE and STRING_ERROR_FN
ESPACE_DECLARE(liba)

// END: DECLARE_YOUR_ERROR_SPACE
 
// START: DEFINE_YOUR_ERROR_SPACE
// Should put this block into source file

// define array of STRING_ERRORs
#define LIBA_ERRSTRS_SIZE 3
const char * LIBA_ERRSTRS[LIBA_ERRSTRS_SIZE] = {
    "1rt Error",
    "2sd Error",
    "3rd Error"
};

// define ERROR_STORAGE and STRING_ERROR_FN
ESPACE_DEFINE(liba, LIBA_ERRSTRS, LIBA_ERRSTRS_SIZE)

// END: DEFINE_YOUR_ERROR_SPACE

void * t1_entry(void *arg)
{
    liba_errno = LIBA_E001;
    printf("thread 1, errno=%u, errstr=%s\n", liba_errno, 
            liba_errstr(liba_errno));

    return NULL;
}

void * t2_entry(void *arg)
{
    // wait for thread 1 set errno
    sleep(1);
    
    printf("thread 2, errno=%u, errstr=%s\n", liba_errno, 
            liba_errstr(liba_errno));

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t t1;
    pthread_t t2;
    int ret;

    // start threads
    if (pthread_create(&t1, NULL, t1_entry, NULL)) {
        perror(strerror(errno));
        return EXIT_FAILURE;
    }
    if (pthread_create(&t2, NULL, t2_entry, NULL)) {
        perror(strerror(errno));
        return EXIT_FAILURE;
    }

    // wait for thread exited
    ret = pthread_join(t1, NULL);
    if (ret) {
        perror(strerror(ret));
        return EXIT_FAILURE;
    }
    ret = pthread_join(t2, NULL);
    if (ret) {
        perror(strerror(ret));
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
