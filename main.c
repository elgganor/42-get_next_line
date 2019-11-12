#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        ft_putchar(str[i++]);
}

int main(int ac, char **av)
{
    int fd;
    if (ac == 2)
        fd = open(av[1], O_RDONLY);
    else
        fd = 0;
    char *line = "";
    int r;

    /* Lecture de tout le fichier */
    while ((r = get_next_line(fd, &line)) > 0)
    {
        printf("%d - %s\n", r, line);
        free(line);
    }
    printf("%d\n", r);
    // while (1) ;

    /* Test au cas par cas */
    // get_next_line(fd, &line);
    // ft_putstr(line);
    // write(1, "\n", 1);
    // free(line);

    // get_next_line(fd, &line);
    // ft_putstr(line);
    // write(1, "\n", 1);
    // free(line);

    // get_next_line(fd, &line);
    // ft_putstr(line);
    // write(1, "\n", 1);
    // free(line);

    // get_next_line(fd, &line);
    // ft_putstr(line);
    // write(1, "\n", 1);
    // free(line);

    // get_next_line(fd, &line);
    // ft_putstr(line);
    // write(1, "\n", 1);
    // free(line);
    // while (1) ;

    close(fd);
    return (0);
}