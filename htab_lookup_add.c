// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include "htab.h"
#include "htab_struct.h"

/* find record with key, if not exist add else inc value */
htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key)
{
    //calculate index for table
    size_t index = (htab_hash_function(key) % t->arr_size);
    
    //
    if (htab_find(t, key) == NULL)
    {
        //nenajdu vložím

    }
    else
    {
        //najdu přičtu value
    }
    
    //return NULL;
    //return item;
}