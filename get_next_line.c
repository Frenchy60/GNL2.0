/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton </var/mail/agraton>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 09:19:00 by agraton           #+#    #+#             */
/*   Updated: 2021/08/06 22:13:50 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_contains(char *str, char stop)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		if (str[i++] == stop)
			return (1);
	return (0);
}

int		ft_strlenc(char *str, char stop)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != stop)
		i++;
	return (i);
}

char		*ft_strjoinc(char *str, char *str2, char stop)
{
	int		i;
	int		o;
	int		p;
	char	*newstr;

	i = ft_strlenc(str2, stop);
	o = ft_strlenc(str, stop);
	newstr = malloc(sizeof(char) * (i + o + 1));
	if (!newstr)
	{
		if (str)
			free(str);
		return (NULL);
	}
	p = -1;
	while (++p < o)
		newstr[p] = str[p];
	p = -1;
	while (++p < i)
		newstr[o + p] = str2[p];
	newstr[i + o] = '\0';
	if (str)
		free(str);
	return (newstr);
}

void	ft_strmove(char *str, char stop)
{
	int	size;
	int	i;

	size = ft_strlenc(str, stop);
	i = 1;
	while (str[size + i])
	{
		str[i - 1] = str[size + i];
		i++;
	}
	i--;
	while (i <= BUFFER_SIZE)
		str[i++] = '\0';
}

char	*get_next_line(int fd)
{
	static char		buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char			*newline;
	int				readn;

	if (fd <= 0)
		return (NULL);
	readn = -5;
	newline = NULL;
	newline = ft_strjoinc(newline, buffer[fd], '\n');
	if (!newline)
		return (NULL);
	while (!ft_contains(buffer[fd], '\n') && (readn > 0 || readn == -5))
	{
		readn = read(fd, buffer[fd], BUFFER_SIZE);
		newline = ft_strjoinc(newline, buffer[fd], '\n');
		if (!newline)
			return (NULL);
	}
	ft_strmove((char *)(buffer[fd]), '\n');
	if (!newline || (!(ft_strlenc(newline, '\n') + ft_strlenc(buffer[fd], '\n')) && !readn))
	{
		if (newline)
			free(newline);
		return (NULL);
	}
	return (newline);
}
