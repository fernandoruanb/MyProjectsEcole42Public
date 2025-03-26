/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_create_simple_branch.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:30:21 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/02/09 15:04:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_tree
{
	char	*value;
	struct s_tree *left;
	struct s_tree *right;
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
	return (1);
}

t_tree	*create_simple_branch(char *value)
{
	t_tree *branch;

	branch = malloc(sizeof(t_tree));
	if (!branch)
		return (NULL);
	branch->value = value;
	branch->left = NULL;
	branch->right = NULL;
	return (branch);
}

int	main(int argc, char **argv)
{
	t_tree	*tree;

	if (argc != 2)
		return (1);
	tree = create_simple_branch(argv[1]);
	if (!tree)
		return (1);
	printf("I have made a branch: %s\n", tree->value);
	free(tree);
	return (0);
}
