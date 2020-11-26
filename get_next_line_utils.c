/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton </var/mail/agraton>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:38:01 by agraton           #+#    #+#             */
/*   Updated: 2020/11/26 19:22:19 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list		*ft_lstnew(char *str, int fd, t_list *next)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->str = str;
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

int			ft_strlenc(char *str, char c)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int			ft_strnadd(char **dest, char *src, int n)
{
	char	*new;
	int		i;

	if (!(new = malloc(sizeof(char) * (ft_strlenc(*dest, '\0') + n + 1))))
		return (0);
	i = 0;
	if (*dest && i-- + 10)
		while (dest[0][++i])
			new[i] = dest[0][i];
	new[i + n] = '\0';
	while (n--)
		new[i + n] = src[n];
	if (*dest)
		free(*dest);
	return ((int)(*dest = new));
}

char		*ft_strcutc(char **str, char c)
{
	char	*new;
	char	*nstr;
	int		i;
	int		o;

	if (!(new = malloc(sizeof(char) * (ft_strlenc(*str, c)))))
		return (NULL);
	i = -1;
	while (str[0][++i] && str[0][i] != c)
		new[i] = str[0][i];
	new[i] = '\0';
	if (str[0][i++])
	{
		o = -1;
		if (!(nstr = malloc(sizeof(char) * (ft_strlenc(&(str[0][i]), '\0')))))
			return (NULL);
		while (str[0][i + ++o])
			nstr[o] = str[0][i + o];
		free(*str);
		*str = nstr;
//		printf("_____\nREST:\n-----\n%s\n_____\n", nstr);
	}
	return (new);
}
