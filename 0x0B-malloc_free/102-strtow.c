#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * strtow - Split a string into words
 * @str: The string to split
 *
 * Return: A pointer to an array of strings (words), or NULL if str is NULL or empty,
 * or if memory allocation fails.
 * Each element of the array contains a single word, null-terminated.
 * The last element of the array is NULL.
 */
char **strtow(char *str)
{
	int len, count, i, j, k;
    char **words;

    if (str == NULL || *str == '\0') {
        return NULL;
    }

    len = strlen(str);
    count = 0;
    words = (char **)malloc((len + 1) * sizeof(char *));
    if (words == NULL) {
        return NULL;
    }

    for (i = 0, j = 0; i < len; i++) {
        if (isspace(str[i])) {
            continue;
        }

        j = i;
        while (!isspace(str[j]) && j < len) {
            j++;
        }

        words[count] = (char *)malloc((j - i + 1) * sizeof(char));
        if (words[count] == NULL) {
            for (k = 0; k < count; k++) {
                free(words[k]);
            }
            free(words);
            return NULL;
        }

        strncpy(words[count], &str[i], j - i);
        words[count][j - i] = '\0';
        count++;

        i = j;
    }

    words[count] = NULL;
    return words;
}

