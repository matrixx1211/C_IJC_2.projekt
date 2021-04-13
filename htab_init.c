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
    htab_t *hash_table = malloc((sizeof(htab_t) + (n * sizeof(htab_pair_t))));

    //check if alloc success
    if (!hash_table)
        return NULL; // if not return null

    //set arr_size
    hash_table->arr_size = n;

    //initialize array
    for (size_t i = 0; i < n; i++)
    {
        hash_table->ptr[i].key = NULL;
        hash_table->ptr[i].value = 0;
    }

    // if malloc success return structure
    return hash_table;
}