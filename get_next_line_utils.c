/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton </var/mail/agraton>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:38:01 by agraton           #+#    #+#             */
/*   Updated: 2020/11/26 12:56:19 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list		*ft_lstnew(char *content, int fd, t_list *next)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->content = content;
	new->fd = fd;
	new->next = next;
	return (new);
}

t_list		*ft_lstsearch(t_list **lst, int fd)
{
	if (!*lst)
		return (*lst = ft_lstnew(NULL, fd, NULL));
	if ((*lst)->fd == fd)
		return (*lst);
	return (ft_lstsearch(&(*lst)->next, fd));
}
