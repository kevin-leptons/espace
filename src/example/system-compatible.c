#include <stdio.h>
#include <errno.h>                      // reference to System Error
#include <espace/error.h>               // reference to ESPACE APIs
#include <espace/sys.h>                 // reference to 
                                        // ESPACE's System Error

int main(int argc, char *argv[])
{
    sys_raise(EPERM);                   // raise System Error 
    printf("raise error\n");            // as ESPACE's ERROR
    
    if (espace_catch(SYS_EPERM)) {      // try to catch ERROR
        printf("catched ERROR\n");      // and catched ERROR

        printf("handle for ERROR\n");   // do somethings to handle ERROR

        espace_clear();                 // clear ERROR after handling
        printf("clear ERROR\n");        //
    }

    printf("continue process\n");       // do other things
}
