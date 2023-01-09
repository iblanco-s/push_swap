# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iblanco- <iblanco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 17:14:03 by iblanco-          #+#    #+#              #
#    Updated: 2023/01/09 17:30:08 by iblanco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc -Wall -Werror -Wextra

RM = rm -f

SRCS = main.c utils.c ft_mod_split.c

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

re:	fclean all

.PHONY:	all clean fclean re 