# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kimtaebin <kimtaebin@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/24 02:52:49 by taebkim           #+#    #+#              #
#    Updated: 2024/11/25 00:13:11 by kimtaebin        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
BO_NAME = philo_bonus

SRC = main.c initialize.c utils.c error_handler.c philosophers.c
SRCS = $(addprefix src/, $(SRC))

BNS_SRC = main.c
BNS_SRCS = $(addprefix bonus/, $(BNS_SRC))

OBJ_DIR = obj

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BNS_SRCS:%.c=%.o))

CFLAGS = -Wall -Wextra -Werror -Iincludes

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/src $(OBJ_DIR)/bonus

$(NAME): $(OBJS)
	cc $(CFLAGS) $^ -o $@

bonus: $(OBJ_DIR) $(BO_NAME)

$(BO_NAME): $(BONUS_OBJS)
	cc $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BO_NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re bonus
