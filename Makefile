# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danimart <danimart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 12:52:04 by mbarylak          #+#    #+#              #
#    Updated: 2023/01/11 16:16:25 by danimart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
LIBFT_NAME	=	libft.a

UTILS		=	env_utils env_utils2 print_info free
EXEC		=	exec_builtins exec_cmd exec_single_child
PARSER		=	create_tree
LEXER		=	lexer
BUILTINS	=	env pwd echo exit cd export unset

SRCS		=	$(addsuffix .c, $(addprefix sources/utils/, $(UTILS))) \
				$(addsuffix .c, $(addprefix sources/executor/, $(EXEC))) \
				$(addsuffix .c, $(addprefix sources/parser/, $(PARSER))) \
				$(addsuffix .c, $(addprefix sources/lexer/, $(LEXER))) \
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
	@printf "\n\e[0;33m-\e[1;32m "
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME) -lreadline
	@printf "\n\033[0m"

%.o:	%.c
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(LIBFT_DIR)$(LIBFT_NAME): $(LIBFT_DIR)
	@printf "\n\e[1;31m> \e[1;36mMaking \e[1;34m$(NAME)\e[1;36m...\
	\n\n\e[0;35m$(LIBFT_NAME) commands\e[1;30m:\n"
	make -C $(LIBFT_DIR)
	@printf "\n\e[0;35m$(NAME) commands\e[1;30m:\n"

clean:
	@printf "\n\e[1;31m> \e[1;36mRemoving \e[1;34m$(NAME)\e[1;36m's objects...\
	\e[1;30m\n\n"
	@printf "\e[0;33m-\e[1;32m "
	make -C $(LIBFT_DIR) clean
	@printf "\e[0;33m-\e[1;32m "
	$(RM) ${OBJS}
	@printf "\n\033[0m"

fclean:	clean
	@printf "\n\e[1;31m> \e[1;36mRemoving \e[1;34m$(NAME)\e[1;36m...\
	\e[1;30m\n\n"
	@printf "\e[0;33m-\e[1;32m "
	make -C $(LIBFT_DIR) fclean
	@printf "\e[0;33m-\e[1;32m "
	$(RM) $(NAME)
	@printf "\n\033[0m"

re:	fclean all

.PHONY:	all clean fclean re
