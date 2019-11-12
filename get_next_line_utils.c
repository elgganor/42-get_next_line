#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t len;

    len = 0;
    while (s[len] != '\0')
        len++;
    return (len);
}

void *ft_calloc(size_t count, size_t size)
{
    unsigned char *dest;
    size_t i;

    if (count * size == 0)
    {
        count = 1;
        size = 1;
    }
    if (!(dest = (unsigned char *)malloc(size * count)))
        return (NULL);
    i = 0;
    while (i < count * size)
        dest[i++] = '\0';
    return ((void *)dest);
}

char *ft_strdup(const char *s)
{
    char *dest;
    size_t len;
    size_t i;

    len = ft_strlen(s);
    if (!(dest = (char *)ft_calloc(len + 1, sizeof(char))))
        return (NULL);
    i = 0;
    while (i < len)
    {
        dest[i] = s[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *ft_strjoin(char *s1, char *s2)
{
    size_t len;
    size_t i;
    char *dest;

    len = ft_strlen(s1) + ft_strlen(s2);
    if (!(dest = (char *)ft_calloc(len + 1, sizeof(char))))
        return (NULL);
    i = 0;
    while (i < ft_strlen(s1))
    {
        dest[i] = s1[i];
        i++;
    }
    i = 0;
    while (i < ft_strlen(s2))
    {
        dest[ft_strlen(s1) + i] = s2[i];
        i++;
    }
    dest[ft_strlen(s1) + i] = '\0';
    return (dest);
}

void ft_strjoin_free(char **str, char *buf)
{
    char *tmp;

    if (!(*str))
        *str = ft_strdup(buf);
    else if (**str == '\0')
    {
        free(*str);
        *str = ft_strdup(buf);
    }
    else
    {
        tmp = ft_strdup(*str);
        free(*str);
        *str = ft_strjoin(tmp, buf);
        free(tmp);
    }
}