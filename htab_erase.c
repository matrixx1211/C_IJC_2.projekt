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
    //item before item to be erased
    htab_item_t *pre;

    //item to be erased
    htab_item_t *tmp;

    //find
    for (size_t i = 0; i < t->arr_size; i++)
    {
        pre = t->ptr[i];
        tmp = t->ptr[i];

        while (tmp != NULL)
        {
            //if not find item with key 
            if (strcmp(tmp->item.key, key) != 0)
            {
                pre = tmp;
                tmp = tmp->next;
            }
            else
            {
                if (pre != tmp)
                    //set next of erased item to previous next
                    pre->next = tmp->next;
                else
                    //if erased item is on beginning  
                    t->ptr[i] = tmp->next;

                //decrease size
                t->size--;

                //free memory of key
                free((void *)tmp->item.key);
                //free memory of struct
                free(tmp);

                //if erase was successful
                return true;
            }
        }
    }
    return false;
}