#include <stdio.h>
#include <ctype.h>

int ft_puts(char *);
int	ft_isdigit(int);
int	ft_isalpha(int);

void check_puts(char *s);
void check_isDigit(int);

void check_puts(char *s)
{
	puts(s);
	ft_puts(s);
}
void check_isDigit(int i)
{
	printf("data: %c isdigit: %d, ft_isdigit: %d \n", i, isdigit(i), ft_isdigit(i));
}
void check_isAlpha(int i)
{
	printf("data: %c isalpha: %d, ft_isalpha: %d \n", i, isalpha(i), ft_isalpha(i));
}


int main()
{
	puts("### ft_puts ##");
	check_puts("great succes !");
	check_puts(0);

	puts("### ft_isdigit ##");
	check_isDigit('5');
	check_isDigit('p');
	check_isDigit('0');
	check_isDigit('9');

	puts("### ft_alpha ##");
	check_isAlpha('A');
	check_isAlpha('Z');
	check_isAlpha('F');
	check_isAlpha('{');
	check_isAlpha(']');
	check_isAlpha('a');
	check_isAlpha('f');
	check_isAlpha('z');
	check_isAlpha('*');
	return 0;
}
