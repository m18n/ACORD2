#include "include/StrParse.h"
int SearchWord(char *text, int size, const char *word)
{
    int lenword = strlen(word);
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        if (text[i] == word[n])
        {

            n++;

            if (n == lenword)
            {
                return i - n + 1;
            }
        }
        else
        {
            n = 0;
        }
    }
    return -1;
}