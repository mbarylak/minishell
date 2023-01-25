/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:37:29 by mbarylak          #+#    #+#             */
/*   Updated: 2023/01/25 16:23:38 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

enum	e_token_type
{
	T_PIPE = 1,
	T_CMD,
	T_ARG,
	T_FILE,
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
