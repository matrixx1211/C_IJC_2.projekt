// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#ifndef __HTAB_H_STRUCT__
#define __HTAB_H_STRUCT__

#include "htab.h"

typedef struct htab_item htab_item_t;
struct htab_item
{
    htab_pair_t item;
    htab_item_t *next;
}; 


struct htab {
        //count of records
        size_t size;
        //size of array
        size_t arr_size;
        //array of htab_pair_t
        htab_item_t *ptr[];
    };


#endif //__HTAB_H_STRUCT__