#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Helper function to free memory allocated for words array */
void free_words(char **words, int count)
{
    for (int i = 0; i < count; i++)
    {
        free(words[i]);
    }
    free(words);
}

char **strtow(char *str)
{
    /* Check for NULL or empty string */
    if (str == NULL || *str == '\0')
    {
        return NULL;
    }

    /* Check if string contains only whitespace characters */
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (!isspace(str[i]))
        {
            break;
        }
    }
    if (str[i] == '\0')
    {
        return NULL;
    }

    /* Count the number of words in the string */
    int count = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (!isspace(str[i]))
        {
            count++;
            while (!isspace(str[i]) && str[i] != '\0')
            {
                i++;
            }
        }
    }

    /* Allocate memory for the words array */
    char **words = malloc((count + 1) * sizeof(char *));
    if (words == NULL)
    {
        return NULL;
    }

    /* Split the string into words */
    int j = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (!isspace(str[i]))
        {
            int word_start = i;
            while (!isspace(str[i]) && str[i] != '\0')
            {
                i++;
            }
            int word_len = i - word_start;
            words[j] = malloc((word_len + 1) * sizeof(char));
            if (words[j] == NULL)
            {
                free_words(words, j);
                return NULL;
            }
            strncpy(words[j], &str[word_start], word_len);
            words[j][word_len] = '\0';
            j++;
        }
    }
    words[j] = NULL;
    return words;
}

