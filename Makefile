# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 14:04:30 by edcastro          #+#    #+#              #
#    Updated: 2023/11/08 16:18:00 by edcastro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
LIBFT_DIR	:= ./libft
LIBFT 	:= $(LIBFT_DIR)/libft.a
HEADERS	:= -I ./include -I $(LIBFT_DIR)/inc
UNAME_S	:= $(shell uname -s)

SRC_DIR	:= sources
SRC		:= pipex.c \
			
SRCS	:= $(addprefix $(SRC_DIR)/, $(SRC))
OBJ_DIR	:= obj
OBJ		:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
NAME	:= pipex

all: $(NAME)

$(LIBFT): $(LIBFT_DIR)
	make -C$(LIBFT_DIR);

$(OBJ_DIR):
	mkdir obj

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(HEADERS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/pipex.h
	$(CC) -c $(CFLAGS) $< -o $@ $(HEADERS)

clean:
	rm -rf $(OBJ)
	make clean -C$(LIBFT_DIR)

fclean: clean
	rm $(NAME)
	rmdir $(OBJ_DIR)

re: fclean all

.PHONY: all, clean, fclean, re