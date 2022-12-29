/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:54:21 by mbarylak          #+#    #+#             */
/*   Updated: 2022/12/29 17:52:31 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LEXER_H
# define LEXER_H

#include "minishell.h"

enum	token_type
{
	T_CMD = 1,
	T_ARG,
	T_PIPE,
};

typedef struct	s_token
{
	char	*data;
	int		type;
}	t_token;

/* LEXER */

t_token	*tokenizer(char **ine);

#endif
