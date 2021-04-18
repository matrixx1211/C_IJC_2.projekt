// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include <stdlib.h>
#include "htab.h"
#include "htab_struct.h"

void htab_clear(htab_t *t)
{
    //temporary ptr
    htab_item_t *tmp;

    //temporary ptr to next because of free
    htab_item_t *tmpnext;

    //for every array index i
    for (size_t i = 0; i < t->arr_size; i++)
    {
        tmp = t->ptr[i];

        //go through items on index i in array ptr
        while (tmp != NULL)
        {
            //temporary save ptr to next
            tmpnext = tmp->next;

            //free key
            free((char *)tmp->item.key);

            //because of this free
            free(tmp);

            //set new begin to next
            tmp = tmpnext;
        }
    }
}