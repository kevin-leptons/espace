#include <example/error.h>

// define array of ERROR_STRING_SET
#define LIBA_ERRSTRS_SIZE 3
const char * LIBA_ERRSTRS[LIBA_ERRSTRS_SIZE] = {
    "1rt Error",
    "2sd Error",
    "3rd Error"
};

// define ERROR_STRING_FN and ERROR_RAISING_FN
ESPACE_DEFINE(liba, LIBA_ERRSTRS, LIBA_ERRSTRS_SIZE);
