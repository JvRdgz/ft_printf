# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 19:12:23 by jarodrig          #+#    #+#              #
#    Updated: 2020/11/11 20:09:28 by jarodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS += -Wall -Werror -Wextra

LIBOBJS = libft/*.o

SRC = ft_printf.c libft_own_utils.c \
libft_own_utils_v2.c width_precision_flags.c \
flag_management.c c_type.c s_type.c d_type.c \
d_type_v2.c u_type.c u_type_v2.c p_type.c \
p_type_v2.c x_xx_type.c x_xx_type_v2.c \

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

lib:
		@$(MAKE) -C libft all
$(NAME): lib
		@$(CC) $(CFLAGS) -c $(SRC)
		@ar rc $(NAME) $(OBJ) $(LIBOBJS)

all: $(NAME)

bonus:	all

clean: 
		@rm -f $(OBJ)
		@$(MAKE) -C libft clean

fclean: clean
		@rm -f $(NAME)
		@$(MAKE) -C libft fclean

clean_test: fclean
		@rm -rf a.out a.out.dSYM

re: fclean all

all: $(NAME)
