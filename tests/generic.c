/* fucking nmokrane copyright !!! */
#include "libfts.h"

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

#define COLOR1(_s)      (isatty(1) ? "\033[" #_s "m" : "")
#define COLOR(_s)       (COLOR1(_s))

#define P_OK            (printf("%s%s", COLOR(32), "."))
#define P_KO            (printf("%s%s", COLOR(31), "-KO-"))

#define RUN_TEST(_s)    (printf("\n\n%sRUNNING TEST '%s':\n", COLOR(35), _s))
#define ASSERT(_e)      ((_e) ? P_OK : P_KO && ++errors)
#define BOOL(_e)        (!!_e)


#define I_MIN -50
#define I_MAX 50

#define RANDSTR_MAXSZ 500


size_t errors = 0;

static int  cat(int fd)
{
    char    buf[1020];
    int     ret;

    while (1)
    {
        if ((ret = read(fd, buf, 1020)) < 1)
            return (-1);
        if (write(1, buf, ret) < 1)
            return (-1);
    }
    return (0);
}


void *memrchr(const void *s, int c, size_t n)
{
    const unsigned char *ptr;
    if (n == 0)
        return (NULL);
    ptr = s + n - 1;
    while (n--)
    {
        if (*ptr == c)
            return ((void*)ptr);
        ptr--;
    }
    return (NULL);
}


static size_t   randstr(char *str)
{
    size_t size = (rand() % RANDSTR_MAXSZ) + 1;
    size_t n;
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

static void     randmem(char *str)
{
    size_t size = (rand() % RANDSTR_MAXSZ) + 1;

    while (size--)
    {
        *str = (char)rand();
        str++;
    }
}


static void     test_bool_ascii(void)
{
    int i;

    RUN_TEST("ft_isalpha");
    for(i=I_MIN; i<I_MAX; i++)
        ASSERT(BOOL(ft_isalpha(i)) == BOOL(isalpha(i)));

    RUN_TEST("ft_isdigit");
    for(i=I_MIN; i<I_MAX; i++)
        ASSERT(BOOL(ft_isdigit(i)) == BOOL(isdigit(i)));

    RUN_TEST("ft_isalnum");
    for(i=I_MIN; i<I_MAX; i++)
        ASSERT(BOOL(ft_isalnum(i)) == BOOL(isalnum(i)));

    RUN_TEST("ft_isascii");
    for(i=I_MIN; i<I_MAX; i++)
        ASSERT(BOOL(ft_isascii(i)) == BOOL(isascii(i)));

    RUN_TEST("ft_isprint");
    for(i=I_MIN; i<I_MAX; i++)
        ASSERT(BOOL(ft_isprint(i)) == BOOL(isprint(i)));
}

static void     test_misc_ascii(void)
{
    int i;

    RUN_TEST("ft_toupper");
    for(i=I_MIN; i<I_MAX; i++)
        ASSERT(ft_toupper(i) == toupper(i));

    RUN_TEST("ft_tolower");
    for(i=I_MIN; i<I_MAX; i++)
        ASSERT(ft_tolower(i) == tolower(i));
}

static void     test_strlen(void)
{
    int         i;
    char        str[RANDSTR_MAXSZ];
    size_t      len;

    RUN_TEST("ft_strlen");
    for (i=I_MIN; i<I_MAX; i++)
    {
        len = randstr(str);
        ASSERT(ft_strlen(str) == len);
    }
}

static void     test_memcpy(void)
{
    int         i;
    char        backup[RANDSTR_MAXSZ];
    char        str1[RANDSTR_MAXSZ];
    char        str2[RANDSTR_MAXSZ];
    size_t      len;

    char *ret;

    RUN_TEST("ft_memcpy");
    for (i=I_MIN; i<I_MAX; i++)
    {
        len = rand() % (RANDSTR_MAXSZ - 1);
        randmem(backup);
        str1[0] = 0;
        str2[0] = 0;
        str1[len+1] = 0;
        str2[len+1] = 0;

        memcpy(str1+1, backup, len);
        ret = ft_memcpy(str2+1, backup, len);

        ASSERT(ret == str2+1
                && memcmp(str1, str2, len+2) == 0);
    }
}


static void     test_memset(void)
{
    int         i;
    char        str1[RANDSTR_MAXSZ];
    char        str2[RANDSTR_MAXSZ];
    size_t      len;
    void        *ret;

    RUN_TEST("ft_memset");
    for (i=I_MIN; i<I_MAX; i++)
    {
        len = rand() % (RANDSTR_MAXSZ - 1);
        str1[0] = 42;
        str2[0] = 42;
        str1[len+1] = 42;
        str2[len+1] = 42;

        memset(str1+1, i, len);
        ret = ft_memset(str2+1, i, len);

        ASSERT(ret == str2+1
                && memcmp(str1, str2, len+2) == 0);
    }

    RUN_TEST("ft_bzero");
    for (i=I_MIN; i<I_MAX; i++)
    {
        len = rand() % (RANDSTR_MAXSZ - 1);
        str1[0] = 42;
        str2[0] = 42;
        str1[len+1] = 42;
        str2[len+1] = 42;

        bzero(str1+1, len);
        ft_bzero(str2+1, len);

        ASSERT(memcmp(str1, str2, len+2) == 0);
    }
}

static void     test_strcat(void)
{
    int         i;
    char        buf1[RANDSTR_MAXSZ*3];
    char        buf2[RANDSTR_MAXSZ*3];
    char        str1[RANDSTR_MAXSZ];
    char        str2[RANDSTR_MAXSZ];
    size_t      len;

    void *ret1;
    void *ret2;

    RUN_TEST("ft_strcat");
    for (i=I_MIN; i<I_MAX; i++)
    {
        memset(buf1, 42, RANDSTR_MAXSZ*3);
        buf1[10] = 0;
        memset(buf2, 42, RANDSTR_MAXSZ*3);
        buf2[10] = 0;

        memset(str1, 43, RANDSTR_MAXSZ);
        memset(str2, 43, RANDSTR_MAXSZ);

        randstr(str1);
        randstr(str2);

        strcat(buf1+5, str1);
        strcat(buf1+5, str2);


        ret1 = ft_strcat(buf2+5, str1);
        ret2 = ft_strcat(buf2+5, str2);

        ASSERT(ret1 == buf2+5
                && ret2 == buf2+5
                && memcmp(buf1, buf2, RANDSTR_MAXSZ*3) == 0);
    }
}

static void     test_strdup(void)
{
    int         i;
    char        str[RANDSTR_MAXSZ];
    long        diff;

    char        *ret;

    RUN_TEST("ft_strdup");
    for (i=I_MIN; i<I_MAX; i++)
    {
        randstr(str);
        ret = ft_strdup(str);

        diff = abs((long)ret - (long)str);

        ASSERT(diff > RANDSTR_MAXSZ * 2
                && strcmp(ret, str) == 0);
    }
}


static void     test_cat(void)
{
    RUN_TEST("ft_cat");

    ft_cat(-2345); ASSERT(1);
    ft_cat(-1); ASSERT(1);
    ft_cat(1024 * 1024); ASSERT(1);
    ft_cat(0x7ffffffe); ASSERT(1);
    ft_cat(34987234); ASSERT(1);
    ft_cat(0x7fffffff); ASSERT(1);
    ft_cat(0xffffffff); ASSERT(1);
}

/* BONUSES */
// static void     test_memchr(void)
// {
//     int         i;
//     char        str[RANDSTR_MAXSZ];

//     int         to_find;
//     char        *ret;

//     void        *res1;
//     void        *res2;

//     RUN_TEST("ft_memchr");
//     for (i=I_MIN; i<I_MAX; i++)
//     {
//         randstr(str);
//         to_find = rand();
//         res1 = memchr(str, to_find, RANDSTR_MAXSZ);
//         res2 = ft_memchr(str, to_find, RANDSTR_MAXSZ);
//         ASSERT(res1 == res2);
//     }


//     RUN_TEST("ft_memrchr");
//     for (i=I_MIN; i<I_MAX; i++)
//     {
//         randstr(str);
//         to_find = (rand() % 25) + 30;
//         res1 = memrchr(str, to_find, RANDSTR_MAXSZ);
//         res2 = ft_memrchr(str, to_find, RANDSTR_MAXSZ);
//         ASSERT(res1 == res2);
//     }
// }

// static void     test_memccpy(void)
// {
//     int         i;
//     char        backup[RANDSTR_MAXSZ];
//     char        str1[RANDSTR_MAXSZ];
//     char        str2[RANDSTR_MAXSZ];
//     size_t      len;
//     int to_find;

//     char *ret1;
//     char *ret2;
//     /* int fd1 = open("1", O_CREAT | O_TRUNC | O_WRONLY, 0777); */
//     /* int fd2 = open("2", O_CREAT | O_TRUNC | O_WRONLY, 0777); */
//     /* ASSERT(fd1 > -1); */
//     /* ASSERT(fd2 > -1); */
//     int assertion;

//     RUN_TEST("ft_memccpy");
//     for (i=I_MIN; i<I_MAX; i++)
//     {
//         len = rand() % (RANDSTR_MAXSZ - 1);
//         randmem(backup);
//         to_find = rand() % 1;
//         memset(str1, 42, RANDSTR_MAXSZ);
//         memset(str2, 42, RANDSTR_MAXSZ);
//         str1[0] = 0;
//         str2[0] = 0;
//         str1[len+1] = 0;
//         str2[len+1] = 0;

//         ret1 =    memccpy(str1+1, backup, to_find, len);
//         ret2 =    ft_memccpy(str2+1, backup, to_find, len);

//         if (ret1 == NULL)
//             assertion = ret2 == NULL;
//         else
//             assertion = ret1 - ret2 == str1 - str2;
//         ASSERT(assertion && memcmp(str1, str2, RANDSTR_MAXSZ) == 0);
//         /* if (memcmp(str1, str2, RANDSTR_MAXSZ) != 0) */
//         /* { */
//         /*     write(fd1, "\n\n\n\n\n\n", 6); */
//         /*     write(fd1, str1, RANDSTR_MAXSZ); */
//         /*  */
//         /*     write(fd2, "\n\n\n\n\n\n", 6); */
//         /*     write(fd2, str2, RANDSTR_MAXSZ); */
//         /* } */
//     }
// }

// static void     test_strchr(void)
// {
//     int         i;
//     char        str[RANDSTR_MAXSZ];

//     int         to_find;
//     char        *ret;

//     void        *res1;
//     void        *res2;

//     RUN_TEST("ft_strchr");
//     for (i=I_MIN; i<I_MAX; i++)
//     {
//         randstr(str);
//         str[RANDSTR_MAXSZ-1] = 0;
//         to_find = rand();
//         res1 = strchr(str, to_find);
//         res2 = ft_strchr(str, to_find);

//         ASSERT(res1 == res2);
//     }
// }

// void xmemcmp(const void *s1, const void *s2, size_t n)
// {
//     int r1;
//     int r2;

//     r1 = memcmp(s1, s2, n);
//     r2 = ft_memcmp(s1, s2, n);
//     /* printf("\n\n\nr1=%i\nr2=%i\n", r1, r2); */
//     if (r1 < 0)
//         ASSERT(r2 < 0);
//     else if (r2 > 0)
//         ASSERT(r2 > 0);
//     else
//         ASSERT(r2 == 0);
// }

// #define CHK memcmp_wrap
// static void     test_memcmp(void)
// {
//     RUN_TEST("ft_memcmp");
//     xmemcmp(NULL, NULL, 0);
//     xmemcmp((void*)0x0a, (void*)0x0a, 0);
//     xmemcmp((void*)999999, (void*)999991, 0);
//     xmemcmp("sglkjh", "sflkjhsdkh", 6);

//     xmemcmp("sflkjhsdkh", "sglkjh", 6);

//     xmemcmp("blax", "blay", 4);
//     xmemcmp("blay", "blax", 4);
//     xmemcmp("blax", "blay", 3);

//     int i;

//     char        str1[RANDSTR_MAXSZ];
//     char        str2[RANDSTR_MAXSZ];

//     for (i=I_MIN; i<I_MAX; i++)
//     {
//         randstr(str1);
//         randstr(str2);
//         xmemcmp(str1, str2, rand() % RANDSTR_MAXSZ);
//     }
// }

int             main(int ac, char **av)
{
    int seed = 1337;
    if (ac > 1)
        seed = atoi(av[1]);
    srand(seed);
    setbuf(stdout, NULL);

    test_bool_ascii();
    test_misc_ascii();
    test_strlen();
    test_memcpy();
    test_memset();
    test_strcat();
    test_strdup();
    test_cat();


    /* BONUS */
    // test_memchr(); // memchr() / memrchr()
    // test_memccpy(); // memccpy()
    // test_strchr(); // strchr()
    // test_memcmp();

    puts("");
    return (errors > 0 ? 1 : 0);
}
