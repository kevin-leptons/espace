#include <stdlib.h>
#include <stdio.h>

#include <example/error.h>

int main(int argc, char *argv[])
{
    espace_raise(LIBA_E001);

    if (espace_iserror(LIBA_E001))
        espace_perror(espace);

    espace_perror(LIBA_E002);
    espace_perror(LIBA_E003);
    espace_pbox(LIBA_E002->box);
}
