/*
DESCRIPTION

    Show simple way to define ERROR_SPACE.

AUTHORS

    Kevin Leptons <kevin.leptons@gmail.com>
*/

#include <stdlib.h>
#include <stdio.h>

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

int main(int argc, char *argv[])
{
    printf("liba_errno=%u, str=%s\n", liba_errno, liba_errstr(liba_errno));

    liba_errno = LIBA_E001;
    printf("liba_errno=%u, str=%s\n", liba_errno, liba_errstr(liba_errno));

    liba_errno = LIBA_E002;
    printf("liba_errno=%u, str=%s\n", liba_errno, liba_errstr(liba_errno));

    liba_errno = LIBA_E003;
    printf("liba_errno=%u, str=%s\n", liba_errno, liba_errstr(liba_errno));
    
    return EXIT_SUCCESS;
}
