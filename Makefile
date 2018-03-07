# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/08 04:13:47 by apruvost          #+#    #+#              #
#    Updated: 2018/03/07 14:35:54 by apruvost         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_ls.c

OBJS = $(SRCS:.c=.o)

LIB_PATH = libft
LIB_LINK = -L $(LIB_PATH) -lft

INC_DIR = ft_ls.h
INCS = -I ./$(INC_DIR) -I $(INC_DIR)

CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIB_LINK)
	@echo "ft_ls Done !"

%.o : %.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<


clean:
	rm -f $(OBJS)
	@make -C libft/ clean
	@echo "Objects files deleted."

fclean: clean
	rm -f $(NAME)
	@make -C libft/ fclean
	@echo "$(NAME) deleted."

relib:
	@make -C libft/ re
	@echo "Libs redone."

re: fclean all

respeed:
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIB_LINK)
	@echo "ft_ls Done !"