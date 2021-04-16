// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#ifndef __IO_H__
#define __IO_H__

#include <stdio.h>

/* read word from FILE f, return length of word  */
int read_word(char *s, int max, FILE *f);

#endif //__IO_H__