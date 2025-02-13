/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:26:21 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/02/13 19:07:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_tree
{
	int	value;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

t_tree	*create_new_branch(int value)
{
	t_tree	*branch;

	branch = malloc(sizeof(t_tree));
	if (!branch)
		return (NULL);
	branch->value = value;
	branch->left = NULL;
	branch->right = NULL;
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
	free(*tree);
	*tree = NULL;
}

void	add_new_branch(t_tree **tree, int value)
{
	if (*tree == NULL)
		*tree = create_new_branch(value);
	else if ((*tree)->value > value)
		add_new_branch(&(*tree)->left, value);
	else if ((*tree)->value < value)
		add_new_branch(&(*tree)->right, value);
}

void	show_tree(t_tree *tree, int level)
{
	int	index;

	if (tree == NULL)
		return ;
	show_tree(tree->right, level + 1);
	index = 1;
	while (index++ < level)
		printf("     ");
	printf("%d     \n", tree->value);
	show_tree(tree->left, level + 1);
}

int	main(int argc, char **argv)
{
	int	index;
	t_tree	*tree;

	if (argc < 2)
		return (1);
	tree = create_new_branch(atoi(argv[1]));
	if (!tree)
		return (1);
	index = 2;
	while (index < argc)
	{
		add_new_branch(&tree, atoi(argv[index]));
		index++;
	}
	if (tree)
	{
		show_tree(tree, 1);
		clean_tree(&tree);
	}
	return (0);
}
