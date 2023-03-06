/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myworld-paulin.leclercq
** File description:
** srand.c
*/

#include <unistd.h>
#include <fcntl.h>

unsigned rand_seed(void)
{
    int fd = open("/dev/urandom", O_RDONLY);
    unsigned seed;

    if (fd < 0)
        return (unsigned)(unsigned long)(&fd);
    read(fd, &seed, sizeof(unsigned));
    close(fd);
    return seed;
}
