// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "io.h"

#define MAXWORD 128
#define HTAB_SIZE 256 //! prověřit číslo testováním různých možností a následně vybrat to s nejnižším time ./word...

int main()
{
    //initialize hash table with size HTAB_SIZE
    htab_t *t = htab_init(HTAB_SIZE);

    //array of chars for string/words from file F
    char s[MAXWORD];

    //return value from read_word, length of word or EOF
    int l;

    //readed file
    FILE *f = stdin;

    //read one word and put it in hash table 
    while ((l = read_word(s, MAXWORD, f)) != EOF)
        if (l != 0)
            htab_lookup_add(t, s);
    
    //print every record in hash table
    htab_for_each(t, printf);

    //clear values in array and free memory 
    htab_free(t);

    return 0;
}
