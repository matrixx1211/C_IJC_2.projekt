// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include "htab.h"
#include "htab_struct.h"

void htab_for_each(const htab_t *t, void (*f)(htab_pair_t *data))
{
    //go through array
    for (size_t i = 0; i < t->arr_size; i++)
    {
        htab_item_t *tmp = t->ptr[i]; 
        //go through every array index records
        while (tmp != NULL)
        {
            //call function f with ptr to htab_pair_t
            f(&(tmp->item));
            tmp = tmp->next;
        }
        
    }
    
}