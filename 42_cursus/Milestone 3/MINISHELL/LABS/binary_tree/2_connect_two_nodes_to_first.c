/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_connect_two_nodes_to_first.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:07:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/02/09 16:03:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_tree
{
	char	*value;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

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
	}
	else if (flag == 2)
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
	free(*tree);
	*tree = NULL;
}

void	show_tree(t_tree *tree)
{
	if (tree == NULL)
		return ;
	printf("%s\n", tree->value);
	show_tree(tree->left);
	show_tree(tree->right);
}

int	main(int argc, char **argv)
{
	t_tree	*tree;
	int	index;
	int	flag;

	if (argc != 5)
		return (ft_putendl_fd_1("Too few arguments", 2));
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
