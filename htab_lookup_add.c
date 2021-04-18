// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include <stdlib.h>
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
        //alloc memory for new structure
        htab_item_t *new_item = malloc(sizeof(htab_item_t));

        //check if malloc success
        if (new_item == NULL)
            return NULL;

        //alloc memory for new key
        new_item->item.key = malloc(sizeof(char) * (strlen(key) + 1));

        //check if malloc success
        if (new_item->item.key == NULL)
            return NULL;

        //set values for new item
        new_item->item.value = 1;
        new_item->next = NULL;
        strcpy((char *)new_item->item.key, key);

        //check if t on index is empty or not
        if (tmp != NULL)
        {
            //go through ptr array with index and set empty record to tmp
            while (tmp->next != NULL)
                tmp = tmp->next;
            //save new item to t on index on the end
            tmp->next = new_item;
        }
        else
            //save new item to t on index on the beginning
            t->ptr[index] = new_item;

        //set ptr of new item to last pos of table
        tmp = new_item;

        //inc count of records
        t->size++;
    }
    else
        record->value++;

    //return ptr to new item
    return &(tmp->item);
}