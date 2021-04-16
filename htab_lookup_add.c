// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include <stdlib.h>
#include<string.h> //?maybe
#include "htab.h"
#include "htab_struct.h"

/* find record with key, if not exist add else inc value */
htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key)
{
    //calculate index for table
    size_t index = (htab_hash_function(key) % t->arr_size);

    //one record from hash table
    htab_pair_t *record;

    //temporary item
    htab_item_t *tmp = t->ptr[index];
    
    //if record with key not exist, create record
    if ((record = htab_find(t, key)) == NULL)
    {
        //go through ptr array with index and set empty record to tmp
        while (tmp->next != NULL)
            tmp = tmp->next;
        
        //alloc memory for new item
        htab_item_t *newitem = malloc(sizeof(key) + sizeof(htab_item_t));

        //set values for new item
        newitem->item.key = key; //?if not working strncpy
        newitem->item.value = 1;
        newitem->next = NULL;

        //set ptr of new item to last pos of table
        tmp = newitem;

        //inc count of records
        t->size++;
    }
    else
        record->value++;
    
    //?maybe it destroy pointer 
    //return ptr to new item
    return &tmp->item;
}