/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:12:59 by mbarylak          #+#    #+#             */
/*   Updated: 2023/01/12 17:26:59 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

enum e_cmd_pos
{
	P_FIRST = 1,
	P_MIDDLE,
	P_LAST,
};

enum e_node_type
{
	N_PIPE = 1,
	N_OTHER,
};

typedef struct s_tree
{
	char			**content;
	int				cmd_pos;
	int				n_type;
	struct s_tree	*right;
	struct s_tree	*left;
}	t_tree;

/* CREATE_TREE */

void	add_node_right(t_tree *tree, char **arg, int pos);
void	add_node_left(t_tree *tree, char **arg, int pos);
t_tree	*create_node(char **arg, int pos, int n_type);
t_tree	*create_tree(void);

/* JOIN_CMD */

int		arg_counter(int first, int last);
char	**join_cmd(int first, int last);

/* INPUT PARSER */

char	**parse_input(char *input);

#endif
