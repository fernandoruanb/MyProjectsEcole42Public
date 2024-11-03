/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaretel- <yaretel-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:28:12 by yaretel-          #+#    #+#             */
/*   Updated: 2022/12/08 17:17:51 by yaretel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_splitnode(t_list *lst, char *nl)
{
	t_list			*new;
	unsigned int	i;

	if (lst == NULL || nl == NULL)
		return (NULL);
	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	i = 0;
	nl++;
	while (nl[i] != '\0')
	{
		(new->buf)[i] = nl[i];
		if (i == 0)
			nl[i] = '\0';
		i++;
	}
	(new->buf)[i] = '\0';
	return (new);
}

char	*ft_list_to_string(t_list *lst)
{
	size_t	len;
	size_t	i;
	size_t	j;
	t_list	*lstcpy;
	char	*string;

	lstcpy = lst;
	len = ft_lstlen(lst);
	if (len <= 0)
		return (ft_lstreset(lstcpy));
	string = malloc(sizeof(*string) * (len + 1));
	if (string == NULL)
		return (ft_lstreset(lstcpy));
	lst = lstcpy;
	i = 0;
	while (lst != NULL && i < len)
	{
		j = 0;
		while ((lst->buf)[j] != '\0')
			string[i++] = (lst->buf)[j++];
		lst = lst->next;
	}
	string[i] = '\0';
	ft_lstreset(lstcpy);
	return (string);
}

void	ft_gnl_check(char **nl, t_list **start, ssize_t *red, t_list *lst)
{
	*nl = NULL;
	*start = NULL;
	*red = 1;
	if (lst != NULL)
	{
		*start = lst;
		*nl = ft_strchr(lst->buf, '\n');
	}
}

int	ft_extend_list_and_move_lst(t_list **lst, t_list **start)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return ((long)ft_lstreset(*start));
	new->next = NULL;
	if (*lst == NULL)
		*start = new;
	else
		(*lst)->next = new;
	*lst = new;
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	t_list			*start;
	char			*nl;
	ssize_t			red;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_gnl_check(&nl, &start, &red, lst);
	while (nl == NULL && red > 0)
	{
		if (ft_extend_list_and_move_lst(&lst, &start) == 0)
			return (NULL);
		red = read(fd, lst->buf, BUFFER_SIZE);
		if (red < 0)
		{
			lst = NULL;
			return (ft_lstreset(start));
		}
		(lst->buf)[red] = '\0';
		nl = ft_strchr(lst->buf, '\n');
	}
	lst = ft_splitnode(lst, nl);
	return (ft_list_to_string(start));
}
