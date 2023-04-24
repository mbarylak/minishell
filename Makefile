# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarylak <mbarylak@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:16:25 by danimart          #+#    #+#              #
#    Updated: 2023/04/24 20:24:45 by mbarylak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT_NAME	=	libft.a

UTILS		=	env_utils env_utils2 print_info free redir_utils
EXEC		=	exec_builtins exec_cmd exec_single_child shell_loop exe_pipes \
				redir
PARSER		=	create_tree join_cmd input_parser get_redir_list
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
