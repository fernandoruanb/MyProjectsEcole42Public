/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_Impress_Tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:04:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/02/09 16:42:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_tree
{
	char	*value;
	struct s_tree	*parent;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

t_tree	*create_new_branch(char *value)
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

void	add_new_branch(t_tree **tree, char *value, int flag)
{
	t_tree	*last;

	if (flag == 1)
	{
		last = *tree;
		while (last->left)
			last = last->left;
		last->left = create_new_branch(value);
		last->parent = last;
	}
	else if (flag == 2)
	{
		last = *tree;
		while (last->right)
			last = last->right;
		last->right = create_new_branch(value);
		last->parent = last;
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
	free(*tree);
	*tree = NULL;
}

void	show_tree(t_tree *tree)
{
	if (tree == NULL)
		return ;
	printf("   %s\n", tree->value);
	printf("  /    \\\n");
	if (tree->left)
		printf(" %s  ", tree->left->value);
	else
		printf("NULL  ");
	if (tree->right)
		printf(" %s\n", tree->right->value);
	else
		printf("NULL\n");
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
	write(fd, "\n", 1);
	return (1);
}

int	main(int argc, char **argv)
{
	int	index;
	int	flag;
	t_tree	*tree;

	if (argc < 2)
		return (ft_putendl_fd_1("Too few arguments.\n", 2));
	tree = create_new_branch(argv[1]);
	if (!tree)
		return (1);
	index = 2;
	flag = 1;
	while (index < argc)
	{
		add_new_branch(&tree, argv[index], flag);
		if (flag == 1)
			flag = 2;
		else
			flag = 1;
		index++;
	}
	show_tree(tree);
	clean_tree(&tree);
	return (0);
}
