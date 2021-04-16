// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include "htab.h"
#include "htab_struct.h"

size_t htab_size(const htab_t *t)
{
    //return count of records
    return t->size;
}