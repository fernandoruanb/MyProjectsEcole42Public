/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:04:56 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/02/14 11:55:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * A recursão, o computador faz como uma foto do estado de todas as
 * variáveis. Guarda na pilha de recursão. Quando finaliza, ele volta para
 * o estado anterior. Nosso objetivo aqui é conseguir montar uma árvore usando
 * o modelo iterativo de loop.
 */

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
		printf("      ");
	printf("%d   \n", tree->value);
	show_tree(tree->left, level + 1);
}

void	add_new_branch(t_tree **tree, int value)
{
	t_tree	*temp;

	temp = *tree;
	while (temp)
	{
		if (temp->value > value)
		{
			tree = &(*temp).left;
			temp = temp->left;
		}
		else if (temp->value < value)
		{
			tree = &(*temp).right;
			temp = temp->right;
		}
		else
			break ;
	}
	if (temp == NULL)
		temp = create_new_branch(value);
	*tree = temp;
}

t_tree	*search_an_element(t_tree *find, int value)
{
	if (find == NULL)
		return (NULL);
	if (find->value == value)
		return (find);
	if (find->value > value)
		return (search_an_element(find->left, value));
	if (find->value < value)
		return (search_an_element(find->right, value));
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_tree	*tree;
	t_tree	*find;
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
	find = search_an_element(find, 2);
	if (find != NULL && find->value == 2)
		printf("We found the value!!!\n");
	else
		printf("We can't find the value! :(");
	if (tree)
	{
		printf("\n-------------------\n");
		printf("-----BINARY_TREE----\n");
		printf("--------------------\n");
		show_tree(tree, 1);
		clean_tree(&tree);
	}
	return (0);
}
