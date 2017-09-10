/*
NAME
    espace - error space.

SYNOPSIS

    // variables
    extern ESPACE_THREAD_ATTR struct espace_estate espace;

    // macros
    ESPACE_DECLARE(prefix) 
    ESPACE_DEFINE(prefix, errstrs, errstrs_size)

    // functions
    espace_raise(uintptr_t error_class, uint32_t code);
    espace_clear();

DESCRIPTION

    espace define error handling mechanism as a specification. It also
    provides methods to do that. To handle errors follow espace, you need to
    define:

        - ERROR_SET
        - ERROR_CODE_SET
        - ERROR_CODE_NAME_SET
        - ERROR_STRING_SET

    Next, espace will help you define:

        - ERROR_STRING_FN
        - ERROR_RAISING_FN

    Then you can handle errors by defined APIs. For more detail about concepts
    and manual, see "doc/index.txt". 

AUTHORS

    Kevin Leptons <kevin.leptons@gmail.com>
*/

#ifndef _ESPACE_ERROR_H_
#define _ESPACE_ERROR_H_

#include <stdint.h>

#ifdef _REENTRANT
#define ESPACE_THREAD_ATTR __thread
#else
#define ESPACE_THREAD_ATTR
#endif

struct espace_estate
{
    uintptr_t cid;
    uint32_t code;
};


extern const char ESPACE_ERRSTR_UNKNOWN[];
extern const char ESPACE_ERRSTR_NONE[];
extern ESPACE_THREAD_ATTR struct espace_estate espace;

void espace_raise(uintptr_t class_id, uint32_t code);
void espace_clear(void);

#define ESPACE_DECLARE(prefix) \
    extern const uintptr_t prefix##_ecid; \
    void prefix##_raise(uint32_t error_code); \
    const char * prefix##_errstr(uint32_t code);

#define ESPACE_DEFINE(prefix, errstrs, errstrs_size) \
    const uintptr_t prefix##_ecid = (uintptr_t) &prefix##_ecid; \
    inline void prefix##_raise(uint32_t error_code) { \
        espace.cid = prefix##_ecid; \
        espace.code = error_code; \
    } \
    const char * prefix##_errstr(uint32_t code) { \
        if (code == 0) \
            return ESPACE_ERRSTR_NONE; \
        if (code > errstrs_size) \
            return ESPACE_ERRSTR_UNKNOWN; \
        return errstrs[code - 1]; \
    }

#endif
