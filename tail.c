#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* 511 chars + 0 */
#define LINELENGTH 512
#define LINECOUNTDEFAULT 10
#define STDINPUT -1
#define DEBUG printf("It goes right here.\n")

/* Try to open file, if success then return ptr on file else exit(1) */
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

/* Check arguments passed on cmd line, if something is wrong then exit(1) */
void arg_check(int c, char const *arg[], bool *plus, long *n, int *fpos)
{
    //testing count of args
    if (c >= 1 && c <= 4)
    {
        for (size_t i = 1; i < c; i++)
        {
            //in case of -n was passed on cmd line
            if (!strcmp("-n", arg[i]))
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

/* counting lines */
int count_lines(FILE *f, int fpos)
{
    char line[LINELENGTH];
    int lc = 0;
    while (!feof(f))
    {
        fgets(line, LINELENGTH, f);
        lc++;
    }
    return lc;
}

/* print selected lines */
int print_lines(long lc, bool plus, long n, FILE *f, int fpos)
{
    char line[LINELENGTH];
    int begin = 0;

    if (plus)
        begin = n-1;
    else
        begin = lc-n;

    fseek(f, 0, SEEK_SET);

    for (size_t i = 0; i < lc; i++)
    {
        fgets(line, LINELENGTH, f);
        if (i >= begin && i <= lc)
        {
            printf("%s", line);
        }
    }
}

/* Main function */
int main(int argc, char const *argv[])
{
    //variables
    long n = LINECOUNTDEFAULT, lc = 0;
    int fpos = STDINPUT;
    bool plus = false;
    FILE *f = NULL;

    arg_check(argc, argv, &plus, &n, &fpos);
    if (fpos == STDINPUT)
    {
        char line[LINELENGTH];
        fgets(line, LINELENGTH, stdin);
        lc = count_lines(stdin);
    }
    else
    {
        f = try_fopen(fpos, argv);
        lc = count_lines(f);
    }
    //! vyřešit abych tam neměl 2x stejnej kód + fprintf pokud bude řádek delší jak LINELENGTH, řádek oseknout na délku danou :)
    //! přidat fprintf když n > lc 
    print_lines(lc, plus, n, f);
    return 0;
}
