#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include <example/error.h>

void * t1_entry(void *arg)
{
    liba_raise(LIBA_E001);
    printf("thread 1, errno=%u, errstr=%s\n", espace.code, 
            liba_errstr(espace.code));
    printf("%p %p %p\n", (void *) liba_ecid, (void *) espace.cid, 
            &liba_ecid);

    if (espace.code != 0) {
        if (espace.cid == liba_ecid)
            printf("match\n");
    }
    espace_clear();
    printf("thread 1, errno=%u, errstr=%s\n", espace.code, 
            liba_errstr(espace.code));

    return NULL;
}

void * t2_entry(void *arg)
{
    // wait for thread 1 set errno
    sleep(1);
    
    printf("thread 2, errno=%u, errstr=%s\n", espace.code, 
            liba_errstr(espace.code));
    espace_raise(liba_ecid, LIBA_E001);

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
