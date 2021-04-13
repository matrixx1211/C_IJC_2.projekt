// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#ifndef __HTAB_H_STRUCT__
#define __HTAB_H_STRUCT__

#include "htab.h"

struct htab {
        int size;
        int arr_size;
        htab_pair_t ptr[];
    };

#endif