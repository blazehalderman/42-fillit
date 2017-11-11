# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhalderm <bhalderm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 14:56:35 by bhalderm          #+#    #+#              #
#    Updated: 2017/11/10 16:01:40 by bhalderm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_connect.c main.c ft_pmalloc.c ft_poscheck.c \
ft_solvepuzzle.c ft_tetchecker.c

HEADER = fillit.h 

NAME = fillit

FLAGS = -Wall -Wextra -Werror

BIN = libft/libft.a

all: $(NAME)

$(BIN):
	@make -C libft

$(NAME): $(BIN)
	@gcc $(FLAGS) $(SRCS) $(BIN) -I $(HEADER) -o $(NAME)

clean:
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all