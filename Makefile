#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/15 01:27:19 by muhsin            #+#    #+#              #
#    Updated: 2026/11/15 01:27:20 by muhsin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= wong-kar-wai
CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -MMD -MP -I./inc -I./libft
LDFLAGS		= -L./libft -lft -lncurses
LIBFT		= ./libft/libft.a
OBJ_DIR		= ./obj

SRCS		= src/main.c \
			  src/reset_board.c \
			  src/print.c
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS		= $(OBJS:.o=.d)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

$(OBJ_DIR)/%.o: %.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
			$(MAKE) -C ./libft

clean:
			$(RM) $(OBJS) $(DEPS)
			$(MAKE) -C ./libft clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) -r $(OBJ_DIR)
			$(MAKE) -C ./libft fclean

re:			fclean all

-include $(DEPS)

.PHONY:		all clean fclean re