/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_Insert_Search_Remove.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:51:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/02/13 16:22:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_tree
{
	int	value;
	int	index;
	struct s_tree *left;
	struct s_tree *right;
}	t_tree;

t_tree	*create_new_branch(int value)
{
	t_tree	*branch;
	static int	index = 0;

	if (!value)
		return (NULL);
	branch = malloc(sizeof(t_tree));
	if (!branch)
		return (NULL);
	branch->index = index++;
	branch->value = value;
	branch->left = NULL;
	branch->right = NULL;
	return (branch);
}

void	move_right(t_tree **tree, int value)
{
	t_tree	*last;

	last = *tree;
	if (last->right == NULL)
		last->right = create_new_branch(value);
	else
	{
		while (last)
		{
			if (last->value > value && last->right == NULL)
			{
				last->right = create_new_branch(value);
				break ;
			}
			else if (last->value < value && last->left == NULL)
			{
				last->left = create_new_branch(value);
				break ;
			}
			if (last->value < value)
				last = last->left;
			else
				last = last->right;
		}
	}
}

void	move_left(t_tree **tree, int value)
{
	t_tree	*last;

	last = *tree;
	if (last->left == NULL)
		last->left = create_new_branch(value);
	else
	{
		while (last)
		{
			if (last->value < value && last->left == NULL)
			{
				last->left = create_new_branch(value);
				break ;
			}
			else if (last->value > value && last->right == NULL)
			{
				last->right = create_new_branch(value);
				break ;
			}
			if (last->value < value)
				last = last->left;
			else
				last = last->right;
		}
	}
}

void	add_new_branch(t_tree **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = create_new_branch(value);
		return ;
	}
	else if ((*tree)->value < value)
		move_left(tree, value);
	else if ((*tree)->value > value)
		move_right(tree, value);
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
	show_tree(tree->left, level + 1);
	index = 0;
	while (index++ < level)
		printf("    ");
	printf("%d     \n", tree->value);
	show_tree(tree->right, level + 1);
}

void	sort_list(int **list, int argc)
{
	int	index;
	int	number;

	index = 0;
	while (index < argc - 1)
	{
		if ((*list)[index] > (*list)[index + 1])
		{
			number = (*list)[index];
			(*list)[index] = (*list)[index + 1];
			(*list)[index + 1] = number;
			index = 0;
		}
		else
			index++;
	}
}

int	main(int argc, char **argv)
{
	t_tree	*tree;
	int	index;
	int	*list;

	(void)argc;
	tree = NULL;
	list = (int *)malloc(sizeof(int) * argc - 1);
	if (!list)
		return (1);
	index = 0;
	while (index < argc - 1)
	{
		list[index] = atoi(argv[index + 1]);
		index++;
	}
	sort_list(&list, argc);
	tree = create_new_branch(atoi(argv[0]));
	index = 1;
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
	free(list);
	return (0);
}
