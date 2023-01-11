/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:37:29 by mbarylak          #+#    #+#             */
/*   Updated: 2023/01/11 16:16:14 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

enum	e_token_type
{
	T_CMD = 1,
	T_ARG,
	T_PIPE,
};

typedef struct s_token
{
	char	*data;
	int		type;
}	t_token;

/* LEXER */

t_token	*tokenizer(char **line);

#endif
