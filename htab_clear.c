// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include "htab.h"
#include "htab_struct.h"

void htab_clear(htab_t *t)
{
    //temporary ptr to t
    htab_t *tmp = t;

    //temporary ptr to next because of free
    htab_item_t *tmpnext;

    //for every array index i
    for (size_t i = 0; i < tmp->arr_size; i++)
    {
        //go through items on index i in array ptr
        while (tmp->ptr[i]->next != NULL)
        {
            //temporary save ptr to next
            tmpnext = tmp->ptr[i]->next;
            //because of this free
            free(tmp->ptr[i]);
            //set new begin to next
            tmp->ptr[i] = tmpnext;
        }
        
    }
}