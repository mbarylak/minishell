# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danimart <danimart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 16:37:19 by mbarylak          #+#    #+#              #
#    Updated: 2023/01/11 15:56:54 by danimart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	 ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	 ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
	 ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	 ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	 ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_putchar_fd.c \
	 ft_strnstr.c ft_memmove.c ft_isascii.c ft_strjoin.c ft_memdel.c ft_strcmp.c \
	 ft_isnum.c

OBJ = $(SRC:.c=.o)

BONUSSRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		   ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
		   ft_lstmap_bonus.c ft_lstlast_bonus.c ft_lstiter_bonus.c

BONUSOBJ = $(BONUSSRC:.c=.o)

INCLUDE = libft.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

all: $(NAME) bonus

$(NAME): $(OBJ) $(INCLUDE)
	@printf "\n\e[0;33m-\e[1;32m "
	ar rcs $(NAME) $(OBJ)
	@printf "\e[1;30m\n"

bonus: $(BONUSOBJ) $(INCLUDE)
	@printf "\n\e[0;33m-\e[1;32m "
	ar rcs $(NAME) $(BONUSOBJ)

clean:
	@printf "\e[0;33m-\e[1;32m "
	$(RM) $(OBJ) $(BONUSOBJ)

fclean: clean
	@printf "\e[0;33m-\e[1;32m "
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
