#include "libfts.h"

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#ifdef FT_CAT
# define CAT(_s) (ft_cat(_s))
#else
static void  cat(int fd)
{
    char    buf[1020];
    int     ret;

    while (1)
    {
        if ((ret = read(fd, buf, 1020)) < 1)
            return ;
        if (write(1, buf, ret) < 1)
            return ;
    }
    return ;
}
# define CAT(_s) (cat(_s))
#endif



int         main(int ac, char **av)
{
    int fd = 0;
    if (ac > 1)
        fd = atoi(av[1]);
    CAT(fd);
    return (0);
}
