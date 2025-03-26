/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_Search_a_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:37:21 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/02/10 16:19:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_tree
{
	int	value;
	struct s_tree	*left;
	struct s_tree	*right;
	struct s_tree	*parent;
}	t_tree;

t_tree	*create_new_branch(int value)
{
	t_tree	*branch;

	branch = malloc(sizeof(t_tree));
	if (!branch)
		return (NULL);
	branch->value = value;
	branch->left = NULL;
	branch->parent = NULL;
	branch->right = NULL;
	return (branch);
}

void	add_new_branch(t_tree **tree, int value)
{
	t_tree	*last;

	if (value < (*tree)->value)
	{
		last = *tree;
		while (last->left)
			last = last->left;
		last->left = create_new_branch(value);
	}
	else if (value > (*tree)->value)
	{
		last = *tree;
		while (last->right)
			last = last->right;
		last->right = create_new_branch(value);
	}
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

void	show_tree(t_tree *tree)
{
	if (tree == NULL)
		return ;
	if (tree)
		printf("NOW: %d\n", tree->value);
	if (tree->left)
		printf("LEFT: %d\n", tree->left->value);
	else
		printf("LEFT: NULL\n");
	if (tree->right)
		printf("RIGHT: %d\n", tree->right->value);
	else
		printf("RIGHT: NULL\n");
	show_tree(tree->left);
	show_tree(tree->right);
}

int	ft_putendl_fd_1(char *message, int fd)
{
	int	index;

	index = 0;
	while (message[index] != '\0')
	{
		write(fd, &message[index], 1);
		index++;
	}
	write(1, "\n", 1);
	return (1);
}

t_tree	*get_value(t_tree *tree, int target)
{
	t_tree	*last;

	last = tree;
	while (last->left)
	{
		if (last->left->value == target)
			return (last->left);
		last = last->left;
	}
	last = tree;
	while (last->right)
	{
		if (last->right->value == target)
			return (last->right);
		last = last->right;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int	index;
	t_tree	*tree;
	t_tree	*target;

	if (argc < 2)
		return (ft_putendl_fd_1("Too few arguments.", 2));
	tree = create_new_branch(atoi(argv[1]));
	if (!tree)
		return (1);
	index = 2;
	while (index < argc)
	{
		add_new_branch(&tree, atoi(argv[index]));
		index++;
	}
	show_tree(tree);
	target = get_value(tree, 2);
	if (target)
		printf("I found the target!!!, %d!!!\n", target->value);
	else
		printf("Unfortunately, I can't find the value.\n");
	clean_tree(&tree);
	return (1);
}
