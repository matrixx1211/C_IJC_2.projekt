// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include <stdlib.h>
#include "htab.h"

void htab_free(htab_t *t)
{
    //destruct table
    htab_clear(t);
    
    //free memory
    free(t);
}