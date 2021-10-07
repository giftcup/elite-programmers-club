#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN];
int line_len = 0;
int num_words = 0;

void add_word(char *word)
{
    if (num_words > 0)
    {
        line[line_len] = ' ';
        line[line_len + 1] = '\0';
        line_len++; 
    }
    strcat(line, word);
    line_len = strlen(word);
    num_words++;
}

void clear_line(void)
{
    line[0] = '\0';
    line_len = 0;
    num_words = 0;
}

void write_line(void)
{
    if (line_len > 0)
        puts(line);
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}