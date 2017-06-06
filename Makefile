# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/20 13:01:52 by oshudria          #+#    #+#              #
#    Updated: 2017/06/06 18:04:53 by oshudria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = alum1
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./srcs/
SRC_NAME = main.c \
		parse_input.c \
		clean_data.c \
		play.c \
		ai_algo.c \
		output.c \
		get_next_line.c \
		ft_strnew.c \
		ft_isdigit.c \
		ft_atoi.c \
		ft_strdel.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_strlen.c \
		ft_strcpy.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strsub.c \
		ft_strdup.c \
		ft_bzero.c \
		ft_memset.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_memcpy.c \
		ft_memalloc.c \
		ft_putendl.c \
		ft_putendl_fd.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_PATH = ./objs/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INCLUDES = -I./includes/

LIBFT = ./libft/libft.a
LIBFT_INC = -I./libft/includes/

COLOR_NONE = \033[0m
COLOR_YELLOW = \033[33m
COLOR_MAGENTA = \033[35m

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT_INC) -o $@ $(OBJ)
	@echo "$(COLOR_YELLOW)alum1 succesfully compiled.$(COLOR_NONE)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT_INC) -o $@ -c $<

clean:
	make clean -C ./libft
	@rm -rf $(OBJ_PATH)
	@echo "$(COLOR_MAGENTA)alum1 clean done.$(COLOR_NONE)"

fclean: clean
	make fclean -C ./libft
	@$(RM) $(NAME)
	@echo "$(COLOR_MAGENTA)alum1 fclean done.$(COLOR_NONE)"

re: fclean all
