/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:12:59 by mbarylak          #+#    #+#             */
/*   Updated: 2022/12/29 17:56:25 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct	s_tree
{
	char			*content;
	struct s_tree	*right;
	struct s_tree	*left;
}	t_tree;

/* CREATE_TREE */

t_tree	*create_tree(char *line);

#endif
