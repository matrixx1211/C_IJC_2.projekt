// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include <inttypes.h>
#include <stdio.h>
#include "htab.h"

/* calculate hash from str */
size_t htab_hash_function(const char *str)
{
#ifdef HASHTEST
    
    //djb2 algorithm
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;

#else

    //PePe algorithm
    uint32_t h = 0;
    const unsigned char *p;
    for (p = (const unsigned char *)str; *p != '\0'; p++)
        h = 65599 * h + *p;
    return h;

#endif
}