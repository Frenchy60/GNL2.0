/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:54:40 by agraton           #+#    #+#             */
/*   Updated: 2020/11/26 19:22:21 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_lstfree(t_list **lst, int fd)
{
	t_list	*tmp;

	tmp = *lst;
	if (tmp->fd == fd)
	{
		if (tmp->str)
			free(tmp->str);
		*lst = tmp->next;
		free(tmp);
		return (1);
	}
	if (!*lst)
		return (1);
	return (ft_lstfree(&tmp->next, fd));
}

int			ft_strchr(char *s)
{
	if (!s)
		return (0);
	while (*s)
		if (*(s++) == '\n')
			return (1);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char			*tmp;
	int				rn;
	static t_list	*startlst = NULL;
	t_list			*lst;

//	if (!line || fd < 0 || !(tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE))
//			|| (!(lst = ft_lstsearch(&startlst, fd)) && (free(tmp) * 0) + 1))
//		return (-1);
	if (!line || fd < 0 ||  !(lst = ft_lstsearch(&startlst, fd)) ||
			!(tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
		return ((lst) ? ft_lstfree(&startlst, fd) - 2 : -1);
	while (0 < (rn = (ft_strchr(lst->str)) ? -2 : read(fd, tmp, BUFFER_SIZE)))
		if (!ft_strnadd(&(lst->str), tmp, rn))
			return (ft_lstfree(&startlst, fd) - 2);
	free(tmp);
	if (rn == -1 && (ft_lstfree(&startlst, fd)))
		return (-1);
	if (!(*line = ft_strcutc(&(lst->str), '\n')))
		return (ft_lstfree(&startlst, fd) - 2);
	if (!ft_strlenc(lst->str, '\0') && rn == 0)
		return (ft_lstfree(&startlst, fd) - 1);
	return (1);
}
