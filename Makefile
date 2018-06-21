# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/08 04:13:47 by apruvost          #+#    #+#              #
#    Updated: 2018/06/21 15:04:32 by apruvost         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c \
		ft_ls.c \
		ft_readrep.c \
		ft_getinfo.c \
		ft_fillst.c \
		ft_lstswitch.c \
		ft_getopt.c \
		ft_display.c \
		ft_dellst.c \
		ft_exit.c \
		ft_sort.c \
		ft_getmaxs.c \
		ft_nbsp.c \
		ft_nbsptwo.c \
		ft_gettimest.c

OBJS = $(SRCS:.c=.o)

LIB_PATH = libft
LIB_LINK = -L $(LIB_PATH) -lft

INC_DIR = .
INCS = -I ./

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