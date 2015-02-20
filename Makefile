
SRC_LIB =	ft_bzero.s		\
			ft_strcat.s		\
			ft_isalpha.s	\
			ft_isdigit.s	\
			ft_isalnum.s	\
			ft_isascii.s	\
			ft_isprint.s	\
			ft_toupper.s	\
			ft_tolower.s	\
			ft_puts.s		\
			ft_strlen.s		\
			ft_memset.s		\
			ft_memcpy.s		\
			ft_strdup.s		\
			ft_cat.s		\
			\
			ft_islower.s \
			ft_isupper.s \
			ft_strcpy.s \
			ft_strncpy.s \
			ft_strchr.s \

NAME		=	libfts.a

CFLAGS		=	-f macho64

OBJ_LIB		=	$(SRC_LIB:.s=.o)

all:		$(NAME)

$(NAME):	$(OBJ_LIB)
	@ar -rc $(NAME) $(OBJ_LIB)
	@ranlib $(NAME)
	@echo ""
	@echo "\033[33m"Compilation of libfts.a : "\033[32m"Success"\033[0m"


%.o:		%.s
	@echo -n .
	@nasm $(CFLAGS) -s $< -o $@

clean:
	@echo "\033[31m"Objects of libfts.a : deleted"\033[0m"
	@/bin/rm -f $(OBJ_LIB)

fclean:		clean
	@echo "\033[31m"libft.a : deleted"\033[0m"
	@/bin/rm -f $(NAME)

re:			fclean all

test:		re
	@gcc $(NAME) main.c
	@./a.out


.PHONY:		all re fclean clean test