#include <stdio.h>

#define MAX_LEN 25

int read_string(char *word, int len);
void add_points(char *word, int len);

int main(void)
{
    char string[MAX_LEN + 4];
    int word_len;

    word_len = read_string(string, MAX_LEN + 1);
    if (word_len > MAX_LEN)
    {
        add_points(string, word_len-1);
    }
    printf("%s\n", string);
}

/*
    read_word: Gets an empty array of characters and
               reads characters from stdin into the
               array, stoping when the length has been
               exceeded or when the new-line character
               is entered.
               Adds the null char at the end of the
               string
               returns
*/

int read_string(char *string, int len)
{
    int ch, pos;

    pos = 0;
    while ((ch = getchar()) != '\n' && pos < len)
        string[pos++] = ch;
    string[pos] = '\0';

    return pos;
}

/*
    add_points: Adds `...' at the end of a string whose
                length exceeds the given string length.

                returns;
*/

void add_points(char *string, int len)
{
    for (int i = len; i < MAX_LEN + 3; i++)
    {
        string[i] = '.';
    }
    string[MAX_LEN + 3] = '\0';
}