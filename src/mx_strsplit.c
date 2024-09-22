#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c)
{
    if (!s)
        return NULL;

    int count_words = mx_count_words(s, c);
    char **result = (char **)malloc((count_words + 1) * sizeof(char *));
    if (!result)
        return NULL;

    int i = 0, counter = 0;
    while (s[i] != '\0')
    {
        while (s[i] == c)
            i++;
        if (s[i] == '\0')
            break;

        int start = i;
        while (s[i] != c && s[i] != '\0')
            i++;
        int len = i - start;

        result[counter] = mx_strndup(&s[start], len);
        counter++;
    }
    result[counter] = NULL;
    return result;
}
