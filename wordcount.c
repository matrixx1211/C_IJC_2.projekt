// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "io.h"

#define MAXWORD 128
#define HTAB_SIZE 255 //! i choose this size because of (2^8-1)

void print(htab_pair_t *data)
{
    printf("%s\t%u\n", data->key, data->value);
}

int main()
{
    //initialize hash table with size HTAB_SIZE
    htab_t *t = htab_init(HTAB_SIZE);
    if (t == NULL)
    {
        fprintf(stderr, "WORDCOUNT: Unexpected error with initializing table.");
        return 1;
    }

    //data inserted into table
    htab_pair_t *inserted;

    //array of chars for string/words from file f
    char s[MAXWORD] = {0};

    //return value from read_word, length of word or EOF
    int l;

    //readed file
    FILE *f = stdin;

    //read one word and put it in hash table
    while ((l = read_word(s, MAXWORD, f)) != EOF)
    {
        if (s[0] != '\0')
        {
            inserted = htab_lookup_add(t, s);
            if (inserted == NULL)
            {
                fprintf(stderr, "WORDCOUNT: Unexpected error with inserting word into table.");
                htab_free(t);
                return 1;
            }
        }
    }

    htab_erase(t, "-");

    //print every record in hash table
    htab_for_each(t, print);

    //clear values in array and free memory
    htab_free(t);

    return 0;
}
