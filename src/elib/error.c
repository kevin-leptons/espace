#include <example/error.h>

#include <stdlib.h>

struct espace_box _LIBA_EBOX = 
{
    .name="liba"
};

const struct espace_box * const LIBA_EBOX = &_LIBA_EBOX;

const struct espace_error * const LIBA_E001 = &(struct espace_error)
{
    .box = &_LIBA_EBOX, 
    .code = 1, 
    .str = "1rt Error"
};
const struct espace_error * const LIBA_E002 = &(struct espace_error)
{
    .box = &_LIBA_EBOX,
    .code = 2,
    .str = "2nd Error"
};
const struct espace_error * const LIBA_E003 = &(struct espace_error)
{
    .box = &_LIBA_EBOX,
    .code = 3,
    .str = "3rd Error"
};
