#ifndef __TAIL__
#define __TAIL__

/* 511 chars + 0 */
#define LINELENGTH 512
#define LINECOUNTDEFAULT 10
typedef struct lines_table
{
    char const *fname;

    size_t n;
    bool plus;

    char **line;
    size_t line_count;
} lines_table_t;

/* Initialize table for lines, construct */
lines_table_t *table_init();

/* Checking arguments passed on cmd line, if something is wrong then exit(1) */
void arg_check(int argc, char const *argv[], lines_table_t *l);

/* Trying to open file, if success then return ptr on file else exit(1) */
FILE *open_file(char const *fname);

/* Read file */
void read_file(FILE *f, lines_table_t *l);

/* Add new line to table (realloc size) */
void add_line(char *buffer, lines_table_t *l);

/* Print lines which should be printed  */
void print_lines(lines_table_t *l);

/* Free memory of lines */
void table_clear();

/* Free memory of structure, destruct */
void table_free();

#endif //__TAIL__