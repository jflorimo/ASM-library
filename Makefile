CC = gcc

CFLAGS = -Wl,-no_pie

NAME = libftasm.com

ASM =	ft_puts.s \
		ft_isdigit.s \
		ft_isalpha.s \
		ft_isalnum.s \
		ft_isascii.s \
		ft_isprint.s \
		ft_bzero.s \
		ft_strcat.s \
		ft_tolower.s \
		ft_toupper.s \
		ft_strlen.s \
		ft_memset.s \
		ft_memcpy.s \
		ft_strdup.s \

SRCS =	main.c \

ASMO = $(ASM:.s=.o)

INCLUDES = ./

all: $(NAME)

$(NAME): $(ASMO)
	$(CC) $(CFLAGS) -o $(NAME) $(ASMO) $(SRCS)

%.o: %.s
	nasm -f macho64 $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all