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
#include <stdbool.h>

#ifdef _REENTRANT
#define ESPACE_THREAD_ATTR __thread
#else
#define ESPACE_THREAD_ATTR
#endif

#define ESPACE_CLEAN NULL

struct espace_domain
{
    const char * name;
};

struct espace_error
{
    const struct espace_domain * const domain;
    const uint32_t code;
    const char *str;
};

extern const __thread struct espace_error * espace;

void espace_raise(const struct espace_error * state);
void espace_clear(void);
bool espace_indomain(const struct espace_domain * domain);
bool espace_inerror(const struct espace_error * error);
void espace_perror(const struct espace_error * error);
void espace_pdomain(const struct espace_domain * domain);

//declare and define error domain
#define ESPACE_DOMDEC(dom_symbol) \
    const struct espace_domain * const dom_symbol;

#define ESPACE_DOMDEF(dom_symbol, dom_name) \
    const struct espace_domain _##dom_symbol = { \
        .name = dom_name \
    }; \
    const struct espace_domain * const dom_symbol = &_##dom_symbol;

// declare and define error
#define ESPACE_ERRDEC(name) \
    extern const struct espace_error * const name;

#define ESPACE_ERRDEF(dmo_symbol, err_name, err_code, err_str) \
    const struct espace_error * const err_name = &(struct espace_error) { \
        .domain = &_##dmo_symbol, \
        .code = err_code, \
        .str = err_str \
    };

#endif
