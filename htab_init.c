// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include <stdlib.h>
#include "htab.h"
#include "htab_struct.h"

/* initialize hast table  */
htab_t *htab_init(size_t n)
{
    //alloc memory for table
    htab_t *t = malloc((sizeof(htab_t) + (n * sizeof(htab_item_t))));

    //check if alloc success
    if (!t)
        return NULL; // if not return null

    //set size
    t->size = 0;
    //set arr_size
    t->arr_size = n;

    //initialize array
    for (size_t i = 0; i < n; i++)
        t->ptr[i] = NULL;

    // if malloc success return structure
    return t;
}