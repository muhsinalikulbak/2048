#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/12 11:44:00 by muhsin            #+#    #+#              #
#    Updated: 2026/11/13 01:54:34 by muhsin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			= wong-kar-wai
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I./inc -I./libft
LDFLAGS			= -L./libft -lft -lncurses
LIBFT			= ./libft/libft.a
OBJ_DIR			= ./obj

SRCS			= src/main.c src/create_board.c src/reset_board.c
OBJS			= $(OBJ_DIR)/src/main.o $(OBJ_DIR)/src/create_board.o $(OBJ_DIR)/src/reset_board.o

all:			$(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

$(OBJ_DIR)/src/main.o: src/main.c
				@mkdir -p $(@D)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/src/create_board.o: src/create_board.c
				@mkdir -p $(@D)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/src/reset_board.o: src/reset_board.c
				@mkdir -p $(@D)
				$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
				$(MAKE) -C ./libft

clean:
				$(RM) $(OBJS)
				$(MAKE) -C ./libft clean

fclean:			clean
				$(RM) $(NAME)
				$(RM) -rf $(OBJ_DIR)
				$(MAKE) -C ./libft fclean

re:				fclean all

.PHONY:			all clean fclean re
