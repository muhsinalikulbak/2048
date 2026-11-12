#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/12 11:44:00 by muhsin            #+#    #+#              #
#    Updated: 2026/11/12 14:55:23 by muhsin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			= wong-kar-wai
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I./inc -I./libft/libft
LDFLAGS			= -L./libft/libft -lft -lncurses
LIBFT			= ./libft/libft/libft.a
OBJ_DIR			= ./obj

SRCS			= src/main.c
OBJS			= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all:			$(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

$(OBJ_DIR)/%.o:	%.c
				@mkdir -p $(@D)
				$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
				$(MAKE) -C ./libft/libft

clean:
				$(RM) $(OBJS)
				$(MAKE) -C ./libft/libft clean

fclean:			clean
				$(RM) $(NAME)
				$(RM) -rf $(OBJ_DIR)
				$(MAKE) -C ./libft/libft fclean

re:				fclean all

.PHONY:			all clean fclean re
