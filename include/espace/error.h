/*
SYNOPSIS

    // macros
    ESPACE_DECLARE(prefix) 
    ESPACE_DEFINE(prefix, errstrs, errstrs_size)

DESCRIPTION

    Support to define ERROR_SPACE. To do that, you must define ERROR_SET,
    ERROR_CODE_SET, ERROR_CODE_NAME_SET, ERROR_STRING_SET. Then espce will
    help you define ERROR_STORAGE and ERROR_STRING_FN.  For more detail about
    concepts and manual, see "doc/index.txt". 

AUTHORS

    Kevin Leptons <kevin.leptons@gmail.com>
*/

#ifndef _ESPACE_ERROR_H_
#define _ESPACE_ERROR_H_

#include <stdlib.h>

extern const char ESPACE_ERRSTR_UNKNOWN[];
extern const char ESPACE_ERRSTR_NONE[];

#ifdef _REENTRANT
#define _ESPACE_ERRNO_ATTR __thread
#else
#define _ESPACE_ERRNO_ATTR 
#endif

#define ESPACE_DECLARE(prefix) \
    extern _ESPACE_ERRNO_ATTR unsigned int prefix##_errno; \
    const char * prefix##_errstr(unsigned int code);

#define ESPACE_DEFINE(prefix, errstrs, errstrs_size) \
    _ESPACE_ERRNO_ATTR unsigned int prefix##_errno = 0; \
    const char * prefix##_errstr(unsigned int code) { \
        if (code == 0) \
            return ESPACE_ERRSTR_NONE; \
        if (code > errstrs_size) \
            return ESPACE_ERRSTR_UNKNOWN; \
        return errstrs[code - 1]; \
    }

#endif
