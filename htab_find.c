// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include "htab.h"
#include "htab_struct.h"

/* find record with key */
htab_pair_t *htab_find(htab_t *t, htab_key_t key)
{
    //go through htab_item_t array
    for (size_t i = 0; i < t->arr_size; i++)
    {
        //temporary htab_item_t
        htab_item_t *tmp = t->ptr[i];

        //while next is not NULL then try find record with key
        while (tmp->next != NULL)
        {
            if (!strcmp(key, tmp->item.key))
            {
                return &tmp->item;
            }
            tmp = tmp->next;
        }
    }

    //if record with key doesnt exist return null
    return NULL;
}