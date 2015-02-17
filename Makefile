CC = gcc

CFLAGS = -Wl,-no_pie

NAME = libftasm.com

ASM =	ft_puts.s \
		ft_isdigit.s \
		ft_isalpha.s \

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