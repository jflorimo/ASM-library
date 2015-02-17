#include <stdio.h>
#include <ctype.h>

int ft_puts(char *);
int	ft_isdigit(int);
int	ft_isalpha(int);
int ft_isalnum(int);
int ft_isascii(int);
int ft_isprint(int);


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
void check_isAlnum(int i)
{
	printf("data: %c isalnum: %d, ft_isalnum: %d \n", i, isalnum(i), ft_isalnum(i));
}
void check_isAscii(int i)
{
	printf("data: %c isascii: %d, ft_isascii: %d \n", i, isascii(i), ft_isascii(i));
}
void check_isprint(int i)
{
	printf("data: %c isprint: %d, ft_isprint: %d \n", i, isprint(i), ft_isprint(i));
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

	puts("### ft_alnum ##");
	check_isAlnum('5');
	check_isAlnum('p');
	check_isAlnum('0');
	check_isAlnum('9');
	check_isAlnum('A');
	check_isAlnum('Z');
	check_isAlnum('F');
	check_isAlnum('{');
	check_isAlnum(']');
	check_isAlnum('a');
	check_isAlnum('f');
	check_isAlnum('z');
	check_isAlnum('*');
	puts("### ft_alascii ##");
	check_isAscii('5');
	check_isAscii('p');
	check_isAscii('0');
	check_isAscii(150);
	check_isAscii(-4);
	check_isAscii(127);
	check_isAscii(0);
	check_isAscii('{');
	check_isAscii(']');
	check_isAscii('a');
	check_isAscii('f');
	check_isAscii('z');
	check_isAscii('*');
	puts("### ft_isprint ##");
	check_isprint('5');
	check_isprint('p');
	check_isprint('0');
	check_isprint(150);
	check_isprint(-4);
	check_isprint(127);
	check_isprint(0);
	check_isprint(32);
	check_isprint(126);
	check_isprint('{');
	check_isprint(']');
	check_isprint('a');
	check_isprint('f');
	check_isprint('z');
	check_isprint('*');
	return 0;
}
