#include <stdio.h>
#include <espace/error.h>                   // reference to ESPACE APIs
#include <example/error.h>                  // reference to defined ERROR

int main(int argc, char *argv[])
{
    espace_perror(LIBA_E001);               // print ERROR_IDENTITY to stderr

    fprintf(stderr, "ERROR: %s\n",          // print ERROR_IDENTITY 
            LIBA_E001->id);                 // with formatting to stderr

    espace_perror(espace);                  // printf current ERROR_IDENTITY
                                            // to stderr

    fprintf(stderr, "Current ERROR: %s",    // print current ERROR_IDENTITY 
            espace->id);                    // with formatting to stderr
}
