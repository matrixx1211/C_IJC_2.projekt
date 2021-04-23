// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include <stdlib.h>
#include "htab.h"
#include "htab_struct.h"

/* move data from old table from to new table t2*/
htab_t *htab_move(size_t n, htab_t *from)
{
    //new table initialize
    htab_t *t2 = htab_init(n);

    //temporary ptr to item
    htab_item_t *tmp; 

    //inserted item
    htab_pair_t *inserted_item;

    //get keys from from and saving it to t2 
    for (size_t i = 0; i < from->arr_size; i++)
    {
        tmp = from->ptr[i];
        while (tmp != NULL)
        {
            //insert item
            inserted_item = htab_lookup_add(t2, tmp->item.key);
            
            //set value of inserted item to old value
            inserted_item->value = tmp->item.value;

            //go to next item
            tmp = tmp->next;
        }
    }

    //return ptr to new table
    return t2;
}