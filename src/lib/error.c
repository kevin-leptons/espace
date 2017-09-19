#include <espace/error.h>
#include <stdio.h>

ESPACE_ERRDEF(ESPACE_ENONE);
const __thread struct espace_error * espace = &_ESPACE_ENONE;

inline void espace_raise(const struct espace_error * error)
{
    espace = error; 
}

inline void espace_clear(void)
{
    espace = ESPACE_ENONE;
}

inline bool espace_iserror(const struct espace_error * error)
{
    return espace == error; 
}

inline void espace_perror(const struct espace_error * error)
{
    printf("%s\n", error->name);
}
