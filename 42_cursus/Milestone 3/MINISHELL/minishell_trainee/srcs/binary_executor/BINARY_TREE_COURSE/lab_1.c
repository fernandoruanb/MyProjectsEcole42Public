/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:23:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/02/13 18:13:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_tree
{
	int	value;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

t_tree	*create_new_branch(int value)
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

void	show_tree(t_tree *tree, int level)
{
	int	index;

	if (tree == NULL)
		return ;
	show_tree(tree->right, level + 1);
	index = 0;
	while (index++ < level)
		printf("     ");
	printf("%d      \n", tree->value);
	show_tree(tree->left, level + 1);
}

t_tree	*add_new_branch(t_tree **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = create_new_branch(value);
		return (*tree);
	}
	else if ((*tree)->value > value)
		(*tree)->left = add_new_branch(&(*tree)->left, value);
	else if ((*tree)->value < value)
		(*tree)->right = add_new_branch(&(*tree)->right, value);
	return (*tree);
}

void	print_tree(t_tree *tree)
{
	if (tree == NULL)
		return ;
	print_tree(tree->left);
	printf("%d ", tree->value);
	print_tree(tree->right);
}

int	main(int argc, char **argv)
{
	t_tree	*tree;
	int	index;

	if (argc < 2)
		return (1);
	tree = NULL;
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
		if (argc > 2)
			print_tree(tree);
		printf("\n");
		clean_tree(&tree);
	}
	return (0);
}
