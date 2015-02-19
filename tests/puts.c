#include "libfts.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>


#ifdef FT_PUTS
# define PUTS(_s) (ft_puts(_s))
#else
# define PUTS(_s) (puts(_s))
#endif

#define RANDSTR_MAXSZ 500
static size_t   randstr(char *str)
{
    size_t n;
    size_t size = (rand() % RANDSTR_MAXSZ) + 1;
    if (size) {
        --size;
        for (n = 0; n < size; n++)
        {
            str[n] = (char)(rand() % 253) + 1;
        }
        str[size] = '\0';
    }
    return (size);
}

int main(void)
{
    srand(424242); /* default seed */
    setbuf(stdout, NULL); /* disable stdout buffering */

    int i;
    char        str[RANDSTR_MAXSZ];
    int ret;

    /* test with null */
    printf("======================\n");
    printf("VAL=");
    ret = PUTS(NULL);
    printf("RET=%s\n", (ret < 0) ? "false" : "true");
    printf("======================\n");

    /* test with random values (fixed seed) */
    for (i=0; i<10000; i++)
    {
        randstr(str);
        printf("======================\n");
        printf("VAL=");
        ret = PUTS(str);
        printf("RET=%s\n", (ret < 0) ? "false" : "true");
        printf("======================\n");
    }

    return (0);
}
