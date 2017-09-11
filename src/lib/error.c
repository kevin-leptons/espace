#include <espace/error.h>

#include <stdio.h>

const __thread struct espace_error * espace = ESPACE_CLEAN;

inline void espace_raise(const struct espace_error * error)
{
    espace = error; 
}
inline void espace_clear()
{
    espace = ESPACE_CLEAN;
}

inline bool espace_isbox(const struct espace_box * box)
{
    return espace->box == box;
}

inline bool espace_iserror(const struct espace_error * error)
{
    return espace == error; 
}

inline void espace_perror(const struct espace_error * error)
{
    printf("%s: %08u - %s\n", error->box->name, error->code, error->str);
}

inline void espace_pbox(const struct espace_box * box)
{
    printf("%s\n", box->name);
}
