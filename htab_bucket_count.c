// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include "htab.h"
#include "htab_struct.h"

size_t htab_bucket_count(const htab_t *t)
{
    //return size of array
    return t->arr_size;
}