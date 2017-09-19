#include <stdlib.h>
#include <stdio.h>
#include <espace/sys.h>

#include <example/error.h>

int main(int argc, char *argv[])
{
    espace_raise(LIBA_E001);

    if (espace_inerror(LIBA_E001))
        espace_perror(espace);
    if (espace_indomain(LIBA_DOME))
        espace_perror(espace);

    espace_perror(LIBA_E004);
    espace_perror(LIBA_E003);
    espace_pdomain(LIBA_E002->domain);

    /*espace_raise(SYS_EAGAIN);*/
    espace_perror(espace);

    espace_clear();
    espace_perror(espace);
}
