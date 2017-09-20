#include <espace/error.h>
#include <stdio.h>
#include <signal.h>

ESPACE_ERRDEF(ESPACE_ENONE);
const __thread struct espace_error * espace = &_ESPACE_ENONE;

inline void espace_raise(const struct espace_error * error)
{
    if (error == NULL)
        raise(SIGSEGV);
    else
        espace = error; 
}

inline void espace_clear(void)
{
    espace = ESPACE_ENONE;
}

inline bool espace_catch(const struct espace_error * error)
{
    return espace == error; 
}

inline bool espace_check(void)
{
    return espace != ESPACE_ENONE;
}

inline void espace_perror(const struct espace_error * error)
{
    if (error == NULL)
        raise(SIGSEGV);
    else
        fprintf(stderr, "%s\n", error->id);
}
