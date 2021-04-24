// Author:      Marek Bitomský
// Project:     IJC - 2. homework
// Date:        20. 04. 2021
// School:      VUT FIT Brno

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tail.h"

void arg_check(int argc, char const *argv[], lines_table_t *l)
{
    //testing count of args
    if (argc >= 1 && argc <= 4)
    {
        //for every arg
        for (int i = 0; i < argc; i++)
        {
            //if -n is passed
            if (!strcmp(argv[i], "-n"))
            {
                //tests if value of -n is in interval <1,inf>
                if (atoll(argv[i + 1]) < 1)
                {
                    fprintf(stderr, "TAIL: Unexpected value for option -n passed.\n");
                    exit(1);
                }

                //set number of lines to be printed
                l->n = (size_t)atoll(argv[i + 1]);

                //tests if plus was passed
                if (strchr(argv[i + 1], '+'))
                    l->plus = true;
            }
        }

        //if count of arguments is 2 then fname is 1
        if (argc == 2)
            l->fname = argv[1];

        //if count of arguments is 4 then fname is 3
        if (argc == 4)
            l->fname = argv[3];
    }
    else
    {
        fprintf(stderr, "TAIL: Unexpected arguments passed.\n");
        exit(1);
    }
}

FILE *open_file(char const *fname)
{
    //open file with name fname
    FILE *f = fopen(fname, "r");

    //tests if opening was successful
    if (f == NULL)
    {
        fprintf(stderr, "TAIL: Unexpected error with opening file.\n");
        exit(1);
    }

    //returns ptr to file
    return f;
}

lines_table_t *table_init()
{
    //alloc memory
    lines_table_t *l = malloc(sizeof(lines_table_t));

    //test if alloc success
    if (l == NULL)
    {
        fprintf(stderr, "TAIL: Unexpected error with allocating memory for table.\n");
        exit(1);
    }

    //set to default values
    l->fname = NULL;
    l->n = LINECOUNTDEFAULT;
    l->plus = false;
    l->line = NULL;
    l->line_count = 0;

    //returns allocated structure
    return l;
}

void table_clear(lines_table_t *l)
{
    //for every line free memory
    for (size_t i = 0; i < l->line_count; i++)
        free(l->line[i]);
}

void table_free(lines_table_t *l)
{
    //free lines
    table_clear(l);

    //free structure
    free(l);
}

void add_line(char *buffer, lines_table_t *l)
{
    //if line is not allocated
    if (l->line_count == 0)
    {
        //increment line count
        l->line_count++;

        //malloc line to first string
        l->line = malloc(sizeof(char *) * l->line_count);

        //tests if alloc success or not
        if (l->line == NULL)
        {
            fprintf(stderr, "TAIL: Unexpected error with allocating memory for array.");
            exit(1);
        }
    }
    else
    {
        //increment line count
        l->line_count++;

        //realloc array to new size
        l->line = realloc(l->line, sizeof(char *) * l->line_count);
    }

    //alloc memory for new line, SIZEOF(CHAR) = 1, but i want this
    l->line[l->line_count - 1] = malloc(sizeof(char) * (strlen(buffer) + 1));

    //tests if alloc success or not
    if (l->line[l->line_count - 1] == NULL)
    {
        fprintf(stderr, "TAIL: Unexpected error with allocating memory for new line.");
        table_free(l);
        exit(1);
    }

    //copy buffer to l->line[index]
    strcpy(l->line[l->line_count - 1], buffer);
}

void read_file(FILE *f, lines_table_t *l)
{
    //buffer for line string
    char buffer[LINELENGTH] = {0};

    //while there is something to read
    while (fgets(buffer, LINELENGTH, f) != NULL)
    {
        //if length of line is more then
        if (strlen(buffer) > (LINELENGTH - 2))
        {
            char tmp[LINELENGTH];
            strcpy(tmp, buffer);
            buffer[LINELENGTH - 2] = '\n';
            buffer[LINELENGTH - 1] = '\0';
            while (strlen(tmp) == LINELENGTH-1 && tmp[strlen(tmp) - 1] != '\n')
            {
                fgets(tmp, LINELENGTH, f);
            }
        }

        //add line to table
        add_line(buffer, l);
    }
}

void print_lines(lines_table_t *l)
{
    //defines where start printing
    size_t beginning = 0;

    //if plus was passed
    if (l->plus)
        //prints from passed line (index = n - 1)
        beginning = l->n - 1;
    else
        //prints last n lines (index = line_count - n)
        beginning = l->line_count - l->n;
    
    //for every line in range
    for (size_t i = beginning; i < l->line_count; i++)
        printf("%s", l->line[i]);
}

/* Main function */
int main(int argc, char const *argv[])
{
    lines_table_t *l = table_init();

    //checking if arguments was correctly passed
    arg_check(argc, argv, l);

    //in default reads from stdin
    FILE *f = stdin;

    //tests if fname was passed, then open file
    if (l->fname != NULL)
        f = open_file(l->fname);

    //read lines from file or stdin
    read_file(f, l);

    //prints lines
    print_lines(l);

    //free memory of table
    table_free(l);

    return 0;
}
