#include <espace/error.h>

const char ESPACE_ERRSTR_UNKNOWN[] = "Unkown Error";
const char ESPACE_ERRSTR_NONE[] = "No Error";

ESPACE_THREAD_ATTR struct espace_estate espace = {0, 0};

inline void espace_raise(uintptr_t class_id, uint32_t code)
{
    espace.cid = class_id;
    espace.code = code;
}

inline void espace_clear(void)
{
    espace.cid = 0;
    espace.code = 0;
}

