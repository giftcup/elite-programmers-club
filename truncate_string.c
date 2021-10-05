#include <stdio.h>

#define MAX_LEN 25

int read_word(char *word, int len);

int main(void)
{
    char word[MAX_LEN + 4];
    int word_len;

    word_len = read_word(word, MAX_LEN + 1);
    if (word_len > MAX_LEN)
    {
        for (int i = word_len-1; i < MAX_LEN + 3; i++)
        {
            word[i] = '.';
        }
        word[MAX_LEN + 3] = '\0';
    }
    printf("%s\n", word);
}

int read_word(char *word, int len)
{
    int ch, pos;

    pos = 0;
    while ((ch = getchar()) != '\n' && pos < len)
        word[pos++] = ch;
    word[pos] = '\0';

    return pos;
}