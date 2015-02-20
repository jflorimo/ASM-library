#ifndef LIBFTS_H
# define LIBFTS_H
# include <string.h>

void ft_bzero(void *, size_t);
int ft_puts(char *);
int	ft_isdigit(int);
int	ft_isalpha(int);
int ft_isalnum(int);
int ft_isascii(int);
int ft_isprint(int);
int	ft_tolower(int);
int ft_toupper(int);
char *ft_strcat(char *, const char *);
int	ft_strlen(char *);
char *ft_memset(char *, int, size_t);
char *ft_memcpy(const char *, const char *, size_t);
char *ft_strdup(char *);
void ft_cat(int);

int ft_islower(int);
int ft_isupper(int);
char *ft_strcpy(char *, char *);
char *ft_strncpy(char *, char *, size_t);
char *ft_strchr(char *, int);

#endif