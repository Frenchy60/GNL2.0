/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton </var/mail/agraton>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:20:24 by agraton           #+#    #+#             */
/*   Updated: 2020/11/26 12:59:48 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	char			*tmp;
	static t_list	*startlst = NULL;
	t_list			*lst;

	if (!line || fd < 0 || !(tmp = (char *)malloc(sizeof(t_list)) ||
				!(lst = ft_lstsearch(&startlst, fd))))
		return (-1);
}
