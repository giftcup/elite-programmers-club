#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 25

void read_string(char *string, int len);

int main(void)
{
    char spinal_string[MAX_LEN+1];
    
    printf("Enter string: ");
    read_string(spinal_string, MAX_LEN+1);
    printf("%s\n", spinal_string);
}


/*
    read_string: gets and empty string and maximum
                length of the string.
                Reads text from stdin, converting all
                alphabetic character to lowercase and
                all spaces to hyphens.
*/
void read_string(char *string, int len)
{
    int ch, pos;

    pos = 0;
    while ((ch = getchar()) != '\n' && pos < len)
    {
        if (isalpha(ch))
            ch = tolower(ch);
        if (ch == ' ')
            ch = '-';
        string[pos++] = ch;
    }
    string[pos] = '\0';
}