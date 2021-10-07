#include "word.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void begins_with_vowel(char *word);
void begins_with_consonant(char *word, char *vowels, int len);
int read_char(void);

/*
    read_char: Takes a character and add it to an array.
               returns.
*/
int read_char(void)
{
    int ch = getchar();

    if (ch == '\n' || ch == '\t')
        ch = ' ';
    return ch;
}

/*
    read_word: Takes an empty array of characters and writes
               a word in it.
               returns the length of the word
*/
int read_word(char *word, int len)
{
    int ch, pos;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};

    pos = 0;
    while ((ch = read_char()) == ' ');
    while (ch != ' ' && ch != EOF)
    {
        if (pos < len)
            word[pos++] = ch;
        ch = read_char();
    }
    word[pos] = '\0';
    if (pos == 0)
        return pos;
        
    if (memchr(vowels, tolower(word[0]), sizeof(vowels)))
    {
        begins_with_vowel(word);
    }
    else
    {
        begins_with_consonant(word, vowels, pos);
        // printf("%s\n", word);
    }

    return strlen(word);
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
        i++;
    }

    strcat(word, "ay");
}