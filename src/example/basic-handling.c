#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <espace/error.h>               // reference to ESPACE APIs
#include <example/error.h>              // reference to defined ERROR

int main(int argc, char *argv[])
{
    espace_raise(LIBA_E001);            // raise ERROR
    printf("raise ERROR\n");

    if (espace_catch(LIBA_E001)) {      // try to catch ERROR 
        printf("catched ERROR\n");      // and catched ERROR

        printf("handle for ERROR\n");   // do somethings to 
                                        // handle for ERROR

        espace_clear();                 // clear ERROR after handling
        printf("clear ERROR\n");        //
    }

    printf("continue process\n");       // do other things
}
