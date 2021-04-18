// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include <stdio.h>
#include <ctype.h>
#include "io.h"

int read_word(char *s, int max, FILE *f)
{
    //length of word
    int l = 0;

    //one character from file f
    int c;

    //max string length
    int str_l = max - 1;

    //while readed char is not from isspace
    while (!(isspace(c = fgetc(f))) && c != EOF)
    {
        //print error if word is longer than max-1
        if (l == str_l)
            fprintf(stderr, "IO: Unexpected length of word.\n");
        //
        if (l < str_l)
        {
            s[l] = c;
            l++;
        }
    }

    //set terminator for string
    s[l] = '\0';

    //if file is on end
    if (feof(f))
        return EOF;

    //return length of readed word
    return l;
}