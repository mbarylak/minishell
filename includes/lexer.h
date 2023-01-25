/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:37:29 by mbarylak          #+#    #+#             */
/*   Updated: 2023/01/25 15:41:46 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

enum	e_token_type
{
	T_CMD = 1,
	T_TEXT,
	T_PIPE,
	T_REDIR_OUT,
	T_APPEND,
	T_REDIR_IN,
	T_HEREDOC,
};

typedef struct s_token
{
	char	*data;
	int		type;
}	t_token;

/* LEXER */

int		check_access(char *line);
int		check_redir(char *line, t_token *tokens, int i);
t_token	create_token(char *data, int type);
t_token	*tokenizer(char **line);

#endif
