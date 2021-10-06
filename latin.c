#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 30
#define END 3
#define MAX_LEN (MAX_WORD_LEN + END)

int read_word(char *word, int len);
void begins_with_vowel(char *word);
void begins_with_consonant(char *word,char *vowels, int len);

int main(void)
{
    char word[MAX_LEN + 1];
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int word_len;
    //int temp_char;

    word_len = read_word(word, MAX_WORD_LEN+1);
    if (memchr(vowels, tolower(word[0]), sizeof(vowels)))
    {
        begins_with_vowel(word);
        printf("%s\n", word);
    }
    else
    {
        begins_with_consonant(word, vowels, word_len);
        printf("%s\n", word);
    }
}

/*
    read_word: Takes an empty array of characters and writes
               a word in it.
               returns the length of the word.
*/
int read_word(char *word, int len)
{
    int ch, pos;

    pos = 0;
    ch = getchar();
    while (ch != ' ' && ch != '\n' && pos < len)
    {
        word[pos++] = ch;
        ch = getchar();
    }
    word[pos] = '\0';

    return pos;
}

/*
    begins_with_vowel: Takes a word that begins with a vowel
                       Adds 'way' behind a word that
                       begins.
                       returns;
*/
void begins_with_vowel(char *word)
{
    strcat(word, "way");
}

/*
    begins_with_consonant: Gets a word and an array of chars
                           which contains vowels.
                           Moves the consonant or consonant
                           cluster the word begins with to the 
                           end of the word and adds 'ay' at 
                           the end
                           returns
*/

void begins_with_consonant(char *word, char *vowels, int len)
{
    int i = 0;

    while (i <= len)
    {
        if (memchr(vowels, tolower(word[0]), sizeof(vowels)))
            break;
        int temp = word[0];
        for (int j = 0; j < len - 1; j++)
        {
            word[j] = word[j + 1];
        }
        word[len-1] = temp;
    }

    strcat(word, "ay");
}