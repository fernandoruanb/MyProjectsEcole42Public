/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:44:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/02/10 18:38:35 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../libft/libft.h"

typedef struct s_tree
{
	char	*value;
	struct s_tree	*left;
	struct s_tree	*right;
	struct s_tree	*parent;
}	t_tree;

t_tree	*create_new_branch(char	*value)
{
	t_tree	*branch;

	if (!value)
		return (NULL);
	branch = malloc(sizeof(t_tree));
	if (!branch)
		return (NULL);
	branch->value = value;
	branch->left = NULL;
	branch->right = NULL;
	branch->parent = NULL;
	return (branch);
}

void	clean_tree(t_tree **tree)
{
	if (*tree == NULL)
		return ;
	clean_tree(&(*tree)->left);
	clean_tree(&(*tree)->right);
	(*tree)->left = NULL;
	(*tree)->right = NULL;
	(*tree)->parent = NULL;
	free(*tree);
	*tree = NULL;
}

int	is_operator(char *value)
{
	if (ft_strcmp(value, "|") == 0 || ft_strcmp(value, "<") == 0
		|| ft_strcmp(value, ">") == 0 || ft_strcmp(value, "<<") == 0
		|| ft_strcmp(value, ">>") == 0)
		return (1);
	return (0);
}

void	add_new_branch(t_tree **tree, char *value)
{
	t_tree	*last;

	if (!*tree)
		*tree = create_new_branch(value);
	if (ft_strcmp(value, "|") == 0)
	{
		last = *tree;
		while (last->left)
			last = last->left;
		last->left = create_new_branch(value);
	}
	else
	{
		last = *tree;
		while (last->right)
			last = last->right;
		last->right = create_new_branch(value);
	}
}

void	show_tree(t_tree *tree, int level)
{
	int	index;

	if (tree == NULL)
		return ;
	show_tree(tree->left, level + 1);
	index = 0;
	while (index++ < level)
		printf("     ");
	printf("%s  \n", tree->value);
	show_tree(tree->right, level + 1);
}

int	main(void)
{
	t_tree	*tree;

	tree = create_new_branch("|");
	if (!tree)
		return (1);
	add_new_branch(&tree, "ls -l");
	add_new_branch(&tree, "|");
	add_new_branch(&tree, "echo oi tudo bem");
	show_tree(tree, 1);
	clean_tree(&tree);
	return (0);
}
