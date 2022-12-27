# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 12:52:04 by mbarylak          #+#    #+#              #
#    Updated: 2022/12/27 17:22:17 by mbarylak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
LIBFT_NAME	=	libft.a

UTILS		=	env_utils env_utils2 print_info free
EXEC		=	exec_builtins exec_cmd exec_single_child
BUILTINS	=	env pwd echo exit cd export unset

SRCS		=	$(addsuffix .c, $(addprefix sources/utils/, $(UTILS))) \
				$(addsuffix .c, $(addprefix sources/executor/, $(EXEC))) \
				$(addsuffix .c, $(addprefix sources/builtins/, $(BUILTINS))) \
				main.c

OBJS		=	${SRCS:.c=.o}

LIBFT_DIR	=	./libft/

CC			=	gcc

RM			=	rm -rf

AR			=	ar rcs

CFLAGS		=	-Wall -Werror -Wextra -g3

INCLUDES	=	-I ./includes -I ./libft/

LIBFT		=	-L libft/ -lft

all:	${NAME}

$(NAME):	$(LIBFT_DIR)$(LIBFT_NAME) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME) -lreadline

%.o:	%.c
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(LIBFT_DIR)$(LIBFT_NAME): $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) ${OBJS}

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
