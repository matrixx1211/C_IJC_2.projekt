// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include <stdlib.h>
#include <stdbool.h>
#include "htab.h"
#include "htab_struct.h"

/* erase record with key in table t */
bool htab_erase(htab_t *t, htab_key_t key)
{
    //find if record with key exist or not
    htab_pair_t *exist = htab_find(t, key);
    
    //if not exist
    if (exist == NULL)
        //if erase was not successful
        return false;

    //temporary ptr to table t
    htab_t *tmp = t;

    //find
    for (size_t i = 0; i < t->arr_size; i++)
    {
        while (exist != &tmp->ptr[i]->item)
        {
            //TODO: předělat next smazaného na předchozí, free záznam 
            tmp->ptr[i] = tmp->ptr[i]->next; 
        }
    }

    //if erase was successful
    return true;
}
