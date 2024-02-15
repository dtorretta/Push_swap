# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 16:42:39 by dtorrett          #+#    #+#              #
#    Updated: 2024/02/12 16:37:42 by dtorrett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#			Variables				#
# The name of the executable
NAME = push_swap
# The path to the libft library
LIB = $(LIBDIR)libft.a
# The directory containing libft source code
LIBDIR = ./libft/

CC = cc
FLAGS = -Wall -Wextra -Werror

#			Source files			#
SRCS = push_swap.c ft_swap.c ft_rotate.c ft_rrotate.c ft_push.c checks.c big_sort.c index.c small_sort.c free.c
OBJS = $(SRCS:.c=.o)

# Default target is to build the executable
all: $(NAME)

# Build the libft library
$(LIB):
	$(MAKE) -C $(LIBDIR)

# Build the executable using object files and libft
$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $^ -o $@
# $^ represents all the prerequisites (object files and the libft library)
# -o specifies the output file
# $@ represents the target, which is the name of the executable

# Compile each source file into object files
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBDIR) -I . -c $< -o $@
# -I$(LIBDIR): This flag specifies an additional directory to include header files from. In this case, it includes header files from the libft directory.
# -I .: This flag includes the current directory as a directory to search for header files. The dot (.) represents the current directory.
#-c: This flag tells the compiler to generate object files (*.o) without linking. It essentially compiles the source code into an object file.
# $<: This is an automatic variable that represents the first prerequisite (dependency) of the rule. In the context of a compilation rule, it typically represents the source file (*.c file).
#-o $@: This flag specifies the output file name. $@ is an automatic variable representing the target of the rule, which, in this case, is the object file (*.o). So, -o $@ indicates that the compiler should output the compiled object file with the same name as the target.

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBDIR) clean


fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all

# Declare these targets as phony (not real files) to avoid conflicts
.PHONY: all clean fclean re