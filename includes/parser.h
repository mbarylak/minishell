/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:12:59 by mbarylak          #+#    #+#             */
/*   Updated: 2023/02/09 16:37:06 by mbarylak         ###   ########.fr       */
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

typedef struct s_redir
{
	char			*value;
	int				r_type;
	struct s_redir	*next;
}	t_redir;

typedef struct s_tree
{
	char			**content;
	int				cmd_pos;
	int				n_type;
	t_redir			**l_redir;
	struct s_tree	*right;
	struct s_tree	*left;
}	t_tree;

typedef struct s_input
{
	char	*content;
	void	*prev;
	void	*next;
}	t_input;

/* CREATE_TREE */

void	add_node_right(t_tree *tree, char **arg, int pos, t_redir **redir_l);
void	add_node_left(t_tree *tree, char **arg, int pos, t_redir **redir_l);
t_tree	*create_node(char **arg, int pos, int n_type, t_redir **redir_l);
t_tree	*create_tree(void);

/* JOIN_CMD */

int		arg_counter(int first, int last);
char	**join_cmd(int first, int last);

/* GET_REDIR_LIST */

t_redir	*create_r_node(int type, char *value);
void	add_r_node(t_redir **redir_l, t_redir *nw);
t_redir	**get_redir_list(int first, int last);

/* INPUT PARSER */

t_input	*parse_input(char *input);

#endif
