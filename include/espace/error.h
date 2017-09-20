/*
NAME
    espace - error space.

SYNOPSIS

    // macros
    ESPACE_ERRDEC(err_name);
    ESPACE_ERRDEF(err_name);

    // global, thread-local variables
    struct espace_error * espace;

    // functions
    void espace_raise(const struct espace_error * state);
    bool espace_catch(const struct espace_error * error);
    void espace_clear(void);
    void espace_perror(const struct espace_error * error);

DESCRIPTION

    ESPACE_ERRDEC() declares ERROR in header files.
    ESPACE_ERRDEF() defines ERROR in source files.

    espace variable is ERROR_STATE.
    
    espace_raise(), espace_catch() espace_clear() is uses to raise, catch and
    clear ERROR_STATE.
    espace_perror() is uses to print ERROR_IDENTITY_NAME to stderr.

    For more detail about concepts, see <doc/index.txt>
    
AUTHORS

    Kevin Leptons <kevin.leptons@gmail.com>
*/

#ifndef _ESPACE_ERROR_H_
#define _ESPACE_ERROR_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef _REENTRANT
#define ESPACE_THRDATTR __thread
#else
#define ESPACE_THRDATTR
#endif

#define ESPACE_ERRDEC(err_name) \
    extern const struct espace_error * const err_name;

#define ESPACE_ERRDEF(err_name) \
    const struct espace_error _##err_name = { \
        .id = #err_name \
    }; \
    const struct espace_error * const err_name = &_##err_name;

struct espace_error
{
    const char *id;
};

extern const ESPACE_THRDATTR struct espace_error * espace;
void espace_raise(const struct espace_error * state);
bool espace_catch(const struct espace_error * error);
void espace_clear(void);
void espace_perror(const struct espace_error * error);

#endif
