# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 17:14:03 by iblanco-          #+#    #+#              #
#    Updated: 2023/05/11 16:09:33 by iblanco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc -Wall -Werror -Wextra

RM = rm -f

SRCS = main.c utils.c ft_mod_split.c mov.c mov2.c mov3.c more_utils.c ft_algo.c ft_algo_utils.c errors.c more_errors.c 

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $^ -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS) 

fclean:	clean
	$(RM) $(NAME)

limpito: all clean

re:	fclean all

.PHONY:	all clean fclean re 