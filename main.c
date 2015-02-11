#include <stdio.h>

void ft_puts(char *s);

void check_puts(char *s);

void check_puts(char *s)
{
	puts(s);
	ft_puts(s);
}

int main()
{
	check_puts("mampppth !");
	return 0;
}