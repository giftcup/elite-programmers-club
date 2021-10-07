#include "word.h"
#include "line.h"
#include <stdio.h>

#define MAX_WORD_LEN 30
#define END 3
#define MAX_LEN (MAX_WORD_LEN + END)

int main(void)
{
    char word[MAX_LEN + 1];
    int word_len;
    int i = 0;

    clear_line();
    for (;;)
    {
        word_len = read_word(word, MAX_WORD_LEN+1);
        if (word_len == 0)
        {
            write_line();
            return 0;
        }
        if (word_len + 1 > space_remaining())
        {
            write_line();
            clear_line();
        }
        add_word(word);
    }

}