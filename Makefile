# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/26 22:57:40 by aaubin            #+#    #+#              #
#    Updated: 2014/02/13 17:36:01 by aaubin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang

LKFLAGS=-Wall -Wextra -pedantic #-Werror

CFLAGS=-Wall -Wextra -pedantic #-Werror

LDFLAGS=-g

NAME=libvector.a

SRC=c_vector.c\
	c_vector_ops.c\
	ft_realloc.c\
	c_vector_capacity.c\
	c_vector_remove.c

NOM=$(basename $(SRC))
OBJ=$(addsuffix .o, $(NOM))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	$(CC) -g -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf $(OBJ)

fclean: clean mrproper

re: fclean all

.PHONY: clean mrproper

mrproper: clean
	@rm -rf $(NAME)
