#include <espace/error.h>

#include <stdio.h>

const __thread struct espace_error * espace = ESPACE_CLEAN;

inline void espace_raise(const struct espace_error * error)
{
    espace = error; 
}

inline void espace_clear(void)
{
    espace = ESPACE_CLEAN;
}

inline bool espace_indomain(const struct espace_domain * domain)
{
    return espace->domain == domain;
}

inline bool espace_inerror(const struct espace_error * error)
{
    return espace == error; 
}

inline void espace_perror(const struct espace_error * error)
{
    if (error == NULL)
        printf("None\n");
    else
        printf("%s: %8u - %s\n", 
                error->domain->name, error->code, error->str);
}

inline void espace_pdomain(const struct espace_domain * domain)
{
    printf("%s\n", domain->name);
}
