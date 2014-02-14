# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/26 22:57:40 by aaubin            #+#    #+#              #
#    Updated: 2014/02/14 20:01:16 by aleger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang

LKFLAGS=-Wall -Wextra -pedantic -Werror

CFLAGS=-Wall -Wextra -pedantic -Werror

LDFLAGS=-g

NAME=libvector.a

SRC=c_vector.c\
	c_vector_ops.c\
	c_vector_iterate.c\
	c_vector_alloc.c\
	c_vector_memory.c\
	c_vector_capacity.c\
	c_vector_remove.c\
	c_vector_access.c\
	c_vector_ops.c
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
