// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* 511 chars + 0 */
#define LINELENGTH 512
#define LINECOUNTDEFAULT 10
#define STDINPUT -1

/* Trying to open file, if success then return ptr on file else exit(1) */
FILE *try_fopen(int fpos, char const *argv[])
{
    FILE *f = fopen(argv[fpos], "r");
    if (f == NULL)
    {
        fprintf(stderr, "TAIL: Unexpected error with opening file.\n");
        exit(1);
    }
    return f;
}

/* Checking arguments passed on cmd line, if something is wrong then exit(1) */
void arg_check(int c, char const *arg[], bool *plus, unsigned int *n, int *fpos)
{
    //testing count of args
    if (c >= 1 && c <= 4)
    {
        for (int i = 1; i < c; i++)
        {
            //in case of -n was passed on cmd line
            if (!strcmp("-n", arg[i]))
            {
                if (atoi(arg[i + 1]) > 0 && !(isdigit(atoi(arg[i + 1]))))
                {
                    *n = atoi(arg[i + 1]);
                    if (strchr(arg[i + 1], '+'))
                        *plus = true;
                }
                else
                {
                    fprintf(stderr, "TAIL: Unexpected value for option -n passed.\n");
                    exit(-1);
                }
            }
            //testing if file was passed or not
            if (strchr(arg[i], '.'))
                *fpos = i;
        }
    }
    else
    {
        fprintf(stderr, "TAIL: Unexpected arguments passed.\n");
        exit(-1);
    }
}

/* Counting lines */
int count_lines(FILE *f)
{
    //variables
    char c;
    int lc = 0;

    //go through file and count lines
    while (!feof(f))
    {
        c = fgetc(f);
        if (c == '\n' || feof(f))
            lc++;
    }
    return lc;
}

/* Printing selected lines */
void print_lines(unsigned int lc, bool plus, unsigned int n, FILE *f)
{
    //variables
    int c;
    int begin = 0, ll = 0, cl = 0;
    //checking if + is passed
    if (plus)
        begin = n - 1;
    else
        begin = lc - n;
    //set pointer on beginning of file
    fseek(f, 0, SEEK_SET);
    //printing
    while (!feof(f))
    {
        c = fgetc(f);
        ll++;
        if (cl >= begin && ll <= LINELENGTH)
        {
            if (ll == (LINELENGTH - 1))
            {
                c = '\n';
                fprintf(stderr, "TAIL: Unexpected length of line.\n");
            }
            if (ll == LINELENGTH)
                c = '\0';
            printf("%c", c);
        }
        if (c == '\n' && ll != (LINELENGTH - 1))
        {
            cl++;
            ll = 0;
        }
        if (ll == (LINELENGTH - 1))
            ll++;
        if (feof(f))
            printf("\n");
    }
}

/* Main function */
int main(int argc, char const *argv[])
{
    //variables
    unsigned int n = LINECOUNTDEFAULT, lc = 0;
    int fpos = STDINPUT;
    bool plus = false;
    FILE *f = stdin;

    //check if args are correctly passed
    arg_check(argc, argv, &plus, &n, &fpos);
    //select stdin/file
    if (fpos != STDINPUT)
        f = try_fopen(fpos, argv);
    lc = count_lines(f);
    //print output
    print_lines(lc, plus, n, f);

    return 0;
}
