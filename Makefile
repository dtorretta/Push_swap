NAME = pushswap.a

LIBFT	= libft.a
LIBFTDIR	= ./libft

SRCS = push_swap.c ft_swap.c ft_rotate.c ft_rrotate.c ft_push.c errors.c big_sort.c
OBJS = $(SRCS:.c=.o)

INCS = -I push_swap.h

AR = ar rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) 

makelib:
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) .
	mv $(LIBFT) $(NAME)

$(NAME): makelib $(OBJS)
	$(AR) -g $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	cd $(LIBFTDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY:		all clean fclean re
